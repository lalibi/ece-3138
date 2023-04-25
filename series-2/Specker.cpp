#include <iostream>
#include <limits>
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

        current_player = 0;
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

        current_player = (current_player + 1) % number_of_players;
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
        return current_player;
    }

    friend ostream &operator<<(ostream &out, const State &state) {
        // 0, 20, 17 with 0/5 playing next

        for (int i = 0; i < state.number_of_heaps; i++) {
            if (i > 0) out << ", ";
            out << state.coins[i];
        }

        out << " with " << state.current_player << "/" << state.number_of_players
            << " playing next";

        return out;
    }

  private:
    int *coins;
    int number_of_heaps;
    int number_of_players;
    int current_player;
};

class Player {
  public:
    Player(const string &n) {
        name = n;
    }

    virtual const string &getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream &operator<<(ostream &out, const Player &player) {
        out << player.type << " player " << player.name;
        return out;
    }

  protected:
    string type;

  private:
    string name;
};

class GreedyPlayer : public Player {
  public:
    GreedyPlayer(const string &n) : Player(n) {
        type = "Greedy";
    }

    const string &getType() const {
        return type;
    }

    Move play(const State &s) {
        int max_coins = s.getCoins(0);
        int max_heap = 0;

        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > max_coins) {
                max_coins = s.getCoins(i);
                max_heap = i;
            }
        }

        return Move(max_heap, max_coins, 0, 0);
    }
};

class SpartanPlayer : public Player {
  public:
    SpartanPlayer(const string &n) : Player(n) {
        type = "Spartan";
    }

    const string &getType() const {
        return type;
    }

    Move play(const State &s) {
        int max_coins = s.getCoins(0);
        int max_heap = 0;

        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > max_coins) {
                max_coins = s.getCoins(i);
                max_heap = i;
            }
        }

        return Move(max_heap, 1, 0, 0);
    }
};

class SneakyPlayer : public Player {
  public:
    SneakyPlayer(const string &n) : Player(n) {
        type = "Sneaky";
    }

    const string &getType() const {
        return type;
    }

    Move play(const State &s) {
        int min_coins = INT_MAX;
        int min_heap = 0;

        for (int i = 0; i < s.getHeaps(); i++) {
            int c = s.getCoins(i);
            if (c > 0 && c < min_coins) {
                min_coins = c;
                min_heap = i;
            }
        }

        return Move(min_heap, min_coins, 0, 0);
    }
};

class RighteousPlayer : public Player {
  public:
    RighteousPlayer(const string &n) : Player(n) {
        type = "Righteous";
    }

    const string &getType() const {
        return type;
    }

    Move play(const State &s) {
        int max_coins = s.getCoins(0);
        int max_heap = 0;
        int min_coins = s.getCoins(0);
        int min_heap = 0;

        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > max_coins) {
                max_coins = s.getCoins(i);
                max_heap = i;
            }

            if (s.getCoins(i) < min_coins) {
                min_coins = s.getCoins(i);
                min_heap = i;
            }
        }

        int t;
        if (max_coins % 2 == 0) {   // even
            t = max_coins / 2;
        } else {   // odd
            t = max_coins / 2 + 1;
        }

        // int t = ceil(mac_coints / 2);

        return Move(max_heap, t, min_heap, t - 1);
    }
};

class Game {
  public:
    Game(int h, int p) {
        total_heaps = h;
        total_players = p;

        heaps = new int[total_heaps];
        players = new Player *[total_players];

        heaps_added = 0;
        players_added = 0;
    }

    ~Game() {
        delete[] heaps;
        delete[] players;
    }

    void addHeap(int coins) throw(logic_error) {
        if (total_heaps == heaps_added) throw logic_error("all heaps have already been added");

        heaps[heaps_added++] = coins;
    }

    void addPlayer(Player *player) throw(logic_error) {
        if (total_players == players_added)
            throw logic_error("all players have already been added");

        players[players_added++] = player;
    }

    void play(ostream &out) throw(logic_error) {
        if (heaps_added != total_heaps) throw logic_error("not all heaps have been added");
        if (players_added != total_players) throw logic_error("not all players have been added");

        State state(total_heaps, heaps, total_players);

        out << "State: " << state << endl;

        Player *player;
        while (!state.winning()) {
            player = players[state.getPlaying()];
            Move move = player->play(state);   // (*player).play(state)

            out << *player << " " << move << endl;

            state.next(move);

            out << "State: " << state << endl;
        }

        out << *player << " wins";
    }

    int getPlayers() const {
        return total_players;
    }

    const Player *getPlayer(int p) const throw(logic_error) {
        if (p < 0 || p >= total_players) throw logic_error("invalid player number");

        return players[p];
    }

  private:
    int total_heaps;
    int total_players;

    int *heaps;
    Player **players;

    int heaps_added;
    int players_added;
};

int main() {
    Game specker(3, 4);
    specker.addHeap(10);
    specker.addHeap(20);
    specker.addHeap(17);
    specker.addPlayer(new SneakyPlayer("Tom"));
    specker.addPlayer(new SpartanPlayer("Mary"));
    specker.addPlayer(new GreedyPlayer("Alan"));
    specker.addPlayer(new RighteousPlayer("Robin"));
    specker.play(cout);
}
