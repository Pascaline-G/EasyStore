#ifndef MENU_H
#define MENU_H

#include "store.h"
#include <iostream>
#include <string>

class Menu {
public:
  Menu(Store mag);
  void showMainMenu();
  void choiceMainMenu(int choice);
  void productMenu();
  void choiceProductMenu(int choice);
  void addProduct();
  void DeleteProduct();
  void clientsMenu();
  void ordersMenu();

private:
  Store _mag;
};
#endif