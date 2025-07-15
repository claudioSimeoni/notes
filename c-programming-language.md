- **printf specifiers: ** 
```
int %d               float %f
short %hd            double %lf
long %ld             char %c
long long %lld       pointer %p
unsigned %u          string %s 
octal %o             hexadecimal %x

%10d specifies the minimum field width (if not reached uses spaces for padding) 
%7.8 specifies both the width and the decimal digits
```
- **getchar() and putchar()** respectively get a char from the input stream and print a char onto the output stream.
- char[] is an array of characters and it is stored in a precise sized memory and it can be changed safely by accessing to the single indices, while char* is used for literal expressions and it is unsafe to randomly access its indices. Remember that a string always has the escape symbol \0. 
- files can use variables, functions and structs from other files linked to it. If you want to use something on another file you must declare it (if it is a variable you must use **extern**, and if you don't want something to be used in other files you can use **static**), typically functions and structs are declared in a separate files, the header that acts exactly in this way: if you include it in a .c file it is like you pasted it on the top of the file. 
- limits.h and float.h store some constants about c types 
- when you use constants in operations you may want to use the characters at the end to help the compiler understand what type is that value: 1092815718275289L or 9816761237641.0214F.
- 0365215 is an octal number while 0x1834 is an hexadecimal number, you can also define additional escape sequences to refer to specific characters \012 is an octal value for the char 012 in ascii while \x23 is hexadecimal.
- enum is like a set of constants by default set from 0 1 2 ... The idea is that you are creating a type whose constants are instances.

| Livello | Operatori                                                                              | Associatività     |
| ------- | -------------------------------------------------------------------------------------- | ----------------- |
| 1       | `()` `[]` `->` `.`                                                                     | Sinistra a destra |
| 2       | `++` `--` `+` `-` `!` `~` `*` `&` `(type)` `sizeof`                                    | Destra a sinistra |
| 3       | `*` `/` `%`                                                                            | Sinistra a destra |
| 4       | `+` `-`                                                                                | Sinistra a destra |
| 5       | `<<` `>>`                                                                              | Sinistra a destra |
| 6       | `<` `<=` `>` `>=`                                                                      | Sinistra a destra |
| 7       | `==` `!=`                                                                              | Sinistra a destra |
| 8       | `&`                                                                                    | Sinistra a destra |
| 9       | `^`                                                                                    | Sinistra a destra |
| 10      | `                                                                                      | Sinistra a destra |
| 11      | `&&`                                                                                   | Sinistra a destra |
| 12      | `                                                                                      | Sinistra a destra |
| 13      | `?:`                                                                                   | Destra a sinistra |
| 14      | `=` `+=` `-=` `*=` `/=` `%=` `<<=` `>>=` `&=` ...                                      | Destra a sinistra |
| 15      | `,`                                                                                    | Sinistra a destra |
- **register** int x is a declaration of a variable that is going to be used so much so you basically tell the compiler to put that variable into the registers of the machine.
- on the right of the defined you can use # and ## to do the two following things: 
```c
~ #define
dprint(expr)
printf(#expr " = %g\n", expr)
// When this is invoked, as in
dprint(x/y)
// the macro is expanded into
printf("x/y" " = %g\n", x/y);


~ #define paste(front, back) front ## back
so paste(name, 1) creates the token name1
```

- a pointer to void can point any type but cannot be dereferenced
- pay attention with comparing strings with == , this only compares the pointers, if you wanna compare two strings use strcmp() from string.h. 
- structs add padding to align each of its element to an address that is a multiple of the bytes of your machine. 