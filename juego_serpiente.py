import pygame
import random

pygame.init() #Inicializo la pantalla

screen_width = 800 #Ancho de la pantalla
screen_height = 600 #Alto de la pantalla

screen = pygame.display.set_mode((screen_width, screen_height)) #Creo la pantalla

black = (0, 0, 0) #Codigo del color negro
white = (255, 255, 255)
red = (255, 0, 0)

block_size = 20 #Tamaño de cada bloque

clock = pygame.time.Clock() #Reloj para controlar los FPS

#Funcion para dibujar la serpiente
def draw_snake(snake_blocks, block_size):
    for block in snake_blocks:
        """
        La funcion draw.rect recibe 4 parametros:
            1. La pantalla donde se va a dibujar
            2. El color del rectangulo
            3. Una tupla con las coordenadas del rectangulo (x, y)
            4. El tamaño del rectangulo (ancho, alto)
        """
        pygame.draw.rect(screen, black, [block[0], block[1], block_size, block_size])

#Funcion para dibujar la comida
def generate_food():
    """
    Genero un número aleatorio entre un rango especifico
    Genero un número aleatorio entre 1 y el número de bloques de ancho de la pantalla
    Genero un número aleatorio entre 1 y el número de bloques de alto de la pantalla
    Por ultimo multiplico el número por el tamaño de cada bloque
    """
    return [random.randrange(1, (screen_width//block_size)) * block_size,
            random.randrange(1, (screen_height//block_size)) * block_size]

#Funcion para detectar si la serpiente se choca con ella misma o con los bordes
def check_collision(snake_blocks):
    if snake_blocks[0] in snake_blocks[1:]:
        return True
    if snake_blocks[0][0] < 0 or snake_blocks[0][0] > screen_width-block_size:
        return True
    if snake_blocks[0][1] < 0 or snake_blocks[0][1] > screen_height-block_size:
        return True
    return False

#Funcion que verifica si la serpiente come la comida
def check_food_collision(snake_blocks, food_pos):
    if snake_blocks[0] == food_pos:
        return True
    return False

snake_blocks = [[100, 100]]
food_pos = generate_food()
food_spawn = True
direction = "RIGHT"
change_to = direction

while True:
    clock.tick(20) #FPS

    for event in pygame.event.get():
        if event.type == pygame.QUIT: #Si se presiona la X de la ventana
            pygame.quit() #Cierro la ventana
            sys.exit() #Cierro el programa
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP: #Si se presiona la flecha arriba
                change_to = "UP"
            if event.key == pygame.K_DOWN: #Si se presiona la flecha abajo
                change_to = "DOWN"
            if event.key == pygame.K_LEFT: #Si se presiona la flecha izquierda
                change_to = "LEFT"
            if event.key == pygame.K_RIGHT: #Si se presiona la flecha derecha
                change_to = "RIGHT"

#Verifico las colisiones
if check_collision(snake_blocks):
    pygame.quit() 
    sys.exit()

#Verifico si la serpiente come la comida
if check_food_collision(snake_blocks, food_pos):
    food_spawn = False
else:
    snake_blocks.pop()

#Verifico la direccion de la serpiente
if change_to == "UP" and direction != "DOWN":
    direction = "UP"
if change_to == "DOWN" and direction != "UP":
    direction = "DOWN"
if change_to == "LEFT" and direction != "RIGHT":
    direction = "LEFT"
if change_to == "RIGHT" and direction != "LEFT":
    direction = "RIGHT"

#Muevo la serpiente
if direction == "UP":
    snake_blocks[0][1] -= block_size
if direction == "DOWN":
    snake_blocks[0][1] += block_size
if direction == "LEFT":
    snake_blocks[0][0] -= block_size
if direction == "RIGHT":
    snake_blocks[0][0] += block_size

#Genero nueva comida
if not food_spawn:
    food_pos = generate_food()
    food_spawn = True

screen.fill(white) #Pinto la pantalla de blanco
draw_snake(snake_blocks, block_size) #Dibujo la serpiente
pygame.draw.rect(screen, red, [food_pos[0], food_pos[1], block_size, block_size]) #Dibujo la comida

pygame.display.update() #Actualizo la pantalla
