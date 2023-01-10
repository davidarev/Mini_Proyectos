#Clase Entero
class Entero:
    #Constructor
    def __init__(self, num: int):
        self.setValor(num)

    #Setters
    def setValor(self, num: int):
        if num > 0:
            self.__num = num
        else:
            raise ValueError("El numero debe ser mayor que 0")

    #Getters
    def getValue(self) -> int:
        return self.__num
    def getFactores(self, num: int) -> list:
        factores = [] #Lista para guardar los factores
        for i in range(1, num + 1): #Recorro todos los numeros desde 1 hasta el numero ingresado
            if self.esPrimo(i): #Si el numero es primo
                factores.append(i) #Agrego el numero a la lista de factores
        return factores

    #Metodo para saber si un numero es primo
    def esPrimo(self, num: int) -> bool:
        if num < 2:
            return False
        for i in range(2, num // 2 + 1):
            if num % i == 0:
                return False
        return True

#Funcion Principal
def main():
    num = int(input("Introduzca un numero positivo: "))
    integer = Entero(num) #Creo un objeto de la clase Entero

    print(f"Los factores del numero '{num}' son: ", end="")
    factors = integer.getFactores(num) #Obtengo los factores del numero en un array
    for elem in factors:
        print(f"{elem}, ", end="") #Imprimo los factores del numero
    print("\n")

    #Indico si el numero es primo o no
    if integer.esPrimo(num):
        print(f"El numero '{num}' es primo.")
    else:
        print(f"El numero '{num}' no es primo.")

if __name__ == "__main__":
    main()
