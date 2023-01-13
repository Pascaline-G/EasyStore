#include "menu.h"

Menu::Menu(Store mag) : _mag(mag) {}

void Menu::showMainMenu() {
  int choice = 0;
  while (true) {
    std::cout << "Que souhaitez vous faire ?" << std::endl;
    std::cout << "1 - Gestion des produits ? " << std::endl;
    std::cout << "2 - Gestion des clients ? " << std::endl;
    std::cout << "3 - Gestion des commandes ? " << std::endl;
    std::cin >> choice;
    choiceMainMenu(choice);
  }
}

void Menu::choiceMainMenu(int choice) {
  switch (choice) {
  case 1:
    productMenu();
    break;
  case 2:
    clientsMenu();
    break;
  case 3:
    ordersMenu();
    break;
  default:
    break;
  }
}

void Menu::productMenu() {
  int choice = 0;
  std::cout << "Il y a : " << _mag.sizeProducts() << "Produit(s) enregistrés"
            << std::endl;
  std::cout << "Que souhaitez vous faire ?" << std::endl;

  std::cout << "1 - Voir la liste des produits ? " << std::endl;
  std::cout << "2 - Ajouter un produit ? " << std::endl;
  std::cout << "3 - Supprimer un produit ? " << std::endl;
  std::cout << "4 - Modifier un produit ? " << std::endl;
  std::cin >> choice;
  choiceProductMenu(choice);
}

void Menu::choiceProductMenu(int choice) {
  switch (choice) {
  case 1:
    _mag.showProducts();
    break;
  case 2:
    addProduct();
    break;
  case 3:
    DeleteProduct();
    break;
  default:
    break;
  }
}

void Menu::addProduct() {
  std::string nom, desc;
  int quantity;
  float price;

  std::cout << "Entrez le nom du produit  :" << std::endl;
  std::cin >> nom;
  std::cout << "Entrez la description du produit  :" << std::endl;
  std::cin >> desc;
  std::cout << "Entrez la quantité disponible du produit  :" << std::endl;
  std::cin >> quantity;
  std::cout << "Entrez le prix du produit  :" << std::endl;
  std::cin >> price;
  _mag.addProduct(Product(nom, desc, quantity, price));
}

void Menu::DeleteProduct() {
  int id = 0;
  _mag.showProducts();
  std::cout << "Quel prodruit est à supprimer ?" << std::endl;
  std::cin >> id;
  _mag.deleteProduct(id - 1);
}

void Menu::clientsMenu() {
  std::cout << _mag.sizeClients() << std::endl;
  std::cout << "Que souhaitez vous faire ?" << std::endl;

  std::cout << "1 - Voir la liste des clients ? " << std::endl;
  std::cout << "2 - Ajouter un client ? " << std::endl;
  std::cout << "3 - Supprimer un client ? " << std::endl;
  std::cout << "4 - Modifier un client ? " << std::endl;
  std::cout << "5 - Voir le panier d'un client" << std::endl;
}

void Menu::ordersMenu() {
  std::cout << "Que souhaitez vous faire ?" << std::endl;

  std::cout << "1 - Voir la liste des commandes? " << std::endl;
  std::cout << "2 - Merttre à jour une Commande ? " << std::endl;
}
