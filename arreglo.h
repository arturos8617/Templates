#ifndef ARREGLO_H
#define ARREGLO_H
#include <iostream>

using namespace std;
template <class T>
class ArregloDinamico{
    private:
        T *arreglo;
        size_t tam;
        size_t cont;
        const static size_t max=10;
    public:
        ArregloDinamico();
        ~ArregloDinamico();
        void insertar(const T& x, size_t p);
        void agregar_final(const T& x);
        void agregar_inicio(const T& x);
        void eliminar_final();
        void eliminar_inicio();
        void eliminar(size_t p);
        T operator[](size_t n){
            return arreglo[n];
        }
        size_t size();
    private:
        void expandir();

};
template<class T>
ArregloDinamico<T>::ArregloDinamico(){
    arreglo=new T[max];
    tam=max;
    cont=0;
}

template<class T>
ArregloDinamico<T>::~ArregloDinamico(){
    delete[] arreglo;
}

template<class T>
void ArregloDinamico<T>::agregar_inicio(const T& x){
    if(cont==tam){
        expandir();
    }
    for(size_t i=cont;i>0;i--){
        arreglo[i]=arreglo[i-1];
    }
    arreglo[0]=x;
    cont++;
}

template<class T>
void ArregloDinamico<T>::agregar_final(const T& x){
    if(cont==tam){
        expandir();
    }
    arreglo[cont]=x;
    cont++;
}

template<class T>
void ArregloDinamico<T>::insertar(const T& x,size_t p){
    if(p>=cont){
        cout<<"Posicion No Valida"<<endl;
        return;
    }
    if(cont==tam){
        expandir();
    }
    for(size_t i=cont;i>p;i--){
        arreglo[i]=arreglo[i-1];
    }
    arreglo[p]=x;
    cont++;
}

template<class T>
void ArregloDinamico<T>::eliminar_final(){
    if(cont==0){
        cout<<"Arreglo Vacio"<<endl;
        return;
    }
    cont--;
}

template<class T>
void ArregloDinamico<T>::eliminar_inicio(){
    if(cont==0){
        cout<<"Arreglo Vacio"<<endl;
        return;
    }
    for(size_t i =0;i<cont-1;i++){
        arreglo[i]=arreglo[i+1];
    }
    cont--;
}

template<class T>
void ArregloDinamico<T>::eliminar(size_t p){
    
    if(cont==0){
        cout<<"Arreglo Vacio"<<endl;
        return;
    }
    if(p>=cont){
        cout<<"Valor no valido"<<endl;
        return;
    }
    for(size_t i =p;i<cont-1;i++){
        arreglo[i]=arreglo[i+1];
    }
    cont--;
} 

template <class T>
size_t ArregloDinamico<T>::size(){
    return cont;
}

template<class T>
void ArregloDinamico<T>::expandir()
{
    T *nuevo=new T  [tam+max];
    for(int i=0;i<cont;i++){
            nuevo[i]=arreglo[i];
    }
    delete[]arreglo;
    arreglo=nuevo;
    tam=tam+max;
}




#endif