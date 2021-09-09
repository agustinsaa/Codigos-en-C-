// Crear un grafo en C++

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; // n es el número de vértices
    int m; // m es el número de aristas 

    cin >> n >> m   // Lee por entrada el número de vértices y aristas del grafo G

    // G es el grafo que se va a crear a través de la matriz de adyacencia

    vector<vector<int>> G(n);

    for(int i=0; i < m; ++i){
        int a, b;
        cin >> a >> b;  // Se lee una arista (a,b)

        // Se introduce los vértices a y b
        G[a].push_back(b);
        G[b].push_back(a);

    }

    // Se crea el grafo y se imprime finalmente 
    for(int i=0; i < n; ++i){
        cout << "Los vertices adyacentes a " << i << ": ";
        for(int j=0; j < G[i].size(); ++j) cout << G[i][j];
        cout << endl; 
    }
