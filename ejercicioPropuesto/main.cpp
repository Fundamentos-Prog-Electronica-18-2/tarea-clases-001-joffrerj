

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int convertirStringToInt(string v){
    // proceso para convertir un cadena en entero

    int i;
    std::istringstream(v) >> i;
    return i;
}

void split(const string& s, char c,
           vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

int main()
{
    int suma = 0;
    string promedio;
    string s;
    ifstream f( "datacuatro.txt" );
    if ( f.is_open() )
    {
        // getline( f, s );

        while( !f.eof() )
        {
            vector<string> v;

            split(s, ',', v);
            getline( f, s, '\n' );
            for (int i = 0; i < v.size(); ++i) {
                    if(i==0){
                        int d = convertirStringToInt(v[i]);
                        suma = suma + d;

                    cout << "El valor de la fila es: " << suma << " en base al valor de fila se afirma que resultado es: " << promedio << endl ;
                    }
            }
        }

                        if((suma/4) <= 20){
                            promedio = "Regular";
                        }else{
                            if((suma/4)>20 && (suma/4)<=40){
                                promedio = "Bueno";
                            }else{
                                if((suma/4) > 40){
                                    promedio = "Excelente";
                                }
                            }
                        }

    }else{
        cout << "Error de apertura del archivo." << endl;
    }

    return 0;
}


