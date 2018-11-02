#include "hamster.h"

using namespace std;

int main(){

  Hamster h1("b", 2);

  h1.linksUm();

  while(h1.vornFrei()){
    h1.fwd();
  }

  h1.linksUm();
  h1.linksUm();
  h1.linksUm();

  while(!(h1.vornFrei())){
    h1.linksUm();
    h1.linksUm();
    h1.linksUm();
    h1.fwd();
    h1.linksUm();

    h1.fwd();
  }

  while(h1.vornFrei()){
    h1.fwd();
    h1.linksUm();

    h1.fwd();

    h1.linksUm();
    h1.linksUm();
    h1.linksUm();
  }


  h1.getData();
}
