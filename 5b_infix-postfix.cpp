#include <iostream>

using namespace std ;

struct stck 
{
    char item[10];
    int top;
}s;

int isfull(struct stck *ps)
{
    if(ps->top == 9)
        return 1;
    else
        return 0;
}

int isempty(struct stck *ps)
{
    if(ps->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stck *ps, char pushed_element)
{
    if (isfull(ps))
        cout << "Stack is Full ...";
    else
    {
        ps->top = ps->top + 1;
        ps->item[ps->top] = pushed_element;
    }
}

char pop(struct stck *ps)
{
    char popped_element = '\0';
    if (isempty(ps))
        cout << "Stack is empty";
    else
    {
        popped_element = ps->item[ps->top];
        ps->top = ps->top - 1;
    }
    return popped_element;
}

int precedence(char operator_element)
{
    if (operator_element == '$' || operator_element == '^')
        return 3;
    if (operator_element == '*' || operator_element == '/')
        return 2;
    if (operator_element == '+' || operator_element == '-')
        return 1;
    return 0;
}

int check_precedence(char in_operator, char stck_operator)
{
    if(precedence(in_operator) > precedence(stck_operator))
        return 1;
    else 
        return 0;
}

int main()
{
    system("cls");
    char expr[50],postfix[50];
    int i=0,j=0;
    s.top=0;

    cout << "\nEnter an expression : " ; gets(expr);

    while(expr[i] != '\0')
    {
        if (expr[i] == '*' || expr[i] == '/' || expr[i] == '+' || expr[i] == '-' || expr[i] == '$' || expr[i] == '^')
        {
            if (isempty(&s))
                push(&s, expr[i]);
            else
            {
                while(!check_precedence(expr[i],s.item[s.top]))
                    postfix[j++] = pop(&s);
                push(&s, expr[i]);
            }
        }
        else
            postfix[j++] = expr[i];
        i++;
    }
    while(!isempty(&s))
        postfix[j++] = pop(&s);
    
    cout << "\nPostfix Expression : " << postfix ;

    return 0;
}
