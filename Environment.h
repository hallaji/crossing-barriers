#include <iostream>
using namespace std;

#include <glut.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

class Environment {

	public: int VehicleType;
			int VehiclePosition;
			int	VehicleSpeed;
			int	BarriersPosition;
			bool GamePause;
	
	public: Environment(){
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(600, 600);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Crossing the Barriers by Airplane");
		glOrtho(0, 600, 0, 400, -1, 1);
		glClearColor(0.15, 0.3, 0.35, 1.0);
		glShadeModel(GL_FLAT);

		VehicleType = 1; // Airplane=1 , Ship=2
		VehiclePosition = 0;
		VehicleSpeed = 1;
		BarriersPosition = 0;

		GamePause = true;
	}

	private: void InitializeTexture(){
		GLuint Texture;
		const int Width=168, Height=168;
		GLubyte Data[Width * Height * 3];
		FILE * File;
		File = fopen( "Bricks.raw", "rb" );
		fread(Data, Width * Height * 3, 1, File);
		fclose(File);

		glGenTextures(1, &Texture);
		glBindTexture(GL_TEXTURE_2D,Texture);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, Width, Height, GL_RGB, GL_UNSIGNED_BYTE, Data);
	}

	private: void QuadPattern(float X, float Y, int Size){
		float Coord, Width, Height;
		switch(Size){
			case 1:
				Coord = 0.25;
				Width = 40;
				Height = 25;
				break;
			case 2:
				Coord = 0.5;
				Width = 80;
				Height = 50;
				break;
			case 3:
				Coord = 0.75;
				Width = 120;
				Height = 75;
				break;
			case 4:
				Coord = 1.0;
				Width = 160;
				Height = 100;
				break;
			case 5:
				Coord = 1.25;
				Width = 200;
				Height = 125;
				break;
			case 6:
				Coord = 1.5;
				Width = 240;
				Height = 150;
				break;
			case 7:
				Coord = 1.75;
				Width = 280;
				Height = 175;
				break;
			case 8:
				Coord = 2.0;
				Width = 320;
				Height = 200;
				break;
		}
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(X, BarriersPosition + Y);
		glTexCoord2f(Coord, 0.0);
		glVertex2f((X + Width), BarriersPosition + Y);
		glTexCoord2f(Coord, Coord);
		glVertex2f((X + Width), BarriersPosition + (Y + Height));
		glTexCoord2f(0.0, Coord);
		glVertex2f(X, BarriersPosition + (Y + Height));
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	private: void DrawPatterns(){
		InitializeTexture();

		QuadPattern(100, 170, 2);
		QuadPattern(0, 200, 4);
		QuadPattern(160, 200, 4);
		QuadPattern(240, 200, 4);
		QuadPattern(490, 231, 2);
		QuadPattern(550, 200, 4);

		QuadPattern(530, 320, 1);
		QuadPattern(530, 344, 1);

		QuadPattern(0, 440, 2);
		QuadPattern(80, 440, 2);
		QuadPattern(250, 440, 2);
		QuadPattern(330, 440, 2);
		QuadPattern(410, 440, 2);
		QuadPattern(490, 440, 2);
		QuadPattern(570, 440, 2);

		QuadPattern(70, 550, 2);

		QuadPattern(-50, 650, 8);
		QuadPattern(380, 650, 8);
		QuadPattern(-50, 750, 8);
		QuadPattern(380, 750, 8);

		QuadPattern(0, 1000, 4);
		QuadPattern(160, 1100, 4);
		QuadPattern(460, 1200, 4);

		QuadPattern(0, 1400, 1);
		QuadPattern(40, 1400, 1);
		QuadPattern(220, 1400, 1);
		QuadPattern(260, 1400, 1);
		QuadPattern(300, 1400, 1);
		QuadPattern(340, 1400, 1);
		QuadPattern(380, 1400, 1);
		QuadPattern(420, 1400, 1);
		QuadPattern(460, 1400, 1);
		QuadPattern(500, 1400, 1);
		QuadPattern(540, 1400, 1);
		QuadPattern(580, 1400, 1);

		QuadPattern(20, 1600, 6);
		QuadPattern(310, 1600, 2);

		QuadPattern(120, 1900, 2);
		QuadPattern(350, 1900, 2);
		QuadPattern(550, 1900, 2);

		QuadPattern(200, 2100, 8);

		QuadPattern(80, 2200, 4);
	}

	private: void DrawAirplane(){ 
		glBegin(GL_LINE_LOOP);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(300 + VehiclePosition, 21);
			glVertex2f(300 + VehiclePosition, 25);
			glVertex2f(320 + VehiclePosition, 30);
			glVertex2f(320 + VehiclePosition, 35);
			glVertex2f(300 + VehiclePosition, 40);
			glVertex2f(300 + VehiclePosition, 50);
			glVertex2f(290 + VehiclePosition, 60);
			glVertex2f(280 + VehiclePosition, 50);
			glVertex2f(280 + VehiclePosition, 40);
			glVertex2f(260 + VehiclePosition, 35);
			glVertex2f(260 + VehiclePosition, 30);
			glVertex2f(280 + VehiclePosition, 25);
			glVertex2f(280 + VehiclePosition, 21);
			glVertex2f(290 + VehiclePosition, 22);
		glEnd();
	}

	private: void DrawShip(){ 
		glBegin(GL_LINE_LOOP);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(302 + VehiclePosition, 17);
			glVertex2f(310 + VehiclePosition, 21);
			glVertex2f(310 + VehiclePosition, 50);
			glVertex2f(295 + VehiclePosition, 60);
			glVertex2f(280 + VehiclePosition, 50);
			glVertex2f(280 + VehiclePosition, 21);
			glVertex2f(288 + VehiclePosition, 17);
		glEnd();
	}

	public: void KeyboardController(unsigned char key, int x, int y){ 
		switch(key){
			case 27 :
				exit(0);
				break;
		}
	}

	public: void SpecialKeyboardController(int key, int x, int y){ 
		switch(key){
			case GLUT_KEY_RIGHT :
				VehiclePosition += 20;
				break;
			case GLUT_KEY_LEFT :
				VehiclePosition -= 20;
				break;
			case GLUT_KEY_UP :
				VehicleSpeed += 1;
				break;
			case GLUT_KEY_DOWN :
				VehicleSpeed -= 1;
				break;
			case GLUT_KEY_PAGE_DOWN :
				glScalef(0.5, 0.5, 0);
				break;
			case GLUT_KEY_PAGE_UP :
				glScalef(2, 2 , 0);
				break;
			case GLUT_KEY_INSERT :
				if(VehicleType == 2){
					VehicleType = 1;
				}else{
					VehicleType = 2;
				}
				break;
		}
		if(VehicleSpeed >= 5){
			VehicleSpeed = 5;
		}
		else if(VehicleSpeed <= 1){
			VehicleSpeed = 1;
		}
	}

	public: void MenuInitializer(){
		glutAddMenuEntry("Change Vehicle Type",1);
		glutAddMenuEntry("Zoom In", 2);
		glutAddMenuEntry("Zoom Out", 3);
		glutAddMenuEntry("Play", 4);
		glutAddMenuEntry("Pause", 5);
		glutAddMenuEntry("Restart", 6);
		glutAddMenuEntry("Help", 7);
		glutAddMenuEntry("About The Game", 8);
		glutAddMenuEntry("Exit", 9);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	}

	public: void MenuController(int item){
		switch(item){
			case 1: // Change Vehicle Type (Airplane or Ship)
				if(VehicleType == 2){
					VehicleType = 1;
				}else{
					VehicleType = 2;
				}
				break;
			case 2: // Zoom In
				glScalef(2, 2 , 0);
				break;
			case 3: // Zoom Out
				glScalef(0.5, 0.5, 0);
				break;
			case 4: // Play
				GamePause = false;
				break;
			case 5: // Pause
				GamePause = true;
				break;
			case 6: // Restart
				BarriersPosition = 0;
				GamePause = true;
				break;
			case 7: // Help
				MessageBoxA(NULL, "How to start:\n\nClick on the play option in menu to start the game.\n\nWhat is key actions:\n\nRIGHT KEY:  Move the vehicle to the right\nLEFT KEY:  Move the vehicle to the left\nUP KEY:  Speed up the vehicle\nDOWN KEY:  Speed down the vehicle\nINSERT KEY:  Change Vehicle Type (Airplane or Ship)\nPAGEUP KEY:  Zoom In\nPAGEDOWN KEY:  Zoom Out\nESC KEY:  Exit\n", "Help", MB_OK);
				break;
			case 8: // About The Game
				MessageBoxA(NULL, "Creator:\nVahid Hallaji\n\nCopyright 2013, All rights reserved.", "About The Game", MB_OK);
				break;
			case 9: // Exit
				exit(0);
				break;
		}
	}

	private: void GameController(){
		if(GamePause == false){
			BarriersPosition -= VehicleSpeed;
			Sleep(20);
		}	
	}

	public: void Display(){
		glClear(GL_COLOR_BUFFER_BIT);
		GameController();  
		DrawPatterns();
		switch(VehicleType){
			case 1 :
				DrawAirplane();
				break;
			case 2 :
				DrawShip();
				break;
		}
		glFlush();
	}

	public: void ReDisplay(){
		glutPostRedisplay();
	}

	public: void Start();

};


