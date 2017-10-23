#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include "produto.h"
#include "fruta.h"
#include "roupa.h"
#include "bebida.h"

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<shared_ptr<Produto>> lista;
	
	lista.push_back(make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	lista.push_back(make_shared<Fruta>("001002004-44","Laranja",4.75,"23/09/2017",15));
	lista.push_back(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));
	lista.push_back(make_shared<Fruta>("001002005-11","Limao amarelo",2.50,"01/10/2017",22));
	
	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		
		std::cout << (**i) << std::endl;	
	}

	auto k = lista.begin();

	double result = (**k) - (**(k + 2));
	std::cout << result << std::endl;

	result = (**(k + 1)) + (**k);
	std::cout << result << std::endl;

	if((**(k+3)) == (**(k+2))){
		lista.pop_back();
	}

	for (auto j = lista.begin(); j != lista.end(); ++j)
	{
		
		std::cout << (**j) << std::endl;	
	}

	return 0;
}