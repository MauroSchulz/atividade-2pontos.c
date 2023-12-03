#include <stdio.h>


char validaSexo() {
    char sexo;
    do {
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &sexo);
    } while (sexo != 'M' && sexo != 'F');
    return sexo;
}


float validaSalario() {
    float salario;
    do {
        printf("Informe o salário (maior que R$1,00): ");
        scanf("%f", &salario);
    } while (salario <= 1.0);
    return salario;
}

void classificaSalario(float salario, float salarioMinimo) {
    if (salario > salarioMinimo) {
        printf("Salário: R$ %.2f - Acima do salário mínimo\n", salario);
    } else if (salario == salarioMinimo) {
        printf("Salário: R$ %.2f - Igual ao salário mínimo\n", salario);
    } else {
        printf("Salário: R$ %.2f - Abaixo do salário mínimo\n", salario);
    }
}


void mostraClassifica(char sexo, float salario, float salarioMinimo) {
    printf("Sexo: %s\n", (sexo == 'M') ? "Masculino" : "Feminino");
    classificaSalario(salario, salarioMinimo);
    printf("\n");
}

int main() {
    const float salarioMinimo = 1400.0;
    int totalAbaixo = 0, totalAcima = 0;
    char continuar;

    do {
        char sexo = validaSexo();
        float salario = validaSalario();

        mostraClassifica(sexo, salario, salarioMinimo);

        if (salario < salarioMinimo) {
            totalAbaixo++;
        } else {
            totalAcima++;
        }

        printf("Deseja cadastrar outro assalariado? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    printf("\nTotal de assalariados abaixo do salário mínimo: %d\n", totalAbaixo);
    printf("Total de assalariados acima do salário mínimo: %d\n", totalAcima);

    return 0;
}