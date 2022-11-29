#Este es un ahorcado sencillo, mi juego del ahorcado 'avanzado' está aquí --> https://github.com/davidarev/Programacion_I/tree/main/Practicas/Proyecto_Final

import random

def is_valid_letter(letter): #Verifica que la letra sea válida
    return letter.isalpha() and len(letter) == 1

def main(): #Función principal
    words = ["hola", "adios", "python", "programacion",
             "computadora", "teclado", "mouse", "monitor",
             "laptop", "celular", "telefono", "casa", "perro",
             "gato", "casa", "arbol", "sol", "luna", "estrella", "agua"] #Array con las palabras
    word = random.choice(words) #Elije una palabra al azar
    guessed_letters = [] #Array con las letras adivinadas
    wrong_letters = [] #Array con las letras incorrectas
    while len(wrong_letters) < 7: #Se repite el juego hasta que el usuario adivine la palabra o hasta que haya ingresado 6 letras incorrectas
        print("Palabra: ", end="")
        for letter in word: #Muestra la palabra con las letras que ya fueron adivinadas
            if letter in guessed_letters:
                print(letter, end="")
            else:
                print("_", end="")
        print()
        print("Letras incorrectas: ", end="")
        for letter in wrong_letters: #Muestra las letras incorrectas
            print(letter, end=" ")
        print()
        letter = input("Ingresa una letra: ")
        while not is_valid_letter(letter): #Verifica que la letra sea válida
            print("Eso no es una letra válida")
            letter = input("Ingresa una letra: ")
        if letter in word: #Verifica si la letra está en la palabra
            guessed_letters.append(letter)
        else:
            wrong_letters.append(letter)
        if len(wrong_letters) == 1: #Dibuja el ahorcado
            print(" _______")
            print(" |     |")
            print(" |")
            print(" |")
            print(" |")
            print(" |")
            print("_|_ \n")
        elif len(wrong_letters) == 2:
            print(" _______")
            print(" |     |")
            print(" |     O")
            print(" |")
            print(" |")
            print(" |")
            print("_|_ \n")
        elif len(wrong_letters) == 3:
            print(" _______")
            print(" |     |")
            print(" |     O")
            print(" |     |")
            print(" |")
            print(" |")
            print("_|_ \n")
        elif len(wrong_letters) == 4:
            print(" _______")
            print(" |     |")
            print(" |     O")
            print(" |    /|")
            print(" |")
            print(" |")
            print("_|_ \n")
        elif len(wrong_letters) == 5:
            print(" _______")
            print(" |     |")
            print(" |     O")
            print(" |    /|\ ")
            print(" |")
            print(" |")
            print("_|_ \n")
        elif len(wrong_letters) == 6:
            print(" _______")
            print(" |     |")
            print(" |     O")
            print(" |    /|\ ")
            print(" |    /")
            print(" |")
            print("_|_ \n")
        elif len(wrong_letters) == 7: #Muestra el mensaje de derrota
            print(" _______")
            print(" |     |")
            print(" |     O")
            print(" |    /|\ ")
            print(" |    / \ ")
            print(" |")
            print("_|_")
            print("Perdiste")
            print("La palabra era: ", word)
            break
        if set(word) == set(guessed_letters): #Muestra el mensaje de victoria
            print("La palabra era: ", word)
            print("Ganaste")
            break

if __name__ == "__main__":
    main()
