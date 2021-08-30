
// Ejercicio 1:  Determinar si un número es par
procedure numeroPar(n):
	// Inputs: n: núnero que se verificará para definir si es par o impar
	// Output: resultado: número par o impar
	resultado = ""
	if(n % 2 == 0) 
		imprimir("n es un número par")
		resultado = "par"
	else 
		imprimir("n es un número impar")
		resultado = "impar"
	return resultado

// Complejidad del primer ejercicio
t7 + 2 *t8 + t9 + t10 + t14  

t = 1 ms
t = 10 ms
t = 5 ms

O(2)


// Ejercio 2: Mayor de tres números
procedure mayor3Num(a, b, c):
	// Input: tres números a,b,c
	// Output: mayor de a,b,c
	mayor = 0
	if(a > b and a > c):
		imprimir("a es el mayor elemento")
		mayor = a
	if(b > a and b > c):
		imprimir("b es el mayor elemento")
		mayor = b
	if(c > a and c > b):
		imprimir("c es el mayor elemento")
		mayor = c
	return mayor


// Ejercicio 3: determinar si u número "n" está dentro de un 
// intervalo [0, 10]

 procedure pertenencia(n): n = 11
 	// Input: n número aleatorio entero 0,1000
 	// Output: pertenece, no pertenece
 	pertenece = TRUE
 	a = 0
 	b = 10
 	if(n >= a and n <= b):
 		imprimir("n está dentro del intervalo")
 		pertenece = TRUE
 	else:
 		imprimir("n no esta dentro del intervalo")
 		pertenece = FALSE
 	return pertenece

// Ejercio 4: Derminar si todos los números de un arreglo pertencen a un intervalo [0,10]
procedure pertenenciaArray(A, n): A = [9, 10, 15, 25, 56] n = 5 A[1]
	//Input: A: Array enteros 0,10000 n: tamaño del arreglo
	//Output: B: Array de booleanos
	a = 0
	b = 10
	B[n] = FALSE // Todas las posiciones del arreglo son falsas inicialmente
	for(i = 0; i < n ; i++): i = 5 A[4] = 56
		if(A[i] >= a and A[i] <= b):
			B[i] = TRUE
		else
			B[i] = FALSE
	return B

B = [TRUE, TRUE, FALSE, FALSE, FALSE]

t63 + t64 + t65 + t66 * n

O(n)


	





	