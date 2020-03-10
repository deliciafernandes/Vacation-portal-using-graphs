
//#include<graphics.h>
#include <conio.h>
#include <limits.h>
#include <stdio.h>
#include<stdlib.h>
#define V 5

void diagram();
int begin();
int fin();
int menu();
int minDistance(int dist[], int sptSet[]);
int printSolution(int dist[]);
int dijkstra(int graph[V][V], int src) ;
int dest=-1;



int main()
{
	system("cls");
	begin();

	menu();
	getch();

	fin();
	getch();

	return 0;
}


int begin()
{
    printf("--------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\tWELCOME TO VOYAGERS:");

    printf("\n\n\t\t\t~Where dreams meets destination~\n");

    printf("\n\n\t\t\t\tTO AVAIL: Diwali offer\n\n\t\t\t\t   Use code VOYAGE\n");

    printf("--------------------------------------------------------------------------------");


    return 0;

}

int fin()
{
    printf("\t\t->->->-.->->->-.->->->-.->->->- \n");

    printf("\t\t          ~Voyagers~             \n ");

    printf("\t\t->->->-.->->->-.->->->-.->->->- \n");
    printf("\n\n\t\t YOUR ONE STOP TO YOUR DREAM VACATION!\n");

    printf("\nGOT A QUESTION? LET US KNOW : www.voyagerscustomercare.com                    \n\n\n\n");

    printf("\t\t\t\t\nHAPPY JOURNEY!\n\n\n\n");

     getch();

    return 0;

}

int menu()
{

    int source,  out,option,start,flag=1;



    //graph data

    int graph1[V][V] = {
    { 0, 1430, 2755, 1420, 1209},

    { 1430, 0, 3290, 2710, 2470},

    { 2755, 3290, 0, 2710, 2470},

    { 1420, 1000, 1900, 0, 200},

    { 1209, 2470, 1700, 200, 0}};


    printf("\n\nCities Available: \n\t\t\t\t0.Mumbai\n\t\t\t\t1.Kochi\n\t\t\t\t2.Guwahati\n\t\t\t\t3.Delhi\n\t\t\t\t4.Agra\n\n");

    printf("\nChoose your starting point: ");

    scanf("%d",&source);

    printf("\nChoose your Destination: ");

    scanf("%d",&dest);

	printf("\n\n\t\tVoyagers is providing you with your dream package!\n");
		printf("\n\t\t\tHappiness Loading.............\n\n");


	    start=dijkstra(graph1, source);
	    system("cls");
return start;

}



int minDistance(int dist[], int sptSet[])

{

    // Initialize min value

    int min = INT_MAX, min_index=0,v;



    for (v = 0; v < V; v++)

      {

    if (sptSet[v] == 0 && dist[v] <= min)

    {

	min = dist[v];

	min_index = v;

    }

      }



    return min_index;

}



// A utility function to print the constructed distance array

int printSolution(int dist[])

{

    int i;

    printf("Your dream vacay is just %d kilometers away ",dist[dest]);

    printf("\n\t\t\tAU REVOIR!\n");
    return 0;
}

int dijkstra(int graph[V][V], int src)

{

    int dist[V]; // The output array.  dist[i] will hold the shortest

    // distance from src to i

    int i,count,u,v;

   int sptSet[V]; // sptSet[i] will be  true if vertex i is included in shortest

    // path tree or shortest distance from src to i is finalized



    // Initialize all distances as INFINITE and stpSet[] as false

    for (i = 0; i < V; i++)

    {

    dist[i] = INT_MAX;

    sptSet[i] =0;

    }



    // Distance of source vertex from itself is always 0

    dist[src] = 0;



    // Find shortest path for all vertices

    for (count = 0; count < V - 1; count++)

    {

    u = minDistance(dist, sptSet);



    // Mark the picked vertex as processed

    sptSet[u] = 1;



    // Update dist value of the adjacent vertices of the picked vertex.

    for (v = 0; v < V; v++)

     {

    if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])

	dist[v] = dist[u] + graph[u][v];

    }

   }

    // print the constructed distance array

    printSolution(dist);

  getch();

    return 0;

}


