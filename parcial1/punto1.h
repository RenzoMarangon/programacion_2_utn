#ifndef PUNTO1_H_INCLUDED
#define PUNTO1_H_INCLUDED


///Para cada material la cantidad de compras que se hayan realizado entre todas las compras.
void punto1()
{
    Material materiales[5];
    Compra compras[3];

    ///Cargo 5 materiales
    /*
    for( int i = 0; i<5;i++)
    {
        materiales[i].Cargar();
        std::cout << std::endl;
    }

    ///Cargo 5 compras
    for( int i = 0; i<5;i++)
    {
        compras[i].Cargar();
        std::cout << std::endl;
    }
    */

    materiales[0].setCodigoMaterial(1);
    materiales[0].setTipo(1);
    materiales[0].setNombre("Tornillo para golpear");
    materiales[0].setMarca("Kingston");
    materiales[0].setPU(25.83);
    materiales[0].setActivo(true);

    materiales[1].setCodigoMaterial(2);
    materiales[1].setTipo(2);
    materiales[1].setNombre("Clavo para atornillar");
    materiales[1].setMarca("Kingston");
    materiales[1].setPU(45.69);
    materiales[1].setActivo(true);

    materiales[2].setCodigoMaterial(3);
    materiales[2].setTipo(3);
    materiales[2].setNombre("Martillo hammer");
    materiales[2].setMarca("Kingston");
    materiales[2].setPU(27);
    materiales[2].setActivo(true);

    compras[0].setNumeroCompra(0);
    compras[0].setNumeroproveedor(1);
    compras[0].setCodigoMaterial(1);
    compras[0].setCantidad(1);
    float importe = 0;
    for( Material material : materiales )
    {
        if(material.getCodigoMaterial() == compras[0].getCodigoMaterial())
        {
            importe += compras[0].getCantidad()*material.getPU();
        }
    }
    compras[0].setImporte( importe );
    compras[0].setCodigoObra("obraReLoca");
    compras[0].setActivo(true);


    compras[1].setNumeroCompra(0);
    compras[1].setNumeroproveedor(1);
    compras[1].setCodigoMaterial(1);
    compras[1].setCantidad(1);
    importe = 0;
    for( Material material : materiales )
    {
        if(material.getCodigoMaterial() == compras[1].getCodigoMaterial())
        {
            importe += compras[1].getCantidad()*material.getPU();
        }
    }
    compras[1].setImporte( importe );
    compras[1].setCodigoObra("obraReLoca");
    compras[1].setActivo(true);

    compras[2].setNumeroCompra(0);
    compras[2].setNumeroproveedor(1);
    compras[2].setCodigoMaterial(2);
    compras[2].setCantidad(1);
    importe = 0;
    for( Material material : materiales )
    {
        if(material.getCodigoMaterial() == compras[2].getCodigoMaterial())
        {
            importe += compras[2].getCantidad()*material.getPU();
        }
    }
    compras[2].setImporte( importe );
    compras[2].setCodigoObra("obraReLoca");
    compras[2].setActivo(true);


    int materialesVendidos[6] = {0};

    for( Compra compra : compras)
    {
        materialesVendidos[ compra.getCodigoMaterial()-1 ]++;
    }

    for( int mat : materialesVendidos )
    {
        cout << mat << endl;
    }



}

#endif // PUNTO1_H_INCLUDED
