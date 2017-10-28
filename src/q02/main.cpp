#include <iostream>

#include "conta_corrente.h"
#include "agencia_bancaria.h"

int main(){

	Agencia BB;

	BB.newConta(make_shared<Conta_corrente>("1668-3","42.328-9",0,200,300.0));
	BB.newConta(make_shared<Conta_corrente>("1668-4","12.368-5",0,400,567.0));
	BB.newConta(make_shared<Conta_corrente>("1485-7","65.152-6",1,100,340.0));
	BB.newConta(make_shared<Conta_corrente>("1983-1","44.779-1",0,800,900.0));

/*
	BB.listContas();
	BB.deleteConta(2);
	BB.saque(1);	
	BB.depositos(1);
	BB.printSaldo(1);
	BB.extrato(1);
	BB.transferencia(2, 1);
	BB.listContas();*/

	int escolha = 8;
	int indice;
	int indice2;

	//Menu:
	while(escolha != 0){
		std::cout << "Escolha a operação:" << std::endl
			<< "0 - Sair" << std::endl
			<< "1 - Listar contas da empresa" << std::endl
			<< "2 - Deletar conta" << std::endl
			<< "3 - Saque" << std::endl
			<< "4 - Deposito" << std::endl
			<< "5 - Saldo da conta" << std::endl
			<< "6 - Extrato da conta" << std::endl
			<< "7 - Transferencia" << std::endl
			<< "8 - Adicionar nova conta" << std::endl
			<< "Opção: ";
		std::cin >> escolha;

		while(escolha < 0 || escolha > 8){
			std::cout << "OPÇÃO INVÁLIDA, Escolha outra opção: ";
			std::cin >> escolha; 
		}

		switch(escolha){
			case (1):
				BB.listContas();
				break;

			case (2):
				BB.listContas();
				std::cout << "Escolha o índice da conta que deseja deletar: ";
				std::cin >> indice;
				BB.deleteConta(indice);
				break;

			case (3):
				BB.listContas();
				std::cout << "Escolha o índice da conta que deseja sacar: ";
				std::cin >> indice;
				BB.saque(indice);
				break;

			case (4):
				BB.listContas();
				std::cout << "Escolha o índice da conta que deseja depositar: ";
				std::cin >> indice;
				BB.depositos(indice);
				break;

			case (5):
				BB.listContas();
				std::cout << "Escolha o índice da conta que deseja verificar o saldo: ";
				std::cin >> indice;
				BB.printSaldo(indice);
				break;

			case (6):
				BB.listContas();
				std::cout << "Escolha o índice da conta que deseja verificar o saldo: ";
				std::cin >> indice;
				BB.printSaldo(indice);
				break;

			case (7):
				BB.listContas();
				std::cout << "Escolha o índice da conta que deseja trasnferir o valor: ";
				std::cin >> indice;

				std::cout << "Escolha o índice da conta que deseja receber o valor: ";
				std::cin >> indice2;

				BB.transferencia(indice, indice2);
				break;

			case (8):
				BB.newConta();
				break;
		}
	}
}