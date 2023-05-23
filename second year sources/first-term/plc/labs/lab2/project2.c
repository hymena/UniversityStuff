#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100] = "\0";
int top = -1;
char input[100];
char *pointerToInput;
void push(char c)
{
    top++;
    stack[top] = c;
}

void pop()
{
    if (stack[top] < 0)
    {
        printf("Error!");
        exit(1);
    }

    stack[top] = '\0';
    top--;
}

void display()
{
    int i = 0;
    int j = 0;
    int t=0;
    int z = 0;
    while (i <= top)
    {
        if (stack[i] == 'a')
        {
            printf("10");
            i++;
            continue;
        }
        if (stack[i] == 'b')
        {
            printf("11");
            i++;
            continue;
        }
        printf("%c", stack[i]);

        if (stack[i] == 'i')
        {
            printf("d");
        }
        i++;
    }
    while (t<30-i)
    {
        printf(" ");
        t++;
    }
    
    while (j <= strlen(input))
    {
        printf("%c", *(pointerToInput + j));
        j++;
    }

    while (z<30-j)
    {
        printf(" ");
        z++;
    }

}

void GOTO(char c, int i)
{
    if ((c == '0' || c == '1') && (i == 1 || i == 2))
    {
        push('E');
        push('1');
        return;
    }
    if (c == '4' && (i == 1 || i == 2))
    {
        push('E');
        push('8');
        return;
    }

    if ((c == '0' || c == '4') && (i == 3 || i == 4))
    {
        push('T');
        push('2');
        return;
    }
    if (c == '6' && (i == 3 || i == 4))
    {
        push('T');
        push('9');
        return;
    }
    if ((c == '0' || c == '4' || c == '6') && (i == 5 || i == 6))
    {
        push('F');
        push('3');
        return;
    }
    if (c == '7' && (i == 5 || i == 6))
    {
        push('F');
        push('a');
        return;
    }
}

