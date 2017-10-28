#include "agencia_bancaria.h"
#include <memory>

using namespace std;

Agencia::Agencia(){}

Agencia::~Agencia(){}

int 
Agencia::newConta(){
	shared_ptr<Conta_corrente>newConta;
	std::cin >> (*newConta);

	Banco.push_back(newConta);
	return 1;
}

int
Agencia::newConta(shared_ptr<Conta_corrente> kt){
	Banco.push_back(kt);
	return 1;
}
int
Agencia::listContas(){
	int cont = 0;

	for(auto it(Banco.begin()); it!=Banco.end(); ++it){
		std::cout << "Índice: "<< cont << ": " << (**it) << std::endl;
		++cont;
	}
	return 1;
}		
int
Agencia::deleteConta(int aux){	
	char q;

	std::cout << "Deseja deletar uma conta? s - Sim " ;
	std::cin >> q;
	if(q == 's'){
		Banco.erase((Banco.begin() + aux));
	}else{
		return 1;
	}
	return 1;
}

void
Agencia::saque(int aux){

	auto it = Banco.begin();
	
	double kt;

	std::cout << (**(it+aux)) << std::endl;

	std::cout << "Qual o valor do saque? ";
	std::cin >> kt;

	while((**(it + aux)).getSaldo() < kt) {
		std::cout << "Valor inválido tente novamente: ";
		std::cin >> kt;
	}

	kt = (**(it + aux)).getSaldo() - kt;

	(**(it + aux)).setSaldo(kt);

	std::string mdes = "Saque";

	(**(it + aux)).addMov(mdes, kt, 1);

	std::cout << (**(it+aux)) << std::endl;
}

void
Agencia::depositos(int aux){

	auto it = Banco.begin();
	
	double kt;

	std::cout << (**(it+aux)) << std::endl;
	
	std::string mdes = "Deposito";

	std::cout << "Qual o valor do deposito? ";
	std::cin >> kt;

	while(kt < 0){
		std::cout << "Valor inválido tente novamente: ";
		std::cin >> kt;
	}

	kt = (**(it+aux)).getSaldo() + kt;
	(**(it+aux)).setSaldo(kt);

	(**(it+aux)).addMov(mdes, kt, 1);

	std::cout << (**(it+aux)) << std::endl;
}

void
Agencia::printSaldo(int aux){

	auto it = Banco.begin();
	
	std::cout << "O saldo da conta é: " << (**(it+aux)).getSaldo();
	std::cout << std::endl;
}

void
Agencia::extrato(int aux){

	auto it = Banco.begin();

	(**(it+aux)).List_movimentacoes();

	std::cout << std::endl;
}
		
void
Agencia::transferencia(int aux, int aux2){

	auto it = Banco.begin();

	std::cout << (**(it+aux)) << std::endl;

	std::cout << (**(it+aux2)) << std::endl;

	double kt, kt2;
	std::string mdes = "Transferencia";

	std::cout << "Valor a ser transferido: "; 
	std::cin >> kt;

	bool choice;

	if((**(it+aux)).getSaldo() > kt){
		std::cout << "Deseja usar crédito ou débito? 0 - Crédito || 1 - Débito: ";
		std::cin >> choice;

		while(choice != 0 && choice != 1){
			std::cout << "Valor inválido tente novamente: ";
			std::cin >> choice;
		}

		kt2 = kt;

		kt = (**(it+aux)).getSaldo() - kt;
		(**(it+aux)).setSaldo(kt);
		(**(it+aux)).addMov(mdes, kt, choice);
		
		kt = (**(it+aux2)).getSaldo() + kt2;
		(**(it+aux2)).setSaldo(kt2);
		(**(it+aux2)).addMov(mdes, kt2, choice);
	}
	else if((**(it+aux)).getSaldo() < kt && (**(it+aux)).getLimite_disponivel() > kt){
		kt2 = kt;
		choice = 0;

		kt = (**(it+aux)).getSaldo() - kt;
		(**(it+aux)).setSaldo(kt);
		(**(it+aux)).addMov(mdes, kt, choice);
		
		kt2 = (**(it+aux2)).getSaldo() + kt2;
		(**(it+aux2)).setSaldo(kt2);
		(**(it+aux2)).addMov(mdes, kt2, choice);
	}
	else{
		std::cout << "Saldo e Limites insuficientes!";
	}
	std::cout << (**(it+aux)) << std::endl;
	std::cout << (**(it+aux2)) << std::endl;
}