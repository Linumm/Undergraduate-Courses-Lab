//accounts.h -header file
class Account {
    public:
        int account_ID; //account name( 0~9 )
        int balance; //jandon
};

class AccountManager {
    public:
        Account accounts[10];
        int noa=0; //the number of accounts opened
	int dwt_limit[10][3]; // limit of deposit, withdraw, transfer (each 1) (dwt[][0]=d, [][1]=w, [][2]=t)
    public:
        void assign_newAcc(int& id);
	int check_balance(int id, int user_input);
        void deposit(int id, int amount);
        void withdraw(int id, int amount);
        void transfer(int sender, int receiver, int amount);
	void print_bal(int id);
};
//we only use Account* for assign to accounts array.
//then other methods use "int" because we can use array[int]
