#ifndef CLASSE_SENSOR_
#define CLASSE_SENSOR_

//using std::cout, std::fixed(2), std::setprecision(2)

using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define low 4                   //Parâmetros do intervalo da corrente;
#define high 20

class SensorTemperatura
{
    private:

    //Atributos;
    bool ligado = true;
    bool defeito = true;
    
    static int n_sensores;

    float corrente_saida;
    int unidade;

    float convert_corrente(); //Função que retorna a temperatura de acordo com a corrente;
    
    public:

    SensorTemperatura (int unidade); //Constructor;
    ~SensorTemperatura ();          //Destructor;

    //Métodos set;
    void setunidade(int unidade);
    void setdefeito(int defeito);
    
    //Métodos get;
    bool getligado();
    int getn_sensores();
    int getdefeito();
    int getunidade();
    float getcorrente_saida();
    
    void imprimir();        //imprime o estado do objeto
    void ligar();           //liga o sensor
    void desligar();        //desliga o sensor
    
    static float CelsiusToKelvin();
    static float CelsiusToFahrenheit();

    static float KelvinToCelsius();
    static float KelvinToFahrenheit();
    
    static float FahrenheitToCelsius();
    static float FahrenheitToKelvin();
    
    float efetuaMedicao();  //medicao feita pelo sensor
};

#endif
