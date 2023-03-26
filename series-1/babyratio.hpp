class rational {
  public:
    // Constructor
    rational(int n, int d);

    // Methods
    rational add(rational r);
    rational sub(rational r);
    rational mul(rational r);
    rational div(rational r);

    void print();

  private:
    // Fields
    int nom, den;   // nominator, denominator

    // Helper function
    static int gcd(int a, int b);
};
