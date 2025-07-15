```html
<!DOCTYPE html>
<html lang="en">
<head> 
    <!-- Metadata: specify character encoding and responsive behavior -->
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
    <!-- Page title -->
    <title>My First HTML5 Learning Page</title>
    
    <!-- Favicon: small icon displayed in browser tab -->
    <!-- 'rel' attribute defines the relationship between this document and the linked resource -->
    <link rel="icon" href="https://letsenhance.io/static/73136da51c245e80edc6ccfe44888a99/1015f/MainBefore.jpg"> 
    
    <!-- Internal CSS and JS block (empty here but ready for styles) -->
    <style></style>
    <script></script> 
    
    <!-- External CSS or JS-->
    <link rel="stylesheet" href="cssnotes.css"> 
    <script src="js/html5shiv.js"></script> 
</head>

<body>
    <!-- Header: site branding and main navigation -->
    <header>
        <h1>Example Website</h1>
        <nav>
            <!-- Navigation links using anchors to sections -->
            <a href="#work">Work</a> | 
            <a href="#family">Lulu</a>
            <hr> <!-- Horizontal line used as separator -->
        </nav>
    </header>

    <!-- Main content container: should appear only once per page -->
    <main>
        <!-- Home section -->
        <section id="home">
            <h2>Welcome!</h2>
            <p>This is a sample website to learn HTML5 and its main elements.</p>
        </section>

        <!-- Services section with two articles -->
        <section id="services">
            <h2>Our Services</h2>

            <!-- Article: independent content block -->
            <article>
                <h3>Web Design</h3>
                <p>We create modern and responsive websites.</p>
            </article>

            <article>
                <h3>SEO Optimization</h3>
                <p>We help you get found online effectively.</p>
            </article>
        </section>

        <!-- Aside: related or supplementary content -->
        <aside>
            <h3>Recommended Resources</h3>
            <ul>
                <li><a href="#">HTML5 Guide</a></li>
                <li><a href="#">CSS Basics</a></li>
                <li><a href="#">JavaScript Tutorials</a></li>
            </ul>
        </aside>

        <figure>
            <img src="mountain.jpg" alt="Snowy mountain at sunset">
            <figcaption>Snowy mountain at sunset – Alps, 2024</figcaption>
        </figure>
    </main>

    <!-- Footer: copyright and legal info -->
    <footer>
        <p>&copy; 2025 Claudio Simeoni. All rights reserved.</p>
    </footer>
</body>
</html>
```

In html tags you can use some shortcuts like **`onclick="function()"`** or **`onload="function()`**, the second one is typically used for the body and can be used as an initialization of the page. 

## FEATURES 

```html
<h1>Hello, my name is Claudio!</h1> 
        <p>This page is used to test different HTML elements while learning.</p>
        
        <!-- Email link: opens user's default mail client -->
        <p>
            <a href="mailto:cla.simeoni1990@gmail.com"> brume </a>
            <a href="http://www.google.com"> brume </a>
            <a href="dir/index.html"> brume </a>
            <a href="#id"> brume </a>
        </p>
        
        <!-- Image with alt attribute for accessibility -->
        <img 
          src="https://www.alleycat.org/wp-content/uploads/2019/03/FELV-cat.jpg" 
          height="150" 
          width="100"
          alt="A cat sitting comfortably"
          title="best primizie ever" 
        >
        
        <!-- Formatted inline text elements -->
        <div>
            <b>Bold</b> | <i>Italic</i> | <mark>Highlighted</mark> |   
            <del>Strikethrough</del> | <ins>Underlined</ins><br>
            Chemical formula: H<sub>2</sub>O | Mathematical power: 7<sup>3</sup>
        </div>

        <!-- Lists examples -->
        <div class="highlight">
            <h3>Unordered List (bullets)</h3>
            <ul>
                <li>HTML</li>
                <li>CSS</li>
                <li>JavaScript</li>
            </ul>

            <h3>Ordered List (numbers)</h3>
            <ol>
                <li>Learn</li>
                <li>Practice</li>
                <li>Master</li>
            </ol>

            <h3>Definition List</h3>
            <dl>
                <dt>HTML</dt>
                <dd>HyperText Markup Language</dd>
                <dt>CSS</dt>
                <dd>Cascading Style Sheets</dd>
            </dl>
        </div>
```

## TABLES

