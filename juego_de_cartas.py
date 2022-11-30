#Version Beta

import random

def main():
    # Crear una baraja de cartas
    baraja = crear_baraja()
    # Crear una mano para cada jugador
    mano_jugador1 = []
    mano_jugador2 = []
    # Repartir 5 cartas a cada jugador
    repartir_cartas(baraja, mano_jugador1, mano_jugador2)
    # Mostrar las 2 primeras cartas de cada jugador
    mostrar_cartas(mano_jugador1, mano_jugador2, 2)
    # Preguntar si el jugador quiere seguir jugando
    if input("¿Quieres seguir jugando? (s/n) ") == "s":
        # Mostrar 3 cartas de cada jugador
        mostrar_cartas(mano_jugador1, mano_jugador2, 3)
        # Preguntar si el jugador quiere seguir jugando
        if input("¿Quieres seguir jugando? (s/n) ") == "s":
            # Mostrar 5 cartas de cada jugador
            mostrar_cartas(mano_jugador1, mano_jugador2, 5)
        else:
            print("El jugador 2 gana.")
    else:
        print("El jugador 1 gana.")

def crear_baraja():
    # Crear una baraja de cartas
    baraja = []
    palos = ["Oros", "Copas", "Espadas", "Bastos"]
    for palo in palos:
        for numero in range(1, 13):
            baraja.append((palo, numero))
    return baraja

def repartir_cartas(baraja, mano_jugador1, mano_jugador2):
    # Repartir 5 cartas a cada jugador
    for i in range(5):
        carta = random.choice(baraja)
        baraja.remove(carta)
        mano_jugador1.append(carta)
        carta = random.choice(baraja)
        baraja.remove(carta)
        mano_jugador2.append(carta)

def mostrar_cartas(mano_jugador1, mano_jugador2, numero_cartas):
    # Mostrar las cartas de cada jugador
    print("Mano del jugador 1:", mano_jugador1[:numero_cartas])
    print("Mano del jugador 2:", mano_jugador2[:numero_cartas])

main()