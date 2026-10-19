#include <iostream>

#include "src/JobQueue.hpp"

int main() {
    JobQueue jobQueue;
    Job job1("Job 1", 5);
    Job job2("Job 2", 10);
    Job job3("Job 3", 7);
    Job job4("Job 4", 3);
    Job job5("Job 5", 8);
    jobQueue.insert(job1);
    jobQueue.insert(job2);
    jobQueue.insert(job3);
    jobQueue.insert(job4);
    jobQueue.insert(job5);

    jobQueue.runHighestPriority(); //should run job2
    jobQueue.runHighestPriority(); //should run job5
    jobQueue.runHighestPriority(); //should run job3
    jobQueue.runHighestPriority(); //should run job1
    jobQueue.runHighestPriority(); //should run job4
    jobQueue.runHighestPriority(); //should do nothing since the queue is empty

}
