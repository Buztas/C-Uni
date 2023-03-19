# deque.h 

    #include "deque.h"

Includes the entire library for the deque, adds the functions addFront, addRear, delFront, delRear, display.

    addFront(int*, int, int*, int*);

The first parameter is a pointer to the array, the second paramter refers to the integer you want to add to the deque, the last two 
parameters are pointers to the beginning and the end of the current deque, with each use, we change the beginning and the end.

Adds a member to the deque in the front.

    addRear(int*, int, int *, int *);

Adds a member to the deque in the rear.

    delFront(int *, int *, int *)

Paramters are similar to the addFront and addRear, except in the deletion functions we do not need the 2nd parameter from the add functions. 

The function deletes the current first element in the deque.

    delRear(int *, int *, int *)

This function deletes the current last element in the deque.

    void display(int *)

This function displays the entire deque.

    run.bat

Runs the .exe file and opens the project files, if something goes wrong it throws an error.txt window and also displays the message in cmd.
