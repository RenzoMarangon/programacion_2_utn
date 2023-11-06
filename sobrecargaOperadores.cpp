# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
     //
     Cadena(const char *ini="nada"){
        tam=strlen(ini)+1;
        p=new char[tam];
        if(p==NULL){
            cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
            exit(1);
        }
        strcpy(p,ini);
        p[tam-1]='\0';
     }
    //
    void Mostrar(){
        cout<<p<<endl;
     }
    //
    int getTam(){return tam;}
    //
    const char *getP(){return p;}
    //
     ~Cadena(){
        delete p;
     }
    //sobrecargas
    ///Compara dos objetos cadenas
    bool operator==(const Cadena &obj)
    {
        if(strcmp(this->p, obj.p) == 0) return true; else return false;
    }
    ///Compara objeto cadena con array de char
    bool operator==(const char *obj)
    {
        if(strcmp(this->p, obj) == 0) return true; else return false;
    }
    ///Compara el valor de cada caracter
    bool operator>(const Cadena &obj)
    {
         if(strcmp(this->p, obj.p) > 0) return true; else return false;
    }
    ///Compara el length de cada cadena
    bool operator>(int tamanio)
    {
         if(tam > tamanio) return true; else return false;
    }


    ///Cambia el valor actual por el de la cadena
    Cadena & operator=(const Cadena &obj){
        delete p;
        tam=obj.tam;
        p=new char[tam];
        if(p==NULL) exit(1);
        strcpy(p,obj.p);
        return *this;
     }
    ///Cambia el valor actual por el array de char
     Cadena & operator=(const char *obj){
        delete p;
        tam=strlen(obj)+1;
        p=new char[tam];
        if(p==NULL) exit(1);
        strcpy(p,obj);
        p[tam-1]='\0';
        return *this;
     }

     bool operator != (const Cadena &obj)
     {
        if(strcmp(this->p, obj.p) != 0) return true; else return false;
     }

    void operator +=( Cadena &obj)
    {

        int tamanio = tam += obj.getTam()-1;

        char * aux = new char[tam];

        if(aux == NULL)
        {
            cout << "Error de asignacion de memoria";
            exit(1);
        }

        strcpy(aux,p);

        delete p;

        p = new char[tamanio];
        if(p == NULL)
        {
            cout << "Error de asignacion de memoria";
            exit(1);
        }

        strcat(aux, obj.p);

        strcpy(p,aux);

        delete aux;
    }


};

int main()
{


    Cadena aguantia("aguantia"), eee("aguantia"), gato(" gato");
    //if( aguantia != eee ) cout << "Son diferentex"; else cout << "son igualex";

    aguantia+=gato;

    aguantia.Mostrar();


    return 0;
}
