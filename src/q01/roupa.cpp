/**
 * @file	roupa.h
 * @author	Mattheus Augusto Pinheiro de Oliveira
 * @brief	Implementação da classe Roupa
*/ 

#include <iomanip>
#include "roupa.h"

/**
 * @brief	Costrutores e Destrutor
*/
Roupa::Roupa(){}
Roupa::Roupa(std::string _codigo, std::string _descricao, short _preco, std::string _marca, bool _sexo, short _tamanho): 
		Produto(_codigo, _descricao, _preco),
		marca(_marca),
		sexo(_sexo),
		tamanho(_tamanho) {}
Roupa::~Roupa() {}

/**
 * @brief	Getters e Setters
*/
std::string
Roupa::getMarca(){
	return marca;
}
bool
Roupa::getSexo(){
	return sexo;
}
short
Roupa::getTamanho(){
	return tamanho;
}

void 
Roupa::setMarca(std::string _marca){
	marca = _marca;
}
void
Roupa::setSexo(bool _sexo){
	sexo = _sexo;
}
void
Roupa::setTamanho(short _tamanho){
	tamanho = _tamanho;
}

/**
 * @brief	Método de Impressão
*/
std::ostream& 
Roupa::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << marca << " | ";
	if(sexo == 0) {
		o << std::setfill (' ') << std::setw (5) << "M" << " | ";
	}
	else if(sexo == 1){
		o << std::setfill (' ') << std::setw (5) << "F" << " | ";
	}
	o << std::setfill (' ') << std::setw (5) << tamanho;
	return o;
}