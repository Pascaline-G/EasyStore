#include "menu.h"

Menu::Menu(Store mag) : _mag(mag) {}

void Menu::showMainMenu() {
  int choice = 0;
  while (true) {
    std::cout << "Que souhaitez vous faire ?" << std::endl;
    std::cout << "1 - Gestion des produits ? " << std::endl;
    std::cout << "2 - Gestion des clients ? " << std::endl;
    std::cout << "3 - Gestion des commandes ? " << std::endl;
    std::cin.clear();
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
  std::cin.clear();
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
    deleteProduct();
    break;
  case 4:
    modifyProduct();
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

void Menu::deleteProduct() {
  int id = 0;
  _mag.showProducts();
  std::cout << "Quel prodruit est à supprimer ?" << std::endl;
  std::cin >> id;
  while (id <= 0 || id > _mag.sizeProducts()) {
    std::cout << "Valeur invalide, saississez une autre";
    std::cin >> id;
  }
  _mag.deleteProduct(id - 1);
}

void Menu::modifyProduct() {
  int id = 0;
  std::string valeur = "";
  int number = -1;
  float prix = 1.0;
  _mag.showProducts();
  std::cout << "Quel prodruit est à modifier ?" << std::endl;
  std::cin >> id;
  while (id <= 0 || id > _mag.sizeProducts()) {
    std::cout << "Valeur invalide, saississez une autre";
    std::cin >> id;
  }
  Product &p = _mag.findProduct(id);
  std::cout << "Modifier le titre ? (Saissez 'Q' pour ne pas modifier)"
            << std::endl;
  std::cin >> valeur;
  if (valeur != "Q") {
    p.setTitle(valeur);
  }
  std::cout << "Modifier la description ? (Saissez 'Q' pour ne pas modifier)"
            << std::endl;
  std::cin >> valeur;
  if (valeur != "Q") {
    p.setDescription(valeur);
  }
  std::cout << "Modifier la quantité ? (Saissez '-1' pour ne pas modifier)"
            << std::endl;
  std::cin >> number;
  if (number > 0) {
    p.setQuantity(number);
  }
  std::cout << "Modifier le prix ? (Saissez '-1' pour ne pas modifier)"
            << std::endl;
  std::cin >> prix;
  if (prix > 0) {
    p.setPrice(prix);
  }
}

void Menu::clientsMenu() {
  int choice = 0;
  std::cout << _mag.sizeClients() << std::endl;
  std::cout << "Que souhaitez vous faire ?" << std::endl;

  std::cout << "1 - Voir la liste des clients ? " << std::endl;
  std::cout << "2 - Ajouter un client ? " << std::endl;
  std::cout << "3 - Modifier un client ? " << std::endl;
  std::cout << "4 - Voir le panier d'un client" << std::endl;
  std::cin >> choice;
  std::cin.clear();
  choiceClientMenu(choice);
}

void Menu::choiceClientMenu(int choice) {
  switch (choice) {
  case 1:
    _mag.showClients();
    break;
  case 2:
    addClient();
    break;
  case 3:
    modifyClient();
  case 4:
    showPanierClient();
  default:
    break;
  }
}

void Menu::addClient() {
  unsigned id;
  std::string firstname, name;

  std::cout << "Entrez le nom du client  :" << std::endl;
  std::cin >> name;
  std::cout << "Entrez le prénom du client  :" << std::endl;
  std::cin >> firstname;
  id = _mag.sizeClients()+1;
  _mag.addClient(Client(id, firstname, name));
}

void Menu::modifyClient() {
  std::string firstname, name;

  std::cout << "Entrez le nom du client  :" << std::endl;
  std::cin >> name;
  std::cout << "Entrez le prénom du client  :" << std::endl;
  std::cin >> firstname;
}

void Menu::showPanierClient() {
  int id = 0;
  _mag.showClients();
  std::cout << "Quel client est à supprimer ?" << std::endl;
  std::cin >> id;
  _mag.show
  Client c = _mag.findClient(id);
}

void Menu::ordersMenu() {
  std::cout << "Que souhaitez vous faire ?" << std::endl;

  std::cout << "1 - Voir la liste des commandes? " << std::endl;
  std::cout << "2 - Merttre à jour une Commande ? " << std::endl;
}
