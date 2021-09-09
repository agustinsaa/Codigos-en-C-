//Problema Busqueda de un Tesoro
#include <iostream>
#include <vector>

using namespace std 

// tesoro = t
// obstaculo = X
// camino libre = .

// Movimientos que se pueden hacer en el mapa
vector <pair<int, int> movimientos_mapa = {{ 1,0}, {-1,0}, {0,1}, {0,-1}};

// Funciones de apoyo 

// Se establecen los límites de movimiento en el mapa 

bool limites_mapa(vector < vector <char>>& M, int i, int j){
    return i>=0 and j>=0 and i < int(M.size()) and j < int(M[0].size())
}

// Se busca el tesoro a través de busqueda en profundidad
bool busqueda_tesoro(vector < vector <char> >& M, int i, int j){
    if (M[i][j] == "t") return true; // Si empiezo en t, regreso verdadero
    if (M[i][j] == "X") return false;  // Si empiezo en X, regreso falso 

    M[i][j] = "X";   // Al recorrer un camino libre, se deja como obstaculo para no volver a recorrerlo 

    for(auto& e : movimientos_mapa){    // Aquí hay movimiento en el mapa 

        int mov_i = i + e.first;
        int mov_j = j + e.second;
        
        if(limites_mapa(M, mov_i, mov_j) and busqueda_tesoro(M, mov_i, mov_j)) return true;
    }

}


//Función principal 

int main(){

    int n; //número de filas que hay en el mapa  
    int m; //número de columnas que hay en el mapa
    cin >> n >> m;  // Se ingresa y se lee el valor de filas y columnas

    // Se representa el mapa del tesoro en una matriz

    for (i=0; i < n; ++i){
        for (j=0; j < m; ++j){
            cin >> T[i][j];
        }
    } 

int r; // fila en la que se empieza a buscar el tesoro
int c; // columna en la que se empieza a buscar el tesoro

cin >> r >> c; // Se lee r y c 

bool decision = busqueda_tesoro(M, r-1, c-1);

if (decision) cout << "Si";  // Si llega al tesoro en (r,c) entonces se regresa "Si"
else cout << "No";  // Si no llega al tesoro, se regresa un "No"
cout << endl; 

}
