/**
 * @file	bebida.h
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @brief	Declaração da classe Bebida
*/
#ifndef BEBIDA_H
#define BEBIDA_H

#include "produto.h"

class Bebida : public Produto {
	
	private:
		double teor_alcoolico;

	public:
		/**
		 * @brief	Construtores e Destrutor
		*/
		Bebida();
		Bebida(std::string _codigo, std::string _descricao, double _preco, 
			double _teor);
		~Bebida();

		/**
		 * @brief	Getters e Setters 
		*/ 
		double getTeor_alcoolico();
		void setTeor_alcoolico(double _teor);

	private:
		/**
		 * @brief	Método de impressão
		*/
		std::ostream& print(std::ostream& o) const;

};

#endif