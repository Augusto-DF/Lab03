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

		int deleteConta(int aux);
		void saque(int aux);
		void depositos(int aux);
		void printSaldo(int aux);
		void extrato(int aux);
		void transferencia(int aux, int aux2);
};

#endif