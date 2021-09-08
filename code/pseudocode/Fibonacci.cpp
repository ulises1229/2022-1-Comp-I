// Autor: Ulises Olivares
// uolivares@unam.mx
// 01 Sept, 2021

// Algoritmo 1: Calcular la serie de Fibonacci hasta n = 100
procedure calculteFibonacci(n):
	//Input: n número de iteraciones
	//Output: Array
	fib[n]	// Definición de un arreglo
	fib[0] = 1
	fib[1] = 2
	i = 2
	while(i <= n):
	 fib[i] = fib[i-2] + fib[i-1]
	 i = i + 1
	return fib

	Complejidad: O(n)
