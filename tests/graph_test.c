#include <graph/graph.h>

/**
 * Test for DFS & BFS in UnDirected Graph
 * Demo:
 * https://raw.githubusercontent.com/danielhu19/mypicgocloud/master/img/202305151553216.png
 */
void TestUDG() {
  ALGraph G;
  G.vexNum = 6;
  G.arcNum = 7;
  G.kind = UDG;

  G.vertices[0].data = 'a';
  G.vertices[1].data = 'b';
  G.vertices[2].data = 'c';
  G.vertices[3].data = 'd';
  G.vertices[4].data = 'e';
  G.vertices[5].data = 'f';
  // a->b a->c a->d
  G.vertices[0].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[0].first->adjVex = 1;
  G.vertices[0].first->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[0].first->next->adjVex = 2;
  G.vertices[0].first->next->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[0].first->next->next->adjVex = 3;
  G.vertices[0].first->next->next->next = NULL;

  // b->a b->e b->f
  G.vertices[1].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[1].first->adjVex = 0;
  G.vertices[1].first->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[1].first->next->adjVex = 4;
  G.vertices[1].first->next->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[1].first->next->next->adjVex = 5;
  G.vertices[1].first->next->next->next = NULL;

  // c->a c->e
  G.vertices[2].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[2].first->adjVex = 0;
  G.vertices[2].first->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[2].first->next->adjVex = 4;
  G.vertices[2].first->next->next = NULL;

  // d->a d->f
  G.vertices[3].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[3].first->adjVex = 0;
  G.vertices[3].first->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[3].first->next->adjVex = 5;
  G.vertices[3].first->next->next = NULL;

  // e->b e->c
  G.vertices[4].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[4].first->adjVex = 1;
  G.vertices[4].first->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[4].first->next->adjVex = 2;
  G.vertices[4].first->next->next = NULL;

  // f->b f->d
  G.vertices[5].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[5].first->adjVex = 1;
  G.vertices[5].first->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[5].first->next->adjVex = 3;
  G.vertices[5].first->next->next = NULL;

  /* start from 0 */
  // DFSTraverse(G);

  /* start from 3*/
  // DFS(G, 3);

  /* start from 0 */
  // BFSTraverse(G);

  /* start from 3*/
  // BFS(G, 3);

  BFSShortestPath(G, 1);
}

/**
 * Test for Topological Sort in Directed Graph
 * Demo:
 * https://raw.githubusercontent.com/danielhu19/mypicgocloud/master/408/202305301000900.png
 */
void TestTopo() {
  ALGraph G;
  G.arcNum = 5;
  G.vexNum = 5;
  G.kind = DG;

  G.vertices[0].data = 'a';
  G.vertices[1].data = 'b';
  G.vertices[2].data = 'c';
  G.vertices[3].data = 'd';
  G.vertices[4].data = 'e';

  // 0 -> 1
  G.vertices[0].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[0].first->adjVex = 1;
  G.vertices[0].first->next = NULL;

  // 1 -> 3
  G.vertices[1].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[1].first->adjVex = 3;
  G.vertices[1].first->next = NULL;

  // 2 -> 3 -> 4
  G.vertices[2].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[2].first->adjVex = 3;
  G.vertices[2].first->next = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[2].first->next->adjVex = 4;
  G.vertices[2].first->next->next = NULL;

  // 3 -> 4
  G.vertices[3].first = (ArcNode *)malloc(sizeof(ArcNode));
  G.vertices[3].first->adjVex = 4;
  G.vertices[3].first->next = NULL;

  // 4 -> null
  G.vertices[4].first = NULL;

  // make sure in_degree is correct
  Assert(GetInDegree(G, 0) == 0, "in_degree of 0 should be 0");
  Assert(GetInDegree(G, 1) == 1, "in_degree of 1 should be 1");
  Assert(GetInDegree(G, 2) == 0, "in_degree of 2 should be 0");
  Assert(GetInDegree(G, 3) == 2, "in_degree of 3 should be 2");
  Assert(GetInDegree(G, 4) == 2, "in_degree of 4 should be 3");

  TopoLogicSort(G);
  puts("");
}

int main() {
  TestUDG();
  TestTopo();
  return 0;
}