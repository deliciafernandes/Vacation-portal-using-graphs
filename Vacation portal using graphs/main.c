
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
    
    void dijkstra(int G[MAX][MAX],int n,int startnode);
    
    int main()
    {
        int G[MAX][MAX],i,j,n,u;
    
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "C:\\TC\\BGI");
            system("COLOR F5"); \\05
        
            setbkcolor(GREEN);
            
            getch();
            closegraph();
         textbackground(RED);
               printf("                 {{{{{{{{{{}}}}}}}}}                 ");
               printf("             {{{{{{{{    MENU    }}}}}}}               ");
               printf("                 {{{{{{{{{{}}}}}}}}}                 ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
        rintf("\n\t\t\t\tChoose from our favourite cities:");
        printf("\n\t\t\t\t1.MUMBAI\n\t\t\t\t2.COCHI\n\t\t\t\t3.AGRA\n\t\t\t\t4.INDORE\n\t\t\t\t5.KOLKATA");
               
        
        
        printf("\n\n\n\n\t\t\t\tDid you make up your mind on the number of cities you want to visit?:");
        setcolor(4);
        settextstyle(5,0,4);
        printf("\n\n\n\n\t\t\t\tChoose quick! Offers valid only till 12 am!");
        scanf("%d",&n);
        printf("\n\n\t\t\t\tEnter your price point:\n");
        getch();
        closegraph();
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&G[i][j]);
        
        printf("\n\t\t\t\tEnter the starting city :");
        scanf("%d",&u);
        dijkstra(G,n,u);
        
        return 0;
    }
    
    void dijkstra(int G[MAX][MAX],int n,int startnode)
    {
        
        int cost[MAX][MAX],distance[MAX],pred[MAX];
        int visited[MAX],count,mindistance,nextnode,i,j;
        
        //pred[] stores the predecessor of each node
        //count gives the number of nodes seen so far
        //create the cost matrix
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(G[i][j]==0)
                    cost[i][j]=INFINITY;
                else
                    cost[i][j]=G[i][j];
        
        //initialize pred[],distance[] and visited[]
        for(i=0;i<n;i++)
        {
            distance[i]=cost[startnode][i];
            pred[i]=startnode;
            visited[i]=0;
        }
        
        distance[startnode]=0;
        visited[startnode]=1;
        count=1;
        
        while(count<n-1)
        {
            mindistance=INFINITY;
            
            //nextnode gives the node at minimum distance
            for(i=0;i<n;i++)
                if(distance[i]<mindistance&&!visited[i])
                {
                    mindistance=distance[i];
                    nextnode=i;
                }
            
            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
            count++;
        }
        
        //print the path and distance of each node
        for(i=0;i<n;i++)
            if(i!=startnode)
            {
                printf("\n\t\t\t\tDistance of city %d = %d",i,distance[i]);
                printf("\nn\t\t\t\tPath = %d",i);
                
                j=i;
                do
                {
                    j=pred[j];
                    printf("<-%d",j);
                }while(j!=startnode);
            }
        printf("Created by, DnS Developers!");
    }
