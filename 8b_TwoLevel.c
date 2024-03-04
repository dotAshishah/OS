#include <stdio.h>

struct st
{
    char dname[10];
    char sdname[10][10];
    char fname[10][10][10];
    int ds, sds[10];
} dir[10];

void main()
{
    int i, j, k, n;
    char name[10];
    printf("Enter number of users:");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter user directory %d name:", i + 1);
        scanf("%s", &dir[i].dname);
        printf("Enter size of directories:");
        scanf("%d", &dir[i].ds);
        for (j = 0; j < dir[i].ds; j++){
            printf("Enter subdirectory name and size:");
            scanf("%s", &dir[i].sdname[j]);
            scanf("%d", &dir[i].sds[j]);

            for (k = 0; k < dir[i].sds[j]; k++){
                printf("Enter file name:");
                scanf("%s", &dir[i].fname[j][k]);
            }
        }
    }
    printf("\ndirname\t\tsize\tsubdirname\tsize\tfiles\n");
    printf("\n**************************************************************\n");
    for (i = 0; i < n; i++){
        printf("%s\t\t%d", dir[i].dname, dir[i].ds);

        for (j = 0; j < dir[i].ds; j++){
            printf("\t%s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);
            for (k = 0; k < dir[i].sds[j]; k++)
                printf("%s\t", dir[i].fname[j][k]);
            printf("\n\t\t");
        }
        printf("\n");
    }
}
