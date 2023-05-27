#include <graph/graph.h>

int main() {
  /* demo:
   * https://raw.githubusercontent.com/danielhu19/mypicgocloud/master/img/202305151553216.png
   */

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

  // DFSTraverse(G);
  // DFS(G, 3);
  // BFSTraverse(G);
  BFS(G, 3);
  return 0;
}