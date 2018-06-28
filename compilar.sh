#!/bin/bash
flex traductor.l
bison  -d traductor.y 
gcc lex.yy.c traductor.tab.c -o Traductor
clear
echo -n "Generador de traductor completa "
echo -n "Ingrese NOMBRE del archivo (sin extension C) que sera la ENTRADA del traductor: "
read  var1
var1+=".c"
x=0
	while [ $x == 0 ]
	do
		if [ -f $var1 ]; then
			echo $var1
		 	break
		else
		  echo -n "archivo inexistente, Favor INGRESE EL ARCHIVO C sin su extencion (.c) "
          read  var1
		  var1+=".c"
		  echo $var1
		fi
	done
echo -n "Ingrese NOMBRE del archivo (sin extension PHP) que sera la SALIDA del traductor (PUEDE NO EXISTIR, si es asi, se creara): "
read  var
var+=".php"
clear
touch $var
./Traductor $var1 $var

