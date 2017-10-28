#include "conta_corrente.h"

Conta_corrente::Conta_corrente(){}

Conta_corrente::Conta_corrente(string _agencia, string _numero, bool _status, double _limite, double _saldo): agencia(_agencia), numero(_numero), status(_status), limite(_limite), saldo(_saldo){}

Conta_corrente::~Conta_corrente(){}

std::string
Conta_corrente::getAgencia(){
	return agencia;
}

std::string
Conta_corrente::getNumero(){
	return numero;
}

double
Conta_corrente::getSaldo(){
	return saldo;
}

bool
Conta_corrente::getStatus(){
	return status;
}

double
Conta_corrente::getLimite(){
	return limite;
}

double
Conta_corrente::getLimite_disponivel(){
	return limite + saldo;
}

void
Conta_corrente::setAgencia(std::string _agencia){
	agencia = _agencia;
}
void
Conta_corrente::setNumero(std::string _numero){
	numero = _numero;
}
void
Conta_corrente::setSaldo(double _saldo){
	saldo = _saldo;
}
void
Conta_corrente::setStatus(bool _status){
	status = _status;
}
void
Conta_corrente::setLimite(double _limite){
	limite = _limite;
}

//Lista as movimentações da conta:
int
Conta_corrente::List_movimentacoes(){
	for(auto it = listMov.begin(); it != listMov.end(); ++it){
		std::cout << (**it) << std::endl;
	}
	return 1;
}
//Faz uma nova movimentação:
int
Conta_corrente::addMov(std::string mdescricao, double mvalor, bool mcred_deb){
	listMov.push_back(make_shared<Movimentacoes>(mdescricao, mvalor, mcred_deb));
	return 1;
}

std::ostream& operator<<(std::ostream& o, Conta_corrente& c){
	o << std::setfill(' ') << std::setw(7) << "Agencia" << " | "
		<< std::setfill(' ') << std::setw(10) << "Numero" << " | "
		<< std::setfill(' ') << std::setw(20) << "Saldo" << " | "
		<< std::setfill(' ') << std::setw(12) << "Status" << " | "
		<< std::setfill(' ') << std::setw(20) << "Limite" << " | "
		<< std::setfill(' ') << std::setw(20) << "Limite Disponivel" << " | "
		<< std::endl;
	
	o << std::setfill(' ') << std::setw(7) << c.getAgencia() << " | "
		<< std::setfill(' ') << std::setw(10) << c.getNumero() << " | "
		<< std::setfill('.') << std::setw(20) << c.getSaldo() << " | ";
		if(c.getStatus() == 0) {
			o << std::setfill(' ') << std::setw(12) << "Especial" << " | "; 
		}else{
			o << std::setfill(' ') << std::setw(12) << "Não-especial" << " | ";
		}
		o << std::setfill(' ') << std::setw(20) << c.getLimite() << " | "
		<< std::setfill(' ') << std::setw(20) << c.getLimite_disponivel() << " | ";

		return o;
}

std::istream& operator>>(std::istream& i, Conta_corrente& c){
	std::cout << "Digite o numero da agencia: ";
	i >> c.agencia;
	std::cout << "Digite o numero da conta: ";
	i >> c.numero;
	std::cout << "Deseja que seja conta especial? 0 - Sim || 1 - Não: ";
	i >> c.status;
	std::cout << "Digite o Limite: ";
	i >> c.limite;

	return i;
}