int main()
{
    printf("PLC lab project 2\nShift-Reduce Algorithm Implementation\nOmer Faruk Uysal 19290337\nAli Furkan Karaman 19290029\n");
    printf("Enter the input followed by $: \n");
    scanf("%s", input);
    pointerToInput = input;
    push('0');
    printf("STACK\t\t\t\tINPUT\t\t\tACTION\n");
    if (stack[top] == '0' && (*pointerToInput) == '$')
    {
        printf("Invalid input!!!!");
        return -1;
    }

    while (1)
    {
        display();

        if (stack[top] == '1' && (*pointerToInput) == '$') //4
        {
            printf("Accept!!!\n");
            exit(0);
        }

        if (stack[top] == '0' && (*pointerToInput) == 'i') //1
        {
            push('i');
            push('5');
            pointerToInput += 2;
            printf("shift 5\n");
            continue;
        }

        if (stack[top] == '0' && (*pointerToInput) == '(') //2
        {
            push('(');
            push('4');
            pointerToInput++;
            printf("shift 4\n");
            continue;
        }

        if (stack[top] == '1' && (*pointerToInput) == '+') //3
        {
            push('+');
            push('6');
            pointerToInput++;
            printf("shift 6\n");
            continue;
        }

        

        if (stack[top] == '2' && (*pointerToInput) == '+')//5
        {
            //Reduce 2
            pop();
            pop();
            GOTO(stack[top], 2);
            printf("reduce 2 use GOTO[E,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='2' && (*pointerToInput)=='*')//6
        {
            push('*');
            push('7');
            pointerToInput++;
            printf("shift 7\n");
            continue;
        }

        if (stack[top]=='2' && (*pointerToInput)==')')//7
        {
            //reduce 2
            pop();
            pop();
            GOTO(stack[top],2);
            printf("reduce 2 use GOTO[E,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='2' && (*pointerToInput)=='$')//8
        {
            //reduce 2
            pop();
            pop();
            GOTO(stack[top],2);
            printf("reduce 2 use GOTO[E,%c]\n",stack[top-2]);
            continue;
        }
        

        if (stack[top]=='3' && (*pointerToInput)=='+')//9
        {
            //reduce 2
            pop();
            pop();
            GOTO(stack[top],4);
            printf("reduce 4 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='3' && (*pointerToInput)=='*')//10
        {
            //reduce 2
            pop();
            pop();
            GOTO(stack[top],4);
            printf("reduce 4 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='3' && (*pointerToInput)==')')//11
        {
            //reduce 2
            pop();
            pop();
            GOTO(stack[top],4);
            printf("reduce 4 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='3' && (*pointerToInput)=='$')//12
        {
            //reduce 2
            pop();
            pop();
            GOTO(stack[top],4);
            printf("reduce 4 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='4' && (*pointerToInput)=='i')//13
        {
            push('i');
            push('5');
            pointerToInput+=2;
            printf("shift 5\n");
            continue;
        }

        if (stack[top]=='4' && (*pointerToInput)=='(')//14
        {
            push('(');
            push('4');
            pointerToInput++;
            printf("shift 4\n");
            continue;
        }
        
        if (stack[top]=='5' && (*pointerToInput)=='+')//15
        {
            //reduce 6
            pop();
            pop();
            GOTO(stack[top],6);
            printf("reduce 6 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='5' && (*pointerToInput)=='*')//16
        {
            //reduce 6
            pop();
            pop();
            GOTO(stack[top],6);
            printf("reduce 6 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='5' && (*pointerToInput)==')')//17
        {
            //reduce 6
            pop();
            pop();
            GOTO(stack[top],6);
            printf("reduce 6 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='5' && (*pointerToInput)=='$')//18
        {
            //reduce 6
            pop();
            pop();
            GOTO(stack[top],6);
            printf("reduce 6 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='6' && (*pointerToInput)=='i')//19
        {
            push('i');
            push('5');
            pointerToInput+=2;
            printf("shift 5\n");
            continue;
        }

        if (stack[top]=='6' && (*pointerToInput)=='(')//20
        {
            push('(');
            push('4');
            pointerToInput++;
            printf("shift 4\n");
            continue;
        }

        if (stack[top]=='7' && (*pointerToInput)=='i')//21
        {
            push('i');
            push('5');
            pointerToInput+=2;
            printf("shift 5\n");
            continue;
        }

        if (stack[top]=='7' && (*pointerToInput)=='(')//22
        {
            push('(');
            push('4');
            pointerToInput++;
            printf("shift 4\n");
            continue;
        }
        
        if(stack[top]=='8' && (*pointerToInput)=='+')//23
        {
            push('+');
            push('6');
            pointerToInput++;
            printf("shift 6\n");
            continue;
        }
        
        if(stack[top]=='8' && (*pointerToInput)==')')//24
        {
            push(')');
            push('b');
            pointerToInput++;
            printf("shift 11\n");
            continue;
        }

        if(stack[top]=='9' && (*pointerToInput)=='+')//25
        {
            //reduce 1
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],1);
            printf("reduce 1 use GOTO[E,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='9' && (*pointerToInput)=='*')//26
        {
            push('*');
            push('7');
            pointerToInput++;
            printf("shift 7\n");
            continue;
        }
        
        if(stack[top]=='9' && (*pointerToInput)==')')//27
        {
            //reduce 1
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],1);
            printf("reduce 1 use GOTO[E,%c]\n",stack[top-2]);
            continue;
        }

        if(stack[top]=='9' && (*pointerToInput)=='$')//28
        {
            //reduce 1
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],1);
            printf("reduce 1 use GOTO[E,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='a' && (*pointerToInput)=='+')//29
        {
            //reduce 3
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],3);
            printf("reduce 3 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }
        if (stack[top]=='a' && (*pointerToInput)=='*')//30
        {
            //reduce 3
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],3);
            printf("reduce 3 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }
        
        if (stack[top]=='a' && (*pointerToInput)==')')//31
        {
            //reduce 3
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],3);
            printf("reduce 3 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }
        
        if (stack[top]=='a' && (*pointerToInput)=='$')//32
        {
            //reduce 3
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],3);
            printf("reduce 3 use GOTO[T,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='b' && (*pointerToInput)=='+')//33
        {
            //reduce 5
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],5);
            printf("reduce 5 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='b' && (*pointerToInput)=='*')//34
        {
            //reduce 5
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],5);
            printf("reduce 5 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='b' && (*pointerToInput)==')')//35
        {
            //reduce 5
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],5);
            printf("reduce 5 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }

        if (stack[top]=='b' && (*pointerToInput)=='$')//36
        {
            //reduce 5
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            GOTO(stack[top],5);
            printf("reduce 5 use GOTO[F,%c]\n",stack[top-2]);
            continue;
        }
        
        else{
            printf("Error!!!\n");
            exit(1);
        }
    }

    return 0;
}
