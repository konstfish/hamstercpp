#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <unistd.h>

class Feld{
private:

public:
  /* M = Mauer / . = Leeres Feld / , = Korn */
  std::string rows[5] = {".......",
                         ".......",
                         "...M...",
                         "..MMM..",
                         ".MMMMM."};

  Feld() {};
};


class Hamster : public Feld{
private:
  int schritte = 0;
  int korn = 0;

  int y = 0;
  int x = 0;

  std::string dirs[4] = {"\033[1;31m>\033[0m", "\033[1;31mv\033[0m", "\033[1;31m<\033[0m", "\033[1;31m^\033[0m"};
  int dir = 0;

  std::string name;
public:
  Hamster();
  Hamster(int k);
  Hamster(std::string n, int k);

  ~Hamster();

  void printFeld();

  void fwd();
  void linksUm();
  void friss();
  void lassFallen();

  bool kornDa();
  bool vornFrei();

  void getData();
};

#endif
