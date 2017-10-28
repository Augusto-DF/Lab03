#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>

#include "movimentacoes.h"

using namespace std;

class Conta_corrente{
	private:
		string agencia;
		string numero;
		bool status;
		double saldo;
		double limite;
		double limite_disponivel;
		std::vector<shared_ptr<Movimentacoes>> listMov;

	public:
		Conta_corrente();
		Conta_corrente(string _agencia, string _numero, bool _status, double _limite, double _saldo);
		~Conta_corrente();

		std::string getAgencia();
		std::string getNumero();
		double getSaldo();
		bool getStatus();
		double getLimite();
		double getLimite_disponivel();

		void setAgencia(std::string _agencia);
		void setNumero(std::string _numero);
		void setSaldo(double _saldo);
		void setStatus(bool _status);
		void setLimite(double _limite);

		int List_movimentacoes();
		int addMov(std::string mdescricao, double mvalor, bool mcred_deb);

		friend std::ostream& operator<<(std::ostream& o, Conta_corrente& c);
		friend std::istream& operator>>(std::istream& i, Conta_corrente& c);

};

#endif