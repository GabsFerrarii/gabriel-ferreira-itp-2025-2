# Introdução a Técnicas de Programação - Unidade 1

**Aluno**: Gabriel Ferreira Cavalcante  
**Matrícula**: 20250035736  
**Período**: 2025.2

## 📁 Estrutura do Projeto
- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo

## 🚀 Projeto: Jogo Da Vida de Conway em C
**Descrição**: Este projeto é uma implementação do clássico autômato celular "Jogo da Vida" de John Conway, desenvolvido inteiramente na linguagem C. O programa simula a evolução de uma colônia de células em um tabuleiro bidimensional, onde o usuário pode definir o estado inicial e observar as gerações se desenvolverem de acordo com um conjunto de regras simples. A interação é feita via linha de comando (CLI).  
**Repositório**: [Gabriel-Ferreira-Itp-2025-2](https://github.com/GabsFerrarii/gabriel-ferreira-itp-2025-2)  
**Vídeo de Demonstração**: [Entrega da U1](https://youtu.be/AHrKrddTh1o)

### Funcionalidades Implementadas:
- Tabuleiro Configurável: As dimensões do tabuleiro (altura e largura) podem ser facilmente alteradas através de constantes no código.

- Modo de Edição Interativo: Permite ao usuário definir o estado inicial do tabuleiro, adicionando células vivas em coordenadas específicas antes de iniciar a simulação.

- Simulação de Gerações: O programa calcula e exibe a evolução das células geração por geração, seguindo fielmente as regras clássicas do Jogo da Vida.

- Visualização no Terminal: A cada geração, o estado do tabuleiro é limpo e redesenhado no terminal, criando uma animação baseada em texto.

- Controle de Ritmo: A simulação pausa a cada geração, aguardando que o usuário pressione "Enter" para continuar, permitindo uma análise calma de cada etapa.

### Conceitos da U1 Aplicados

- **Estruturas condicionais:** Foram usadas de forma crucial em várias partes do código:
  - Na função `calcularProximaGeracao` para aplicar as 4 regras do jogo (sobrevivência, morte ou nascimento) com base no estado da célula e no número de vizinhos.
  - Na função `contarVizinhosVivos` para garantir que a contagem de vizinhos não acesse posições fora dos limites do tabuleiro.
  - Na função `inicializarTabuleiro` para validar se as coordenadas inseridas pelo usuário estão dentro do tabuleiro.

- **Estruturas de repetição:** Essenciais para o funcionamento do projeto:
  - Laços `for` aninhados são a base de quase todas as funções, usados para percorrer cada célula do tabuleiro para inicializar, imprimir, contar vizinhos e calcular a próxima geração.
  - Um laço `while` foi utilizado no modo de edição (`inicializarTabuleiro`) para permitir que o usuário adicione quantas células quiser, e também na função `esperarEnter` para limpar o buffer de entrada.

- **Vetores:** A estrutura de dados central do projeto é um **vetor bidimensional** (matriz) de inteiros (`int tabuleiro[ALTURA][LARGURA]`).
  - Ele armazena o estado de cada célula (0 para morta, 1 para viva).
  - Um segundo vetor bidimensional (`proximoTabuleiro`) é usado como um buffer para calcular o estado da geração seguinte, resolvendo o desafio da atualização "simultânea" de todas as células.

- **Funções:** O código foi amplamente modularizado com **6 funções** além da `main`, cada uma com uma responsabilidade única para garantir a organização e a clareza:
  - `inicializarTabuleiro`: Responsável por zerar o tabuleiro e gerenciar a interface com o usuário para definir o estado inicial.
  - `imprimirTabuleiro`: Limpa a tela e exibe o tabuleiro formatado.
  - `contarVizinhosVivos`: Isola a lógica complexa de verificar os 8 vizinhos de uma célula, tratando os casos de borda.
  - `calcularProximaGeracao`: Aplica as regras do Jogo da Vida para preencher o tabuleiro da próxima geração.
  - `copiarTabuleiro`: Atualiza o tabuleiro principal com os dados da nova geração.
  - `esperarEnter`: Pausa a execução para melhorar a experiência do usuário.

## 📚 Listas de Exercícios

### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos

### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código
- ✅ Questões 5-11: Implementações

### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ✅ Problema 3: Pousando a sonda espacial

### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido

## 🎯 Principais Aprendizados
Já venho de um contexto com base em programação, pois estava em um curso técnico de informática, mas entrar no BTI e encarar a linguagem C na disciplina de ITP aprofundou muitos conceitos básicos para mim! Sempre tive um pouco de interesse no Jogo da Vida de Conway, então desenvolver esse projeto usando os importantes conceitos da disciplina foi divertido! Essa base é, definitivamente, muito importante.

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows
- **Compilador**: GCC versão `15.2.0`
- **Editor**: VS Code
