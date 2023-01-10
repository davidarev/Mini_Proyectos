package test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        
        // Paso 1
        int[] arr = new int[40];
        Random random = new Random();
        for (int i = 0; i < arr.length; i++) {
            int numero = random.nextInt(16) + 5;
            arr[i] = numero;
        }
        
        System.out.println("El array generado es: " + Arrays.toString(arr));
        Map<Integer, Integer> posiciones = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (posiciones.containsKey(arr[i])) {
                posiciones.put(arr[i], posiciones.get(arr[i]) + 1);
            } 
            else {
                posiciones.put(arr[i], 1);
            }
        }
        
        int moda = 0;
        int max = 0;
        for (Map.Entry<Integer, Integer> entry : posiciones.entrySet()) {
            if (entry.getValue() > max) {
                max = entry.getValue();
                moda = entry.getKey();
            }
        }
        
        System.out.println("\nLa moda es el número " + moda);

        // Paso 2
        System.out.println();
        List<Integer> ordenados = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if (!ordenados.contains(arr[i])) {
                ordenados.add(arr[i]);
            }
        }
        
        ordenados.sort(null);
        System.out.println("Los números ordenados y sin duplicar son: " + ordenados);

        // Paso 3
        System.out.println();
        double mediana;
        if (ordenados.size() % 2 == 0) {
            mediana = (ordenados.get(ordenados.size() / 2) + ordenados.get(ordenados.size() / 2 - 1)) / 2.0;
        } 
        else {
            mediana = ordenados.get(ordenados.size() / 2);
        }
        
        System.out.println("La mediana es: " + mediana);
    }
}
