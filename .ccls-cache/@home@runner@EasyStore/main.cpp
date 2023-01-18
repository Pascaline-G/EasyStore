#include "client.h"
#include "menu.h"
#include "order.h"
#include "store.h"
#include <fstream>
#include <iostream>

void save(Store mag) {
  std::filebuf fb;
  fb.open("save.txt", std::ios::trunc | std::ios::out);
  std::ostream os(&fb);
  os << "Bouh" << std::endl;
  fb.close();
}

int main() {
  std::string bouh;
  std::cin >> bouh;

  std::cout << bouh << std::endl;
  std::cout << "hey" << std::endl;

  
  std::cout << "Bonjour et Bienvenu dans la gestion du magasin easy store !"
            << std::endl;
  Store mag;
  Menu menu(mag);
  save(mag);
  menu.showMainMenu();
}