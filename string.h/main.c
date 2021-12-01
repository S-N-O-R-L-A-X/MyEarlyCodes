#include <stdio.h>
#include <stdlib.h>

char *_strcpy(char *dest,const char *src)
{
    char *p=dest;
    while(*src!='\0')
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest='\0';
    return p;
}

int _strlen(const char *str)
{
    int n;
    n=0;
    while(*str!='\0')
    {
        n++;
        str++;
    }
    return n;
}

int _strcmp(const char *lhs,const char *rhs)
{

    while(1)
    {

         if(*lhs<*rhs)
         {
             return -1;break;
         }
         if(*lhs>*rhs)
         {
             return 1;break;
         }
         if(*lhs==*rhs)
         {
             lhs++;
             rhs++;
         }
         if(*lhs=='\0'&&*rhs=='\0')
            return 0;
    }
}

/*
int _strcmp(const char *lhs,const char *rhs)
{
    char l,r;
	while(1)
	{
		l=*lhs++;
		r=*rhs++;
		if(l!=r)
			return l-r;
		if(l=='\0')
			break;

	}
	return 0;
}*/

char *_strcat(char *dest,const char *src)
{
    char *p=dest;
    while(*dest!='\0')
        dest++;
    while(*src!='\0')
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest='\0';
    return p;

}

char *_gets(char *str)
{
    char *p=str;
    while((*str=getchar())!='\n')
    {
        str++;
    }
    *str='\0';
    return p;
}

int main()
{
    char a[201],b[101],cmd[7];
    while(1) {
        _gets(cmd);
        if(_strcmp(cmd, "GETS") == 0) {
            puts(_gets(a));
        } else if(_strcmp(cmd, "STRCPY") == 0) {
            int offset;
            scanf("%d",&offset);
            getchar();
            _gets(b);
            _strcpy(a + offset, b);
            puts(a);
        } else if(_strcmp(cmd, "STRLEN") == 0) {
            printf("%d\n",_strlen(a));
        } else if(_strcmp(cmd, "STRCMP") == 0) {
            _gets(b);
            int result = _strcmp(a, b);
            printf("%d\n", result > 0 ? 1 : (result < 0 ? -1 : 0));
        } else if(_strcmp(cmd, "STRCAT") == 0) {
            _gets(b);
            puts(_strcat(a, b));
        } else {
            break;
        }
    }
    return 0;
}
