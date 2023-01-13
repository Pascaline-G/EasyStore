#ifndef ORDER_H
#define ORDER_H

#include "client.h"
#include <string>
#include <unordered_map>

class Order {
public:
  Order(Client client);
  Client getClient() const;
  std::unordered_map<std::string, unsigned> getProducts() const;
  std::string getStatus() const;
  void setStatus(std::string status);

  friend std::ostream &operator<<(std::ostream &os, const Order &order);

private:
  Client _client;
  std::unordered_map<std::string, unsigned> _products;
  std::string status;
};

#endif