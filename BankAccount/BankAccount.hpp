class BankAccount {
  public:
    // Constructor
    BankAccount(int a, double b);

    // Methods
    void deposit(double amount);
    void withdraw(double amount);
    int get_account_number();
    double get_balance();

    // Overloaded operators
    friend BankAccount operator+(const BankAccount &x, const BankAccount &y);
    friend BankAccount operator-(const BankAccount &x, const BankAccount &y);

  private:
    int account_number;
    double balance;
};
