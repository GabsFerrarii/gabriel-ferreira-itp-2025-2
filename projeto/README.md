# Jogo da Vida de Conway em C

Uma implementação em C do clássico autômato celular de John Conway. O programa permite a criação de estados iniciais customizados e a observação da evolução das células em um ambiente de terminal.

### Como Compilar

Navegue até a pasta do projeto e, dentro do terminal, execute o seguinte comando:
```sh
gcc src/main.c -o JogoDaVida
```
Isso criará um arquivo executável chamado `JogoDaVida`.

### Como Jogar

1.  Execute o programa no seu terminal:
    ```sh
    ./JogoDaVida
    ```

2.  **Preparando o Tabuleiro:**
    - Um menu inicial será exibido com opções para popular o tabuleiro.
    - Você pode escolher um padrão pré-definido (como Glider, Blinker, etc.) digitando o número correspondente e pressionando Enter.
    - Ou, para criar seu próprio padrão, escolha a opção **"Modo de edição manual"**. Neste modo:
      - Digite o número da linha e da coluna para adicionar uma célula viva (exemplo: `5 10`).
      - Continue adicionando quantas células desejar.
      - Para finalizar a edição e iniciar a simulação, digite `-1` e pressione Enter.

3.  **Iniciando a Simulação:**
    - Após a preparação, a simulação começará.
    - Pressione a tecla **Enter** para avançar para a próxima geração e observar a evolução das células.

### Regras

O universo do Jogo da Vida é um tabuleiro bidimensional onde cada célula pode estar viva ou morta. O estado de cada célula na geração seguinte é determinado por quatro regras simples, baseadas em suas 8 células vizinhas:

- **Solidão:** Qualquer célula viva com menos de dois vizinhos vivos morre.
- **Sobrevivência:** Qualquer célula viva com dois ou três vizinhos vivos sobrevive para a próxima geração.
- **Superpopulação:** Qualquer célula viva com mais de três vizinhos vivos morre.
- **Nascimento:** Qualquer célula morta com exatamente três vizinhos vivos torna-se uma célula viva.