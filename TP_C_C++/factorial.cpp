#include <iostream>
using namespace std;

int factorial( int n ){
int c;
int result;
result = 1;
c = 1;
while( c <= n ){
result = result * c;
c = c + 1;
}
return result;
}
int prueba( int a ){
return 0;
}
int prueba2( int b ){
return 0;
}
int prueba3( int d ){
return 0;
}
int prueba4( int e ){
return 0;
}
int main(  ){
int number;
int i;
int j;
int array[ 5] [ 10] ;
char hola[ 3] ;
int resultado;
i = 0;
while( i < 5 ){
j = 0;
while( j < 10 ){
array[ i ][ j ] = i + j;
cout << "array [" << i << "][" << j << "] = " << array[i][j] << "\n";
j++;
}
i++;
}
number = 3;
resultado = factorial( number );
return 0;
}
