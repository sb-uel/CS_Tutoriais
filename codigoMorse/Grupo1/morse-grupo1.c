#include <stdio.h>// Biblioteca base para os comandos em linguagem C.
#include <string.h>// Biblioteca que possibilita manipular melhor frases em linguagem C.
#include <ctype.h> // Biblioteca que facilita manipular caracteres na linguagem C.

// Função para codificar.
void codificarCaractere(char c) { 
    const char *morse[] = { //array de strings.
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--..",   // Caracteres em morse.
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
        "---..", "----."    //Numeros em morse.
    };
    
    if (c >= 'A' && c <= 'Z') { //If para verificar o caractere e colocar seu correspondente.
        printf("%s ", morse[c - 'A']); 
    } else if (c >= '0' && c <= '9') { //If para analisar se for um número.
        printf("%s ", morse[c - '0' + 26]);
    } else if (c == ' ') { // If quando o caractere for espaço.
        printf(" / "); // Imp: na hora de printar na tela o espaço, colocamos uma barra entre os espaços.
    }  
    
}

// Função para decodificar 
void decodificarcaractere(const char *codigoMorse) {
    const char *morse[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--..", // Caracteres em morse.
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
        "---..", "----.","/" // Numeros em morse.
    };
    const char *alfanumerico[] = { // Correspondentes do morse em alfanumerico.
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
        "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
        "U", "V", "W", "X", "Y", "Z",
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"," "
        
        };
    
    char *token = strtok((char *)codigoMorse, " "); // Divide a string em subtokens e para quando detecta um espaço(delimitador).

    while (token != NULL) { // Enquanto nao chegar no \0.
        for (int i = 0; i < 37; i++) { // Percorre a sequencia de caracteres em morse.
            if (strcmp(token, morse[i]) == 0) { // Busca o caractere correspondente.
                printf("%s", alfanumerico[i]); 
                break;
            }
        }// Fim do loop.
        
        token = strtok(NULL, " "); // Busca o proximo token.
        
    }
    printf("\n");// Pula uma linha.
}

int main() {
    char mensagem[256]; // Maximo de 256 caracteres.
    int escolha;
    
    printf("Escolha:\n");     // Escolha se quer codificar ou decodificar.
    printf("1. Codificar em codigo Morse\n");
    printf("2. Decodificar codigo Morse\n");
    scanf("%d", &escolha);
    getchar(); // Limpar a entrada.

    if (escolha == 1) {
        printf("Digite uma mensagem para codificar em codigo Morse: ");
        fgets(mensagem, sizeof(mensagem), stdin);
        mensagem[strlen(mensagem) - 1] = '\0';  // Remove o caractere de nova linha.

        printf("Mensagem codificada em codigo Morse: "); 
        for (int i = 0; mensagem[i]; i++) {     //Chama a funcao de decodificar em um loop.
            codificarCaractere(toupper(mensagem[i]));// Deixa a mensagem em maiusculo e printa ela codificada.
        }
        printf("\n");
    } else if (escolha == 2) {
        printf("Seguindo como este exemplo: (... / --- / ... )\n");
        printf("Digite um codigo Morse (com espaco e uma barra entre as palavras) para decodificar: ");
        fgets(mensagem, sizeof(mensagem), stdin);
        mensagem[strlen(mensagem) - 1] = '\0';  // Remove o caractere de nova linha.

        printf("Mensagem decodificada: "); 
        decodificarcaractere(mensagem); // Chama a função e printa a mensagem decodificada.
    } else {
        printf("Opçao invalida.\n");
    }

    return 0;
}