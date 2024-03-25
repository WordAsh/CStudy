#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ladder_score;
    int pat_score;
} Student;

int compare(const void *a,const void *b){
    //升序排序
    Student *stu1 = (Student *)a;
    Student *stu2 = (Student *)b;
    if(stu1->ladder_score != stu2->ladder_score){
        return stu1->ladder_score - stu2->ladder_score; 
    }else{
        return stu1->pat_score - stu2->pat_score;
    }
}

int main() {
    int N,K,S;
    scanf("%d %d %d",&N,&K,&S);

    Student students[N];
    int count = 0;
    for(int i=0; i <N; i++){
        int ladder,pat;
        scanf("%d %d",&ladder,&pat);
        if(ladder >= 175){ 
            students[count].ladder_score = ladder;
            students[count].pat_score = pat;
            count++;
        }
    }

    qsort(students,count,sizeof(Student),compare);//按照成绩升序排列

    
    int curr_stack = 0;//标记当前所在栈
    int recommended = 0, last_score = -1, batch = 0;
    for(int i = 0; i < count; i++){
        if(students[i].ladder_score > last_score){
            recommended++;
            last_score = students[i].ladder_score;
            curr_stack = 0;
        }else if(students[i].pat_score >= S){
            recommended++;
        }else if(curr_stack < batch){
            recommended++;
            curr_stack++;
        }else{
            batch++;
            if(batch < K){
                recommended++;
                curr_stack++;
            }
        }
    }

    printf("%d\n",recommended);
    return 0;
}
