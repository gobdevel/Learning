# Learning

Clone submodules
```git submodule update --init --recursive```

Create build Directory
```mkdir build```

Compile commands
```cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..```
```cmake --build .```
Create symlink to compile_commands
```ln -s ~/Learning/build/compile_commands.json compile_commands.json```

