#include <iostream>
#include <ctype.h>
#include "Header.h"
#include <cstring>
#include <math.h>
using namespace std;

void push(stack*& tmp, char x)
{
    stack* temp = new stack;
    temp->key = x;
    temp->next = tmp->head;
    tmp->head = temp;
}
void pop(stack* tmp)
{
    stack* temp = tmp->head->next;
    delete tmp->head;
    tmp->head = temp;
}
void Show(stack* tmp)
{
    stack* temp = tmp->head;
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
}
bool empty(stack* tmp)
{
    return tmp->head == nullptr;
}
void Computation(char* ArrayForCalculating, int size)
{
    stack* notation = new stack;
    notation->head = NULL;
    int temp = 0;
    while (temp < size)
    {
        if (isdigit(ArrayForCalculating[temp]))
        {
            push(notation, ArrayForCalculating[temp]);
            temp++;
            continue;
        }
        if (ArrayForCalculating[temp] == 'p' && ArrayForCalculating[temp + 1] == 'i')
        {
            push(notation, '3');
            temp = temp + 2;
            continue;
        }
        if (ArrayForCalculating[temp] == 'e')
        {
            push(notation, '2');
            temp++;
            continue;
        }
        if (notation->head != nullptr)
        {
            if (ArrayForCalculating[temp] == '+')
            {
                int FirstPart = notation->head->key - '0';
                pop(notation);
                int summ = FirstPart + (notation->head->key - '0');
                char con = summ + '0';
                pop(notation);
                push(notation, con);
                temp++;
                continue;
            }
            if (ArrayForCalculating[temp] == '-')
            {
                int FirstPart = notation->head->key - '0';
                pop(notation);
                int minus = (notation->head->key - '0') - FirstPart;
                pop(notation);
                char con = minus + '0';
                push(notation, con);
                temp++;
                continue;
            }
            if (ArrayForCalculating[temp] == '*')
            {
                int FirstPart = notation->head->key - '0';
                pop(notation);
                int ymnoj = FirstPart * (notation->head->key - '0');
                char con = ymnoj + '0';
                pop(notation);
                push(notation, con);
                temp++;
                continue;
            }
            if (ArrayForCalculating[temp] == '/')
            {
                int FirstPart = notation->head->key - '0';
                pop(notation);
                int delenie = (notation->head->key - '0') / FirstPart;
                pop(notation);
                char con = delenie + '0';
                push(notation, con);
                temp++;
                continue;
            }
            if (ArrayForCalculating[temp] == '^')
            {
                int FirstPart = notation->head->key - '0';
                pop(notation);
                int SecondPart = (notation->head->key - '0');
                int stepen = pow(SecondPart, FirstPart);
                pop(notation);
                char con = stepen + '0';
                push(notation, con);
                temp++;
                continue;
            }
        }
    }
    if (notation->head != nullptr)
    {
        char head = notation->head->key;
        int result = head - '0';
        cout << "Calculation result: " << result << endl;
    }
}
void Convert(int size, char* ArrayForConvert_2)
{
    int index = 0, OpeningParentheses = 0, ClosingParentheses = 0;
    while (index < size)
    {
        if (ArrayForConvert_2[index] == '(') OpeningParentheses++;
        if (ArrayForConvert_2[index] == ')') ClosingParentheses++;
        index++;
    }
    if (OpeningParentheses != ClosingParentheses) throw invalid_argument("Brace mismatch");
    stack* notation = new stack;
    notation->head = NULL;
    char* ResultOfConvert = new char[size];
    int i = 0, temp = 0, parentheses = 0;
    while (temp < size)
    {
        if (ArrayForConvert_2[temp] == '(' || ArrayForConvert_2[temp] == ')') parentheses++;
        if (isdigit(ArrayForConvert_2[temp]))
        {
            ResultOfConvert[i] = ArrayForConvert_2[temp];
            temp++;
            i++;
            continue;
        }
        if (ArrayForConvert_2[temp] == 'e')
        {
            ResultOfConvert[i] = ArrayForConvert_2[temp];
            temp++;
            i++;
            continue;
        }
        if (ArrayForConvert_2[temp] == 'p' && ArrayForConvert_2[temp + 1] == 'i')
        {
            ResultOfConvert[i] = ArrayForConvert_2[temp];
            ResultOfConvert[i+1] = ArrayForConvert_2[temp+1];
            temp = temp + 2;
            i = i + 2;
            continue;
        }
        if (isdigit(ArrayForConvert_2[temp]))
        {
            ResultOfConvert[i] = ArrayForConvert_2[temp];
            temp++;
            i++;
            continue;
        }
        if ((ArrayForConvert_2[temp] == '+') || (ArrayForConvert_2[temp] == '-') || (ArrayForConvert_2[temp] == '*') || (ArrayForConvert_2[temp] == '/') || (ArrayForConvert_2[temp] == '^') || (ArrayForConvert_2[temp] == '('))
        {
            if (notation->head != nullptr)
            {
                if ((ArrayForConvert_2[temp] == '*' || ArrayForConvert_2[temp] == '/') && (notation->head->key == '*' || notation->head->key == '/' || notation->head->key == '^'))
                {
                    ResultOfConvert[i] = notation->head->key;
                    pop(notation);
                    i++;
                }
                if ((ArrayForConvert_2[temp] == '+' || ArrayForConvert_2[temp] == '-') && (notation->head->key == '*' || notation->head->key == '/' || notation->head->key == '+' || notation->head->key == '-' || notation->head->key == '^'))
                {
                    ResultOfConvert[i] = notation->head->key;
                    pop(notation);
                    i++;
                }
                if (ArrayForConvert_2[temp] == '^' && (notation->head->key == '^'))
                {
                    ResultOfConvert[i] = notation->head->key;
                    pop(notation);
                    i++;
                }
            }
            push(notation, ArrayForConvert_2[temp]);
            temp++;
            continue;
        }
        if (ArrayForConvert_2[temp] == ')' && (notation->head != nullptr))
        {
            while (notation->head->key != '(')
            {
                ResultOfConvert[i] = notation->head->key;
                pop(notation);
                i++;
            }
            pop(notation);
            temp++;
        }
        if (temp == 0) throw invalid_argument("Incorrectly entered expression");
    }
    if (temp != i) throw invalid_argument("Incorrectly entered expression");
    while (notation->head != nullptr)
    {
        ResultOfConvert[i] = notation->head->key;
        pop(notation);
        i++;
    }
    for (int p = 0; p < (size - parentheses); ++p) ArrayForConvert_2[p] = ResultOfConvert[p];
    Computation(ArrayForConvert_2, (size - parentheses));
}
int main()
{   
    string Expression;
    cout << "Enter your expression: ";
    cin >> Expression;
    cout << Expression << endl;
    int SizeExpression = Expression.size();
    char* ArrayForConvert = new char[SizeExpression];
    for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
    Convert(SizeExpression, &*ArrayForConvert);
    cout << "Result of Convert: ";
    for (int i = 0; i < 11; ++i) cout << ArrayForConvert[i];
    return 0;
}
