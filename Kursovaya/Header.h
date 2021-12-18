#ifndef ADD_H
#define ADD_H
#include <iostream>
struct stack
{
    char key;
    stack* next;
    stack* head;
    /*~stack()
    {
        if (head != nullptr)
        {
            while (head != nullptr)
            {
                pop();
            }
        }
    }*/
};
void Convert(int size, char* ArrayForConvert_2);
#endif