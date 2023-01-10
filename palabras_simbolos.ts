let frase: string = prompt("Ingrese una frase: ");

// Regex to match any symbol
let regex = /[.,-?¿!¡()"·$%&;:_"]/g;

// Replace all symbols in the sentence with empty spaces
let fraseSinSimbolos = frase.replace(regex, "");

// Split the sentence into words and store them in an array
let palabras: string[] = fraseSinSimbolos.split(" ");
console.log(`Palabras en la frase: ${palabras}`);

// Initialize counters for each symbol
let punto = 0;
let coma = 0;
let guion = 0;
let pregunta = 0;
let exclamacion = 0;

// Iterate through each character in the sentence
for (let i = 0; i < frase.length; i++) {
    switch (frase[i]) {
        case ".":
            punto++;
            break;
        case ",":
            coma++;
            break;
        case "-":
            guion++;
            break;
        case "?":
            pregunta++;
            break;
        case "¿":
            pregunta++;
            break;
        case "!":
            exclamacion++;
            break;
        case "¡":
            exclamacion++;
            break;
    }
}

// Print the count of each symbol
console.log(`Puntos: ${punto}`);
console.log(`Comas: ${coma}`);
console.log(`Guiones: ${guion}`);
console.log(`Preguntas: ${pregunta}`);
console.log(`Exclamaciones: ${exclamacion}`);
