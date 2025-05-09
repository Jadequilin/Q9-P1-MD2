#include <stdio.h>

// Função para calcular o máximo divisor comum (MDC)
int mdc(int a, int b) {
    printf("   MDC(%d, %d) = ", a, b); // Mostrar valores iniciais
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        printf("MDC(%d, %d) -> ", a, b); // Passo intermediário
    }
    printf("%d\n", a); // MDC final
    return a;
}

// Função para verificar se um número é primo
int eh_primo(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

// Função para calcular o inverso modular usando o algoritmo estendido de Euclides
int inverso_modular(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    printf("\n2. Calculando o inverso modular de %d em Zn (%d)...\n", a, m);
    
    if (m == 1) return 0;
    
    // Mostrar o passo a passo da divisão sucessiva
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
        
        // Exibir cada iteração
        printf("   Passo: q = %d, m = %d, a = %d, x0 = %d, x1 = %d\n", q, m, a, x0, x1);
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Função para calcular a função totiente de Euler φ(n)
int totient_euler(int n) {
    if (n == 1) return 1;
    if (eh_primo(n)) return n - 1;
    
    int result = n;
    
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    
    if (n > 1) {
        result -= result / n;
    }
    
    return result;
}

// Função para exponenciação modular eficiente
int exp_mod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    
    return result;
}

int main() {
    int H, G, n, x, n1;

    printf("=== SISTEMA DE VERIFICACAO MODULAR ===\n");
    printf("=== Disciplina: Matematica Discreta II ===\n");
    printf("=== Professora: Cristiane Loesch de Souza Costa ===\n");
    printf("=== Aluno: Joao Pedro Araujo de Freitas Lyra, Matricula: 232003661 ===\n\n");
    
    printf("=== Sistema de Verificação Modular ===\n");
    printf("Digite o valor de H (para calcular a base a = H/G mod n): ");
    scanf("%d", &H);
    printf("Digite o valor de G (para calcular a base a = H/G mod n): ");
    scanf("%d", &G);
    printf("Digite o valor de n (para calcular a base a = H/G mod n): ");
    scanf("%d", &n);
    printf("Digite o expoente x: ");
    scanf("%d", &x);
    printf("Digite o modulo n1: ");
    scanf("%d", &n1);
    
    printf("\n=== PASSO A PASSO ===\n");
    
    // Passo 1: Verificar se G e n são coprimos
    printf("\n1. Verificando se G (%d) e n (%d) sao coprimos (MDC(G,n) = 1)...\n", G, n);
    int gcd_gn = mdc(G, n);
    
    if (gcd_gn != 1) {
        printf("   ERRO: G e n nao sao coprimos (MDC = %d). Divisao modular nao eh possivel.\n", gcd_gn);
        return 1;
    } else {
        printf("   OK: G e n sao coprimos (MDC = 1). Podemos prosseguir.\n");
    }
    
    // Passo 2: Calcular o inverso de G em Zn
    printf("\n2. Calculando o inverso modular de G (%d) modulo n (%d)...\n", G, n);
    int inv_G = inverso_modular(G, n);
    printf("   O inverso modular de %d eh: %d\n", G, inv_G);
    
    // Passo 3: Calcular a base a = H * inv(G) mod n
    printf("\n3. Calculando a base a = H * inv(G) mod n...\n");
    int a = (H % n) * (inv_G % n) % n;
    printf("   a = (%d * %d) mod %d = %d\n", H, inv_G, n, a);
    
    // Passo 4: Verificar se a e n1 são coprimos
    printf("\n4. Verificando se a (%d) e n1 (%d) sao coprimos...\n", a, n1);
    int gcd_an1 = mdc(a, n1);
    
    if (gcd_an1 != 1) {
        printf("   Erro: %d e %d nao sao coprimos (MDC = %d). Nao eh possivel aplicar Totiente de Euler, ou Pequeno teorema de Fermat.\n", a, n1, gcd_an1);
        return 1;
    } else {
        printf("   OK: %d e %d sao coprimos (MDC = 1).\n", a, n1);
    }
    
    // Passo 5: Verificar se n1 é primo
    printf("\n5. Verificando se n1 (%d) eh primo...\n", n1);
    int primo = eh_primo(n1);
    
    if (primo) {
        printf("   n1 eh primo. Aplicaremos o Pequeno Teorema de Fermat.\n");
    } else {
        printf("   n1 nao eh primo. Aplicaremos o Teorema de Euler.\n");
    }
    
    // Passo 6/7: Aplicar Fermat ou Euler
    int q;
    int x1 = (primo) ? n1 - 1 : totient_euler(n1);
    if (primo) {
        q = x1; // pequeno teorema de Fermat
        printf("\n6. Aplicando Pequeno Teorema de Fermat:\n");
        printf("   Como %d eh primo, %d^%d eh congruente a 1 mod %d\n", n1, a, q, n1);
    } else {
        int phi = x1;
        printf("\n7. Aplicando Teorema de Euler:\n");
        printf("  phi(%d) = %d\n", n1, phi);
        printf("  Entao, %d^%d eh congruente a 1 mod %d\n", a, phi, n1);
    }
    
    // Passo 8: Decompor o expoente na forma x = x1*q + r
    printf("\n8. Decompondo o expoente x = x1*q + r...\n");
    int r = x % x1; // Aqui, x1 já foi calculado corretamente antes.
    int q2 = x / x1; // Calcular q com o valor correto de x1
    printf("   x = %d = %d*%d + %d\n", x, x1, q2, r);
    
    // Passo 9: Reescrever a^x como (((a^x1)^q mod n1) * (a^r mod n1)) mod n1
    printf("\n9. %d^%d congruente a (((%d^%d)^%d mod %d) * (%d^%d mod %d)) mod %d...\n", a, x1, a, x1, q2, n1, a, r, n1, n1);

    
    // Passo 10: Calcular os valores intermediários
    printf("\n10. Calculando os valores intermediarios...\n");
    // Calcular a^x1 mod n1
    int a_x1 = exp_mod(a, x1, n1);  // a^x1 mod n1
    printf("   %d^%d mod %d = %d\n", a, x1, n1, a_x1);

    // Calcular (a^x1)^q mod n1
    int a_x1_q = exp_mod(a_x1, q2, n1);  // (a^x1)^q mod n1
    printf("   (%d^%d mod %d)^%d mod %d = %d\n", a, x1, n1, q2, n1, a_x1_q);

    // Calcular a^r mod n1
    int a_r = exp_mod(a, r, n1);  // a^r mod n1
    printf("   %d^%d mod %d = %d\n",a, r, n1, a_r);

    // Passo 11: Combinar os resultados
    printf("\n11. Combinando os resultados...\n");
    int resultado = (a_x1_q * a_r) % n1;
    printf("   Resultado final: (((%d^%d)^%d mod %d) * (%d^%d mod %d)) mod %d = %d\n", a, x1, q2, n1, a, r, n1, n1, resultado);

    return 0;
}
