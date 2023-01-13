#include "order.h"

Order::Order(Client client)
    : _client(client), _products(client.getProducts()),
      status(STATUS_ORDER::VALIDE) {
  client.clearProducts();
}

Client Order::getClient() const { return _client; }
std::unordered_map<std::string, unsigned> Order::getProducts() const {
  return _products;
}

STATUS_ORDER Order::getStatus() const { return status; }

void Order::setStatus(STATUS_ORDER s) { status = s; }

std::ostream &operator<<(std::ostream &os, const Order &order) {
  os << "Commande du client :" << std::endl;
  os << order._client;
  os << "STATUS : " << order.statusToString(order.getStatus()) << std::endl;

  return os;
}

std::string Order::statusToString(STATUS_ORDER status) const {
  switch (status) {
  case VALIDE:
    return "Validé";
  case PAYE:
    return "Payé";
  case ANNULE:
    return "Annulé";
  case ENVOYE:
    return "Envoyé";
  case RECU:
    return "RECU";
  default:
    return "Indéfini";
  }
}
