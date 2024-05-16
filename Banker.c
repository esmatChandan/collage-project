// write a c program to implement the Banker's algorithm for deadlock avoidance

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m], need[n][m], work[m], finish[n], safeSeq[n], count = 0;
    printf("Enter the allocation matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available matrix: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for (i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    while (count < n)
    {
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag1 = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0)
                {
                    for (j = 0; j < m; j++)
                    {
                        work[j] += alloc[i][j];
                    }
                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            printf("System is in unsafe state\n");
            exit(0);
        }
    }
    printf("Safe sequence is: ");
    for (i = 0; i < n; i++)
    {
        (i < n - 1) ? printf("P%d -> ", safeSeq[i])
                    : printf("P%d", safeSeq[i]);
    }
    printf("\n");
}
