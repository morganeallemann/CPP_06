/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include<iostream>
#include<string>
#include"Data.hpp"

class Serializer
{
private:

public:
	/* CONSTRUCTOR */
	Serializer();
	/* COPY CONSTRUCTOR */
	Serializer(Serializer const &copy);
	/* DESTRUCTOR */
	~Serializer();
	/* SURCHARGED OPERATOR */
	Serializer	&operator=(Serializer const &rhs);
	/* MEMBER FUNCTIONS */
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif
