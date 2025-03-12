#include<stdio.h>
void main(){
    int bt[30];
    int wt[30];
    int tat[30];
    int i, n;
    float avgwt, avgtat;

    printf("ENTER NO. OF PROCESSES: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("ENTER THE BURST TIME FOR PROCESSES %d: ",i+1);
        scanf("%d",&bt[i]);
    }


    wt[0]=avgwt=0;
    tat[0]=avgtat=bt[0];

    for(i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nProcess-ID\tBurst Time\tWaiting Time\tTurn-around Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time = %f\n",avgwt/n);
    printf("Average turn-around time = %f",avgtat/n);

}
