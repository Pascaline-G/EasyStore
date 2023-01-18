#include "client.h"

Client::Client(unsigned id, std::string firstname, std::string name)
    : _id(id), _firstname(firstname), _name(name), _products() {}

unsigned Client::getId() const { return _id; }

std::string Client::getFirstName() const { return _firstname; }

std::string Client::getName() const { return _name; }

std::unordered_map<std::string, unsigned> Client::getProducts() const {
  return _products;
}

void Client::addProduct(const Product &product) {
  std::string title = product.getTitle();
  if (_products.contains(title)) {
    _products[title] = _products[title] + 1;
  } else {
    _products.insert({title, 1});
  }
}

void Client::clearProducts() { _products.clear(); }

void Client::setQuantity(const Product &product, unsigned quantity) {
  std::string title = product.getTitle();
  if (_products.contains(title)) {
    _products[title] = quantity;
  } else {
    std::cout << "Produit non present" << std::endl;
  }
}
void Client::deleteProduct(const Product &product) {
  std::string title = product.getTitle();
  if (_products.contains(title)) {
    _products.erase(title);
  }
}

void Client::showPanier() {}

std::ostream &operator<<(std::ostream &os, const Client &client) {
  os << "-----------------------" << std::endl;
  os << client._firstname << " " << client._name << std::endl;
  os << "ID : " << client._id << std::endl;
  for (const std::pair<std::string, unsigned> &p : client._products) {
    std::cout << p.first << " : " << p.second << std::endl;
  }
  os << "-----------------------" << std::endl;
  return os;
}