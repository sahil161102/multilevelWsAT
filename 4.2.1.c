#include<stdio.h>
int p[20],ptype[20],flag[20],at[20], bt[20], wt[20], tat[20],rq[20], i, k,n,time=0, temp,p=0;
int sjfSort(){
for(i=0;i<n && at[i]<=time && ptype[i] == 0 && flag[i]!= 1;i++)
for(k=i+1;k<n && at[i]<=time && ptype[i] == 0 && flag[i]!= 1;k++)
if(bt[i]>bt[k])
{
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;

temp=p[i];
p[i]=p[k];
p[k]=temp;
}
  
temp=ptype[i];
ptype[i]=ptype[k];
ptype[k]=temp;
}
return 0;
}
int BTsort(int a,int b){
for(i=a;i<b;i++)
for(k=i+1;k<b;k++)
if(bt[rq[[i]]>bt[rq[k]])
{
temp=bt[rq[i]];
bt[rq[i]]=bt[rq[k]];
bt[rq[k]]=temp;

temp=p[rq[i]];
p[rq[i]]=p[rq[k]];
p[rq[k]]=temp;
  
temp=ptype[rq[i]];
ptype[rq[i]]=ptype[rq[k]];
ptype[rq[k]]=temp;
}
return 0;
}

void main()
{
float cwt, ctat;
printf("\nEnter the number of procesess-- ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
p[i]=i;
printf("Enter 0 for system p and 1 for user p --", i);
scanf("%d", &ptype[i]);
printf("Enter Arrival Time for Process %d -- ", i);
scanf("%d", &at[i]);
printf("Enter Burst Time for Process %d -- ", i);
scanf("%d", &bt[i]);
  flag[i] = 0;
}
  ATsort();
while(n--){
for(int i =0;i<n;i++)
if(at<=time)
}
}
  
  

wt[0] = cwt = 0;
tat[0] = ctat = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] +bt[i-1];
tat[i] = wt[i] +bt[i] ;
cwt = cwt + wt[i];
ctat = ctat + tat[i];
}
printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
printf("\nAverage Waiting Time -- %f", cwt/n);
printf("\nAverage Turnaround Time -- %f", ctat/n);

}
