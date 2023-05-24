#include "lexicon.cpp"
#include <iostream>

using namespace std;

int main() {
    lexicon l;
    l.insert("the");
    l.insert("boy");
    l.insert("and");
    l.insert("the");
    l.insert("wolf");
    cout << "The word 'the' is found " << l.lookup("the") << " time(s)" << endl;
    cout << "The word 'and' is found at depth " << l.depth("and") << endl;
    cout << l;
    l.replace("boy", "wolf");
    cout << "After replacement:\n";
    cout << l;
    cout << "Now the word 'and' is found at depth " << l.depth("and") << endl;

    cout << "------------------------------------------------\n";

    lexicon l2;

    l2.insert("the");
    l2.insert("boy");
    l2.insert("and");
    l2.insert("the");
    l2.insert("wolf");

    cout << l2;

    cout << "and is now found " << l2.lookup("and") << " time(s) at depth " << l2.depth("and")
         << endl;
    cout << "boy is now found " << l2.lookup("boy") << " time(s) at depth " << l2.depth("boy")
         << endl;
    cout << "the is now found " << l2.lookup("the") << " time(s) at depth " << l2.depth("the")
         << endl;
    cout << "wolf is now found " << l2.lookup("wolf") << " time(s) at depth " << l2.depth("wolf")
         << endl;
    cout << "dummy is now found " << l2.lookup("dummy") << " time(s) at depth " << l2.depth("dummy")
         << endl;

    l2.replace("and", "dummy");

    cout << "wolf is now found " << l2.lookup("wolf") << " time(s) at depth " << l2.depth("wolf")
         << endl;
    cout << "dummy is now found " << l2.lookup("dummy") << " time(s) at depth " << l2.depth("dummy")
         << endl;

    l2.replace("boy", "dummy");

    cout << "wolf is now found " << l2.lookup("wolf") << " time(s) at depth " << l2.depth("wolf")
         << endl;
    cout << "dummy is now found " << l2.lookup("dummy") << " time(s) at depth " << l2.depth("dummy")
         << endl;

    l2.replace("the", "dummy");

    cout << "wolf is now found " << l2.lookup("wolf") << " time(s) at depth " << l2.depth("wolf")
         << endl;
    cout << "dummy is now found " << l2.lookup("dummy") << " time(s) at depth " << l2.depth("dummy")
         << endl;

    l2.replace("wolf", "dummy");

    cout << "wolf is now found " << l2.lookup("wolf") << " time(s) at depth " << l2.depth("wolf")
         << endl;

    cout << l2;

    cout << "------------------------------------------------\n";

    lexicon l3;

    l3.insert("the");
    l3.insert("first");
    l3.insert("electronic");
    l3.insert("computers");
    l3.insert("were");
    l3.insert("monstrous");
    l3.insert("contraptions");
    l3.insert("filling");
    l3.insert("several");
    l3.insert("rooms");
    l3.insert("consuming");
    l3.insert("as");
    l3.insert("much");
    l3.insert("electricity");
    l3.insert("as");
    l3.insert("a");
    l3.insert("good");
    l3.insert("size");
    l3.insert("factory");
    l3.insert("and");
    l3.insert("costing");
    l3.insert("millions");
    l3.insert("of");
    l3.insert("dollars");
    l3.insert("but");
    l3.insert("with");
    l3.insert("the");
    l3.insert("computing");
    l3.insert("power");
    l3.insert("of");
    l3.insert("a");
    l3.insert("modern");
    l3.insert("hand");
    l3.insert("held");
    l3.insert("calculator");
    l3.insert("the");
    l3.insert("programmers");
    l3.insert("who");
    l3.insert("used");
    l3.insert("these");
    l3.insert("machines");
    l3.insert("believed");
    l3.insert("that");
    l3.insert("the");
    l3.insert("computer");
    l3.insert("s");
    l3.insert("time");
    l3.insert("was");
    l3.insert("more");
    l3.insert("valuable");
    l3.insert("than");
    l3.insert("theirs");
    l3.insert("they");
    l3.insert("programmed");
    l3.insert("in");
    l3.insert("machine");
    l3.insert("language");

    cout << l3;

    cout << "------------------------------------------------\n";

    lexicon l4;

    string words[] = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa",
                      "b", "bb", "bbb", "bbbb", "bbbbb", "bbbbbb", "bbbbbbb",
                      "c", "cc", "ccc", "cccc", "ccccc", "cccccc", "ccccccc",
                      "d", "dd", "ddd", "dddd", "ddddd", "dddddd", "ddddddd"};

    for (int i = 0; i < 28; i++) {
        l4.insert(words[i]);
    }

    cout << l4;

    for (int i = 0; i < 28; i++) {
        cout << words[i] << " is now found " << l4.lookup(words[i]) << " time(s) at depth "
             << l4.depth(words[i]) << endl;
    }

    for (int i = 0; i < 28; i++) {
        cout << "dummy is now found " << l4.lookup("dummy") << " time(s) at depth "
             << l4.depth("dummy") << endl;

        l4.replace(words[i], "dummy");

        cout << "ddddddd is now found " << l4.lookup("ddddddd") << " time(s) at depth "
             << l4.depth("ddddddd") << endl;
    }

    cout << l4;
}
