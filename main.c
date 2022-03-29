#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int value;
    char hand[20];
    int P_n_of_cards;
    int P_has_ace; //boolean
}Player;

typedef struct{
    int n_of_cards;
    char deck_letters[52];
    int deck_numbers[52];
    Player Player1;
    Player Player2;
    Player Dealer;
}Game;

int roll_card_number(int n){
    srand(25);
    int card_n=(int)rand() % n;

    return card_n;
};

void cleanup_deck(Game* Game, int card_number){
    for(int i=0;i+card_number < Game->n_of_cards;i++){
        Game->deck_letters[card_number+i]=Game->deck_letters[card_number+1+i];
        Game->deck_numbers[card_number+i]=Game->deck_numbers[card_number+1+i];
    }
}


void roll_value(Game* Game, Player* Player,int card_number){
    if(Game->deck_numbers[card_number]==11){
        if(Player->value+Game->deck_numbers[card_number]>21){
            Player->value++;
        }
        else{
            Player->value=Player->value+Game->deck_numbers[card_number];
            Player->P_has_ace=1;
        }
    }
        else{
            Player->value=Player->value+Game->deck_numbers[card_number];
        }
}

void roll_card(Game* Game,Player* Player){
    int card_number=roll_card_number(Game->n_of_cards);
    roll_value(Game, Player, card_number);
    Player->hand[Player->P_n_of_cards]=Game->deck_letters[card_number];
    cleanup_deck(Game,card_number);
    Game->n_of_cards--;
    Player->P_n_of_cards++;
};


int main()
{
    Game Game = {{52},{'2','2','2','2','3','3','3','3','4','4','4','4','5','5','5','5','6','6','6','6','7','7','7','7','8','8','8','8','9','9','9','9','1','1','1','1','J','J','J','J','Q','Q','Q','Q','K','K','K','K','A','A','A','A'},{2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11},{{0},{},{0}},{{0},{},{0}},{{0},{},{0}}};

    roll_card(&Game, &Game.Dealer);
    printf("rolled Deaaler number is %d.",Game.Dealer.value);




        for(int loop = 0; loop < 52; loop++){
      printf("%d ", Game.deck_numbers[loop]);

        }

                for(int loop = 0; loop < 52; loop++){
      printf("%d ", Game.deck_letters[loop]);

        }
        while(1){};

}
