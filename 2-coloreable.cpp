// Problema para saber si un grafo es 2-coloreable

#include <iostream>
#include <vector>

using namespace std;

// color1 = 0 
// color2 = 1 

// En un grafo G de estructura (V, A)
// color es nuestro vector de colores que hay en el grafo G
// Se va a tomar un vértice v cualquiera
// w es un vértice adyacente a v 

bool doscoloreable(vector<vector<int>>& G, vector<int>& color, int v, int w){
    if (color[v] == 0) {
        color[v] = color[w] % 2 + 1;  //v y w tienen que ser de distinto color
        for(int i=0; i < G[v].size(); ++i){
            if (doscoloreable(G, color, v, w)) return true;  // v y sus adyacentes son 2-coloreables
        }

        return false;   // no es 2-coloreable
    }

    else {
        return color[v] != color[w]; // si los colores de v y w son distintos se regresa verdadero   
    }

}

// Aquí hacemos el DFS para recorrer el grafo G
bool busqueda_profundidad(vector<vector<int>& G){
    int n = G.size();  // n es el número de vértices del grafo
    vector<int> color(n,0); // vectores de colores de G
    for(int i=0; i < n; ++i){
        if(color[i] == 0 and doscoloreable(G, color, i, i)) return true;
    }

    return false; 
}

int main(){
    
    int n; // N° de vértices
    int m; // N° de aristas

    while (cin >> n >> m){ 
        vector<vector<int>> G(n); // declaramos G, un grafo con n vértices

        int y, z; // y, z son 2 vértices de partida cualquiera

        for(int i=0; i < m; ++i){
            cin >> y >> z;   // Se lee (y,z), arista del grafo G
            G[z].push_back(y);
            G[y].push_back(z);
        }

        if(busqueda_profundidad(G)) cout << "Si";  // Si el grafo es 2-coloreable se regresa un "Si"
        else cout << "No";  // Si el grafo no es 2-coloreable, entonces se regresa un "No"

        cout << endl;

    }

}