#ifndef ORDER_H
#define ORDER_H

#include "client.h"
#include <string>
#include <unordered_map>

enum STATUS_ORDER {
  VALIDE,
  PAYE,
  ENVOYE,
  RECU,
  ANNULE,
};

class Order {
public:
  Order(Client client);
  Client getClient() const;
  std::unordered_map<std::string, unsigned> getProducts() const;
  STATUS_ORDER getStatus() const;
  void setStatus(STATUS_ORDER status);
  std::string statusToString(STATUS_ORDER status) const;

  friend std::ostream &operator<<(std::ostream &os, const Order &order);

private:
  Client _client;
  std::unordered_map<std::string, unsigned> _products;
  STATUS_ORDER status;

  
};

#endif