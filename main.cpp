#include <iostream>
#include <time.h>
using namespace std;

// card
struct struct_card{
    int value = 0; // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    char color = 32; // red or black => r, b
    char suit = 32; //  clubs, diamonds, hearts or spades => c, d, h, s
};

// deck
struct struct_deck{
    struct_card card[52]={};
};

// fucntions
void print_deck(struct_deck deck);
struct_deck reset_deck(struct_deck deck);
struct_deck mix_deck(struct_deck deck);

int main(){
    cout<<"testing..."<<endl;
    // program setup
    srand(time(0));


    // deck set up
    struct_deck deck; // create deck
    deck = reset_deck(deck); // reset deck
    print_deck(deck);

    // deck mix up
    deck = mix_deck(deck);
    cout<<endl;
    print_deck(deck);


    cout<<endl;
    return 0;
}

// FUNCTIONS
void print_deck(struct_deck deck){
    int counter=1;
    for(int i=0; i<52 ; i++){
        cout<<"[";
        cout<<deck.card[i].suit<<", ";
        cout<<deck.card[i].color<<", ";
        if(deck.card[i].value<10)cout<<" "; // for better print
        cout<<deck.card[i].value<<"] ";

        // every 13 card new row..
        if(counter==13){
            cout<<endl;
            counter=0;
        }
        counter+=1;
    }
}
struct_deck reset_deck(struct_deck deck){
    // here i change deck
    int value=1;
    int suits_count=0;

    for(int i=0; i<52 ; i++){

        // set card
        deck.card[i].value=value; // set value

        if(suits_count==0){
            deck.card[i].suit='c';
            deck.card[i].color='b';
        }
        if(suits_count==1){
            deck.card[i].suit='d';
            deck.card[i].color='r';
        }
        if(suits_count==2){
            deck.card[i].suit='h';
            deck.card[i].color='r';
        }
        if(suits_count==3){
            deck.card[i].suit='s';
            deck.card[i].color='b';
        }


        if(value==13){
            value=0;
            suits_count+=1;
            cout<<endl;
        }
        value+=1;
    }

    return deck; // return deck ofc
}
struct_deck mix_deck(struct_deck deck){

    for(int i=0; i<52 ; i++){
        // go for every card
        int swap_with=rand()%52; // got random card to swap positions with i card
        struct_card temporarily_card;
 
        // set tenporarily_card to i card values..
        temporarily_card = deck.card[i];

        // set i card to random card values..
        deck.card[i]=deck.card[swap_with];

        // set temporarily card on random card position..
        deck.card[swap_with]=temporarily_card;
    }

    return deck; // return deck ofc
}