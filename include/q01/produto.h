#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
#include <string>

using std::string;

class Produto
{	
	protected:
		std::string m_cod_barras;
		std::string m_descricao;
		double m_preco;		
	
	public:
		Produto();
		Produto(std::string _codigo, std::string _descricao, short _preco);
		virtual ~Produto();

		// getters
		std::string getCodBarras();
		std::string getDescricao();
		double getPreco();
		// setters
		void setCodBarras(std::string _codigo);
		void setDescricao(std::string _descricao);
		void setPreco(double _preco);
		//
		friend std::ostream& operator<< (std::ostream &o, Produto const &t); 
		
		double operator+(const Produto& p) const;
		double operator-(const Produto& p) const;
		bool operator==(const Produto& p) const;
		operator double();

	private:
		virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
