#include <stdio.h> // biblioteca padrão da linguagem C
#include <stdlib.h> // biblioteca utilizada para poder limpar tela

void tabuleiro(char casas2[3][3]) // função para exibir o tabuleiro
{
    system("cls"); // comando que limpa a tela
    printf(">>> JOGO DA VELHA <<<\n\n\n\n");
    printf("      %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]); // define as variáveis que serão exibidas respectivamente
    printf("     -----------\n"); // parte estética do tabuleiro
    printf("      %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("     -----------\n");
    printf("      %c | %c | %c \n\n\n", casas2[2][0], casas2[2][1], casas2[2][2]);
}

int main() // função principal
{
    char casas[3][3], resp;
    int cont, l, c, vez = 0, i, j;
    do
    {
        cont = 1; // declara variável dentro do laço, pois caso queria jogar novamente, a contagem de jogadas volta a ser 1
        //vez = 0; // declara a variavel dentro do laço para que a jogada sempre comece com o mesmo jogador, no caso o jogador X
        for (i = 0; i <= 2; i++) // inicia a primeira jogada e limpa o tabuleiro
        {
            for (j = 0; j <= 2; j++)
                casas[i][j] = ' '; // deixa os "campos" em branco
        }

        do
        {
            tabuleiro(casas); // retorna a função "tabuleiro" para mostrar o "desenho" do tabuleiroidas

            if (vez % 2 == 0) // quando a "vez" for par, sempre será a vez do jogador X
                printf("\n>>> Jogador: X\n");
            else // quando a "vez" for impar, sempre será a vez do jogador O
                printf("\n>>> Jogador: O\n");

            printf("Digite a linha: "); scanf("%d", &l);
            printf("Digite a coluna: "); scanf("%d", &c);

            if (l < 1 || c < 1 || l > 3 || c > 3) // condições de jogada inválida (digitou um numero errado)
            {
                l = 0;
                c = 0;
            }
            else if (casas[l-1][c-1] != ' ') // condição de jogada em que a casa já está ocupada
            { // o numero de linhas e colunas do jogo varia de 0 a 2, porém o usuário enxerga como do 1 ao 3, por isso tem que diminuir a linha e a coluna por 1
                l = 0;
                c = 0;
            }
            else // condição de jogada valida
            { // condição para ir alternando a vez que os jogadores X e O jogam
                if (vez % 2 == 0)
                    casas[l-1][c-1] = 'X'; // se a vez for par, marca um X na casa
                else
                    casas[l-1][c-1] = 'O'; // se a vez for impar, marca um O na casa
                vez++;
                cont++;
            }

            //condições para ganhar o jogo
            if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X') // jogador X ganha pois marcou todos os campos da primeira linha
                cont = 11; // caso essa condição aconteça o 'cont' passa a ser 11, finalizando assim o laço de repetição e então o jogador X é o vencedor
            if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X') // jogador X ganha pois marcou todos os campos da segunda linha
                cont = 11;
            if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X') // jogador X ganha pois marcou todos os campos da terceira linha
                cont = 11;
            if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X') // jogador X ganha pois marcou todos os campos da primeira coluna
                cont = 11;
            if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X') // jogador X ganha pois marcou todos os campos da segunda coluna
                cont = 11;
            if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X') // jogador X ganha pois marcou todos os campos da terceira coluna
                cont = 11;
            if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X') // jogador X ganha pois marcou todos os campos da diagonal principal
                cont = 11;
            if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X') // jogador X ganha pois marcou todos os campos da diagonal inversa
                cont = 11;

            if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O') // jogador O ganha pois marcou todos os campos da primeira linha
                cont = 12; // caso essa condição aconteça o 'cont' passa a ser 12, finalizando assim o laço de repetição e então o jogador O é o vencedor
            if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O') // jogador O ganha pois marcou todos os campos da segunda linha
                cont = 12;
            if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O') // jogador O ganha pois marcou todos os campos da terceira linha
                cont = 12;
            if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O') // jogador O ganha pois marcou todos os campos da primeira coluna
                cont = 12;
            if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O') // jogador O ganha pois marcou todos os campos da segunda coluna
                cont = 12;
            if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O') // jogador O ganha pois marcou todos os campos da terceira coluna
                cont = 12;
            if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O') // jogador O ganha pois marcou todos os campos da diagonal principal
                cont = 12;
            if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O') // jogador X ganha pois marcou todos os campos da diagonal inversa
                cont = 12;
        }
        while (cont <= 9); // laço que permite realizar 9 jogadas enquanto nenhum jogador ganha

        tabuleiro(casas); // retorna a função tabuleiro novamente para mostrar a última casa ocupada
        if (cont == 10) // se 'cont' for igual a 10 quer dizer que todas as casas do jogo foram preenchidas, então não houve nenhum ganhador
            printf("\n>>> Empate entre o jogador X e o jogador O!\n\n");
        if (cont == 11) // se 'cont' for igual a 11 quer dizer que o jogador X é o vencedor
            printf("\n>>> Vencedor: jogador X!\n\n");
        if (cont == 12) // se 'cont' for igual a 12 quer dizer que o jogador Y é o vencedor
            printf("\n>>> Vencedor: jogador O!\n\n");

        printf("Deseja jogar novamente? [S]IM/[N]AO: ");
        fflush(stdin); // limpa o buffer
        resp = getchar();
    }
    while (resp == 's' || resp == 'S'); // executa o jogo enquanto apertar a tecla 'S'/'s'
}
