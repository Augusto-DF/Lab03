/**
 * @file	roupa.h
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @brief	Declaração da classe Roupa
*/ 
#ifndef ROUPA_H
#define ROUPA_H

#include "produto.h"

class Roupa : public Produto{
	private:
		std::string marca;
		bool sexo;
		short tamanho;

	public:
		/**
		 * @brief	Construtores e Destrutor
		*/
		Roupa();
		Roupa(std::string _codigo, std::string _descricao, double _preco, std::string _marca,
			bool _sexo, short _tamanho);
		~Roupa();

		/**
		 * @brief	Getters e Setters
		*/
		std::string getMarca();
		bool getSexo();
		short getTamanho();

		void setMarca(std::string _marca);
		void setSexo(bool _sexo);
		void setTamanho(short _tamanho);

	private:
		/**
		 * @brief	Método de impressão 
		*/
		std::ostream& print(std::ostream& o) const;
};

#endif