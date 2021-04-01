#pragma once

template <int V=0>
class MatrizAdj{
private:
int Matriz[V][V]={{0}};
int NVertex=V;

public:
void InsertEdge(int saida, int chegada);
void DFS();
void DFSVisit(int vertex,int *cor, int *d,int *f, int *tempo);
void BFS(int vertex = 0);
void ImprimeGraph();
};