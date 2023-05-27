#include <graph/graph.h>
#include <queue/linkqueue.h>  // for implementing BFS

/**
 * Create UnDirected Network via Adjacent Matrix
 *
 * @G: pointer to the graph
 * @vexNum: number of vertex
 * @arcNum: number of arc
 * @incInfo: if 1, the graph has info
 * @STATUS: SUCCESS or ERROR
 */
STATUS createUDN(MGraph *G, int vexNum, int arcNum, int incInfo) {
  // pre-check
  Assert(G, "G is NULL");
  Assert(vexNum > 0, "vexNum must be positive");
  Assert(arcNum >= 0, "arcNum must be non-negative");
  Assert(incInfo == 0 || incInfo == 1, "incInfo must be 0 or 1");

  G = (MGraph *)malloc(sizeof(MGraph));
  Assert(G, "malloc failed");

  G->vexNum = vexNum;
  G->arcNum = arcNum;

  /* init vertex array */
  for (int i = 0; i < vexNum; i++) {
    G->vex[i] = 'a' + i;
  }

  /* init adjacent matrix */
  for (int i = 0; i < vexNum; i++) {
    for (int j = 0; j < vexNum; j++) {
      G->arc[i][j].adj = INFINITY;
      // G->arc[i][j].info = NULL;
    }
  }

  /* create adjacent matrix */
  for (int k = 0; k < arcNum; k++) {
    int i, j, w;
    printf("Input the index of the vertex (i, j) and the weight w: ");
    scanf("%d %d %d", &i, &j, &w);
    G->arc[i][j].adj = w;
    if (incInfo) {
      // printf("Input the info of the arc (i, j): ");
      // scanf("%s", G->arc[i][j].info);
    }
    if (i != j) {
      G->arc[j][i].adj = G->arc[i][j].adj;
      // G->arc[j][i].info = G->arc[i][j].info;
    }
  }

  return SUCCESS;
}

bool marked[MAX_VERTEX_NUM];  // mark the vertex if it has been visited

void DFSTraverse(ALGraph G) {
  // initialize `marked` array
  for (int v = 0; v < G.vexNum; v++) {
    marked[v] = 0;
  }
  // traverse
  for (int v = 0; v < G.vexNum; v++) {
    if (!marked[v]) {
      DFS(G, v);
    }
  }
}

/* Depth First Search */
void DFS(ALGraph G, int v) {
  printf("%c ", G.vertices[v].data);  // visit
  marked[v] = 1;
  // traverse
  ArcNode *tmp = G.vertices[v].first;
  while (tmp != NULL) {
    if (!marked[tmp->adjVex]) {
      DFS(G, tmp->adjVex);
    }
    tmp = tmp->next;
  }
}

void BFSTraverse(ALGraph G) {
  LinkQNode *Q;
  // initialize `marked` array
  for (int v = 0; v < G.vexNum; v++) {
    marked[v] = 0;
  }
  InitQueue(Q);
  // traverse from 0 to vexNum
  for (int v = 0; v < G.vexNum; v++) {
    if (!marked[v]) {
      marked[v] = 1;
      printf("%c ", G.vertices[v].data);  // visit
      EnQueue(Q, v);
      while (!QueueEmpty(Q)) {
        int u;
        DeQueue(Q, &u);
        ArcNode *tmp = G.vertices[u].first;
        while (tmp != NULL) {
          if (!marked[tmp->adjVex]) {
            marked[tmp->adjVex] = 1;
            printf("%c ", G.vertices[tmp->adjVex].data);  // visit
            EnQueue(Q, tmp->adjVex);
          }
          tmp = tmp->next;
        }
      }
    }
  }
}

void BFS(ALGraph G, int v) {
  LinkQNode *Q;
  // initialize `marked` array
  for (int v = 0; v < G.vexNum; v++) {
    marked[v] = 0;
  }
  InitQueue(Q);
  // traverse from 0 to vexNum
  if (!marked[v]) {
    marked[v] = 1;
    printf("%c ", G.vertices[v].data);  // visit
    EnQueue(Q, v);
    while (!QueueEmpty(Q)) {
      int u;
      DeQueue(Q, &u);
      ArcNode *tmp = G.vertices[u].first;
      while (tmp != NULL) {
        if (!marked[tmp->adjVex]) {
          marked[tmp->adjVex] = 1;
          printf("%c ", G.vertices[tmp->adjVex].data);  // visit
          EnQueue(Q, tmp->adjVex);
        }
        tmp = tmp->next;
      }
    }
  }
}