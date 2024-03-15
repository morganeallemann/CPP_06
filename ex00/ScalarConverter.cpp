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
	else if (literal.compare("-inf") == 0 || literal.compare("+inf") == 0 || literal.compare(nan) == 0
				|| literal.compare("-inff") == 0 || literal.compare("+inff") == 0 || literal.compare(nanf) == 0)
		isSpecial(literal);
	else{
		
	}
