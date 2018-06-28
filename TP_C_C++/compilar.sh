#!/bin/bash
flex traductor.l
bison  -d traductor.y 
gcc lex.yy.c traductor.tab.c -o Traductor
clear
echo -n "El traductor se ha generado correctamente.\n"
echo -n "Ingrese el nombre del archivo origen (sin la extension .c) con el código en el lenguaje fuente (C): "
read  var1
var1+=".c"
x=0
	while [ $x == 0 ]
	do
		if [ -f $var1 ]; then
			echo $var1
		 	break
		else
		  echo -n "Archivo inexistente. Modo de uso: \"archivo\"\n (Sin extension .c)."
          read  var1
		  var1+=".c"
		  echo $var1
		fi
	done
echo -n "Ingrese el nombre del archivo destino (sin la extension .cpp) donde se almacenará el código traducido al lenguaje destino (C++): "
read  var
var+=".cpp"
clear
touch $var
./Traductor $var1 $var

