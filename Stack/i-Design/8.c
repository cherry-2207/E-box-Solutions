#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct infix
{
    char target[50];
    char stack[50];
    char s[50];
    int top;
};

void initinfix(struct infix *p);
void setexpr(struct infix *p, char *a);
void push(struct infix *p, char a);
char pop(struct infix *p);
int priority(char e);
void convert(struct infix *p);
void show(struct infix p);

int main()
{
    char inexpr[50];
    struct infix p;
    initinfix(&p);
    printf("Enter an expression in infix form:\n");
    scanf("%s", inexpr);
    setexpr(&p, inexpr);
    convert(&p);
    printf("The postfix expression is:\n");
    show(p);
    return 0;
}

void initinfix(struct infix *p)
{
    p->top = -1;
    strcpy(p->target, "");
    strcpy(p->stack, "");
}

void setexpr(struct infix *p, char *a)
{
    strcpy(p->s, a);
}

void push(struct infix *p, char a)
{
    if (p->top == 49)
    {
        printf("Stack Overflow\n");
        return;
    }
    p->top++;
    p->stack[p->top] = a;
}

char pop(struct infix *p)
{
    if (p->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    char temp = p->stack[p->top];
    p->top--;
    return temp;
}

int priority(char e)
{
    if (e == '$')
        return 3;
    else if (e == '*' || e == '/' || e == '%')
        return 2;
    else if (e == '+' || e == '-')
        return 1;
    else
        return 0;
}

void convert(struct infix *p)
{
    char x;
    int j = 0;
    for (int i = 0; p->s[i] != '\0'; i++)
    {
        if (isalnum(p->s[i]))
        {
            p->target[j++] = p->s[i];
        }
        else if (p->s[i] == '(')
        {
            push(p, p->s[i]);
        }
        else if (p->s[i] == ')')
        {
            while ((x = pop(p)) != '(')
            {
                p->target[j++] = x;
            }
        }
        else
        {
            while (priority(p->stack[p->top]) >= priority(p->s[i]))
            {
                x = pop(p);
                p->target[j++] = x;
            }
            push(p, p->s[i]);
        }
    }
    while (p->top != -1)
    {
        p->target[j++] = pop(p);
    }
    p->target[j] = '\0';
}

void show(struct infix p)
{
    printf("%s\n", p.target);
}
