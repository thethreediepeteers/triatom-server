#include "entity.h"
#include <string_view>
#include <uWebSockets/App.h>

struct SocketData {
  int id;
};
using WS = uWS::WebSocket<false, true, SocketData>;

class Client : Entity {
public:
  static std::map<int, Client*> instances;

  Client(WS* socket, int id);
  ~Client();

  void tick();

  void talk(std::string_view message) const;
  void handleMessage(std::string_view message);
  void kick() const;

  int getEntityId() const { return entityId; };
  bool isDead() const { return disconnected; };

private:
  WS* socket;
  bool disconnected;

  int id;
  int entityId;

  XY movement;
  XY mouse;
};
