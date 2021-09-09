// Distancia mínima para encontrar un tesoro

#include <iostream>
#include <vector>
#include <queue> // Ponemos la función cola, porque es busqueda en anchura (BFS)

using namespace std;

// Funciones creadas 

// Rutas posibles que se pueden recorrer en el mapa
vector<pair<int, int>> caminos = {{1,0}, {-1,0}, {0,1}, {0,-1}};

// Limites para recorrer el mapa
bool limites_mapa(vector<vector<char>>&M, int i, int j){
    return i > 0 and j > 0 and i < int(M.size()) and j < int(M[0].size()){
    }
}

// Distancia mínima del tesoro en (i,j)
int busqueda_anchura(vector<vector<char>>&M, int i, int j){
    vector< vector<bool> > visitado(M.size()), vector<bool>(M[0].size(), false);
    queue<pair<pair<int,int>,int>> l
    l.push(make_pair(make_pair(i,j), 0)) // Al inicio la distancia mínima es 0

    int a, b;  // Esto se recorrerá en el mapa
    int recorrido;  // Esto es la distancia que se aumentará
    
    while (not l.empty()){

    a = l.front().first.first;  // x=i
    b = l.front().first.second; // x=j

    recorrido = l.front().second;
    l.pop()  // Se elimina el primer elemento de la cola (FIFO)

    if (M[a][b]) == "t" return recorrido;

    else if (not visitado[a][b]){
        visitado[a][b] = true;  // marcamos (a,b) como arista visitada

        // Se recorre las aristas adyacentes
        for (auto& c : caminos ) {
            int d,e;  // Posicion inicial nueva: (d,e)
            d = a + c.first;
            e = b + c.second;

        if (limitado(M, d, e) and M[d][e] != "X") l.push(make_pair(make_pair(d,e), recorrido + 1));
        }    
    }

    return -1  // Si no es posible llegar al tesoro devolver -1 

}

//Función Principal

int main(){
    int n;   // N°de filas del mapa 
    int m;   // N°de columnas del mapa
    cin >> n >> m 

    vector< vector<char> > M(vector(n, vector<char>(m)) //Este es el mapa M

    //Inicializar el mapa en una matriz

    for(i=0; i<n; ++i){
        for(j=0; j<m; ++j) cin >> M[i][j]
    }

int r; //Fila de partida en el mapa
int c; //Columna de partida en el mapa 
cin >> r >> c;

int distancia_min = busqueda_anchura(M, r-1, c-1);

if (distancia_min == -1) cout << "no treasure can be reached";  // Aquí no se puede llegar a ningun tesoro

else cout << "minimun distance: " << distancia_min;
cout << endl;
 
}
