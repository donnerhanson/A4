# A4
Registrar Queue Analysis
Imagine that the registrar’s office has approached you with the following issues. At certain times during the day students arrive in large numbers. If there are not enough windows open, the average student wait times are too long, and they receive many complaints. On the other hand, if they open too many windows, their staff will be idle for most of the time, and they will be wasting money. They want you to program a simulation that will allow them to calculate metrics on student wait times and window idle times given a specific traffic flow of students.
The Specifics
You will model the above problem to meet the registrar’s requirements. As students arrive in the registrar’s office, they will wait in a queue. When a window becomes available they will exit the queue and remain at the service window for however long they need. Your first task will be to build a generic doubly-linked list data structure, from scratch, supporting the usual operations. You will then use this linked list to build a generic queue data structure, supporting the usual operations. You may not use a queue or linked list from the STL libraries. You will then use your queue implementation to finish the problem. (Note that in the spirit of reusability, you should have 3 classes...one for the list implementation, one for the list interface (pure virtual base class) and one for the queue. Of course, you’ll need additional classes to model the rest of the assignment.)
Input will be in the form of a command line argument (./myprog test.in) that specifies the location of a text file. The text file will define at what times students arrive and will have the following format. The first line will be the number of windows open. The next line will be the time (or clock tick) at which the next students arrive. The next line will be the number of students that arrive at that time. The following lines will be the amount of time each student needs at a window. This is followed by the next clock tick, number of students, etc. For example, and input of:
5\n 
1\n
2\n
5\n 
10\n 
3\n 
1\n 
4\n
 
Means that 5 windows will be open. At time 1, 2 students arrive. One will need 5 minutes at a window, and the other 10. Then, at time 3, 1 student arrives and needs 4 minutes at a window, etc, etc.
When students arrive at the same time, assume that the student listed first in the text file is also the first to get into line. In the above, at time 1 there will be 2 students that arrive. The student requiring 5 minutes will get into line before the student requiring 10 minutes.
The simulation will start at time 0, and run until all student requests have been addressed, meaning the queue is empty and no more students are going to arrive. (This should tell you the main body of the program is going to be a huge loop.)
At the end of the simulation, your program will display (on standard out) the following (labeled) metrics:
1. The mean student wait time.
2. The median student wait time.
3. The longest student wait time.
4. The number of students waiting over 10 minutes
5. The mean window idle time
6. The longest window idle time
7. Number of windows idle for over 5 minutes.
------------------------------------------------------

References:

Data Structures and Algorithms - Assignment 4

References:
CPP Reference - general library information
CPlusPlus.com - general library information
Stack Overflow

C/C++ Lecture Notes I - Raymond Mitchell - UCSD Extension
C/C++ Lecture Notes II - Raymond Mitchell - UCSD Extension
C/C++ Lecture Notes III - Raymond Mitchell III - UCSD Extension
C/C++ Lecture Notes IV - Raymond Mitchell III - UCSD Extension


https://www.geeksforgeeks.org/stdall_of-in-cpp/ - used to check the hasStudent bool value of all windows 

checking the results for calculating the median and mean
http://www.alcula.com/calculators/statistics/median/

Finding the mean and median
https://www.geeksforgeeks.org/program-for-mean-and-median-of-an-unsorted-array/
