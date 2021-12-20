#ifndef ADD_H
#define ADD_H
#include <iostream>
struct stack
{
public:
    char key;
    stack* next;
    stack* head;
    ~stack()
    {
        if (head != nullptr)
        {
            while (head != nullptr)
            {
                stack* temp = head;
                stack* prev = NULL;
                while (temp->next)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if (prev) prev->next = NULL;
                else head = NULL;
                if (temp) delete temp;
            }
        }
    }
};
void Convert(int size, char* ArrayForConvert_2);
#endif