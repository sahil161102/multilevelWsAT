#include<stdio.h>
void main()
{
int p[20], bt[20], wt[20], tat[20], i, k, nSys,nUser,n,m, temp;
float cwt, ctat;
printf("\nEnter the number of sysytem procesess-- ");
scanf("%d", &nSys);
printf("\nEnter the number of user procesess-- ");
scanf("%d", &nUser);
n = nSys + nUser;
for(i=0;i<nSys;i++)
{
p[i]=i;
printf("Enter Burst Time for System Process %d -- ", i);
scanf("%d", &bt[i]);
}
for(i=nSys;i<n;i++)
{
p[i]=i;
printf("Enter Burst Time for user Process %d -- ", i);
scanf("%d", &bt[i]);
}
for(i=0;i<nSys;i++)
for(k=i+1;k<nSys;k++)
if(bt[i]>bt[k])
{
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;

temp=p[i];
p[i]=p[k];
p[k]=temp;
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

