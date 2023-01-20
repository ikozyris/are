# ARE
Advanced REader - A plain text reader in C for linux

Supports:
- Reading with printing line number for each line
- Reading and only printing the total lines at the start
- Reading normally without any modification
- Reading normally and printing the $ at the end of each line


### Compile
```
gcc main.c -o are
```
or
```
make all
```

### Usage
```
Usage: are [FILE]... [OPTION]...                                              
   -r   --read              Read file                                         
   -rl  --read-lines        Read with the line number before each line        
   -e,  --show-ends         Display $ at end of each line                     
   -sn  --single-number     Print total line number at the start              
   -h   --help              Display this help and exit                        
   -v   --version           Output version information and exit
```
