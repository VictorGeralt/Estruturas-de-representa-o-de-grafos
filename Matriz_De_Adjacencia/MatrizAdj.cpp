#include "MatrizAdj.hpp"
#include <iostream>
#include <queue>

using namespace std;



template <int V>
void  MatrizAdj<V>::InsertEdge(int saida, int chegada){
    if (saida == chegada)
    {
        Matriz[saida][chegada]=2;
    }else{
        Matriz[saida][chegada]=1;
    }
    
}

template <int V>
void  MatrizAdj<V>::DFS(){
    int cor[this->NVertex]={{0}}; // Branco 0, Cinza 1, Preto 2
	int d[this->NVertex];   // Tempo de descoberta
	int f[this->NVertex];   // Tempo de finalização
	int tempo = 0;

	for(int v=0; v<this->NVertex; v++){
		if(cor[v] == 0)
		DFSVisit(v,cor, d, f, &tempo);
    };

}

template <int V>
void  MatrizAdj<V>::DFSVisit(int vertex,int *cor, int *d,int *f, int *tempo){
    cor[vertex]  = 1;
	*tempo += 1;
	d[vertex] = *tempo;

	for(int i = 0; i < this->NVertex; i++)
		if(Matriz[vertex][i]==1 && cor[i] == 0){
			DFSVisit(i,cor, d, f, tempo);
        }

	cor[vertex] = 2;
	*tempo += 1;
	f[vertex] = *tempo;
    cout<<"Vertex:"<<vertex<<" D:"<<d[vertex]<<" F:"<<f[vertex]<<endl;
};

template <int V>
void MatrizAdj<V>::BFS(int vertex ){
    int cor[this->NVertex]={{0}}; //0 Branco, 1 Cinza, 2 Preto
	int d[this->NVertex]={{-1}}; //infinito
	int pi[this->NVertex]={{-1}}; // -1 == NULL / ? não tem pai ainda
	queue<int> lista;

	cor[vertex] = 1;
	d[vertex]   = 0;
	pi[vertex]  = -1;

	lista.push(vertex);

	while (lista.size() > 0){
		int atual=lista.front();
        lista.pop();

		for(int i = 0; i < this->NVertex; i++){
			if(this->Matriz[atual][i]==1 && cor[i] == 0){
				cor[i] = 1;
				d[i]   = d[atual] + 1;
				pi[i]  = atual;
				lista.push(i);
			}
		}

		cor[atual] = 2;
		cout<<"Vertex:"<<atual<<endl;
	}
}


template <int V>
void  MatrizAdj<V>::ImprimeGraph(){
    for (int i = 0; i < this->NVertex; i++)
    {
        cout<<" "<<i<<" -> ";
        for (int j = 0; j < this->NVertex; j++)
        {            
            if(this->Matriz[i][j]== 1 || this->Matriz[i][j] == 2) 
                cout<<" "<<j<<" -> ";
        }
        cout<<"\n";
    }
    }
