#include "MatrizAdj.cpp"

int main()
{	

	
	// MatrizAdj<10> Grafo;

	
	// Grafo.InsertEdge(0,1);
	// Grafo.InsertEdge(0,2);
	// Grafo.InsertEdge(1,0);
	// Grafo.InsertEdge(1,4);
	// Grafo.InsertEdge(1,5);
	// Grafo.InsertEdge(2,0);
	// Grafo.InsertEdge(2,3);
	// Grafo.InsertEdge(3,2);
	// Grafo.InsertEdge(4,1);
	// Grafo.InsertEdge(4,5);
	// Grafo.InsertEdge(4,6);
	// Grafo.InsertEdge(5,1);
	// Grafo.InsertEdge(5,4);
	// Grafo.InsertEdge(5,6);
	// Grafo.InsertEdge(5,7);
	// Grafo.InsertEdge(6,4);
	// Grafo.InsertEdge(6,5);
	// Grafo.InsertEdge(6,7);
	// Grafo.InsertEdge(7,5);
	// Grafo.InsertEdge(7,6);

	// 	//Grafo Esparço
	// 	MatrizAdj<100> Grafo;
	// 	srand(100);
	
	// 	for (size_t i = 0; i < 250; i++)
	//    {
	//       int v = rand()%100;
	//       int w = rand()%100;
	//       if (v != w) 
	//          Grafo.InsertEdge(v,w);
	//    }

		//Grafo Denso
		MatrizAdj<100> Grafo;
		srand(100);
	
		for (size_t i = 0; i < 10000; i++)
	   {
	      int v = rand()%100;
	      int w = rand()%100;
	      if (v != w) 
	         Grafo.InsertEdge(v,w);
	   }



	// cout<<"\n\nMatriz de Adjacencia:"<<endl;
	// Grafo.ImprimeGraph();
	
	
	cout<<"\n\nDSF:"<<endl;
	Grafo.DFS();
	
	
	cout<<"\n\nBSF com o 5:"<<endl;
	Grafo.BFS(5);

	return 0;
}