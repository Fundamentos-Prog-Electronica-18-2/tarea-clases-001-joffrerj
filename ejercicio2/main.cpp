#include <iostream>
#include <fstream>
#include <sstream>>

using namespace std;

int convertirStringToInt(string v){
    // proceso para convertir un cadena en entero

    int i;
    std::istringstream(v) >> i;
    return i;
}

int main()
{
    string s;
    string suma = "";
    ifstream f( "datos.txt" );
    if ( f.is_open() )
    {
        // getline( f, s );

        while( !f.eof() )
        {
            getline( f, s );
            suma = suma + convertirStringToInt(s);
            //cout << s << endl;
        }
    }else{
        cerr << "Error de apertura del archivo." << endl;
    }

    cout << suma << endl;
    return 0;
}
