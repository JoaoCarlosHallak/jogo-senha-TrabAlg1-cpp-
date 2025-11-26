# 🔒 Exercício 1: Jogo da Senha (Mastermind)

Este projeto consiste na implementação do clássico **Jogo da Senha** em C++. O objetivo é desafiar o computador (Dono do Segredo) e descobrir uma senha oculta de 4 dígitos através de lógica e dedução.

O projeto foi desenvolvido como parte da disciplina de **Algoritmos (DCC199)** do Departamento de Ciência da Computação da **UFJF**.

## 📋 Descrição do Projeto

O programa atua como o "Dono do Segredo", gerando uma senha aleatória, e o usuário atua como "Decifrador".
O diferencial técnico deste projeto é a **restrição de estruturas de dados**: não é permitido o uso de vetores (arrays) ou matrizes. Toda a manipulação dos dígitos da senha deve ser feita através de variáveis simples e operações matemáticas (divisão inteira e módulo).

### Objetivos de Aprendizagem
- Declaração e manipulação de variáveis.
- Estruturas condicionais (`if`, `else`) e de repetição (`for`, `while`).
- **Modularização**: Uso intensivo de funções para organizar o código.
- Lógica matemática para extração de dígitos de números inteiros.

---

## 🎮 Como Jogar

1. **A Senha**: O computador gera uma senha de 4 dígitos. Cada dígito é um número entre **1 e 6**. Repetições são permitidas (ex: `1145`).
2. **O Palpite**: Você deve digitar um número de 4 dígitos (ex: `1234`).
3. **O Feedback**: A cada tentativa, o programa informa:
   - `o`: Dígito correto na posição correta.
   - `x`: Dígito correto (cor certa), mas na posição errada.
   - `_`: Dígito incorreto.
4. **Vitória/Derrota**: Você tem **10 tentativas** para acertar a senha exata (`oooo`).

### Exemplo de Feedback
Se a senha for `1234` e o palpite for `1562`:
- O `1` está certo e na posição certa (`o`).
- O `2` existe na senha, mas está na posição errada (`x`).
- `5` e `6` não existem (`_`).

---

## 🛠️ Requisitos Técnicos e Restrições


1. **Sem Vetores/Matrizes**: A senha e os palpites são armazenados como variáveis inteiras únicas (ex: `int senha = 4261`).
2. **Matemática**: A separação dos dígitos é feita via divisão (`/`) e resto (`%`).
3. **Validação**: O programa bloqueia entradas inválidas (números fora do intervalo 1-6 ou fora do formato de 4 dígitos).
4. **Modularização**: O código é dividido em funções específicas (geração de senha, validação, loop do jogo, interface).

---

## 💻 Exemplo de Execução

```text
=========================================
        J O G O   D A   S E N H A        
=========================================

 Bem-vindo ao desafio!

 O computador gerou uma senha secreta com 4 digitos.
 Cada digito e um numero entre 1 e 6.
 Repeticoes sao permitidas. MAX: 10

 Seu objetivo e descobrir a senha!

-----------------------------------------
 Dicas do jogo:
 - Voce deve digitar um numero de 4 digitos.
 - Exemplo de palpite valido: 1562
 - Cada tentativa mostrara se voce acertou ou errou.
-----------------------------------------

 Boa sorte! Tente desvendar a senha...

=========================================

----------- 1 TURNO -----------
Digite a senha >> 2345
Resultado: __x_

----------- 2 TURNO -----------
Digite a senha >> 2345
Resultado: __x_

----------- 3 TURNO -----------
Digite a senha >> 2354
Resultado: ___x

----------- 4 TURNO -----------
Digite a senha >> 2351
Resultado: ___o

----------- 5 TURNO -----------
Digite a senha >> 1231
Resultado: x__o

----------- 6 TURNO -----------
Digite a senha >> 2131
Resultado: _x_o

----------- 7 TURNO -----------
Digite a senha >> 2211
Resultado: __oo

----------- 8 TURNO -----------
Digite a senha >> 4311
Resultado: x_oo

----------- 9 TURNO -----------
Digite a senha >> 5411
Resultado: _ooo

----------- 10 TURNO -----------
Digite a senha >> 6411
Resultado: oooo

PARABENS! VOCE VENCEU!
