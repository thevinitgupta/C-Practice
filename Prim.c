#include<stdio.h>
#include<conio.h>
int a,b,u,v,n,i,j,ne=1,visit[10]={0},min,mincost=0,cost[10][10];
void prims ( )
{ while(ne<n) {
 for (i=1,min=999;i<=n;i++)
 for (j=1;j<=n;j++)
 if(cost[i][j]<min)
 if(visit[i]!=0) {
 min=cost[i][j];
 a=u=i;
 b=v=j; }
 if(visit[u]==0 || visit[v]==0) {
 printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
 mincost+=min;
 visit[b]=1;
 }
 cost[a][b]=cost[b][a]=999;
}
printf("\n Minimun cost of spanning tree= %d",mincost);
}
int main()
 {
printf("\n Enter the number of nodes:");
scanf("%d",&n);
printf("\n Enter the adjacency matrix:\n");
for (i=1;i<=n;i++)
 for (j=1;j<=n;j++) {
 scanf("%d",&cost[i][j]);
 if(cost[i][j]==0)
 cost[i][j]=999;
}
visit[1]=1;
printf("\n");
prims( );
return 0;
}