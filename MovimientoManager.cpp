#include <string>
using namespace std;
#include <iostream>
#include "Movimiento.h"
#include "MovimientoArchivo.h"
#include "MovimientoManager.h"




void MovimientoManager::Cargar()
{
  int movID, dia, mes, anio, tipo;
  float importe;
  std::string referencia;
  std::string descripcion;

  cout << "ID: ";
  cin >> movID;
  cout << "DESCRIPCION: ";
  cin.ignore();
  getline(cin, descripcion);
  cout << "FECHA: ";
  cin >> dia;
  cin >> mes;
  cin >> anio;
  cout << "TIPO: ";
  cin >> tipo;
  cout << "IMPORTE: $";
  cin >> importe;
  cout << "REFERENCIA: ";
  cin.ignore();
  getline(cin, referencia);

  Movimiento reg;
  reg.setId(movID);
//  reg.setFecha(Fecha(dia, mes, anio));
  reg.setDescripcion(descripcion);
  reg.setTipoMovimiento(tipo);
  reg.setReferencia(referencia);
  reg.setImporte(importe);

  cout << endl;

  bool ok = _archivo.Guardar(reg);


  ok ? cout << "> El movimiento se registro correctamente."<<endl<<endl : cout << "> El movimiento no se registro correctamente."<<endl <<endl;

}
void MovimientoManager::Editar()
{
    int idMovimiento, posicion;

    cout << "ingresar ID de movimiento" << endl;
    cin >> idMovimiento;

    posicion = _archivo.Buscar( idMovimiento );

    if( posicion > 0)
    {
        Movimiento movimiento = _archivo.Leer( posicion );

        cout << "Registro movimiento a editar:" << endl;

        Mostrar(movimiento);

        float nuevoImporte;
        cout << "Ingrese el nuevo importe" << endl;
        cin >> nuevoImporte;

        movimiento.setImporte( nuevoImporte );
        _archivo.Guardar( movimiento, posicion);
        cout << "> Registro modificado correctamente" << endl;
    }else{
        cout <<"No se ha encontrado el registro con el ID #" << idMovimiento;
    }

}
void MovimientoManager::Eliminar()
{
    int idMovimiento, posicion;

    posicion = _archivo.Buscar( idMovimiento );
    if( posicion > 0)
    {
        Movimiento mov = _archivo.Leer( idMovimiento );

        cout << "¿Esta seguro de borrar el siguiente registro de movimiento? (S/N)" << endl;
        Mostrar(mov);

        char confirmar;
        cin >> confirmar;

        if( toupper(confirmar) == 'S' )
        {
            mov.setEstado(false);
            _archivo.Guardar(mov, posicion);
            cout << "> Registro eliminado correctamente "<< endl;
        }
    }
}
void MovimientoManager::Mostrar(Movimiento reg)
{
  cout << "ID: " << reg.getId() << endl;
  cout << "DESCRIPCION: " << reg.getDescripcion() << endl;
  //cout << "FECHA: " << reg.getFecha().toString() << endl;
  cout << "TIPO: " << reg.getTipoMovimiento() << endl;
  cout << "IMPORTE: $" << reg.getImporte() << endl;
  cout << "REFERENCIA: " << reg.getReferencia() << endl;
  cout << "ELIMINADO: " << (reg.getEstado()?"No":"Si") << endl << endl;
}
void MovimientoManager::MostrarCantidadRegistros()
{
    cout << "La cantidad de registros es de "<< _archivo.contarRegistros();
}

void MovimientoManager::ListarTodos()
{
    for( int i = 0; i< _archivo.contarRegistros(); i++ )
    {
            Mostrar(_archivo.Leer(i));


    }
}
int MovimientoManager::Buscar(int IDMovimiento)
{
    for( int i = 0; i<_archivo.contarRegistros();i++)
    {
        if( _archivo.Leer(i).getId() == IDMovimiento)
        {
            return i;
        }
    }
    return -1;
}
void MovimientoManager::ListarxID()
{
  int ID, posicion;
  cout << "ID Movimiento: ";
  cin >> ID;

  posicion = _archivo.Buscar(ID);
  if (posicion >= 0){
    Movimiento aux = _archivo.Leer(posicion);
    Mostrar(aux);
  }
  else{
    cout << endl << "> No se encontro el movimiento con ID " << ID << "." << endl;
  }
}
void MovimientoManager::ListarxTipoMovimiento(int IDTipoMovimiento)
{
  int cantidadRegistros = _archivo.contarRegistros();
  for(int i=0; i<cantidadRegistros; i++){
    Movimiento reg = _archivo.Leer(i);
    if (reg.getTipoMovimiento() == IDTipoMovimiento){
      Mostrar(reg);
    }
  }
}
