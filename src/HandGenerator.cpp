#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "../include/HandGenerator.h" // Pastikan path ini sesuai dengan struktur foldermu

Hand HandGenerator::generateHand()
{
    std::cout << "Generating random hand...\n";
    Hand hand;

    // 1. Membuat Deck (52 kartu standar remi)
    std::vector<Card> deck;
    char suits[] = {'H', 'D', 'C', 'S'}; // H=Hearts, D=Diamonds, C=Clubs, S=Spades

    for (char suit : suits) {
        for (int rank = 2; rank <= 14; ++rank) { // Rank 2 (Dua) sampai 14 (Ace)
            deck.push_back({rank, suit});
        }
    }

    // 2. Mengocok Deck secara acak
    std::random_device rd;  // Seed acak dari hardware
    std::mt19937 g(rd());   // Generator angka acak (Mersenne Twister)
    std::shuffle(deck.begin(), deck.end(), g); // Proses mengocok vektor deck

    // 3. Mengambil 8 kartu teratas (Standar starting hand game Balatro)
    // Jika dosenmu mewajibkan 5 kartu saja, cukup ubah angka 8 di bawah menjadi 5
    for (int i = 0; i < 8; ++i) {
        hand.cards.push_back(deck[i]);
        
        // (Opsional) Menampilkan kartu yang didapatkan ke terminal agar mudah di-debug
        std::cout << "Card drawn: [" << deck[i].rank << deck[i].suit << "]\n";
    }

    return hand;
}