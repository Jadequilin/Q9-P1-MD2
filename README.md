==================================================
        SISTEMA DE VERIFICAÇÃO MODULAR
          (MD2questao9.c)
==================================================

Disciplina: Matemática Discreta II
Professora: Cristiane Loesch de Souza Costa
Aluno: Joao Pedro Araujo de Freitas Lyra
Matrícula: 232003661

--------------------------------------------------
► DESCRIÇÃO DO PROJETO:
--------------------------------------------------
Implementação da Questão 9 da P1 de Matemática Discreta II,
calculando (H/G)^x mod n1 através de:
- Divisão modular (cálculo de a = H/G mod n)
- Verificação de coprimalidade (MDC)
- Aplicação do Teorema de Euler/Fermat
- Exponenciação modular eficiente

--------------------------------------------------
► ARQUIVO PRINCIPAL:
--------------------------------------------------
Nome: MD2questao9.c
Tipo: Código fonte em C
Compilação: gcc MD2questao9.c -o verificacao_modular

--------------------------------------------------
► FUNCIONALIDADES IMPLEMENTADAS:
--------------------------------------------------
1. Cálculo do MDC usando Algoritmo de Euclides
2. Verificação de números primos
3. Cálculo do inverso modular
4. Implementação da função φ(n) (Totiente de Euler)
5. Exponenciação modular otimizada
6. Verificação de todas as condições matemáticas:
   - MDC(G,n) = 1 para existência do inverso
   - MDC(a,n1) = 1 para aplicar Euler/Fermat

--------------------------------------------------
► MODO DE USAR:
--------------------------------------------------
1. Compile: gcc MD2questao9.c -o questao9
2. Execute: ./questao9
3. Insira os valores quando solicitado:
   - H (numerador)
   - G (denominador)
   - n (módulo da divisão)
   - x (expoente)
   - n1 (módulo final)

--------------------------------------------------
► EXEMPLO DE EXECUÇÃO:
--------------------------------------------------
Entrada:
H = 38, G = 79, n = 252, x = 5, n1 = 11

Saída:
saida : (((26^10)^0 mod 11) * (26^5 mod 11)) mod 11 = 1

--------------------------------------------------
► DETALHES DE IMPLEMENTAÇÃO:
--------------------------------------------------
- O código mostra cada passo matemático detalhadamente
- Inclui todas as verificações exigidas no enunciado
- Implementa corretamente os 11 passos solicitados:
  1. Verifica coprimalidade G e n
  2. Calcula inverso modular
  3. Calcula base a = H/G mod n
  4. Verifica coprimalidade a e n1
  5. Verifica primalidade de n1
  6. Aplica Fermat (se primo) ou Euler
  7. Calcula φ(n1) quando necessário
  8. Decompõe o expoente x = q*x1 + r
  9. Reescreve a função a^x  ≡ (((a^x1)^q mod n1) * (a^r mod n1)) mod n1
  10. Calcula valores intermediarios: a^x1 mod n1, ((a^x1 mod n1)^q mod n1), (a^r mod n1) mod n1
  11. Calcula o resultado final a^x  ≡ (((a^x1)^q mod n1) * (a^r mod n1)) mod n1 = resultado

--------------------------------------------------
► OBSERVAÇÕES:
--------------------------------------------------
- Código desenvolvido como parte da avaliação P1
- Todos os cálculos são validados matematicamente
- Saída formatada para fácil compreensão
- Implementação 100% em C sem bibliotecas externas

==================================================
        FIM DO README
==================================================
