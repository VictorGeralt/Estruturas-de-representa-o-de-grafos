#include "MatrizInc.hpp"
#include <iostream>
#include <queue>

using namespace std;



template <int V,int E>
void  MatrizInc<V,E>::InsertEdge(int saida, int chegada){
    
    Matriz[saida][Contador]=1;
    Matriz[chegada][Contador]=-1;
    Contador++;

}

template <int V,int E>
void  MatrizInc<V,E>::DFS(){
    int cor[this->NVertex]={{0}}; // Branco 0, Cinza 1, Preto 2
	int d[this->NVertex];   // Tempo de descoberta
	int f[this->NVertex];   // Tempo de finalização
	int tempo = 0;

	for(int v; v<this->NVertex; v++){
		if(cor[v] == 0)
		DFSVisit(v,cor, d, f, &tempo);
    };

}

template <int V,int E>
void  MatrizInc<V,E>::DFSVisit(int vertex,int *cor, int *d,int *f, int *tempo){
    cor[vertex]  = 1;
	*tempo += 1;
	d[vertex] = *tempo;

	for(int i=0; i<this->NEdge; i++){
        if (Matriz[vertex][i]==1){
            for (int j= 0; j<NVertex; j++){
                if(Matriz[j][i]==-1 && cor[j] == 0){
			    DFSVisit(j,cor, d, f, tempo);
            }
            }
        }   
    }
	cor[vertex] = 2;
	*tempo += 1;
	f[vertex] = *tempo;
    cout<<"Vertex:"<<vertex<<" D:"<<d[vertex]<<" F:"<<f[vertex]<<endl;
};

template <int V,int E>
void MatrizInc<V,E>::BFS(int vertex ){
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

		for(int i = 0; i < this->NEdge; i++){
            if (Matriz[atual][i]){   
                for (int j = 0; j < NVertex; j++){
			        if(this->Matriz[j][i]==1 && cor[j] == 0){
			        	cor[j] = 1;
			        	d[j]   = d[atual] + 1;
			        	pi[j]  = atual;
			        	lista.push(j);
			        }
                }
            }     
		}
		cor[atual] = 2;
		cout<<"Vertex:"<<atual<<endl;
	}
}


template <int V,int E>
void  MatrizInc<V,E>::ImprimeGraph(){
    cout<<"Numero de Vertex "<<NVertex<<endl;
    cout<<"Numero de Edges "<<NEdge<<endl;
    cout<<"/  |";
    for (int i = 0; i < this->NEdge; i++)
        if (i<10)
        {
          cout<<"  e"<<i<<" |";  
        }else{
            cout<<"  e"<<i<<"|"; 
        }
    cout<<"\n";
    for (int i = 0; i < NVertex; i++)
    {
        cout<<"|"<<i<<" | ";
        for (int j = 0; j < this->NEdge; j++)
        {
            if (Matriz[i][j]<0)
            {
                cout<<""<<Matriz[i][j]<<"  | ";
            }else{
                cout<<" "<<Matriz[i][j]<<"  | ";

            }
        }
        cout<<"\n";
    }
}
    
