/*Justin Liu, jl8wf  Date:9/4/2020    Filname:bankAccount.h */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount{
 public:
  bankAccount(double balance = 0);

  ~bankAccount();
  
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance() const;

 private:
  double balance;
  
};

#endif

