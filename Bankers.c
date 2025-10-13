#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j;
    int alloc[10][10], max[10][10], need[10][10], avail[10];
    int visited[10] = {0}, safe[10];
    int count = 0, k = 0, flag, executed;

    // Input number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    // Input Allocation Matrix
    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input Maximum Matrix
    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input Available Resources
    printf("Enter Available Resources: ");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Print Allocation, Max, Need, and Available
    printf("\nProcess\tAllocation\tMax\t\tNeed\t\tAvailable\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t", i);
        for(j = 0; j < m; j++)
            printf("%d ", alloc[i][j]);
        printf("\t\t");
        for(j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\t\t");
        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        if(i == 0) { // Only print available for the first process
            printf("\t\t");
            for(j = 0; j < m; j++)
                printf("%d ", avail[j]);
        }
        printf("\n");
    }

    // Banker’s Algorithm Loop using your logic
    while(count < n) {
        flag = 0;
        for(i = 0; i < n; i++) {
            executed = 0;
            for(j = 0; j < m; j++) {
                if(need[i][j] <= avail[j])
                    executed++;
            }
            if((executed == m) && visited[i] == 0) {
                for(j = 0; j < m; j++)
                    avail[j] += alloc[i][j]; // Release resources
                visited[i] = 1;
                safe[k++] = i;
                count++;
                flag = 1;
            }
        }
        if(flag == 0) {
            printf("No safe sequence\n");
            exit(0);
        }
    }

    // Print Safe Sequence
    printf("\nSafe sequence: < ");
    for(i = 0; i < n; i++)
        printf("P%d ", safe[i]);
    printf(">\n");

    return 0;
}
