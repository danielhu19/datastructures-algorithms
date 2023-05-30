#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <forehead/forehead.h>

#define MAX_VERTEX_NUM 10
#define INFINITY INT_MAX
typedef char VertexType;
typedef int EdgeType;
typedef int infoType;
/* 0: directed graph
   1: directed network
   2: undirected graph
   3: undirected network
   */
typedef enum { DG, DN, UDG, UDN } GraphKind;

/* ---------------------Adjacent Matrix--------------------- */
typedef struct ArcCell {
  EdgeType adj;  // weight or 0/1
  // InfoType *info;  // other information
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

/* Array representation of graph */
typedef struct {
  int vexNum, arcNum;              // number of vertex and edge
  VertexType vex[MAX_VERTEX_NUM];  // vertex array
  AdjMatrix arc;                   // adjacent matrix
  GraphKind kind;
} MGraph;

STATUS createUDN(MGraph* G, int vexNum, int arcNum, int incInfo);

/* ---------------------Adjacent List--------------------- */
typedef struct ArcNode {
  int adjVex;
  struct ArcNode* next;
} ArcNode;

typedef struct VNode {
  VertexType data;
  ArcNode* first;  // first arc
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
  AdjList vertices;
  int vexNum, arcNum;
  GraphKind kind;
} ALGraph;

/* ---------------------Cross-linked List--------------------- */
typedef struct ArcBox {
  int tailvex, headvex;          // tail and head of arc
  struct ArcBox *hlink, *tlink;  // next arc of head and tail
  infoType* info;                // other information
} ArcBox;

// Vertex
typedef struct VexNode {
  VertexType data;             // vertex data
  ArcBox *firstin, *firstout;  // first arc of in and out
} VexNode;

// Graph
typedef struct {
  VexNode xlist[MAX_VERTEX_NUM];  // vertex array
  int vexNum, arcNum;             // number of vertex and edge
} OLGraph;

/* ---------------------Adjacency MultiList--------------------- */
typedef enum { unvisited, visited } ifVisited;

typedef struct EBox {
  ifVisited mark;
  int ivex, jvex;              // vertex index
  struct EBox *ilink, *jlink;  // next arc of i and j
  infoType* info;              // other information
} EBox;

typedef struct VexBox {
  VertexType data;  // vertex data
  EBox* firstedge;  // first arc
} VexBox;

typedef struct {
  VexBox adjmulist[MAX_VERTEX_NUM];  // vertex array
  int vexNum, arcNum;                // number of vertex and edge
} AMLGraph;

/* Search Algorithms */
void DFSTraverse(ALGraph G);
void DFS(ALGraph G, int v);
void BFSTraverse(ALGraph G);
void BFS(ALGraph G, int v);
void BFSShortestPath(ALGraph G, int v);
int GetInDegree(ALGraph G, int v);
void TopoLogicSort(ALGraph G);

#endif
