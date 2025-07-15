# 📘 JavaScript Base – Guida Sintetica

## 1. Variabili e Tipi di Dati

```js
let nome = "Luca";        // variabile modificabile
const PI = 3.14;          // costante, non cambia
var eta = 30;             // vecchio modo, evita di usarlo

let numero = 10;                            // number
let testo = "ciao";                         // string
let vero = true;                            // boolean
let nulla = null;                           // null = assenza di valore
let indefinito;                             // undefined = non inizializzato
let simbolo = Symbol("id");                 // symbol, valore unico
let grandeNumero = 12345678901234567890n;   // bigint per numeri enormi
```

---

## 2. Operatori Aritmetici

```js
let somma = 5 + 3;             // 8
let sottrazione = 5 - 3;       // 2
let moltiplicazione = 5 * 3;   // 15
let divisione = 10 / 2;        // 5
let modulo = 10 % 3;           // 1 (resto della divisione)
let esponente = 2 ** 3;        // 8 (2 alla 3)
```

---

## 3. Operatori di Confronto

```js
5 == "5";     // true (converte i tipi, evita)
5 === "5";    // false (controlla valore e tipo)
5 != 10;      // true
5 !== "5";    // true
10 > 5;       // true
5 < 10;       // true
5 >= 5;       // true
5 <= 4;       // false
```

---

## 4. Operatori Logici

```js
true && false;  // false (AND)
true || false;  // true  (OR)
!true;          // false (NOT)
```

### Esempio completo:

```js
let eta = 20;
let haPatente = true;

if (eta >= 18 && haPatente) {
  console.log("Puoi guidare");
} else {
  console.log("Non puoi guidare");
}
```

---

## 5. Condizioni

```js
let voto = 7;

if (voto >= 6) {
  console.log("Promosso");
} else if (voto >= 4) {
  console.log("Recupero");
} else {
  console.log("Bocciato");
}
```

---

## 6. Cicli

### For

```js
for (let i = 0; i < 5; i++) {
  console.log(i);
}
```

### While

```js
let i = 0;
while (i < 5) {
  console.log(i);
  i++;
}
```

### Do...while

```js
let i = 0;
do {
  console.log(i);
  i++;
} while (i < 5);
```

### For...of (array)

```js
let nomi = ["Luca", "Mario", "Anna"];
for (let nome of nomi) {
  console.log(nome);
}
```

### For...in (oggetto)

```js
let persona = { nome: "Luca", eta: 25 };
for (let chiave in persona) {
  console.log(chiave, persona[chiave]);
}
```

---

## 7. Funzioni

### Funzione classica

```js
function somma(a, b) {
  return a + b;
}
console.log(somma(3, 4)); // 7
```

### Arrow function

```js
const moltiplica = (a, b) => a * b;
console.log(moltiplica(3, 4)); // 12
```

### Parametri di default

```js
function saluta(nome = "amico") {
  return `Ciao, ${nome}!`;
}
console.log(saluta());       // Ciao, amico!
console.log(saluta("Luca")); // Ciao, Luca!
```

### Parametri rest

```js
// così il numero di parametri è arbitrario
function sommaTutti(...numeri) {
  return numeri.reduce((acc, val) => acc + val, 0);
}
console.log(sommaTutti(1, 2, 3, 4)); // 10
```

---

## 8. Oggetti e Array

### Oggetto

```js
let persona = {
  nome: "Luca",
  eta: 25,
  saluta: function() {
    console.log(`Ciao, sono ${this.nome}`);
  }
};

persona.saluta();  // Ciao, sono Luca
```

Note that an object can be used exactly like an hash map: you declare it `let x = {}` and at this point each key has undefined value so whenever you try to access to one key you should check if !key -> key = 0 or key = Array(dim) ... The default value of any key is `undefined`.
### Array

```js
let numeri = [1, 2, 3];
numeri.push(4);            // aggiunge 4 alla fine
numeri.pop();              // rimuove l'ultimo elemento
numeri.shift();            // removes and returns the head
numeri.unshift(5);         // adds 5 to the head

numeri.sort((a, b) => a - b);          // sorts (invert a and b for inverse)
numeri.reverse(); 

numeri.find(a => a > 7);   // returns the first element that respects the cond
numeri.length;             // proprietà dell'array: its length

let copia = numeri.slice();            // to copy the array

console.log(numeri[0]);    // 1


// to inizialize an empty array you can do the following: 
let numeri = Array(dim); 
// note that it is typically preferred to avoid multiple dimensional array so you would typically use the trick of accessing by i * dimx + j and use a one dimension array. 
```

### Strings 

```js
str.split("char");          // returns an array of strings 
```

### Classes 

```js
class Pr{
	constructor(id, nome){
		this.id = id; 
		this.nome = nome; 
	}

	bruma(){
		console.log("bruma"); 
	}
}

let p = new Pr(id, nome); 
p.bruma(); 
```

## 9. Handling the DOM (Document Object Model)

Selecting Elements: 
```js
let tit = document.getElementById('title');
document.getElementsByClassName('class'); 
document.getElementsByTagName('tag'); // These two return an HTMLCollection
```

Changing Content: 
```js
element.innerHTM: All the text with the html. 
element.textContent: All the text without the html. // You mostly use this
element.innerText: All the text that is actually seen in the page (thus hiding
				   hidden text).

// when dealing with forms to access the inner content of a submitted form you use value: 

element.value; 
```

Changing attributes: 
```js
element.setAttribute('src', 'image.png');
element.getAttribute('href');
element.removeAttribute('disabled');
element.id = 'new-id'; // Shortcut
```

Creating and removing elements: 
```js
const newElement = document.createElement('div');
newElement.textContent = 'New content';

document.body.appendChild(newElement);
parent.insertBefore(newElement, referenceElement);

element.remove(); 
```

Traversing the DOM: 
```js
element.parentNode
element.children
element.firstElementChild
element.lastElementChild
element.previousElementSibling
element.nextElementSibling
```

Events in the DOM: 
```js
element.addEventListener('click', handler); 
element.removeEventListener('click', handler);

// handler is a function that gets toggled when you click on the element in the page, handler(e) means that the handler takes e as an argument where e is the event itself on which you can do several things:

event.target; // The element clicked
event.type; // e.g., 'click'

// Some examples of event
- `click`
- `submit`
- `input`
- `change`
- `mouseover`
- `keydown`, `keyup`
```

## 10. Miscellaneous 

Formatted strings, destructuring assingments and split: 
```js
let s = `ciao sono nella bruma ${variable}`
let s2 = "esempio|split|cazzo"

let [a, b, c] = s2.split('|'); 
// remember that a b and c are strings thus to cast the types: 
a = Number(a); 
b = String(b); 
c = Boolean(c); 
```

Alert and Console log: 
```js
alert('occhio bro'); 
console.log('occhio bro'); 
```

Initializing the page: 
```js
// you build a function that initializes the js and then in the body tag you do the following: 
<body onload="iniz()">
</body> 
```