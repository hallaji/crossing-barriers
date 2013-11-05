#include <iostream>
using namespace std;

#include "Environment.h"
#include <glut.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

Environment* E;

extern "C" void Display(){
  E->Display();
}

extern "C" void ReDisplay(){
  E->ReDisplay();
}

extern "C" void KeyboardController(unsigned char key, int x, int y){ 
  E->KeyboardController(key, x, y);
}

extern "C" void SpecialKeyboardController(int key, int x, int y){
  E->SpecialKeyboardController(key, x, y);
}

extern "C" void MenuController(int item){
  E->MenuController(item);
}

void Environment::Start(){ 
  ::E = this;
  ::glutDisplayFunc(::Display);
  ::glutIdleFunc(::ReDisplay);
  ::glutKeyboardFunc(::KeyboardController);
  ::glutSpecialFunc(::SpecialKeyboardController);
  ::glutCreateMenu(::MenuController);
  E->MenuInitializer();
  glutMainLoop();
}

void main(void){
	Environment Environment;
	Environment.Start();
}