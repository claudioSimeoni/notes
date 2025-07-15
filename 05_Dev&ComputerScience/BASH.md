## Files and directories management 

Whenever you see the dir or file tag, you can insert a path from where you are (or from the home ~ using also ../) to the file or dir you want to apply the command to. 

```sh
pwd #print working directory 
cd dir #navigates in the dir, . is the current dir, while .. 
# is its parent. 
ls dir #lists the files in dir, if no argument the current one 
mkdir dir #creates the directory dir 
touch file #creates the file file 
rmdir dir #if empty deletes dir 
rm file #deletes file 
rm -r dir #deletes the directory and everything inside, 
# the flag -r stands for recursive 
cp source dest #copies the source file's content into the dest one 
mv source dest #either rename source into dest or if dest is a 
# directory moves source into dest 
find dir -name file.txt #finds the files named file.txt in dir 
# if you wanna mention a pattern with the glob *, you put it in quotes 
tree #shows the tree of the directory 
file file #gives information about a file 
```
## Other generic commands 

```sh
cat file #show content of the file
less file #scrollable view of the file 
head -n 10 file #shows first 10 lines 
tail -n 10 file #shows last 10 lines 
wc -l file #counts the lines

grep "pattern" file #finds a pattern 
grep -r "pattern" dir #finds a pattern in a dir
nano/vim/code file #opens file with the respective text editor
history #shows the command line history
man command #opens the manual of hte command 
du file # shows the file dimension in blocks (depends on the machine)

echo "text" >> file #writes text into file 
# > overwrites while >> appends, | is a pipe.
echo bruma #prints on the shell bruma 

# a few flags 

-a #all
-l #long version
-r #recursive
-f #force
```
## Server interaction 

In the internet both hosts and clients have their own **IP** (Internet Protocol), a server generally also has a domain, which is a translated version of the IP into common language. If we want to access to a server in our LAN we can just use its IP, but if it is remote we must typically use its domain. An **URL** (Uniform Resource Locator) instead is a path that provides many information such as the **protocol** used to access to a server whose **domain** is mentioned, and then the specific resources of the server you are accessing to. 

```sh
ping google.com #tests connectivity 
curl google.com #fetches the code of the site

ssh user@host #used to access a remote server securely with user
# user and where host is the ip or the domain of the server 
-p 0000 # to specify a port 

scp /localdirectory/example1.txt user@host:path #copies example
# to the server's path
scp user@host:/home/example.txt ./ #copies example to the current dir
nc host port #creates a less secure than ssh connection to
# the server host to the port
```
## Scripting

#### Variables, IO, Positional Arguments

if we want to execute a bash script we can both do "bash file.sh" that would use the bash interpreter, or we can write `#!/bin/bash` at the beginning of the file and then give the permissions to the file by using `chmod +x file.sh`.

```bash 
#!/bin/bash
dateofbirth="15/00" 

echo insert your name
read name
echo "insert surname"
read surname 
echo hello "$name $surname $dateofbirth, how you doin'"
#here echo works like cout while read works like cin

---

when executing the script: ./scr.sh claudio simeoni
echo "hi this is $1 $2" #these are respectively claudio and simeoni
#positional arguments, $0 is the ./scr.sh
```

As you can see, quotes "" are not strictly necessary, you can put them or not whenever you want, but actually you should always put them, they avoid that some words are confused as keywords instead of text to print.

---

#### Pipes and Redirection of input

With the pipe | you can give the result of command a to a command b as in the example.

```c++
ls -l | grep god 

echo "bruma" > file.txt #overwrites 
echo "bruma" >> file.txt #appends

./a.out < input.txt #gives the input to a.out 
./a.out << EOF #reads the input from the terminal until you write EOF
wc -w <<< "primella idrosa" #you litterally write the input 
#wc -w count the number of words 
```

#### If statement

```bash 
if[ condition ]; then
	#code
elif
	#code
else 
	#code
fi 

@interi 
-eq uguale (==)
-ne non uguale (!=)
-lt minore di (<)
-le minore o uguale (<=)
-gt maggiore di (>)
-ge maggiore o uguale (>=)

@logici
&& || ! solo se usi [[ ]] anzichè []

@stringhe 
= uguale (==)
!= diverso (!=)

@file
-e file esiste
-f file è un file regolare
-d dir è una directory
-r file leggibile
-w file scrivibile
-x file eseguibile
-s file non è vuoto
```

#### For loop 

```bash
frutti=("mela" "banana" "pera") #an array 
echo "${frutti[0]}" #how to access the elements 

frutti+=("kiwi") #adds kiwi to the array
frutti[1]="fragola" #sets frutti[1] to fragola

echo "${frutti[@]}" #you print all of them 
echo "${#frutti[@]}" #print the dim of the array

for frutto in "${frutti[@]}"; do
    echo "Hai scelto: $frutto"
done

for i in "${!arr[@]}"; do
    echo "Indice $i = ${arr[$i]}"
done #looping on the indices 

for ((i=0; i<n; i++)); do 
	echo "i = $i"; 
done 

```