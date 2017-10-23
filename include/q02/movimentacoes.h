#ifndef MOVIMENTACOES_H	
#define MOVIMENTACOES_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Movimentacoes{
	private:
		string descricao;
		double valor;
		bool cred_deb;

	public:
		Movimentacoes();
		Movimentacoes(string _descricao, double _valor, bool _cred_deb);
		~Movimentacoes();

		std::string getDescricao();
		double getValor();
		bool getCred_deb();

		void setDescricao(std::string _descricao);
		void setValor(double _valor);
		void setCred_deb(bool _cred_deb);

		friend std::ostream& operator<<(std::ostream& o, Movimentacoes& m);
		friend std::istream& operator>>(std::istream& i, Movimentacoes& m);
};

#endif