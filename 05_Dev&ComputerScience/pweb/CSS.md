```css
/*
CSS Selectors & Basics:
- Selectors can target an entire element type, a class (.classname), or an ID (#idname).
- The universal selector (*) affects all elements.
- Multiple elements or classes can be targeted by separating them with a comma (e.g., element1, element2).
- Descendant selectors (parent child) apply styles to nested elements.
*/


/* Global styles */
* {
margin: 0;
padding: 0;
box-sizing: border-box;
}
```

## FLEX

About flex we have two great slides from uni: 

![[Screenshot from 2025-07-13 12-41-57.png]]

![[Screenshot from 2025-07-13 12-42-04.png]]

## GRID

```css
#element {
	display: grid;
	
    gap: 1em;
    row-gap, column-gap; 
    
	grid-template-columns: 1fr 1fr;
	grid-template-rows: 3fr 1fr 5fr; 
}
```

## PSEUDO CLASSES 

| Pseudo-class       | What it does                                              | Example                                         |
|--------------------|-----------------------------------------------------------|-------------------------------------------------|
| **🔁 Interaction**  |                                                           |                                                 |
| `:hover`           | Styles element when the mouse is over it                 | `a:hover { color: red; }`                       |
| `:active`          | When the element is being clicked                        | `button:active { transform: scale(0.95); }`     |
| `:focus`           | When the element is focused (e.g., clicked or tabbed)    | `input:focus { outline: 2px solid blue; }`      |
| `:visited`         | Styles a visited link                                    | `a:visited { color: purple; }`                  |
| `:disabled`        | Targets disabled inputs/buttons                          | `button:disabled { opacity: 0.5; }`             |
| `:checked`         | Targets checked checkboxes/radio                         | `input:checked { background: green; }`          |
| **📍 Position**     |                                                           |                                                 |
| `:first-child`     | First child of parent                                    | `p:first-child { font-weight: bold; }`          |
| `:last-child`      | Last child of parent                                     | `li:last-child { margin-bottom: 0; }`           |
| `:nth-child(n)`    | nth child of parent (1-based index)                      | `tr:nth-child(even) { background: #eee; }`      |
| `:nth-of-type(n)`  | nth element of same type                                 | `p:nth-of-type(2) { color: red; }`              |
| `:only-child`      | Selects element if it's the only child                   | `div:only-child { padding: 1rem; }`             |
| **🎯 Attribute**    |                                                           |                                                 |
| `:required`        | Targets form inputs marked `required`                    | `input:required { border: red; }`               |
| `:optional`        | Targets inputs not marked `required`                     | `input:optional { border: green; }`             |
| `:valid`           | Input with valid content (type or pattern)               | `input:valid { border: green; }`                |
| `:invalid`         | Input with invalid content                               | `input:invalid { border: red; }`                |

```css

  
/* Class and ID selectors */

.important {
background-color: rgb(118, 175, 118);ù
opacity: 0.7;
}

#second {
background-color: yellow;
}

#third {
border-style: solid double dotted dashed;
border-width: 10px medium 20px thick;
border-color: red blue green yellow;
}

#fourth {
border-radius: 10px;
border: thick solid purple;
padding: 30px 20px 10px;
outline: dotted 2px black;
outline-offset: 10px;
height: auto;
width: 100px;
}

#txt {
text-align: left;
text-align-last: center;
text-decoration: overline underline blue dashed 15px;
font-size: 2rem;
}


/* Background properties */
body {
background-image: url("https://thumbs.dreamstime.com/b/spring-wallpaper-creating-award-winning-photograph-pic-encapsulates-timeless-beauty-tranquility-nature-351384024.jpg");
background-position: top center;
background-repeat: no-repeat;
background-size: cover;
}


/* Paragraphs */
p {
margin: 50px 23% 40px 20%; /* top, right, bottom, left */
text-transform: capitalize;
text-indent: 20px;
letter-spacing: 2px;
font-family: Arial, Helvetica, sans-serif;
font-style: italic;
font-weight: bold;
} 


/* Table styling */
table, th, td {
padding: 20px;
border: 2px solid;
border-collapse: collapse;
width: 100%;
border-width: 2px;
}
  
tr:hover {
background-color: blue;
color: white;
}


/* Dropdown Menu */
.dropdown-menu {
background-color: lightblue;
min-width: 150px;
display: none;
position: absolute;
z-index: 10;
}

.dropdown-menu a {
color: black;
text-decoration: none;
display: block;
padding: 10px;
}
 
.dropdown-menu a:hover {
background-color: white;
}

.dropdown:hover .dropdown-menu {
display: block;
}

.dropdown:hover .dropdown-button {
background-color: yellow;
}

.dropdown-button {
background-color: green;
padding: 15px 30px;
border: none;
color: white;
font-size: 1.2rem;
cursor: pointer;
transition: background 0.3s;
}

.dropdown-button:hover {
background-color: darkgreen;
}
 

/* Visibility vs Display */
.hidden-element {
visibility: hidden; /* Element is invisible but still takes up space */
}

.removed-element {
display: none; /* Element is completely removed from the layout */
}
```