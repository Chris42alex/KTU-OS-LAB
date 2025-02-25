#include <stdio.h>

int main() 
{
    int nb, np, i, j;

    // Input the number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    
    int blockSize[nb], allocation[nb];  // Block sizes and allocation 
    int flag[nb];  // Array to track allocation status of blocks

    // Input the sizes of memory blocks
    for (i = 0; i < nb; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
        allocation[i] = -1;  // Initially, no block is allocated
        flag[i] = 0;  // flag = 0 (block is free)
    }

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &np);

    int processSize[np];
    // Input the sizes of processes
    for (i = 0; i < np; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    
   // Worst Fit Allocation  
   for (i = 0; i < np; i++) {
        int worstIndex = -1;
        // Search for the largest block that can fit the process
        for (j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i] && flag[j] == 0) {
                // Choose the largest available block
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        // If a suitable block is found, allocate the process to that block
        if (worstIndex != -1) {
            allocation[worstIndex] = i;  // Allocate process i to block worstIndex
            flag[worstIndex] = 1;  // Mark this block as allocated
        }
    }
    
    // Display allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        int allocated = 0;
        for (j = 0; j < nb; j++) {
            if (allocation[j] == i) {
                printf("B%d\n", j + 1);  // Print the block number allocated to process
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Not Allocated\n");  // If no block is allocated, print "Not Allocated"
        }
    }

    return 0;
}

