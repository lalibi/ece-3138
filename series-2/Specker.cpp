#include <iostream>
#include <stdexcept>

using namespace std;

class Move {
  public:
    // Constructor
    // Take sc coins from heap sh and put tc coins to heap th.
    Move(int sh, int sc, int th, int tc) {
        source_heap = sh;
        source_coins = sc;
        target_heap = th;
        target_coins = tc;
    }

    // Getters
    int getSource() const {
        return source_heap;
    }

    int getSourceCoins() const {
        return source_coins;
    }

    int getTarget() const {
        return target_heap;
    }

    int getTargetCoins() const {
        return target_coins;
    }

    // Overloaded insertion operator
    friend ostream &operator<<(ostream &out, const Move &move) {

        // takes 9 coins from heap 2 and puts 8 coins to heap 0
        // takes 3 coins from heap 1 and puts nothing
        out << "takes " << move.source_coins << " coins from heap " << move.source_heap
            << " and puts ";

        if (move.target_coins == 0) {
            out << "nothing";
        } else {
            out << move.target_coins << " coins to heap " << move.target_heap;
        }

        return out;
    }

  private:
    int source_heap;
    int source_coins;

    int target_heap;
    int target_coins;
};

class State {
  public:
    // State with h heaps, where the i-th heap starts with c[i] coins.
    // A total of n players are in the game, numbered from 0 to n-1,
    // and player 0 is the first to play.
    State(int h, const int c[], int n) {
        coins = new int[h];

        for (int i = 0; i < h; i++) {
            coins[i] = c[i];
        }

        number_of_heaps = h;
        number_of_players = n;

        next_player = 0;
    }

    ~State() {
        delete[] coins;
    }

    void next(const Move &move) throw(logic_error) {
        // Logical errors
        if (move.getSource() < 0 || move.getSource() >= number_of_heaps)
            throw logic_error("invalid heap");
        if (move.getTarget() < 0 || move.getTarget() >= number_of_heaps)
            throw logic_error("invalid heap");

        if (number_of_players < 0) throw logic_error("number of players cannot be negative");

        if (move.getSourceCoins() < 0) throw logic_error("source coins cannot be negative");
        if (move.getTargetCoins() < 0) throw logic_error("target coins cannot be negative");
        if (move.getTargetCoins() >= move.getSourceCoins())
            throw logic_error("target coins cannot be equal or greater than source coins");
        if (move.getSourceCoins() > coins[move.getSource()])
            throw logic_error("cannot move more coins than the heap has");

        // Move coins
        coins[move.getSource()] -= move.getSourceCoins();
        coins[move.getTarget()] += move.getTargetCoins();

        next_player = (next_player + 1) % number_of_players;
    }

    bool winning() const {
        for (int i = 0; i < number_of_heaps; i++) {
            if (coins[i] != 0) return false;
        }

        return true;
    }

    int getHeaps() const {
        return number_of_heaps;
    }

    int getCoins(int h) const throw(logic_error) {
        if (h < 0) throw logic_error("heap cannot be negative");
        if (h >= number_of_heaps) throw logic_error("heap cannot be greater than number of heaps");

        return coins[h];
    }

    int getPlayers() const {
        return number_of_players;
    }

    int getPlaying() const {
        return next_player;
    }

    friend ostream &operator<<(ostream &out, const State &state) {
        // 0, 20, 17 with 0/5 playing next

        for (int i = 0; i < state.number_of_heaps; i++) {
            if (i > 0) out << ", ";
            out << state.coins[i];
        }

        out << " with " << state.next_player << "/" << state.number_of_players << " playing next";

        return out;
    }

  private:
    int *coins;
    int number_of_heaps;
    int number_of_players;
    int next_player;
};
