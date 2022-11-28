import turtle

def draw_heart(): #Dibuja el corazón
    turtle.color("red")
    turtle.begin_fill()
    turtle.left(140)
    turtle.forward(180)
    turtle.circle(-90, 200)
    turtle.setheading(60)
    turtle.circle(-90, 200)
    turtle.forward(180)
    turtle.end_fill()

def message(frase): #Muestra el mensaje
    turtle.penup()
    turtle.setpos(0, -100)
    turtle.pendown()
    turtle.color("white")
    turtle.write(frase, align = "center", font = ("Arial", 20, "normal"))

def main(): #Función principal
    turtle.bgcolor("black") #Color de fondo
    draw_heart() #Dibuja el corazón
    message("Feliz dia de los enamorados")
    turtle.done()

if __name__ == '__main__':
    main()





