- `cc --version` tells you the c compiler version.
- `hexdump -C filename` can be used to take a look at an executable file content (more generally to the hexadecimal representation of any file). 
- `vi` command is as vim and stands for visual interface while the second one is a visual interface improved. 
- `cc -S filename` produces the assemble file.s 
- these are some of the optimizations you can use with the c compiler: 
```c
-O0   # No optimization (default)
-O1   # Basic optimization
-O2   # Moderate optimization
-O3   # Aggressive optimization (can increase binary size)
-Os   # Optimize for size
-Ofast # Max performance (may break strict standards)
```
- the linux manual is split into sections, section one refers to user programs so for example if you wanna know more about c function `printf()` you should use `man 3 printf` that refers to the 3rd section of the manual, the one about library functions. 
- here you have a few shell special variables: 
```sh
echo $0        # ./myscript.sh
echo $1        # First argument to script
echo $?        # Exit status of last command
echo $$        # PID of this shell
echo $!        # PID of last backgrounded process
echo $@        # All arguments, separately
echo "$*"      # All arguments as a single string
```
- `!string` tells you the last command run on the shell that started with string
- in unix shell 0 is true while other values are false, this is because 0 means that a program ended correctly. 