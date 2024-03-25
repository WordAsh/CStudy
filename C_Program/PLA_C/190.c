#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    int offset;
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';
    int length = strlen(str);

    scanf("%d",&offset);
    char res[length+1];
    for(int i=0; i <length; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            res[i] = 'a' + (str[i] - 'a' + offset % 26 + 26) % 26;
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            res[i] = 'A' + (str[i] - 'A' + offset % 26 + 26) % 26;
        }
        else{
            res[i] = str[i];
        }
    }
    res[length] = '\0';

    printf("%s",res);


    return 0;
}







