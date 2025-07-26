# Brainfuck-interpreter

## Char list

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

## Install

1. Clone this repository.

- ssh

```bash
git clone git@github.com/K10-K10/Brainfuck-interpreter
```

- https

```bash
git clone https://github.com/K10-K10/Brainfuck-interpreter
```

2. Build

Build code

```bash
g++ main.cpp -o bf
```

3. Copy `bf` in `bin`

```bash
sudo cp bef ~/.local/bin/bf
```

4. Add path in ~/.zshrc

```bash
export PATH="$HOME/.local/bin:$PATH"
```

## Run

```bash
bf file.bf
```
