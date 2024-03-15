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

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

Base * generate(void){
    int choice = std::rand() % 3;                       //Donne l'ordre au generateur de choisir parmis des nombre de 0 a 2

    if (choice == 0)
        return (new A);
    else if (choice == 1)
        return (new B);
    else if (choice == 2)
        return (new C);
    else{
        std::cout << "Error: no choice possible " << std::endl;
        return (NULL);
    }
}

void identify(Base* p){
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "It's an A child " << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "It's a B child " << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "It's a C child " << std::endl;
    else
        std::cout << "Error: Type not found !" << std::endl;
    return ; 
}

void identify(Base& p){
    try{
        const Base& a = dynamic_cast<A &>(p);
        std::cout << "It's an A child " << std::endl;
        (void)a;
        return ;
    }
    catch(std::bad_cast bc){
    }
    try{
        const Base& b = dynamic_cast<B &>(p);
        std::cout << "It's a B child " << std::endl;
        (void)b;
        return ;
    }
    catch(std::bad_cast bc){
    }
    try{
        const Base& c = dynamic_cast<C &>(p);
        std::cout << "It's a C child " << std::endl;
        (void)c;
        return ;
    }
    catch(std::bad_cast bc){
    }
    return ;
}
int main(){
    
    //initialisation du generateur de nombre aléatoire à l'heure actuel
    std::srand(std::time(NULL));
    //Initialisation des variable pour les tests (5)
    Base *test;
    Base *test2;
    Base *test3;
    Base *test4;
    Base *test5;
    // Envoi des different objet a la fonction generate pour generer un objet aléatoire
    test = generate();
    test2 = generate();
    test3 = generate();
    test4 = generate();
    test5 = generate();
    // Identifie de quel type d'objet la fonction precedente a generer.
    identify(*test);
    identify(test);
    std::cout << "--------------------------------------" << std::endl;
    identify(*test2);
    identify(test2);
    std::cout << "--------------------------------------" << std::endl;
    identify(*test3);
    identify(test3);
    std::cout << "--------------------------------------" << std::endl;
    identify(*test4);
    identify(test4);
    std::cout << "--------------------------------------" << std::endl;
    identify(*test5);
    identify(test5);
    std::cout << "--------------------------------------" << std::endl;

    return (0);
}