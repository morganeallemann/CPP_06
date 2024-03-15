/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cctype>

class   ScalarConverter{

	private:
		/* FONCTIONS CONVERTEURS */
		static void	isChar(const std::string &literal);
		static void	isInt(const std::string &literal);
		static void isFloat(const std::string &literal);
		static void isDouble(const std::string &literal);
		static void	isSpecial(const std::string &literal);
		/* FONCTIONS QUI AFFICHE LA CONVERSION */
		static void	printC(const char c);
		static void	printI(const int i);
		static void	printF(const int f);
		static void	printD(const int d);

	public:
		/* CONSTRUCTOR */
		ScalarConverter();
		/* COPY CONSTRUCTOR */
		ScalarConverter(ScalarConverter const &copy);
		/* DESTRUCTOR */
		virtual ~ScalarConverter();
		/* SURCHARGED OPERATOR */
		ScalarConverter &operator=(ScalarConverter const &rhs);
		/* MEMBER FUNCTIONS */
		static int convert(const std::string &literal);
};

#endif