#include "hamster.h"

using namespace std;

void init(){
  system("clear");
  cout << " _                         _                                \n";
  cout << "| |                       | |                                \n";
  cout << "| |__   __ _ _ __ ___  ___| |_ ___ _ __ ___ _ __  _ __       \n";
  cout << "| '_ \\ / _` | '_ ` _ \\/ __| __/ _ \\ '__/ __| '_ \\| '_ \\ \n";
  cout << "| | | | (_| | | | | | \\__ \\ ||  __/ |_| (__| |_) | |_) |   \n";
  cout << "|_| |_|\\__,_|_| |_| |_|___/\\__\\___|_(_)\\___| .__/| .__/  \n";
  cout << "                                           | |   | |         \n";
  cout << "                                           |_|   |_|         \n";

  cout << "start?";
  cin.ignore();
}

Hamster::Hamster(){
  init();
  korn = 0;
  system("clear");
}

Hamster::Hamster(int k){
  init();
  korn = k;
  system("clear");
}

Hamster::Hamster(std::string n){
  init();
  name = n;
  system("clear");
}

Hamster::Hamster(std::string n, int k){
  init();
  name = n;
  korn = k;
  system("clear");
}

Hamster::~Hamster(){
  cout << "Hamster gestorben :(" << endl;
}

void Hamster::fwd(){
  if(dir == 0){
    if(x + 1 < rows[y].size()&& !(rows[y][x + 1] == 'M')){
      x += 1;
      schritte++;
    }else{
      throw logic_error("Hamster haut sich den kopf an :(");
    }
  }

  else if(dir == 1){
    if(y + 1 < sizeof(rows)/sizeof(rows[0]) && !(rows[y + 1][x] == 'M')){
      y += 1;
      schritte++;
    }else{
      throw logic_error("Hamster haut sich den kopf an :(");
    }
  }

  else if(dir == 2){
    if(x - 1 >= 0 && !(rows[y][x - 1] == 'M')){
      x -= 1;
      schritte++;
    }else{
      throw logic_error("Hamster haut sich den kopf an :(");
    }
  }

  else if(dir == 3){
    if(y - 1 >= 0 && !(rows[y - 1][x] == 'M')){
      y -= 1;
      schritte++;
    }else{
      throw logic_error("Hamster haut sich den kopf an :(");
    }
  }
  printFeld();
}

void Hamster::linksUm(){
  dir += 1;
  if (dir == 4){
    dir = 0;
  }
  printFeld();
}

void Hamster::friss(){
  if(kornDa()){
    rows[y][x] = '.';
    korn += 1;
  }else{
    throw logic_error("Hamster frisst nix :(");
  }
}

void Hamster::lassFallen(){
  if(kornDa()){
    throw logic_error("Korn schon da!");
  }else if(korn == 0){
      throw logic_error("Hamster wollte etwas ausspucken ist aber erstickt da er kein Korn hatte!");
    }else {
      rows[x][y] = '.';
      korn -= 1;
    }
}

bool Hamster::kornDa(){
  if(rows[y][x] == ','){
    return true;
  }else{
    return false;
  }
}

bool Hamster::vornFrei(){
  if(dir == 0){

    if(!(x + 1 < rows[y].size())) {
        return false;
    }
    if(rows[y][x + 1] == 'M'){
      return false;
    }
  }

  else if(dir == 1){
    if(!(y + 1 < sizeof(rows)/sizeof(rows[0]))){
      return false;
    }
    if(rows[y + 1][x] == 'M'){
      return false;
    }
  }

  else if(dir == 2){
    if(!(x - 1 >= 0)){
      return false;
    }
    if(rows[y][x - 1] == 'M'){
      return false;
    }
  }

  else if(dir == 3){
    if(!(y - 1 >= 0)){
      return false;
    }
    if(rows[y - 1][x] == 'M'){
      return false;
    }
  }

  return true;
}

void Hamster::printFeld(){
  for(int i=0; i < sizeof(rows)/sizeof(rows[0]); i++){
    for(int j=0; j < rows[i].size(); j++){
      if (y == i && x == j){
        cout << dirs[dir] << " ";
      }else{
        cout << rows[i][j] << " ";
      }
    }
    cout << endl;
  }
  usleep(300000);
  system("clear");
}

void Hamster::getData(){
  cout << "Schritte: " << schritte << endl;
  cout << "Korn: " << korn << endl;

  cout << "Koord: y: " << y << " x: " << x << endl;

  cout << "Name: " << name << endl << endl;
}
