
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

struct stck {
    char item [10];
    int top;
}s;

bool isFull (struct stck *p) {
    if (p->top == 9)
        return true;
    return false;
}

bool isEmpty (struct stck *p) {
    if (p->top == -1)
        return true;
    return false;
}

void push (struct stck *p,char insert_value) {
    if (!isFull(&s)){
        p->top = p->top + 1;
        p->item [p->top] = insert_value;
    }
    else
        cout << "\nStack is Full !!";
}

char pop (struct stck *p) {
    char popped_value;
    if (!isEmpty(&s)) {
        popped_value = p->item [p->top];
        p->top--;
    }
    else
        cout << "\nStack is Empty !!";
    return popped_value;
}

int precedence (char operator_element) {
    if (operator_element == '$' || operator_element == '^')
        return 3;
    if (operator_element == '*' || operator_element == '/')
        return 2;
    if (operator_element == '+' || operator_element == '-')
        return 1;
    return 0;
}

int check_precedence (char in_operator, char stck_operator) {
    if(precedence(in_operator) > precedence(stck_operator))
        return 1;
    return 0;
}

int main() {
    system ("cls");
    int  i = 0, j = 0;
    s.top = 0;
    string infix_expr, temp_expr, prefix_expr;
    char postfix[10];

    cout << "\nEnter an infix expression : ";
    cin >> infix_expr;
    temp_expr = infix_expr; 
    reverse(temp_expr.begin(), temp_expr.end());

    while(temp_expr[i] != '\0')
    {
        if (temp_expr[i] == '*' || temp_expr[i] == '/' || temp_expr[i] == '+' || temp_expr[i] == '-' || temp_expr[i] == '$' || temp_expr[i] == '^')
        {
            if (isEmpty(&s))
                push(&s, temp_expr[i]);
            else
            {
                while(!check_precedence(temp_expr[i],s.item[s.top]))
                    postfix[j++] = pop(&s);
                push(&s, temp_expr[i]);
            }
        }
        else
            postfix[j++] = temp_expr[i];
        i++;
    }
    while(!isEmpty(&s))
        postfix[j++] = pop(&s);
    
    int len = strlen(postfix);          
    for(int j = 0; j < len/2; j++) {                             
        char temp = postfix[j];             
        postfix[j] = postfix[len-j-1];            
        postfix[len-j-1] = temp;
    }

    prefix_expr = postfix;
    cout << "\nPrefix Expression : " << postfix;

    return 0;
}