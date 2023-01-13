#include "order.h"

Order::Order(Client client)
    : _client(client), _products(client.getProducts()), status("En cours") {}

Client Order::getClient() const { return _client; }
std::unordered_map<std::string, unsigned> Order::getProducts() const {
  return _products;
}
std::string Order::getStatus() const { return status; }

void Order::setStatus(std::string s) { status = s; }

std::ostream &operator<<(std::ostream &os, const Order &order) {
  os << "Commande du client :" << std::endl;
  os << order._client;
  os << "STATUS : " << order.status << std::endl;

  return os;
}
