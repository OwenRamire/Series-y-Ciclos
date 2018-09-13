#include <iostream>
using namespace std;

int potencia (int num, int exponente);
int factorial(int num);
float coseno(int x, int n);
int seno(int x, int n);
float ln(int x,int n);
int main ()
//Mediante la aplicación de ciclos y funciones se va a crear un menú que le permita al usuario elegir entre
//calcular el logaritmo natural, seno o coseno mediante la aproximación usando series numéricas infinitas en las
//cuales el usuario definirá la cantidad de términos de la serie a trabajar.
//El menú hará que el usuario regrese al mismo hasta que elija salir con la opción 0.

//Para comprobación considerar que el seno y coseno es para un valor de x en radianes
{
    int opcion, opfinal;
    int Vx, num;

    cout << " ******** Menu del programa ******** " << endl;


    do
    {
    cout <<endl;
    cout << " 1.-Logaritmo natural: " << endl;
    cout << " 2.-Seno " <<endl;
    cout << " 3.-Coseno " <<endl;
    cout <<endl;
    cout << " Que opcion quieres escoger? " ;
    cin >> opcion;
        switch (opcion)
    {

    case 1:  //Logaritmo
        cout << " Dame el valor de X: ";
        cin >> Vx;
        cout << " valor hasta parar: ";
        cin >> num;
        cout << " Ln (" << Vx << ") = " << ln(Vx,num);
        break;
    case 2:   //Seno
        cout << " Dame el valor de X: ";
        cin >> Vx;
        cout << " valor hasta parar: ";
        cin >> num;
        cout << " Sin (" << Vx << ") = " << seno(Vx,num);
        break;
    case 3:   //Coseno
        cout << " Dame el valor de X: ";
        cin >> Vx;
        cout << " valor hasta parar: ";
        cin >> num;
        cout << " Cos(" << Vx << ") = " << coseno(Vx,num);
        break;
    }
    }while (opcion != 0);

    return 0;
}

int potencia (int num, int exponente)           //Funcion potencia
{
    int resultado=1;
    for (int i=1; i<=exponente; i++)
    {
        resultado*=num;
    }
    return resultado;
}

 float coseno(int x, int n)                      //Funcion Coseno
 {
     float resultado=0;

     for (int i=1; i<=n; i++)
     {
         if ((i % 2)!= 0 )
             resultado+=-(potencia((float)x,i*2.0) / factorial(i*2.0));
         else
             resultado+= potencia((float)x,i*2.0) / factorial(i*2.0);
     }
     return resultado;
 }

int factorial(int num)                           //Funcion Factorial
{
    int  facto=1;
    for (int i=num; i>0; i--)
    {
        facto = facto * i;
    }
    return facto;
}

int seno(int x, int n)       //Seno
{
    float result=0;
    for(int i=1;i<=n;i++)
    {
        if((i%2)!=0)
            result+=potencia((float)x,i*2.0-1)/factorial(i*2.0-1);
        else
            result+=-(potencia((float)x,i*2.0-1)/factorial(i*2.0-1));
    }

    return result;
}

float ln(int x,int n)
{
    float result=0;
    for(int i=1;i<=n;i++)
    {
        result+=(1.0/i)*potencia(((x-1.0)/x),i);
    }

    return result;
}
