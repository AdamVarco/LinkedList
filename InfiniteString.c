#include <stdio.h>
#include <stdlib.h>

char *infiniteString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}
void noDups(char s[]){
    int table[256] = {0};
    int index1 = 0, index2 = 0;
    char temp;
    while(s[index1]){
        temp = s[index1];
        if(table[temp]==0){
            table[temp]=1;
            s[index2] =s[index1];
            index2++;
        }
        index1++;
    }
    s[index2] = 0;

}
void isPalindrome(char str[]){
    int l = 0;
    int h = strlen(str)-1;
    while(h>l){
        if(str[l++]!=str[h--]){
            printf("\n%s is not a palindrome \n", str);
            return;
        }
    }
    printf("\n%s is a palindrome \n",str);
}

void isPrime(int num){
    int flag, j;
    if(num<=1){
        printf("%d is not a prime number \n", num);
        return;
    }else
      flag = 0;
      for(j=2; j<=num/2;j++){
        if((num%j)==0){
            flag =1;
            break;
        }
      }
      if(flag == 0)
        printf("%d is a prime number \n", num);
      else
        printf("%d is not a prime number \n", num);
}
void replaceAll(char s[],char old,char newS){
    int counter=0;
    while(s[counter]!='\0'){
        if(s[counter]==old){
           s[counter] = newS;
           }
           counter++;
    }
    printf("\n New String \n%s", s);
}

int main(void){
    char *m, old, newS;
    int i;
    int flag = 0, total =0;
    printf("input string : ");
    m = infiniteString(stdin, 10);
    printf("%s\n", m);
    isPalindrome(m);
    for(i =0; i<strlen(m);i++){
        if(isdigit(m[i])){
            char array[2];
            snprintf(array,sizeof(m),"%c", m[i]);
            int jump = atoi(array);
            isPrime(jump);
            total+=jump;
            flag =1;
        }else
           flag = 0;
    }
    if(flag == 1){
        printf("\nTotal is ");
        printf("\n%d",total);
    }
    printf("Please enter a old char and a new char");
    scanf(" %c %c",&old,&newS);
    replaceAll(m,old,newS);
    printf("\nNo Dups\n");
    noDups(m);
    puts(m);
    free(m);
    return 0;
}
