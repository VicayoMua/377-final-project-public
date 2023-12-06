# DiskVirtualMemoryManager

By: Isabella Marino, Bach Tran, Vicayo Zhang, & Prithvi Kanaujia

## Project Overview

For our final project we decided to extend Project 5 by adding a class named the DiskVirtualMemoryManager. While the original project focuses on managing a single page, we wanted to explore the possibility of creating a virtual disk that would setup and manage multiple pages of memory using the Project 5 code.

To do this we first created the new class, DiskVirtuaMemoryManager. Given a folder path, the constructor either uses the already existing folder by the provided name or creates one. It then creates the first page that will then be handled and modified by our Project 5 code. The class is also completely thread safe with mutual exclusion protections through the use of semaphores.

We additionally modified our base Project 5 code by converting all of the functions into a class named the PageManager. We decided this was the optimal way to begin our process of making the code thread-safe. We completed this task by going throuhg the class methods using semaphors to keep the critical sections safe.

## How To Run The Program

To run the program normally, we have provided an executable named DiskVirtualMemoryManager which can be run locally. It should be noted that due to the nature of the DiskVirtualMemoryManager class, this code cannot be run on the edlab or mac machines. This is because the class requires file managing permissions that are blocked on the edlab for non-administrators. Therefore, the code needs to be run locally on a windows machine.


To run the executable, simply open up the terminal. The first step is to compile the code using the following command:

> make

The next step is to run the executable using the following command:

>./DiskVirtualMemoryManager

## Test Cases

For our test cases we first refactored the tests used for Project 5 to use the new PageManager class methods instead of the original Project functions. These tests can all be run by using the test executable we created named MallocTest. This can be run using the following command:

>./MallocTest

The various tests check to make sure each individual class method is working correctly. 