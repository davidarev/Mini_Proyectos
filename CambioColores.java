package test;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.*;

public class CambioColores extends JFrame {
    private JPanel colorPanel; //Panel para mostrar el color
    private JButton botonColorRandom; //Boton para cambiar el color aleatoriamente
    private JButton botonColorSiguiente; //Boton para cambiar el color al siguiente
    private Color[] colores = {Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, Color.BLUE, Color.MAGENTA}; //Array de colores
    private int indiceColor = 0; //Indice del color actual

    public CambioColores() {
        colorPanel = new JPanel(); //Creo el panel
        colorPanel.setBackground(colores[indiceColor]); //Le pongo el color inicial

        botonColorRandom = new JButton("Color aleatorio"); //Creo el boton para cambiar el color aleatoriamente
        botonColorRandom.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) { //Funcion que se ejecuta al pulsar el boton
                Random random = new Random(); //Creo un objeto random
                int indiceRandom = random.nextInt(colores.length); //Obtengo un numero aleatorio entre 0 y el numero de colores
                colorPanel.setBackground(colores[indiceRandom]); //Le pongo el color aleatorio
                indiceColor = indiceRandom; //Actualizo el indice del color
            }
        });

        botonColorSiguiente = new JButton("Siguiente color"); //Creo el boton para cambiar el color al siguiente
        botonColorSiguiente.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            	indiceColor = (indiceColor + 1) % colores.length; //Actualizo el indice del color
                colorPanel.setBackground(colores[indiceColor]); //Le pongo el color siguiente
            }
        });

        //Añado los botones al panel
        add(botonColorRandom);
        add(botonColorSiguiente);

        add(colorPanel); //Añado el panel al frame

        setLayout(new java.awt.FlowLayout()); //Le pongo un layout al frame
        setSize(500, 100); //Tamaño
        setTitle("Color Changer");  //Titulo
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Para que se cierre al pulsar la X
        setVisible(true); //Para que se vea
    }

    //Funcion principal
    public static void main(String[] args) {
        new CambioColores(); 
    }
}
