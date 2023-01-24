#ifndef MENU_H
#define MENU_H

#include "store.h"
#include <iostream>
#include <string>
#include <time.h>    
#include <stdlib.h>

class Menu {
public:
  Menu(Store mag);
  void showMainMenu();
  void choiceMainMenu(int choice);
  void productMenu();
  void choiceProductMenu(int choice);
  void addProduct();
  void deleteProduct();
  void modifyProduct();
  void clientsMenu();
  void choiceClientMenu(int choice);
  void addClient();
  void modifyClient();
  void showPanierClient();
  void modifyPanierClient();
  void addProductClient(Client &c);
  void deleteProductClient(Client &c);
  void modifyQuantityClient(Client &c);
  void showOrderClient();
  void validateOrderClient();

private:
  Store _mag;
};
#endif