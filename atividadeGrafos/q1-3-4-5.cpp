#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
    }

    void insertItem(int src, int dest) {
        adjLists[src].push_back(dest);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int dest : adjLists[i]) {
                cout << dest << " ";
            }
            cout << endl;
        }
    }

    //15.3
    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int adjVertex : adjLists[v]) {
            if (!visited[adjVertex]) {
                dfsUtil(adjVertex, visited);
            }
        }
    }

    void dfs(int v) {
        vector<bool> visited(numVertices, false);
        dfsUtil(v, visited);
    }


    //15.4
    void exibirCaminhosUtil(int v, int destino, vector<bool>& visited, vector<int>& path) {
        visited[v] = true;
        path.push_back(v);

        if (v == destino) {
            cout << "Caminho encontrado: ";
            for (int vertex : path) {
                cout << vertex << " ";
            }
            cout << endl;
        } else {
            for (int adjVertex : adjLists[v]) {
                if (!visited[adjVertex]) {
                    exibirCaminhosUtil(adjVertex, destino, visited, path);
                }
            }
        }

        visited[v] = false;
        path.pop_back();
    }

    void exibirCaminhos(int origem, int destino) {
        vector<bool> visited(numVertices, false);
        vector<int> path;

        exibirCaminhosUtil(origem, destino, visited, path);
    }
};

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    graph.insertItem(0, 1);
    graph.insertItem(0, 3);
    graph.insertItem(0, 2);
    graph.insertItem(1, 0);
    graph.insertItem(1, 3);
    graph.insertItem(2, 0);
    graph.insertItem(2, 3);
    graph.insertItem(2, 4);
    graph.insertItem(3, 1);
    graph.insertItem(3, 0);
    graph.insertItem(3, 2);
    graph.insertItem(3, 5);
    graph.insertItem(4, 2);
    graph.insertItem(4, 5);
    graph.insertItem(5, 3);
    graph.insertItem(5, 4);

    graph.printGraph();

    int startVertex = 0;
    int endVertex = 5;

    cout << endl << endl;   
    
    //15.3
    cout << "Caminho da busca em profundidade (DFS) a partir do vértice " << startVertex << ": " << endl;
    graph.dfs(startVertex);

    cout << endl << endl;

    /*15.4
    A)
    */
    cout << "Caminhos possíveis do vértice " << startVertex << " ao vértice " << endVertex << ":" << endl;
    graph.exibirCaminhos(startVertex, endVertex);
    /*
    B)
        Não existe essa garantia.
    */


    //15.5
    /*
        A ordenação topológica é aplicável apenas a grafos DAGs. E nesse grafo existe um ciclo entre os vértices 1, 2, 3 e 4.
    */



    return 0;
}
