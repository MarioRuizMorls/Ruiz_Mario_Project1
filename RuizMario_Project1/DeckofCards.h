#include "Card.h"
#include "CardValues.h"
#include <random>
#include <algorithm>
#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

struct DeckofCards{
    //Creates an object of CardValues
    CardValues print;
    //Creates an array object of Cards 
    Card deck[52];
    
    //Initializes the array of Cards objects called deck
    void MakeDeck(){
        //double for loop to assign properly each Card a unique suit, rank and value 
        for(int col = 0; col <=12; col++)
        {
            for(int row = 0; row <=3; row++)
            {
                deck[(col+(row*13))].rank=print.rankArry[col];
                deck[(col+(row*13))].suit=print.SuitArry[row];
                deck[(col+(row*13))].value =print.valueArry[col];
            }
        }
    };
    //Prints the deck of Cards in four rows, each row corresponding to a suit
    void PrintDeck(){
        for(int col = 0; col <=12; col++)
        {
            for(int row = 0; row <=3; row++){
                
                cout << deck[(col+(row*13))].rank << " of " <<  deck[(col+(row*13))].suit << " "<< deck[(col+(row*13))].value<< ", ";
            }
            cout <<endl;
        }
    };
   
    //static function used to compare card values in order to sort deck
    static bool compare(Card a, Card b){
    return a.value > b.value;//if first card is higher in value returns true otherwise false
    
    //Shuffles the entire deck of Cards
    }
     void ShuffleDeck()
    {
        int seed = time(0);
        srand(seed);//creates true randomization
            shuffle(deck, deck+52,
                    default_random_engine(seed));
    }
     //sorts the entire deck in descending order 
     void SortDeck(){
         sort(deck, deck + sizeof(deck) / sizeof(deck[0]), compare);
     }
};
#endif /* DECKOFCARDS_H */

