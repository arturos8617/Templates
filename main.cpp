#include "arreglo.h"

int main(){
    ArregloDinamico<string> arreglo; 
    arreglo.agregar_final("ARTURO");
    arreglo.agregar_final("LENNO");
    arreglo.agregar_inicio("JESUS");
    arreglo.agregar_inicio("PEDRO");
    for(size_t i=0;i<arreglo.size();i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<"\n";
    arreglo.insertar("BILLY",2);
    for(size_t i=0;i<arreglo.size();i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<"\n";
    arreglo.eliminar_inicio();
    arreglo.eliminar_final();
    arreglo.eliminar(1);
    for(size_t i=0;i<arreglo.size();i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
    return 0;
}