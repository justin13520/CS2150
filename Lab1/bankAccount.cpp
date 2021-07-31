/* Justin Liu, jl8wf  Date:9/4/2020  Filename: bankAccount.cpp */

#include "bankAccount.h"
#include <iostream>

using namespace std;

bankAccount :: bankAccount(double b):
                 balance(b){
  
  }

bankAccount :: ~bankAccount(){

    }

double bankAccount :: withdraw(double amount){
  //java : amount > this.balance
  if(amount > balance)
    return balance;
  else
    return balance-amount;
}

double bankAccount :: deposit(double amount){
  balance += amount;
  return balance;
}

double bankAccount :: getBalance() const{
  return balance;
}
