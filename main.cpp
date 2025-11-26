#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int passwordGenerator(){
    srand(time(NULL));

    int d1 = (rand() % 6) + 1;
    int d2 = (rand() % 6) + 1;
    int d3 = (rand() % 6) + 1;
    int d4 = (rand() % 6) + 1;

    return d1 * 1000 + d2 * 100 + d3 * 10 + d4;
}

void interface() {
    cout << "=========================================\n";
    cout << "         J O G O    D A    S E N H A         \n";
    cout << "=========================================\n";
    cout << " Bem-vindo ao desafio!\n\n";
    cout << " O computador gerou uma senha secreta com 4 digitos (1 a 6).\n";
    cout << " MAX TENTATIVAS: 10\n\n";
    cout << " Legenda:\n";
    cout << " o : Numero correto na posicao correta.\n";
    cout << " x : Numero existe, mas na posicao errada.\n";
    cout << " _ : Numero nao existe ou ja foi contabilizado.\n";
    cout << "=========================================\n" << endl;
}

bool entryValidator(int guess) {
    if (guess < 1000 || guess > 9999) return false;

    int dg1 = guess / 1000;
    int dg2 = (guess % 1000) / 100;
    int dg3 = (guess % 100) / 10;
    int dg4 = guess % 10;

    return (dg1 >= 1 && dg1 <= 6 &&
            dg2 >= 1 && dg2 <= 6 &&
            dg3 >= 1 && dg3 <= 6 &&
            dg4 >= 1 && dg4 <= 6);
}

void gameFunc(){
    int guess;
    int password = passwordGenerator();

    int dg1Pass = password / 1000;
    int dg2Pass = (password % 1000) / 100;
    int dg3Pass = (password % 100) / 10; 
    int dg4Pass = password % 10;  

    bool used1, used2, used3, used4;
    char r1, r2, r3, r4; 

    for (int i = 1; i <= 10; i++){

        used1 = used2 = used3 = used4 = false;
        r1 = '_'; r2 = '_'; r3 = '_'; r4 = '_';

        cout << "----------- " << i << " TURNO -----------" << endl;
        cout << "Digite a senha >> ";
        cin >> guess;

        if (!entryValidator(guess)){
            i--;
            cout << "Jogada invalida! Use 4 digitos de 1 a 6." << endl;
            continue;
        }

        int dg1Guess = guess / 1000;
        int dg2Guess = (guess % 1000) / 100;
        int dg3Guess = (guess % 100) / 10; 
        int dg4Guess = guess % 10;  

        if (dg1Guess == dg1Pass){
            r1 = 'o';
            used1 = true;
        }
        if (dg2Guess == dg2Pass) {
            r2 = 'o';
            used2 = true;
        }
        if (dg3Guess == dg3Pass) {
            r3 = 'o';
            used3 = true;
        }
        if (dg4Guess == dg4Pass) {
            r4 = 'o';
            used4 = true;
        }        
        
        if (r1 != 'o') {
            if (dg1Guess == dg2Pass && !used2) {
                r1 = 'x'; 
                used2 = true;
            } else if (dg1Guess == dg3Pass && !used3) {
                r1 = 'x'; 
                used3 = true;
            } else if (dg1Guess == dg4Pass && !used4) {
                r1 = 'x'; 
                used4 = true;
            }
        }

        if (r2 != 'o') {
            if (dg2Guess == dg1Pass && !used1) {
                r2 = 'x'; 
                used1 = true;
            } else if (dg2Guess == dg3Pass && !used3) {
                r2 = 'x'; 
                used3 = true;
            } else if (dg2Guess == dg4Pass && !used4) {
                r2 = 'x'; 
                used4 = true;
            }
        }

        if (r3 != 'o') {
            if (dg3Guess == dg1Pass && !used1) {
                r3 = 'x'; 
                used1 = true;
            } else if (dg3Guess == dg2Pass && !used2) {
                r3 = 'x'; 
                used2 = true;
            } else if (dg3Guess == dg4Pass && !used4) {
                r3 = 'x'; 
                used4 = true;
            }
        }

        if (r4 != 'o') {
            if (dg4Guess == dg1Pass && !used1) {
                r4 = 'x'; 
                used1 = true;
            } else if (dg4Guess == dg2Pass && !used2) {
                r4 = 'x'; 
                used2 = true;
            } else if (dg4Guess == dg3Pass && !used3) {
                r4 = 'x'; 
                used3 = true;
            }
        }        

        cout << "Resultado: " << r1 << r2 << r3 << r4 << endl << endl;

        if (r1 == 'o' && r2 == 'o' && r3 == 'o' && r4 == 'o'){
            cout << "PARABENS! VOCE VENCEU!" << endl;
            break;
        } else if (i == 10){
            cout << "Voce perdeu! A senha era: " << password << endl;
        }
    }
}

void startGame(){
    interface();
    gameFunc();
}

int main(){
    startGame();
    return 0;
}