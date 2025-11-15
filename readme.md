# Simulador de Tabuleiro com Áreas de Habilidade (Cone, Cruz e Octaedro)

Este projeto implementa um simulador em C que utiliza um tabuleiro 10×10 e aplica sobre ele diferentes áreas de habilidade, como **cone**, **cruz** e **octaedro/losango**.  
O código demonstra como sobrepor matrizes de padrões sobre um grid — um conceito comum em jogos de estratégia.

---

## 🧩 Visão Geral

O programa:

- Inicializa um tabuleiro 10×10 com água (`0`).
- Coloca navios (`3`) em posições fixas.
- Gera três matrizes de habilidade (`7×7`):
  - Cone  
  - Cruz  
  - Octaedro / Losango
- Aplica essas habilidades ao tabuleiro, marcando áreas afetadas (`5`) sem sobrescrever navios.
- Exibe as matrizes criadas e o tabuleiro final.

---

## 🗂️ Estrutura das Funções

### `init_board(board)`
Preenche toda a matriz do tabuleiro com `0`.

### `print_board(board)`
Exibe o tabuleiro no terminal:

- `0` → água  
- `3` → navio  
- `5` → área atingida  

### `create_cone(n, mat)`
Gera um padrão triangular (cone).

### `create_cross(n, mat)`
Gera uma cruz com linha e coluna centrais.

### `create_octahedron(n, mat)`
Cria um losango (distância Manhattan).

### `overlay_ability(board, origin_r, origin_c, n, ability)`
Aplica uma matriz de habilidade ao tabuleiro, respeitando bordas e navios.

---

## 🎯 Posições das Habilidades

| Habilidade | Linha | Coluna |
|-----------|-------|--------|
| Cone      | 1     | 3      |
| Cruz      | 5     | 5      |
| Octaedro  | 7     | 2      |

---

## 🛠️ Compilação e Execução

### Compilar:
```bash
gcc batalha-naval.c -o batalha-naval
./batalha-naval
