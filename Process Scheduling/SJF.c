#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n], p[n];  
    float avgtat = 0, avgwt = 0;

    // Input Burst Time
    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;  // Store process ID
        printf("P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    // Sorting processes by Burst Time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap Burst Time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process ID
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Waiting Time Calculation
    wt[0] = 0;  
    for (int i = 1; i < n; i++) {  
        wt[i] = wt[i - 1] + bt[i - 1];
        avgwt += wt[i];
    }

    // Turnaround Time Calculation
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgtat += tat[i];
    }

    // Average calculations
    avgwt /= n;
    avgtat /= n;

    // Display Process Table
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    // Gantt Chart Representation
    printf("\nGantt Chart:\n");

    // Print upper border
    for (int i = 0; i < n; i++) {
        printf("--------");
    }
    printf("\n|");

    // Print process execution sequence
    for (int i = 0; i < n; i++) {
        printf(" P%d |", p[i]);
    }
    printf("\n");

    // Print lower border
    for (int i = 0; i < n; i++) {
        printf("--------");
    }

    // Print time sequence
    printf("\n0");
    for (int i = 0; i < n; i++) {
        printf("      %d", tat[i]);
    }
    printf("\n");

    return 0;
}