```html
<table cellspacing="0" cellpadding="5">
	<caption>Team Members</caption>
	<thead>
		<tr>
			<th>Name</th>
			<th colspan="2">Surname</th> 
			<!-- the second element will cover two columns, the total sum of 
				 the column occupied must be the same for each row --> 
			<!-- rowspan does the same, but the following rows must have an                       element less -->
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>Claudio</td>
			<td>Simeoni</td>
			<td>Engineer</td>
		</tr>
	</tbody>
	<tfoot>
		<tr>
			<td colspan="3">End of table</td>
		</tr>
	</tfoot>
</table>

<!-- you may also avoid to use caption, thead ... -->
```

```css
table{
	border: 1px solid black; /* dotted, dashed... */
	/* only one of those: */
	border-collapse: collapse; 
	border-spacing: 1em;
}
```

## FORM

```html
<!-- Form example with labels and inputs -->
        <form action="process.php" method="POST">
            <!-- Label linked to input via 'for' and 'id' -->
            <label for="name">Name:</label><br>
            <input type="text" name="name" id="name" placeholder="Enter your name" required><br><br>
            
            <label for="email">Email:</label><br>
            <input type="email" name="email" id="email" placeholder="Enter your email" required><br><br>

            <label for="message">Message:</label><br>
            <textarea name="message" id="message" rows="4" placeholder="Your message here..."></textarea><br><br>

            <!-- Radio buttons group example -->
            <fieldset>
                <legend>Preferred Contact Method</legend>
                <label><input type="radio" name="contact_method" value="email" checked> Email</label>
                <label><input type="radio" name="contact_method" value="phone"> Phone</label>
            </fieldset><br>

            <!-- Checkbox example -->
            <label><input type="checkbox" name="subscribe" value="yes"> Subscribe to newsletter</label><br><br>
            
            <button type="submit">Submit</button>
        </form>
```

exam-version, then we will introduce further topics: 
```html
<div>
	<label>bruma</label><input type="text" pattern="\d|[a-z]" required>
	<!-- some types -->
	<input type="text" placeholder="Name" minlength="3">
	<input type="email" required>
	<input type="number" min="1" max="10">
	<input type="range" min="0" max="100" step="10">
	<input type="date">
	
	<label>primizia</label>
	<select>
	<option>gasa</option> 
	<option>gasella</option>
	</select>

	<!-- inside the label you can use for="inputid" (useless) -->
</div>
```

## PATTERNS

Inside input you can use the attribute pattern to check if a certain input satisfies certain conditions, **THEY ONLY WORK WITH TYPE="TEXT"**: 

| Regex           | Meaning                    | Example                                  |
| --------------- | -------------------------- | ---------------------------------------- |
| `.`             | Any single character       | `a.b` matches `acb`, `a1b`               |
| `[abc]`         | One character: a, b, or c  |                                          |
| `[a-z]`         | One lowercase letter       |                                          |
| `[A-Z]`         | One uppercase letter       |                                          |
| `[0-9]` or `\d` | One digit                  |                                          |
| `[^abc]`        | Anything except a, b, or c |                                          |
| `a\|b`          | a or b (OR)                | `a\|b` matches `a` or `b`                |
| `()`            | Grouping                   | `(ab)+` matches `ab`, `abab`             |
| `?`             | 0 or 1 times (optional)    | `colou?r` matches `color` and `colour`   |
| `*`             | 0 or more times            | `a*` matches `""`, `a`, `aaa`            |
| `+`             | 1 or more times            | `a+` matches `a`, `aa`, but not `""`     |
| `{n}`           | Exactly n times            | `[A-Z]{2}` matches `AB`                  |
| `{n,}`          | At least n times           | `[0-9]{3,}` matches `123`, `1234`        |
| `{n,m}`         | Between n and m times      | `[a-z]{2,4}` matches `ab`, `abc`, `abcd` |
#### Pattern Examples (Real Usage)

Only letters (3–10 characters)
```html
<input pattern="^[A-Za-z]{3,10}$" title="Only letters, 3 to 10 characters">
```

Capital first letter, then lowercase
```html
<input pattern="^[A-Z][a-z]+$" title="Start with a capital letter">
```

Exactly 5 digits
```html
<input pattern="^\d{5}$" title="Enter exactly 5 digits">
```

Phone number with dashes or spaces
```html
<input pattern="^\d{3}[-\s]?\d{3}[-\s]?\d{4}$" title="Enter phone like 123-456-7890">
```

Basic email format
```html
<input pattern="^[^@\s]+@[^@\s]+\.[a-zA-Z]{2,}$" title="Enter a valid email">
```

Another important thing you can do is build a pattern and check if a string satisfies it: 
```js
const patt = /^\d\.\d$/
patt.test(x); 
```