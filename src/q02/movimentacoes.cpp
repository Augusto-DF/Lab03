#include "movimentacoes.h"

Movimentacoes::Movimentacoes(){}

Movimentacoes::Movimentacoes(string _descricao, double _valor, bool _cred_deb):
	descricao(_descricao),
	valor(_valor),
	cred_deb(_cred_deb) {}

Movimentacoes::~Movimentacoes(){}

std::string
Movimentacoes::getDescricao(){
	return descricao;
}

double
Movimentacoes::getValor(){
	return valor;
}

bool
Movimentacoes::getCred_deb(){
	return cred_deb;
}

void
Movimentacoes::setDescricao(std::string _descricao){
	descricao = _descricao;
}
void
Movimentacoes::setValor(double _valor){
	valor = _valor;
}
void
Movimentacoes::setCred_deb(bool _cred_deb){
	cred_deb = _cred_deb;
}

std::ostream& operator<< (std::ostream& o, Movimentacoes& m){
	o << std::setfill(' ') << std::setw(20) << m.getDescricao() << " | "
		<< std::setfill('.') << std::setw(10) << m.getValor() << " | ";
		if(m.getCred_deb() == 0){
			o << std::setfill(' ') << std::setw(10) << "Crédito" << " | ";
		}else{
			o << std::setfill(' ') << std::setw(10) << "Débito" << " | ";
		}
	return o;
}

std::istream& operator>>(std::istream& i, Movimentacoes& m){
	std::cout << "Digite a descrição: ";
	i >> m.descricao;
	std::cout << "Digite o valor: ";
	i >> m.valor;
	std::cout << "Digite o tipo da movimentação: 0 - Crédito || 1 - Débito ";
	i >> m.cred_deb;
	return i;
}