#include <stdio.h>


int main(void)
{
    int num;
    scanf("%d\n",&num);
    int letter=0, blank=0, digit=0, other=0;
    char ch;
    for(int i = 0; i < num; i++){
        scanf("%c",&ch);

        if((ch >= 97 && ch <=122) || (ch >= 65 && ch <=90)){
            letter++;
        }else if (ch == ' ' || ch == '\n'){
            blank++;
        }else if (ch >= 48 && ch <= 57)
        {
            digit++;
        }else{
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);

    return 0;
}