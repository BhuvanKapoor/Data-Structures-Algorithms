#include <iostream>
#include <cmath>

using namespace std;

struct stck {
    int item[10];
    int top;
}s;

bool isOperand(char operand) {
    if (operand >= '0' && operand <= '9') 
        return true;
    return false;
}

bool isOperator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '$' || op == '^')
        return true;
    return false;
}

bool isEmpty (struct stck *p) {
    if (p->top == -1)
        return true;
    return false;
}

int eval(int element_1,int element_2,char op) {
    if (op == '+') 
        return element_1+element_2;
    else if (op == '-')
        return element_1-element_2;
    else if (op == '/') 
        return element_1/element_2;
    else if (op == '*') 
        return element_1*element_2;
    else if (op == '$' || op == '^') 
        return pow(element_1,element_2);
    else
        return -1;
}

void push(struct stck *ps,int pushed_element) {
    ps->top = ps->top + 1;
    ps->item[ps->top] = pushed_element;
}

int pop(struct stck *ps) {
    int popped_element;
    popped_element = ps->item[ps->top];
    ps->top = ps->top - 1;
    return popped_element;
}

int main() {
    int i=0, eval_result, element_1, element_2, result;
    char choose;
    s.top=-1;

    string postfix_expr;

    do {
        system("cls");
        cout << "\n**********************************";
        cout << "\n\tPOSTFIX EVALUATION";
        cout << "\n**********************************";
        cout << "\nEnter an postfix expression : ";
        cin >> postfix_expr;

        while (postfix_expr[i] != '\0') {
            if (isOperand(postfix_expr[i])) {
                int postfix_element = int (postfix_expr[i]) - 48;
                push(&s,postfix_element);
            }
            else if (isOperator(postfix_expr[i])) {
                element_2 = pop(&s);
                element_1 = pop(&s);
                eval_result = eval(element_1,element_2,postfix_expr[i]);
                push(&s,eval_result);
            }
            i++;
        }
        result = pop(&s);
        if (isEmpty(&s))
            cout << "\nResult : " << result << endl;
        else
            cout << "\nWarning: Please enter a valid postfix expression !!";
        cout << "\nDo you want to continue (Y|N) : ";
        cin >> choose;
    } while (choose == 'y' || choose == 'Y');
    return 0;
}
