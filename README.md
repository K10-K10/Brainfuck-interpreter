# Brainm\*\*k-interpreter

## char list

| char | command        |
| ---- | -------------- |
| `+`  | increment      |
| `-`  | decrement      |
| `.`  | print          |
| `,`  | input          |
| `[`  | loop begin     |
| `]`  | loop end       |
| `>`  | right bit sift |
| `<`  | left bit sift  |

[reference from wikipedia](https://en.wikipedia.org/wiki/Brainfuck)

## build 
```sh
g++ main.cpp -o bf
```

cp `bf` in `bin`
```sh
sudo cp bf ~/.local/bin/bf
```

add path in `~/.zshrc`
```sh
export PATH="$HOME/.local/bin:$PATH"
```

Restart terminal and use bf!

## run

```sh
bf file.bf
```
