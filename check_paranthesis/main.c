#include <stdio.h>
#include <stdlib.h>

///author Chaitu///

char opposite(char a)
{
    if (a == '}') return '{' ;
    if( a == ')' )return '(' ;
    if (a == ']') return '[' ;
}


char check_paranthesis(char s[100])
{
    int i;
    char Stack[100];
    int top = -1;
    //printf("%d",strlen(s));
    for (i=0;i<strlen(s);i++)
    {
        if (s[i] == '{' || s[i]  == '[' || s[i] == '(' )
        {
            top +=1;
            //printf("%d\n", top);
            Stack[top] = s[i];
            //printf("%c\t %c",s[i],Stack[top]);
        }
        else if ( (s[i] == '}'|| s[i]  == ']' || s[i] == ')' ))
            {
                //printf("%d\t%c \t%c\n", top,Stack[top],s[i]);
                if (top != -1 && Stack[top] == opposite(s[i]))
                    {
                         top = top - 1;
                         //printf("%d\n", top);
                    }

            }
    }
    if (top == -1) printf("balanced");
    else printf("not balanced");

}

int main()
{
    char s[100];
    gets(s);
    //scanf("%[^\n]", s);
    check_paranthesis(s);
}
