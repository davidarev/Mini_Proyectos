import statistics

def main():
    numbers = [] #Lista para guardar los numeros
    while True:
        number = input("Ingrese un número (o 'done' para terminar): ") #Pido un numero al usuario hasta que ingrese 'done'
        if number == "done":
            break
        numbers.append(float(number)) #Agrego el numero a la lista

    mean = statistics.mean(numbers) #Calculo la media usaando la funcion mean de la libreria statistics
    print("La media es: ", mean)

    median = statistics.median(numbers) #Calculo la mediana usando la funcion median de la libreria statistics
    print("La mediana es: ", median)

    stdev = statistics.stdev(numbers) #Calculo la desviacion estandar usando la funcion stdev de la libreria statistics
    print("La desviación estándar es: ", stdev)

    try:
        mode = statistics.mode(numbers) #Calculo la moda usando la funcion mode de la libreria statistics
        print("La moda es: ", mode)
    except statistics.StatisticsError as e:
        print("No se pudo calcular la moda", e)

    variance = statistics.variance(numbers) #Calculo la varianza usando la funcion variance de la libreria statistics
    print("La varianza es: ", variance)

    coef_var = stdev / mean #Calculo el coeficiente de variacion, que es la desviacion estandar dividida por la media
    print("El coeficiente de variación es: ", coef_var)

    #Calculo el percentil 25, que es el numero que se encuentra en el 25% de los datos ordenados de menor a mayor 
    percentile25 = statistics.quantiles(numbers, n=4, method='exclusive')[1]
    print("El percentil 25 es: ", percentile25)

if __name__ == '__main__':
    main()
