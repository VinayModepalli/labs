#include<stdio.h>

int main(){
        int r1,r2,c1,c2,i,j,k,s;
        printf("\nEnter 1st matrix order :");
        scanf("%d%d",&r1,&c1);
        printf("\nEnter 2nd matrix order :");
        scanf("%d%d",&r2,&c2);
        if(c1!=r2){
                printf("\nNot Possible..\n");
                return 0;
        }
        int m1[r1][c1], m2[r2][c2], r[r1][c2] ;
        printf("\nMatrix 1: ");
        for (i=0;i<r1;i++)
                for(j=0;j<c1;j++)
                        scanf("%d",&m1[i][j]);
        printf("\nMatrix 2: ");
        for (i=0;i<r2;i++)
                for(j=0;j<c2;j++)
                        scanf("%d",&m2[i][j]);
        for (i=0;i<r1;i++){
                for(j=0;j<c2;j++){
                        s=0;
                        for(k=0;k<c1;k++){
                                s+=m1[i][k]*m2[k][j] ;
                        }
                        r[i][j] = s;
                }
        }
        printf("\nResult: \n");
        for (i=0;i<r1;i++){
                for(j=0;j<c2;j++){
                        printf("%d ", r[i][j]);
                }
                printf("\n");
        }

return 0;
}