#include "../main.h"
#include <stdio.h>

int main()
{
    strQ *s1 = strQ_init("abcd");
    strQ *s2 = strQ_init("1");
    strQ *s3 = strQ_init("");
    strQ *s4 = strQ_init(NULL);
    char c1 = strQ_pop(s1), c2 = strQ_pop(s2), c3 = strQ_pop(s2), c4 = strQ_pop(s3)//, c5 = strQ_pop(NULL)
    ;
    printf("First:\ta\t%c\nSecond:\t1\t%c\nThird:\t\t%c\nFourth:\t\t%c\n", c1, c2, c3, c4);
    strQ_free(s1);
    strQ_free(s2);
    strQ_free(s3);
    strQ_free(s4);
    strQ_free(NULL);
    printf("All free!\n");
}