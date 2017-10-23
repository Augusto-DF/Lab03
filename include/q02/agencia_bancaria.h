#ifndef AGENCIA_BANCARIA_H
#define AGENCIA_BANCARIA_H

#include "conta_corrente.h"

class Agencia{
	private:
		std::vector<shared_ptr<Conta_corrente>> Banco;

	public:
		Agencia();
		~Agencia();

		int newConta();
		int newConta(shared_ptr<Conta_corrente> kt); //Sobrecarga do método
		int listContas();

		int deleteConta();
		void saque();
		void depositos();
		void printSaldo();
		void extrato();
		void transferencia();
};

#endif