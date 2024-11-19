# brainfuck

Building a [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck#:~:text=Brainfuck%20is%20an%20esoteric%20programming,pointer%2C%20and%20an%20instruction%20pointer.) interpreter in C++ (and maybe a compiler in a distant future?)

# Usage 

The interpreter is alreay built you can use following
```bash
./brainfuck source
```

# Building & Debuging

## Building

```Bash
make #to build the project
make run #to run the program
make clean # to delete object files and the program
```
## Debuging 

Using `VSCode` change `.vscode/tasks.json` and `.vscode/launch.json` as per below

```Bash
{
    "type": "cppbuild",
    "label": "Build [path_to_folder]/main",
    "command": "make",
    "args": ["main"],
    "options": {
        "cwd": "${cwd}/[path_to_folder]"
    },
    "detail": "Build [path_to_folder]/main"
}
```

```Bash
{
    "name": "Debug [path_to_folder]/main",
    "type": "cppdbg",
    "request": "launch",
    "program": "${cwd}/[path_to_folder]/main",
    "args": [],
    "stopAtEntry": false,
    "cwd": "${cwd}/[path_to_folder]",
    "environment": [],
    "externalConsole": false,
    "MIMode": "gdb",
    "miDebuggerPath": "/usr/bin/gdb",
    "setupCommands": [
        {
        "description": "Enable pretty-printing for gdb",
        "text": "-enable-pretty-printing",
        "ignoreFailures": true
        }
    ],
    "preLaunchTask": "Build [path_to_folder]/main"
}
```
