#include<stdio.h>

void main() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    
    for(i = 0; i < 10; i++) {
        flags[i] = 0;
        allocation[i] = -1;
    }
    
    printf("Enter no. of blocks: ");
    scanf("%d", &bno);
    printf("Enter no. of processes: ");
    scanf("%d", &pno);
    
    printf("Enter size of each block:\n");
    for(i = 0; i < bno; i++) {
        printf("Block %d:", i);
        scanf("%d", &bsize[i]);
    }
    
    printf("\nEnter size of each process:\n");
    for(i = 0; i < pno; i++) {
        printf("Process %d:", i);
        scanf("%d", &psize[i]);
    }
    
    for(j = 0; j < bno; j++) {
        // Allocation as per first fit
        for(i = 0; i < pno; i++) {
            if((flags[i] == 0) && (bsize[j] >= psize[i])) {
                allocation[i] = j;
                flags[i] = 1;
                break;
            }
        }
    }
    
    // Display allocation details
    printf("\nFile No\t\tFile size\tBlock no.\tBlock size\tFragment");
    for(i = 0; i < pno; i++) {
        printf("\n%d\t\t%d\t\t", i + 1, psize[i]);
        if(flags[i] == 1) {
            printf("%d\t\t%d\t\t%d", allocation[i] + 1, bsize[allocation[i]], (bsize[allocation[i]] - psize[i]));
        } else {
            printf("0\t\t0\t\t0");
        }
    }
}
