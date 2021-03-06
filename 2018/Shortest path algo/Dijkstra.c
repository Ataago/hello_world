//  Shortest path to all the nodes for undirected graph using DIJKSTRA.
//      Start from a Source node and connect to other node forming a tree.
//      connect this tree with the light edge to the other node.
//      while going through the nodes.. make sure to add and store the sum.
//      Note: This forms a cut in graph.
//      Note: Greedy Algorithm

//  @author Mohammed Ataaur Rahaman
//  School: Dayananda Sagar
//  Date: 22 April, 2018

#include<stdio.h>
#include<conio.h>

int n, costGraph[10][10], source, vist[10] = {0}, cost[10], min;
int i, j, cur;

void dijkstra()
{
    for(i = 1; i <= n; i++)
        cost[i] = costGraph[source][i];
    vist[source] = 1;

    for(i = 1; i <= n-1; i++)
    {
        min = 999;
        for(j = 1; j <= n; j++)
            if(!vist[j] && cost[j] < min)
            {
                min = cost[j];
                cur = j;
            }
        vist[cur] = 1;

        for(j = 1; j <= n; j++)
            if(!vist[j] && cost[cur] + costGraph[cur][j] < cost[j])
                cost[j] = cost[cur] + costGraph[cur][j];
    }
}
void main()
{
    printf("Enter number of Nodes:");
    scanf("%d",&n);

    printf("Enter Cost Adjacency Matrix for Undirected Graph:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            scanf("%d",&costGraph[i][j]);
            if(costGraph[i][j] == 0 && i != j)
                costGraph[i][j] = 999;
        }
    printf("Enter the Source Node: ");
    scanf("%d",&source);

    dijkstra();

    for(i = 1; i<= n; i++)
        printf("%d -> %d = %d\n",source, i, cost[i]);
}
