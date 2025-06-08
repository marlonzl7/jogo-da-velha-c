# Jogo da Velha em C

Este é um projeto simples de jogo da velha desenvolvido em C para rodar no terminal. Dois jogadores jogam alternadamente até que um ganhe ou o jogo termine empatado.

---

## Como compilar

No terminal, dentro da pasta do projeto, execute:

```bash
gcc main.c -o jogo
```

## Como rodar

Depois de compilar execute:
```bash
./jogo
```

## Como jogar

- O tabuleiro é numerado de 1 a 9, da esquerda para a direita, de cima para baixo.
- Os jogadores escolhem um número para fazer sua jogada na posição correspondente.
- O primeiro jogador usa `X` e o segundo `O`.
- O jogo termina quando um jogador conseguir três símbolos em linha, coluna ou diagonal, ou quando todas as posições estiverem preenchidas (empate).
