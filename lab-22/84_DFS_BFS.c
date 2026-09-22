// 84. Write a program to create a graph & implement the adjacency list representation of the graph 
// - Apply DFS and BFS on the given graph. 


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int vertices;
    struct Node **adjList;
};

struct Node *createnode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

struct Graph *creategraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->vertices = vertices;

    graph->adjList = (struct Node **)malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void edge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createnode(dest);

    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createnode(src);

    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void display(struct Graph *graph)
{
    printf("\nAdjacency List:\n");

    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *temp = graph->adjList[i];

        printf("%d -> ", i);

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

void DFS(struct Graph *graph, int vertex, int visited[])
{
    struct Node *temp;

    visited[vertex] = 1;

    printf("%d ", vertex);

    temp = graph->adjList[vertex];

    while (temp != NULL)
    {
        if (visited[temp->vertex] == 0)
            DFS(graph, temp->vertex, visited);

        temp = temp->next;
    }
}

void BFS(struct Graph *graph, int start)
{
    int visited[100] = {0};
    int queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int vertex = queue[front++];

        printf("%d ", vertex);

        struct Node *temp = graph->adjList[vertex];

        while (temp != NULL)
        {
            if (visited[temp->vertex] == 0)
            {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }

            temp = temp->next;
        }
    }
}

void main()
{
    struct Graph *graph;
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    graph = creategraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("\nEnter edges:\n");

    for (int i = 0; i < edges; i++)
    {
        printf("Enter source and destination: ");
        scanf("%d %d", &src, &dest);

        edge(graph, src, dest);
    }

    display(graph);

    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);

    int visited[100] = {0};

    printf("\nDFS Traversal: ");
    DFS(graph, start, visited);

    printf("\n\nEnter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    BFS(graph, start);

    printf("\n");
}