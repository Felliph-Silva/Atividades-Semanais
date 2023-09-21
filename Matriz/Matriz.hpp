#ifndef _MATRIZ_
#define _MATRIZ_

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;

#include <cstdlib>

using std::exit;
using std::rand;
using std::srand;

#include <iomanip>

using std::setprecision;
using std::fixed;

#include <ctime>
using std::time;

#include <cmath>
using std::pow;

//Adicionar método para escalonamento gauss-jordan;
class Matriz
{
private:
    
    int line, column;
    double **matriz;
    double *ptraux;

    void trocalinha(int line, int linechange);  //Troca duas linha entre si;
    void jump_end(int line);                    //Joga a linha para a última posição;
    void zero_fix(int n);                       //Correção dos zeros nas colunas para escalonamento;
    Matriz laplace_method();       //Reduz a ordem da matriz, obs: utilizar apenas a cópia para realizar as alterações;

public:

    Matriz(int line, int column);    //Constructor matriz qualquer;
    Matriz(int = 3);                 //Constructor matriz quadrada;
    Matriz(const Matriz &other);     //Copy Constructor; 
    ~Matriz();                       //Destructor;
    
    
    void imprimir();                       //Mostra os elementos da matriz;
    void fill();                           //Preencher a matriz manual;
    void fillrand(double min, double max); //Preencher a matriz randon;
    bool diagonal_check();                 //Verificar se a matriz é diagonal;
    void gaussian_elimination();           //Escalonamento da matriz;
    double  *autovalor(); //Retorna um vetor com os autovalores da matriz;
    double  *autovetor(); //Retorna um vetor vetor associado ao autovalor;
    double **autospaco(); //Retorna o espaço gerado pelos autovetores da matriz;
    double   determinante(); //Retorna o determinante da matriz;

    //Métodos get:
    int getline()   {return line;};
    int getcolumn() {return column;};
    double **getmatriz();              //Retorna uma cópia do atributo matriz;

    
    //Operator subscrito:
    double *operator[] (int i); //Retorna um ponteiro em forma de vetor para selecionando uma posição;

    //Operator entre objetos:
    Matriz &operator+ (const Matriz &other);         //Soma matricial;
    Matriz &operator- (const Matriz &other);         //Subtração matricial;
    Matriz &operator* (const Matriz &other);         //Multiplicação matricial;
    const Matriz &operator= (const Matriz &other);   //Copiar matriz;

    //Operator para o objeto como lvalue modificável:
    Matriz &operator+ (const double num);                //Soma por escalar;
    Matriz &operator- (const double num);                //Subtração por escalar;
    Matriz &operator* (const double num);                //Multiplicação por escalar;

    //Operator para o objeto como rvalue:
    friend ostream &operator<< (ostream &, const Matriz &right);         //Inserção de fluxo;
    friend istream &operator>> (istream &, Matriz &rigtht);              //Extração de fluxo;

    friend Matriz &operator+ (double num, Matriz &right);                    //Soma por escalar;
    friend Matriz &operator- (double num, Matriz &right);                    //Subtração por escalar;
    friend Matriz &operator* (double num, Matriz &right);                    //Multiplicação por escalar;
};

#endif


