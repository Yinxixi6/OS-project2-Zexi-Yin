# OS-project2-Zexi-Yin
# Overview: Banker’s Algorithm for deadlock avoidance
# Idea of bankers.cpp
The bankers.cpp complie with the form, so firstly create input.txt with the total resources and the process need. Then the project read the system's total resources, allocation matrix, maximum demand matrix, and available resources from input.txt file. Next step is calculate the Need matrix by subtracting allocation from maximum for each process. The program then attempts to find a safe sequence by simulating the execution of processes: if a process's Need is less than or equal to the currently available resources, it is assumed to complete and its allocated resources are returned to the available pool. If all processes can eventually complete without deadlock, the system is declared safe and the safe sequence is printed; otherwise, the system is deemed unsafe. Finally print the result and finished.

# Idea of input.txt
10 5 7 // total resources
5      // number of processes
0 1 0  // allocation p0
2 0 0  // allocation p1
3 0 2  // allocation p2
2 1 1  // allocation p3
0 0 2  // allocation p4
7 5 3  // max p0
3 2 2  // max p1
9 0 2  // max p2
2 2 2  // max p3
4 3 3  // max p4
3 2 2  // available

# Example output:
![image](https://github.com/user-attachments/assets/44ca8024-2e45-4762-aa9f-806056afdf7f)

# Compilation:
I used c++ to finish this project, the environment is Linux, use following commends to complie:

g++ bankers.cpp -o bankers

./bankers
