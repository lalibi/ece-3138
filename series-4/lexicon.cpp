#include <iostream>

using namespace std;

class lexicon {
  public:
    lexicon() {
        root = nullptr;
    }

    ~lexicon() {
        purge(root);
    }

    void insert(const string &s, int count = 1) {
        if (root == nullptr) {
            root = new node(s, nullptr);
        } else {
            node *cur = root;
            while (cur != nullptr) {
                if (s < cur->word) {
                    if (cur->left_child == nullptr) {
                        cur->left_child = new node(s, cur, count);
                        break;
                    } else {
                        cur = cur->left_child;
                    }
                } else if (s > cur->word) {
                    if (cur->right_child == nullptr) {
                        cur->right_child = new node(s, cur, count);
                        break;
                    } else {
                        cur = cur->right_child;
                    }
                } else {
                    cur->count += count;
                    break;
                }
            }
        }
    }

    int lookup(const string &s) const {
        node *cur = root;
        while (cur != nullptr) {
            if (s < cur->word) {
                cur = cur->left_child;
            } else if (s > cur->word) {
                cur = cur->right_child;
            } else {
                return cur->count;
            }
        }

        return 0;
    }

    int depth(const string &s) const {
        node *cur = root;
        int depth = -1;
        while (cur != nullptr) {
            depth++;

            if (s < cur->word) {
                cur = cur->left_child;
            } else if (s > cur->word) {
                cur = cur->right_child;
            } else {
                return depth;
            }
        }

        return -1;
    }

    void replace(const string &s1, const string &s2) {
        node *first, *second;

        first = find(s1, root);

        if (first != nullptr) {
            second = find(s2, root);

            if (second != nullptr) {
                second->count += first->count;
            } else {
                insert(s2, first->count);
            }
            remove(first);
        }
    }

    friend ostream &operator<<(ostream &out, const lexicon &l) {
        node *cur = l.root;

        l.print_node(out, cur);

        return out;
    }

  private:
    class node {
      public:
        node(const string &s, node *p, int c = 1)
            : word(s), count(c), parent(p), left_child(nullptr), right_child(nullptr) {}

        string word;
        int count;

        node *parent;
        node *left_child;
        node *right_child;
    };

    void purge(node *n) {
        if (n != nullptr) {
            purge(n->left_child);
            purge(n->right_child);
            delete n;
        }
    }

    node *find(const string &s, node *root) const {
        node *cur = root;
        while (cur != nullptr) {
            if (s < cur->word) {
                cur = cur->left_child;
            } else if (s > cur->word) {
                cur = cur->right_child;
            } else {
                return cur;
            }
        }

        return nullptr;
    }

    void remove(node *n) {
        if (n == nullptr) return;

        if (n->left_child == nullptr && n->right_child == nullptr) {   // Node has no children
            // Node has a parent / is no root
            if (n->parent != nullptr) {
                if (n->parent->left_child == n) {
                    n->parent->left_child = nullptr;
                } else {
                    n->parent->right_child = nullptr;
                }
            } else {   // Node is root
                root = nullptr;
            }
            delete n;
        } else if (n->left_child == nullptr || n->right_child == nullptr) {   // Node has one child
            node *child = n->left_child != nullptr ? n->left_child : n->right_child;
            if (n->parent != nullptr) {
                child->parent = n->parent;
                if (n->parent->left_child == n) {
                    n->parent->left_child = child;
                } else {
                    n->parent->right_child = child;
                }
            } else {   // Node is root
                child->parent = nullptr;
                root = child;
            }
            delete n;
        } else {
            node *cur = n->left_child;
            while (cur->right_child != nullptr) {
                cur = cur->right_child;
            }

            n->word = cur->word;
            n->count = cur->count;
            remove(cur);
        }
    }

    void print_node(ostream &out, node *n) const {
        if (n != nullptr) {
            print_node(out, n->left_child);
            out << n->word << " " << n->count << endl;
            print_node(out, n->right_child);
        }
    }

    node *root;
};
