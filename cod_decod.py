def codifica(mensaje): # Función que codifica el mensaje
    mensaje_codificado = ""
    for letra in mensaje:
        if letra == "z":
            letra = "a"
        elif letra == "Z":
            letra = "A"
        else:
            letra = chr(ord(letra) + 1) #ord() devuelve el valor ASCII de un carácter y chr() devuelve el carácter correspondiente a un valor ASCII
        mensaje_codificado += letra
    return mensaje_codificado

def decodifica(mensaje): #Función que decodifica el mensaje
    mensaje_decodificado = ""
    for letra in mensaje:
        if letra == "a":
            letra = "z"
        elif letra == "A":
            letra = "Z"
        else:
            letra = chr(ord(letra) - 1)
        mensaje_decodificado += letra
    return mensaje_decodificado

def main():
    mensaje = input("Introduce un mensaje: ")
    mensaje_codificado = codifica(mensaje)
    print("Mensaje codificado: ", mensaje_codificado)
    print("Mensaje decodificado: ", decodifica(mensaje_codificado))

if __name__ == "__main__":
    main()
