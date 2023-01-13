#include "store.h"

Store::Store(std::vector<Product> products, std::vector<Client> clients,
             std::vector<Order> orders)
    : _products(products), _clients(clients), _orders(orders) {}

void Store::addProduct(Product product) {
  if (findProduct(product.getTitle()) != 0) {
    std::cout << "Produit déjà présent" << std::endl;
  } else {
    _products.push_back(product);
    std::cout << "Produit ajouté" << std::endl;
  }
}

void Store::addClient(Client client) { _clients.push_back(client); }

void Store::showClients() const {
  for (const Client &c : _clients) {
    std::cout << c;
  }
}

void Store::showClient(unsigned id) {
  Client *c = findClient(id);
  if (c != nullptr) {
    std::cout << (*c);
  } else {
    std::cout << "Client non present" << std::endl;
  }
}

void Store::showProducts() {
  for (Product p : _products) {
    std::cout << p;
  }
}

void Store::addProductToClient(unsigned idClient, Product product) {
  Client *c = findClient(idClient);
  if (c != nullptr) {
    c->addProduct(product);
  }
}
void Store::deleteProductToClient(unsigned idClient, Product product) {
  Client *c = findClient(idClient);
  if (c != nullptr) {
    c->deleteProduct(product);
  }
}
void Store::setQuantityProductToClient(unsigned idClient, Product product,
                                       unsigned quantity) {
  Client *c = findClient(idClient);
  if (c != nullptr) {
    c->setQuantity(product, quantity);
  }
}

void Store::showProduct(std::string title) {
  auto p = findProduct(title);
  if (p != nullptr)
    std::cout << *p << std::endl;
}

void Store::setQuantity(std::string title, unsigned int quantity) {
  auto p = findProduct(title);
  p->setQuantity(quantity);
}

Product *Store::findProduct(std::string title) {
  Product *prod = nullptr;
  for (Product &p : _products) {
    if (p.getTitle() == title) {
      prod = &p;
    }
  }
  return prod;
}

Client *Store::findClient(unsigned id) {
  Client *res = nullptr;
  for (Client &c : _clients) {
    if (c.getId() == id) {
      res = &c;
    }
  }
  return res;
}

void Store::validateOrder(Client &client) {
  Client *searchedClient = findClient(client.getId());
  if (searchedClient == nullptr) {
    std::cout << "Client non trouvé dans le magasin" << std::endl;
    std::cout << "Command non validé" << std::endl;
    return;
  }

  for (const std::pair<std::string, unsigned> &pair : client.getProducts()) {
    Product *p = findProduct(pair.first);
    if (p != nullptr) {
      if (p->getQuantity() < pair.second) {
        std::cout << "Pas assez de stock pour " << pair.first << std::endl;
        std::cout << "Max stock :  " << pair.second << std::endl;
        std::cout << "Command non validé" << std::endl;
        return;
      }
    } else {
      std::cout << "Produit non trouvé !!! " << pair.first << std::endl;
      std::cout << "Command non validé" << std::endl;
      return;
    }
  }

  Order order(client);
  order.setStatus(STATUS_ORDER::VALIDE);
  _orders.push_back(order);
  client.clearProducts();
  std::cout << "Command validé" << std::endl;
}

void Store::showPreviousOrder() const {
  for (const Order &order : _orders) {
    std::cout << order << std::endl;
  }
}

void Store::showPreviousOrder(const Client &c) const {
  for (const Order &order : _orders) {
    if (order.getClient().getId() == c.getId()) {
      std::cout << order << std::endl;
    }
  }
}

void Store::changeStatusOrder(Order order, STATUS_ORDER status) {
  order.setStatus(status);
}
