// Python context managers allow me to allocate resources just as I want it.
// For example, I can open a file and then do it something to it at the same
// time.

// Private methods are not accessible for users unlike public ones

#include <iostream>
#include <string>

class Player {
public:
  int strength;
  double health;
  void set_values(int, int);
  double attackPower() { return strength * 0.2; }
};

void Player::set_values(int x, int y) {
  health = x;
  strength = y;
}

int main() {
  Player player;
  Player evil_player;
  player.set_values(30.0, 14);
  evil_player.set_values(15.0, 25);
  std::cout << "Remaining health of Player: "
            << player.health - evil_player.attackPower();
  return 0;
}
