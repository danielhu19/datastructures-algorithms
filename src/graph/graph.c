#include <graph/graph.h>
#include <queue/linkqueue.h>  // for implementing BFS
#include <stack/sqstack.h>    // for implementing Topological Sort

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

//  mark whether the vertex is visited(init 0)
bool marked[MAX_VERTEX_NUM] = {};

/**
 * Depth First Search the ALGraph G from vertex 0 to vexNum
 *
 * @param G Adjacent List representation
 */
void DFSTraverse(ALGraph G) {
  // traverse
  for (int v = 0; v < G.vexNum; v++) {
    if (!marked[v]) {
      DFS(G, v);
    }
  }
}

/**
 * Depth First Search the ALGraph G from vertex `v`
 *
 * @param G Adjacent List representation
 * @param v starting vertex
 */
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

LinkQNode Q;  // for implementing BFS

/**
 * Breadth First Search the ALGraph G from vertex 0 to vexNum
 *
 * @param G Adjacent List representation
 */
void BFSTraverse(ALGraph G) {
  InitQueue(&Q);
  // traverse from 0 to vexNum
  for (int v = 0; v < G.vexNum; v++) {
    if (!marked[v]) {
      BFS(G, v);
    }
  }
}

/**
 * Breadth First Search the ALGraph G from vertex `v`
 *
 * @param G Adjacent List representation
 * @param v starting vertex
 */
void BFS(ALGraph G, int v) {
  if (!Q.front) InitQueue(&Q);  // for invoking without BFSTraverse
  marked[v] = 1;
  printf("%c ", G.vertices[v].data);  // visit
  EnQueue(&Q, v);
  while (!QueueEmpty(&Q)) {
    int u;
    DeQueue(&Q, &u);
    ArcNode *tmp = G.vertices[u].first;
    while (tmp != NULL) {
      if (!marked[tmp->adjVex]) {
        marked[tmp->adjVex] = 1;
        printf("%c ", G.vertices[tmp->adjVex].data);  // visit
        EnQueue(&Q, tmp->adjVex);  // enqueue every adjacent vertex
      }
      tmp = tmp->next;
    }
  }
}

/**
 * Find the shortest path from vertex `v` to every other vertex via BFS
 *
 * @param G Adjacent List representation
 * @param v starting vertex to calculate shortest path
 */
void BFSShortestPath(ALGraph G, int v) {
  int dist[MAX_VERTEX_NUM] = {};
  int path[MAX_VERTEX_NUM] = {};
  // init dist and path
  for (int i = 0; i < G.vexNum; i++) {
    dist[i] = INFINITY;
    path[i] = -1;
  }
  dist[v] = 0;
  marked[v] = 1;
  InitQueue(&Q);
  EnQueue(&Q, v);
  // BFS to find shortest path
  while (!QueueEmpty(&Q)) {
    int u;
    DeQueue(&Q, &u);
    ArcNode *tmp = G.vertices[u].first;
    while (tmp != NULL) {
      if (!marked[tmp->adjVex]) {
        marked[tmp->adjVex] = 1;
        dist[tmp->adjVex] = dist[u] + 1;  // update dist + 1
        path[tmp->adjVex] = u;            // update shortest path
        EnQueue(&Q, tmp->adjVex);
      }
      tmp = tmp->next;
    }
  }
  // print shortest path and weight from v to every other vertex
  for (int i = 0; i < G.vexNum; i++) {
    printf("Shortest path from %c to %c: ", G.vertices[v].data,
           G.vertices[i].data);
    if (dist[i] == INFINITY) {
      printf("No path\n");
    } else {
      printf("%d, weight: %d\n", dist[i], dist[i] * 2);
    }
  }
}

int GetInDegree(ALGraph G, int v) {
  int count = 0;
  for (int i = 0; i < G.vexNum; i++) {
    ArcNode *tmp = G.vertices[i].first;
    while (tmp != NULL) {
      if (tmp->adjVex == v) count++;
      tmp = tmp->next;
    }
  }
  return count;
}

void TopoLogicSort(ALGraph G) {
  int count = 0;
  int *in_degree = (int *)malloc(sizeof(int) * G.vexNum);    // inDegree array
  int *topo_series = (int *)malloc(sizeof(int) * G.vexNum);  // topo array
  // initialize inDegree array and topo array
  for (int i = 0; i < G.vexNum; i++) {
    in_degree[i] = GetInDegree(G, i);
    topo_series[i] = -1;
  }

  SqStack S;  // store the vertex which in_degree is 0
  InitSqStack(&S);
  // push vertex which inDegree is 0 to stack
  for (int i = 0; i < G.vexNum; i++) {
    if (in_degree[i] == 0) SqPush(&S, i);
  }

  while (!SqStackEmpty(&S)) {
    int e = 0;
    SqPop(&S, &e);
    topo_series[count++] = e;
    ArcNode *tmp = G.vertices[e].first;
    // decrease the in_degree of every adjacent vertex of e
    while (tmp != NULL) {
      in_degree[tmp->adjVex]--;
      // if in_degree is 0, push it to stack
      if (in_degree[tmp->adjVex] == 0) {
        SqPush(&S, tmp->adjVex);
      }
      tmp = tmp->next;
    }
  }
  // Assert(count == G.vexNum, "Graph has a cycle");

  // print the topo series
  printf("Topo series: ");
  for (int i = 0; i < G.vexNum; i++) {
    printf("%d ", topo_series[i]);
  }
}