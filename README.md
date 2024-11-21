# brainfuck

Building a [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck#:~:text=Brainfuck%20is%20an%20esoteric%20programming,pointer%2C%20and%20an%20instruction%20pointer.) interpreter in C++ (and maybe a compiler in a distant future?)

# Usage 

The interpreter is alreay built, you can use the following
```bash
./brainfuck [name]
```
to print `char` values

```bash
./brainfuck [name] -char
```
# Interpreter logic
- no memory size limit, it can extend indefinitely to the left or right.
- the data type is `int` so the interpreter allows negative values.
- the loop ends when `*ite==0` (not ``*ite>0` like some other interpreters).


# Building & Debuging

## Building

```Bash
make #to build the project
make run #to run the program equivalent. By defualt is lauch source i.e. the command is equivalent to ./brainfuck source
make clean # to delete object files and the program
```
## Debuging 

Using `VSCode` add the config to `.vscode/tasks.json` and `.vscode/launch.json`:

```Bash
{
    "type": "cppbuild",
    "label": "Build brainfuck",
    "command": "make",
    "args": ["brainfuck"],
    "options": {
        "cwd": "${cwd}"
    },
    "detail": "Build brainfuck"
}
```

```Bash
{
    "name": "Debug brainfuck",
    "type": "cppdbg",
    "request": "launch",
    "program": "${cwd}/brainfuck",
    "args": ["source"],
    "stopAtEntry": false,
    "cwd": "${cwd}",
    "environment": [],
    "externalConsole": true,
    "MIMode": "lldb",
    "setupCommands": [
        {
        "description": "Enable pretty-printing for gdb",
        "text": "-enable-pretty-printing",
        "ignoreFailures": true
        }
    ],
    "preLaunchTask": "Build brainfuck"
}
```
By default the debuger runs `source`.