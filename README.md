# Philosophers

The overall purpose of this project is to use threads and mutexes. Using threads make it available to run multiple tasks at the same time, rather than waiting for a task to finish and after that start the next task.
Project Philosophers is about multiple philosophers sitting around a circle table with a large bowl of spaghetti on the table. Each philosopher is either eating, sleeping, or thinking at a time. In order to eat, each philosopher needs two forks, but the number of the forks available on the table is equal to the number of the philosophers meaning each philosopher has a fork on their left side and one on their right side, but each philosopher owns only one of them, and the other fork belongs to the adjacent philosopher. To survive, philosophers must eat in turn, using their own fork and their adjacent fork, and then sleep so that the adjacent philosopher has the opportunity to eat too. After waking up, they will think and start eating again, and it goes on until all the philosophers have eaten enough times or a philosopher has died due to hunger.

## Threads V.S. Processes

Any process creates a copy of all the variables, so it has its own variables independently, which means changing the value of a variable in one process does not affect the value of that variable in another process. In threads, all the threads share the same memory. So, if we create a thread, the main thread and the newly created thread share the same memory, meaning changing the value of a variable in one thread changes the value of that variable in the other thread too.

Furthermore, processes execute the code beginning from the `fork()` call all the way to `exit()` or `return()` from the `main()` function, but threads only execute the function passed as the third argument of the function `pthread_create()`

Also, each process has its own Process ID (pid), but all the threads execute their function inside the process that created them, so it means they have the same pid as the process in which they were created. So, each process can create multiple threads, but a thread cannot create a new process.

## Data race

The condition of multi threads having access to a variable or value to read the value or to assign a new value to the variable at the same time, which might cause some problems and bugs. But, it does not mean every single line of code must be executed by just one thread at a time because in this case using multi threads is meaningless. Mutexes are used to prevent data races.

## Mutex

Mutexes prevent multi threads from having access to the same value or variable at the same time to avoid data races.

## Overall workflow

Create a thread for each philosopher, a monitoring thread responsible to monitor the number of the times that each philosopher has eaten and to check if the program must continue or not, and another monitoring thread which is responsible to monitor the last time each philosopher ate and to check if any philosopher died or not.

### If the total number of philosophers is odd

All the odd index philosophers have the value of true for the `is_hungry` boolean struct member, so they start eating for `time_to_eat` time span. At the same time, all the even index philosophers have the value of false for `is_hungry`, so they start sleeping for the `time_to_sleep` time span. Back to odd philosophers, after `time_to_eat` time span is passed, odd philosophers put the forks back and sleep for `time_to_sleep` time span. Back to even philosophers, when even philosophers wake up, they start thinking, and they get the left and right fork<sup>1</sup> as soon as their adjacent philosopher puts them on the table. Then they start eating and after that they sleep. Whenever odd philosophers wake up, they think until they can get two forks<sup>2</sup>. This cycle continues until a philosopher dies or all the philosophers eat at least as many as specified by the last program argument, which is an optional argument (`./philo number_of_philosopher time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat`). Also, if one of the monitoring threads raise the `is_finished` flag, which means either a philosopher has died or all the philosophers have eaten enough times, all the philosopher threads stop continuing and just return to the caller function, which is the main function.

<font size="1">1, 2. In order to avoid deadlock, odd index philosophers first go for the right fork and then for the left fork, while even index philosophers do vice versa. In other words, odd index philosophers lock the mutex for the right fork as soon as it is unlocked by the adjacent philosopher to pick up the right fork and after that they lock the mutex for the left fork as soon as it is unlocked by the adjacent philosopher and the even index philosophers first go for the left fork and when they got it, they go for the right fork.</font>

### If the total number of philosophers is even

Simply, First all the odd philosophers start eating (at the same time even philosophers sleep). Then after odd philosophers finished eating, they sleep. Even philosophers think after waking up and then eat. After odd philosophers wake up, they think and start eating, and this cycle continues. Again, if the monitoring threads detect the program must terminate, the philosopher threads stop execution and return.

### Monitoring thread responsible to check the number of the time each philosopher eats

This thread consists of an infinite while loop with an inner while loop. The inner while loop, iterates over philosophers to check the number of the time they have eaten. Each philosopher that eats as the number of the `number_of_times_each_philosopher_must_eat` (or more than that), the monitoring thread increases a counter variable by one. If the value of this counter variable is equal to the total number of the philosophers, it means all the philosophers have eaten enough. So, the monitoring thread will raise a flag which says all the philosopher threads to stop execution and return. The other monitoring thread also sees this flag and returns. The current monitoring thread returns too. So, all the threads join the main thread and the program terminates. By the way, this thread starts the iterations only if the `number_of_times_each_philosopher_must_eat`, which is an optional argument, is specified.

### Monitoring thread responsible to check if a philosopher died

This thread consists of an infinite while loop and its inner loop, as well as the other monitoring thread. The inner loop iterates over all the philosophers to check if the time passed from their last meal<sup>3</sup> is greater than `time_to_eat` or not. If yes, the monitoring thread declares that a philosopher died and before returning, raises a flag. All the philosophers, and the other monitoring thread, see the flag and stop execution and return. So, all the threads join the main thread and the program gets terminated.

<font size="1">3.&nbsp;`time_to_die` is calculated from the beginning of the time span `time_to_eat`. In other words, the time when a philosopher picks both forks and starts eating is the reference to be compared to `time_to_die`.</font>

## Some Points

- As the `usleep()` function does not act accurately enough, a custom function is needed.
- One mutex is needed for each variable. If one mutex is going to be used for multiple variables or multiple lines of code, those variables or lines of code must be used together always and in all threads.
- Some mutexes are common between monitoring threads and all philosopher threads (e.g. `mutex_finish`), so we only need one mutex, and we use that mutex in all the threads because if one thread locks that mutex, all the other threads must wait for the mutex to be unlocked and only then have access to the variable or struct member (`is_finished`), but some other mutexes are shared between monitoring threads and one philosopher threads (e.g. `mutex_num_eat` and `mutex_last_eat`) or they are shared between some philosophers such as `mutex_forks` which is common between two adjacent philosophers, so we need as many number of these mutexes as the number of the philosophers. For example, each philosopher has its own `mutex_forks` and only that philosopher and his/her adjacent philosopher have access to that mutex.
