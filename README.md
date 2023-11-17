# mutex-bank-simulator
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
A simple, terminal based, written for my Operating Systems class during my third semester at IFBA. 
Concurrent-Banking-System

This simple C program simulates a multi-threaded banking system where threads perform random withdrawals and deposits on a shared account. The program utilizes the pthread library for thread management and employs a mutex to ensure thread-safe access to the shared data.
The program creates a specified number of threads to perform random withdrawals and deposits on a shared account. The main function initializes the necessary variables, creates threads for withdrawal and deposit operations, and waits for their completion. The final account balance, total withdrawals, and total deposits are then printed. The program uses a mutex to ensure that only one thread can access shared data at a time. This prevents data corruption and race conditions during concurrent operations.
This program is a basic example for educational purposes and may not be suitable for production use. It serves to illustrate the concept of multi-threading and mutex usage in C programming.
