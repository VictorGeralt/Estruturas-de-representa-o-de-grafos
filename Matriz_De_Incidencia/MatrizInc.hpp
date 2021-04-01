#pragma once

template <int V=0,int E=0>
class MatrizInc{
private:
int Matriz[V][E]={{0}};
int NEdge=E;
int Contador=0;
int NVertex=V;



public:
void InsertEdge(int saida, int chegada);
void DFS();
void DFSVisit(int vertex,int *cor, int *d,int *f, int *tempo);
void BFS(int vertex = 0);
void ImprimeGraph();
};