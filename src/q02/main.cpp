#include <iostream>

#include "conta_corrente.h"
#include "agencia_bancaria.h"

int main(){

	Agencia BB;

	BB.newConta(make_shared<Conta_corrente>("1668-3","42.328-9",0,200,300.0));
	BB.newConta(make_shared<Conta_corrente>("1668-4","12.368-5",0,400,567.0));
	BB.newConta(make_shared<Conta_corrente>("1485-7","65.152-6",1,100,340.0));
	BB.newConta(make_shared<Conta_corrente>("1983-1","44.779-1",0,800,900.0));

	BB.deleteConta();
	std::cout << std::endl;
	BB.saque();	
	BB.depositos();
	BB.printSaldo();
	BB.extrato();
	BB.transferencia();
}