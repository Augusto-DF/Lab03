/**
 * @file	bebida.cpp
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @brief	Implementação da classe bebida
*/

#include <iomanip>
#include "bebida.h"

/**
 * @brief Construtores e Destrutor
*/
Bebida::Bebida(){}

Bebida::Bebida(std::string _codigo, std::string _descricao, double _preco, double _teor):
		Produto(_codigo, _descricao, _preco),
		teor_alcoolico(_teor) {}

Bebida::~Bebida(){}

/**
 * @brief	Getters e Setters 
*/
double 
Bebida::getTeor_alcoolico(){
	return teor_alcoolico;
}

void 
Bebida::setTeor_alcoolico(double _teor){
	teor_alcoolico = _teor;
}

/**
 * @brief	Método de impressão
*/
std::ostream&
Bebida::print(std::ostream& o) const{
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << teor_alcoolico << "%";
	return o;
}