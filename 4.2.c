#include<stdio.h>
#include <limits.h>
struct readyQueue{
    int pid;
    int type;
    int bt;
    int at;
};
int main()
{
    int n,i_time=-1,time=0,index=0,pCount=0;
    float cwt=0,ctat=0;
    printf("Enter the number of processes:\t");
    scanf("%d",&n);
    int AT[n],pType[n],BT[n];
    for(int i=0;i<n;i++){
        printf("Enter the type of the process%d: (0-system 1-user) :\t",i);
        scanf("%d",&pType[i]);
        printf("Enter the Arrival time of the process %d:\t",i);
        scanf("%d",&AT[i]);
        printf("Enter the Burst time of the process %d: \t",i);
        scanf("%d",&BT[i]);
        
    }
    
   
    struct readyQueue RQ[n];
    
        printf("\nPROCESS\t\t ARRIVAL TIME BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
        int N=n;
    while(N--){
        for(int i=0;i<n;i++){
            if(AT[i]>i_time && AT[i]<=time){
                RQ[index].type=pType[i];
                RQ[index].pid=i;
                RQ[index].bt=BT[i];
                RQ[index].at=AT[i];
                index++;
                
            }
        }
        i_time=time;
        int min=999,min_id=-1;
        for(int i=0;i<index;i++){
            if(RQ[i].bt<min && RQ[i].type==0 && RQ[i].bt>0){
                min=RQ[i].bt;
                min_id=i;
            }
        }
        
        if(min_id!=-1){
            pCount++;
            time+=RQ[min_id].bt;
            ctat=time -RQ[min_id].at;
            cwt=ctat - RQ[min_id].bt;
            printf("%d\t\t %d\t\t %d\t\t %f\t\t %f \n",RQ[min_id].pid,RQ[min_id].at,min, cwt,ctat  );
            RQ[min_id].bt=-1;
        }else if(pCount<index){
            int min=999,min_id=-1;
            for(int i=0;i<index;i++){
                if(RQ[i].bt>0 && RQ[i].type==1 && RQ[i].at<min){
                    min=RQ[i].at;
                    min_id=i;
                }
            }
            pCount++;
            time+=RQ[min_id].bt;
            ctat=time - RQ[min_id].at;
            cwt=ctat-RQ[min_id].bt;
            printf("%d\t\t %d\t\t %d\t\t %f\t\t %f \n",RQ[min_id].pid,RQ[min_id].at,RQ[min_id].bt, cwt,ctat  );
            RQ[min_id].bt=-1;
        }else{
            time++;
            N++;
        }
    }
    return 0;
}
