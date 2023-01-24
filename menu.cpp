#include "menu.h"

Menu::Menu(Store mag) : _mag(mag) {}

void Menu::showMainMenu() {
  int choice = 0;
  while (true) {
    std::cout << "Que souhaitez vous faire ?" << std::endl;
    std::cout << "1 - Gestion des produits ? " << std::endl;
    std::cout << "2 - Gestion des clients ? " << std::endl;
    std::cout << "3 - Voir les commandes ? " << std::endl;
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
    _mag.showPreviousOrder();
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
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
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
  std::cout << "5 - Modifier le panier d'un client" << std::endl;
  std::cout << "6 - Voir les commandes d'un client" << std::endl;
  std::cout << "7 - Valider un panier" << std::endl;
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
    break;
  case 4:
    showPanierClient();
    break;
  case 5:
    modifyPanierClient();
    break;
  case 6 : 
    showOrderClient();
    break;
  case 7: 
    validateOrderClient();
    break;
  default:
    break;
  }
}

void Menu::addClient() {
  unsigned id;
  std::string firstname, name;
  srand (time(NULL));
  std::cout << "Entrez le nom du client  :" << std::endl;
  std::cin >> name;
  std::cout << "Entrez le prénom du client  :" << std::endl;
  std::cin >> firstname;
  id = rand() % 1000000;
  _mag.addClient(Client(id, firstname, name));
}

void Menu::modifyClient() {
  std::string firstname, name;
  unsigned id;
  _mag.showClients();
  std::cout << "Quel client est à modifier ?" << std::endl;
  std::cin >> id;
  while (_mag.findClient(id)==nullptr) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> id;
  }
  std::cout << "Entrez le nom du client  :" << std::endl;
  std::cin >> name;
  std::cout << "Entrez le prénom du client  :" << std::endl;
  std::cin >> firstname;
  Client &c = *_mag.findClient(id);
  c.setFirstName(firstname);
  c.setName(name);
}

void Menu::showPanierClient() {
  int id = 0;
  _mag.showClients();
  std::cout << "De quel client voulez vous voir le panier ?" << std::endl;
  std::cin >> id;
  while (_mag.findClient(id)==nullptr) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> id;
  }
  (*_mag.findClient(id)).showPanier();
}

void Menu::modifyPanierClient(){
  unsigned id;
  _mag.showClients();
  std::cout << "Quel client est à modifier ?" << std::endl;
  std::cin >> id;
  while (_mag.findClient(id)==nullptr) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> id;
  }
  Client &c = *_mag.findClient(id);
  c.showPanier();

  std::cout << "Que souhaitez vous faire ?" << std::endl;
  std::cout << "1 - Ajouter un produit ?" << std::endl;
  std::cout << "2 - Supprimer un produit ?" << std::endl;
  std::cout << "3 - Modifier la quantité d'un produit ?" << std::endl;
  int choice;
  std::cin >> choice;
  switch (choice) {
    case 1:
      addProductClient(c);
      break;
    case 2:
      deleteProductClient(c);
      break;
    case 3:
      modifyQuantityClient(c);
      break;
    default:
      break;
  }
}

void Menu::addProductClient(Client &c){
  _mag.showProducts();
  std::cout << "Quel produit ajouter ?" << std::endl;
  int id;
  std::cin >> id;
  while (id <= 0 || id > _mag.sizeProducts()) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> id;
  }
  c.addProduct(_mag.findProduct(id));
}

void Menu::deleteProductClient(Client &c){
  c.showPanier();
  std::cout << "Quel produit suprimer ? Entrez le titre" << std::endl;
  std::string titre;
  std::cin >> titre;
  while (_mag.findProduct(titre)==nullptr) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> titre;
  }

  c.deleteProduct(*_mag.findProduct(titre));
}

void Menu::modifyQuantityClient(Client &c){
  c.showPanier();
  std::cout << "Quel produit modifier ? Entrez le titre" << std::endl;
  std::string titre;
  std::cin >> titre;
  while (_mag.findProduct(titre)==nullptr) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> titre;
  }
  unsigned quant = 0;
  std::cout << "Entrez la nouvelle quantité" << std::endl;
  c.setQuantity(*_mag.findProduct(titre),quant);
}

void Menu::showOrderClient() {
  int id = 0;
  _mag.showClients();
  std::cout << "De quel client voulez vous voir le panier ?" << std::endl;
  std::cin >> id;
  while (_mag.findClient(id)==nullptr) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> id;
  }
  _mag.showPreviousOrder(*_mag.findClient(id));
}

void Menu::validateOrderClient(){
  int id = 0;
  _mag.showClients();
  std::cout << "De quel client voulez vous valider le panier ?" << std::endl;
  std::cin >> id;
  while (_mag.findClient(id)==nullptr) {
    std::cout << "Valeur invalide, saississez une autre" << std::endl;
    std::cin >> id;
  }
  _mag.validateOrder(*_mag.findClient(id));
}