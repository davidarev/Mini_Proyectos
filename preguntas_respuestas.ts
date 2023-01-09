const preguntas = [ // Array de preguntas que se van a mostrar en el juego
    {
        pregunta: "¿Cuál es la capital de Francia?", // Pregunta
        respuesta: "París" || "parís" || "paris" // Respuesta/s
    },
    {
        pregunta: "¿Cuál es la moneda de Japón?",
        respuesta: "Yen" || "yen"
    },
    {
        pregunta: "¿Cuál es el río más largo del mundo?",
        respuesta: "Amazonas" || "amazonas"
    },
    {
        pregunta: "¿Qué futbolista tiene más balones de oro?",
        respuesta: "Messi" || "messi"
    },
    {
        pregunta: "¿Donde se encuentra el edificio más alto del mundo?",
        respuesta: "Dubai" || "dubai"
    },
    {
        pregunta: "¿Cuantas peliculas de Harry Potter hay?",
        respuesta: "7"
    }
];

let respuestaCorrecta = 0;

preguntas.forEach(_pregunta => { // Recorre el array de preguntas
    const userAnswer = prompt(_pregunta.pregunta); // Pregunta al usuario
    if (userAnswer === _pregunta.respuesta) { // Comprueba si la respuesta es correcta
        respuestaCorrecta++;
    }
});

console.log(`Has respondido correctamente ${respuestaCorrecta} preguntas.`); // Muestra el resultado
