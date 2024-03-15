/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &copy){
	*this = copy;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs){
	(void)rhs;
	return (*this);
}

void	ScalarConverter::isChar(const std::string &literal){
	char	c = literal[0];

	printC(c);
	printI(static_cast<int>(c));
	printF(static_cast<float>(c));
	printD(static_cast<double>(c));

	return;
}

void	ScalarConverter::isInt(const std::string &literal){
	int	i = std::stoi(literal);

	printC(static_cast<char>(i));
	printI(i);
	printF(static_cast<float>(i));
	printD(static_cast<double>(i));

	return ;
}

void	ScalarConverter::isFloat(const std::string &literal){
	std::string point;
	for (unsigned long i = 0; i < literal.size(); i++){
		if (literal[i] == ',')
			point[i] = '.';
		else
			point[i] = literal[i];
	}
	float	f = std::stof(point);

	printC(static_cast<char>(f));
	printI(static_cast<int>(f));
	printF(f);
	printD(static_cast<double>(f));

	return ;
}

void	ScalarConverter::isDouble(const std::string &literal){
	std::string point;
	for (unsigned long i = 0; i < literal.size(); i++){
		if (literal[i] == ',')
			point[i] = '.';
		else
			point[i] = literal[i];
	}
	double	d = std::stod(point);
	printC(static_cast<char>(d));
	printI(static_cast<int>(d));
	printF(static_cast<float>(d));
	printD(d);

	return ;
}

void	ScalarConverter::isSpecial(const std::string &literal){
	double inf_pos = std::numeric_limits<double>::infinity(); 			// Positive infini double
	double inf_neg = -std::numeric_limits<double>::infinity();			// Négatif infini double
	float inff_pos = std::numeric_limits<float>::infinity(); 			// Positive infini float
	float inff_neg = -std::numeric_limits<float>::infinity();			// Négatif infini float

	if (literal.compare("-inf") == 0 || literal.compare("-inff") == 0){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << inff_neg << std::endl;
		std::cout << "double: " << inf_neg << std::endl;
	}
	else if (literal.compare("+inf") == 0 || literal.compare("+inff") == 0){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << inff_pos << std::endl;
		std::cout << "double: " << inf_pos << std::endl;		
	}
	else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nan" << "f" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	return ;
}

void	ScalarConverter::printC(const char c){
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::printI(const int i){
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printF(const float f){
	if (f == static_cast<int>(f))
		std::cout << "float : " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << std::endl;
}

void	ScalarConverter::printD(const double d){
	if (d == static_cast<int>(d))
		std::cout << "double : " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

int	ScalarConverter::convert(const std::string &literal){
	int	fflag = 0;
	int	dflag = 0;

	if (literal.size() == 1){
		if (!isdigit(literal[0]))
			isChar(literal);
		else
			isInt(literal);
		return (0);
	}
	else if (literal.compare("-inf") == 0 || literal.compare("+inf") == 0 || literal.compare("nan") == 0
				|| literal.compare("-inff") == 0 || literal.compare("+inff") == 0 || literal.compare("nanf") == 0)
		isSpecial(literal);
	else{
		for (unsigned long i = 0; i < literal.length(); i++){
			if (literal[i] == '.' || literal[i] == ',')
				dflag++;
			if (literal[i] == 'f')
				fflag++;
		}
		if (dflag == 1){
			if (fflag == 1)
				isFloat(literal);
			else if (fflag > 1)
				return (1);
			else
				isDouble(literal);
		}
		else if (dflag > 1)
			return (1);
		else
			isInt(literal);
	}
	return (0);
}
