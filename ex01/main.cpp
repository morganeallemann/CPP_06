/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(){
    uintptr_t convert;
    Data *first = new Data;
    first->c = 'C';
    first->i = 42;
    first->str = "Hello World !";
    Data *result;

    // Affichage du premier pointeur avant toutes convertion
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "-------- FIRST POINTEUR DATA ---------" << std::endl;
    std::cout << "First ptr -> " << first << std::endl;
    std::cout << "Data data -> " << first->c << std::endl;
    std::cout << "Data int -> " << first->i << std::endl;
    std::cout << "Data str -> " << first->str << std::endl;

    std::cout << std::endl;

    // Convertissement de Data en uinptr 
    convert = Serializer::serialize(first);
    // Convertissement du retour dans un autre ptr Data.
    result = Serializer::deserialize(convert);

    // Affichage du resultat après les convertions 
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "------- RESULT POINTEUR DATA ---------" << std::endl;
    std::cout << "Result ptr -> " << result << std::endl;
    std::cout << "Data data -> " << result->c << std::endl;
    std::cout << "Data int -> " << result->i << std::endl;
    std::cout << "Data str -> " << result->str << std::endl;
    
    return (0);
}