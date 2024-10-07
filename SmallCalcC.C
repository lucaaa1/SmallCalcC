#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double auswertung(const char* funktions_input, double x) {
    double result = 0.0;

    // Trigonometrische Funktionen
    if (strstr(funktions_input, "sin") != NULL) {
        result += sin(x);
    }
    if (strstr(funktions_input, "cos") != NULL) {
        result += cos(x);
    }
    if (strstr(funktions_input, "tan") != NULL) {
        result += tan(x);
    }

    // Logarithmische Funktionen
    if (strstr(funktions_input, "log") != NULL) {
        result += log(x);
    }

    // Exponentialfunktion
    if (strstr(funktions_input, "exp") != NULL) {
        result += exp(x);
    }

    // Quadratwurzel
    if (strstr(funktions_input, "sqrt") != NULL) {
        result += sqrt(x);
    }

    // Potenzfunktion
    if (strstr(funktions_input, "^") != NULL) {
        // Beispiel: x^2
        char* ptr = strstr(funktions_input, "^");
        double exponent = atof(ptr + 1);
        result += pow(x, exponent);
    }

    // Addition und weitere Operationen
    if (strstr(funktions_input, "+") != NULL) {
        result += 1.0; // Beispiel: +1
    }

    return result;
}

int main() {
    char funktions_input[100];
    double x_min, x_max, step;

    printf("f(x): "); // Beispiel: log, cos, sin....
    scanf("%99s", funktions_input);  // Verhindert Pufferüberlauf
    printf("minimalen Wert von x: ");
    scanf("%lf", &x_min);
    printf("maximalen Wert von x: ");
    scanf("%lf", &x_max);
    printf("Schrittweite: ");
    scanf("%lf", &step);

    if (step <= 0) {
        fprintf(stderr, "Fehler: Schrittweite muss positiv sein.\n"); // Schrittweise nicht positiv
        return 1;
    }

    printf("\nErgebnisse:\n");
    for (double x = x_min; x <= x_max; x += step) {
        if (x <= 0 && (strstr(funktions_input, "log") != NULL || strstr(funktions_input, "sqrt") != NULL)) {
            printf("f(%.2f) ist nicht definiert.\n", x);
            continue;
        }
        double y = auswertung(funktions_input, x);
        printf("f(%.2f) = %.2f\n", x, y);
    }

    return 0;
}
