/*
	PROYECTO PINBALL
	AUTOR: Ramirez Nuñez Daniel 

-------------------------------
TECLAS MOVIMIENTO CAMARA
-------------------------------
W -- ARRIBA
A -- IZQUIERDA
S -- ABAJO
D -- DERECHA
Q -- ATRAS
E -- ADELANTE
-----------------------------------------
TECLAS ENCENDIDO/APAGADO FUENTES DE LUZ
-----------------------------------------
1 -- LUZ 1
2 -- LUZ 2
3 -- LUZ 3
------------------------------------------
TECLAS MOVIMIENTO FLIPPERS
------------------------------------------
4 -- FLIPPER IZQUIERDA
5 -- FLIPPER DERECHA
6 -- FLIPPER ARRIBA
------------------------------------------
TECLA CAMBIO DE CAMARA 
------------------------------------------
0 == CAMBIAR VISTA DE CAMARA
*/

#include "Main.h"
#include "Camera.h"
#include "texture.h"
#include "figuras.h"
#include "cmodel/CModel.h"
#include <iostream>
using namespace std;

// Movimiento de todos los objetos
float Rx=0, Ry=1, Rz=0;
float Tx, Ty, Tz;
// Movimiento del cubo
float Cx, Cy, Cz;
// Escalar cubo
float Sx = 1.0, Sy = 1.0, Sz = 1.0;

// Objetos
CFiguras cabecera;
CFiguras vidrioTablero;
CFiguras tablero;
CFiguras cilFlipperBig;
CFiguras cilFlipperSmall;
CFiguras cuarto;
CFiguras c1_;
CFiguras c2_;
CFiguras c3_;
CFiguras tabScore;
CFiguras palanca;
CFiguras sup1;
CFiguras sup2;
CFiguras sup3;

// Texturas 
CTexture cabRnM;
CTexture glass;
CTexture tabTextmain;
CTexture pared1;
CTexture pared2;
CTexture pared3;
CTexture pared4;
CTexture piso;
CTexture arriba;
CTexture tx1;
CTexture tx2;
CTexture tx3;

CTexture plano1;
CTexture plano2;
CTexture plano3;
CTexture score;
CTexture slvr;

CTexture back1;
CTexture back2;

// Objetos 3ds
CModel sship;
CModel space;
CModel moon;

// Objeto camara
bool _view_1 = true;
bool vDown = true;
float rView = 0.0;
CCamera objCamera;  
CCamera objCamera_2;
GLfloat g_lookupdown = 0.0f;

// Canicas
bool canica_1 = true;
bool canica_3 = true;
float canX = 0, canZ = 0;

// --- Fuente de luz propiedades
bool luz_1 = true;
bool luz_2 = true;
bool luz_3 = true;
// Animacion
bool resorte = false;
bool up = false;

GLfloat Light_ambient[] = { 0.7695, 0.7890, 0.8281, 1.0 };
GLfloat Light_diffuse[] = { 0.7812, 0.8398, 0.9453, 1.0 };
GLfloat Light_specular[] = { 0.7812, 0.8398, 0.9453, 1.0 };

GLfloat Light_ambient_1[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat Light_diffuse_1[] = { 0.859, 0.3046, 0.6835, 1.0 };
GLfloat Light_specular_1[] = { 0.859, 0.3046, 0.6835, 1.0 };
GLfloat Light_Position_1[] = { 0.0f, 0.0f, 0.0f, 0.0f };

GLfloat Light_ambient_2[] = { 0.10, 0.10, 0.10, 1.0 };
GLfloat Light_diffuse_2[] = { 0.2148, 0.75, 0.1953, 1.0 };
GLfloat Light_specular_2[] = { 0.9, 0.9, 0.9, 1.0 };
GLfloat Light_Position_2[] = { 0.0f, 0.0f, 0.0f, 0.0f };

GLfloat Light_position[] = { 0.0f, 27.0f, -5.0f, 0.0f };
GLfloat Light_position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };
GLfloat Light_spot_direction[] = { 0.0, 0.0, -10.0 };
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };


// --- Materiales
// Material de las patas de la mesa
GLfloat mat_ambient_emerald[] = { 0.0215f, 0.1745f, 0.0215f, 0.55f };
GLfloat mat_diffuse_emerald[] = { 0.07568f, 0.61424f, 0.07568f, 0.55f };
GLfloat mat_specular_emerald[] = { 0.633f, 0.727811f, 0.633f, 0.55f };
GLfloat mat_shininess_emerald[] = { 76.8 };
// Material de la mesa
GLfloat mat_ambient_chrome[] = { 0.25f, 0.25f, 0.25f, 1.0f };
GLfloat mat_diffuse_chrome[] = { 0.4f, 0.4f, 0.4f, 1.0f };
GLfloat mat_specular_chrome[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
GLfloat mat_shininess_chrome[] = { 76.8 };
// Material de la cabecera de la mesa
GLfloat mat_ambient_obsidian[] = { 0.05375f, 0.05f, 0.06625f, 0.82f };
GLfloat  mat_diffuse_obsidian[] = { 0.18275f, 0.17f, 0.22525f, 0.82f };
GLfloat  mat_specular_obsidian[] = { 0.332741f, 0.328634f, 0.346435f, 0.82f };
GLfloat mat_shininess_obsidian[] = { 38.4 };

GLfloat mat_ambient_silver[] = { 0.23125f, 0.23125f, 0.23125f, 1.0f };
GLfloat mat_diffuse_silver[] = { 0.2775f, 0.2775f, 0.2775f, 1.0f };
GLfloat mat_specular_silver[] = { 0.773911f, 0.773911f, 0.773911f, 1.0f };
GLfloat mat_shininess_silver[] = { 89.6f };


// Movimiento resorte
float movB = 0, movC = 0, movD = 0, movE = 0;
float _movB = 0, _movC = 0, _movD = 0, _movE = 0;
int i = 0, k = 0;
float movPal = 0;
// Movimiento flippers
float rotF1 = 0;
float rotF2 = 0;
float rotF3 = 0;
bool flip1 = false;
bool flip2 = false;
bool flip3 = false;

void triangle() {
	
	GLfloat frontFace[3][3]{
		0.0, 0.0, 0.0,
		0.0, 0.0, 1.0,
		0.0, 1.0, 1.0
	};

	GLfloat backFace[3][3]{
		-1.0, 0.0, 0.0,
		-1.0, 0.0, 1.0,
		-1.0, 1.0, 1.0
	};
	// Cara 1
	glBegin(GL_POLYGON);
	glVertex3fv(frontFace[0]);
	glVertex3fv(frontFace[1]);
	glVertex3fv(frontFace[2]);
	glEnd();
	// Cara 2
	glBegin(GL_POLYGON);
	glVertex3fv(backFace[0]);
	glVertex3fv(backFace[1]);
	glVertex3fv(backFace[2]);
	glEnd();
	// Cara 3
	glBegin(GL_POLYGON);
	glVertex3fv(frontFace[1]);
	glVertex3fv(frontFace[2]);
	glVertex3fv(backFace[2]);
	glVertex3fv(backFace[1]);
	glEnd();
	// Cara 4
	glBegin(GL_POLYGON);
	glVertex3fv(frontFace[0]);
	glVertex3fv(backFace[0]);
	glVertex3fv(backFace[2]);
	glVertex3fv(frontFace[2]);
	glEnd();
	// Cara 5
	glBegin(GL_POLYGON);
	glVertex3fv(frontFace[0]);
	glVertex3fv(backFace[0]);
	glVertex3fv(backFace[1]);
	glVertex3fv(frontFace[1]);
	glEnd();
}

void flipper() {

	float v4 = 12.0;
	float yh = 2;
	// ----------------------------------- 
	// Arriba
	glBegin(GL_POLYGON);
	glVertex3f(-3.0, 0.0, 0.0);  // v1
	glVertex3f(-2.5, 2.0, 0.0);  // v2
	glVertex3f(0.0, yh, 0.0);   // v3
	glVertex3f(v4, 0.0, 0.0);   // v4
	glVertex3f(0.0, -yh, 0.0);   // v5
	glVertex3f(-2.5, -2.0, 0.0);   // v6
	glEnd();
	// Abajo
	glBegin(GL_POLYGON);
	glVertex3f(-3.0, 0.0, -0.25);  // v1
	glVertex3f(-2.5, 2.0, -0.25);  // v2
	glVertex3f(0.0, yh, -0.25);   // v3
	glVertex3f(v4, 0.0, -0.25);   // v4
	glVertex3f(0.0, -yh, -0.25);   // v5
	glVertex3f(-2.5, -2.0, 0.25);   // v6
	glEnd();
	// Cara 1
	glBegin(GL_POLYGON);
	glVertex3f(-3.0, 0.0, 0.0);  // v1
	glVertex3f(-2.5, 2.0, 0.0);  // v2
	glVertex3f(-2.5, 2.0, -0.25);  // v2
	glVertex3f(-3.0, 0.0, -0.25);  // v1
	glEnd();
	// Cara 2
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, 2.0, 0.0);  // v2
	glVertex3f(0.0, yh, 0.0);   // v3
	glVertex3f(0.0, yh, -0.25);   // v3
	glVertex3f(-2.5, 2.0, 0.0);  // v2
	glEnd();
	// Cara 3
	glBegin(GL_POLYGON);
	glVertex3f(0.0, yh, 0.0);   // v3
	glVertex3f(v4, 0.0, 0.0);   // v4
	glVertex3f(v4, 0.0, -0.25);   // v4
	glVertex3f(0.0, yh, -0.25);   // v3
	glEnd();
	// Cara 4
	glBegin(GL_POLYGON);
	glVertex3f(v4, 0.0, 0.0);   // v4
	glVertex3f(0.0, -yh, 0.0);   // v5
	glVertex3f(0.0, -yh, -0.25);   // v5
	glVertex3f(v4, 0.0, -0.25);   // v4
	glEnd();
	// Cara 5
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, -2.0, 0.0);   // v6
	glVertex3f(-3.0, 0.0, 0.0);  // v1
	glVertex3f(-3.0, 0.0, -0.25);  // v1
	glVertex3f(-2.5, -2.0, 0.0);   // v6
	glEnd();
}

void structFlip() {


	// P1 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);      // v2
	glVertex3f(0, 0, -40);    // v1
	glVertex3f(2, 0, -40);    // v10
	glVertex3f(2, 0, -19);    // v9
	glVertex3f(17, 0, -12);   // v8
	glVertex3f(17, 0, 0);     // v8aux
	glVertex3f(0, 0, 0);      // v2
	glEnd();

	// P2 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(17, 0, 0);     // v8aux
	glVertex3f(17, 0, -12);   // v8
	glVertex3f(34, 0, -12);   // v7
	glVertex3f(34, 0, 0);   // v7aux
	glEnd();
	// P3 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(34, 0, 0);   // v7aux
	glVertex3f(34, 0, -12);   // v7
	glVertex3f(52, 0, -19);   // v6
	glVertex3f(54, 0, -19);   // v6aux
	glVertex3f(54, 0, 0);     // v3
	glEnd();
	// P4 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(52, 0, -19);   // v6
	glVertex3f(52, 0, -40);   // v5
	glVertex3f(54, 0, -40);   // v4
	glVertex3f(54, 0, -19);   // v6aux
	glEnd();

	// P1 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(0, -0.5, 0);      // v2
	glVertex3f(0, -0.5, -40);    // v1
	glVertex3f(2, -0.5, -40);    // v10
	glVertex3f(2, -0.5, -19);    // v9
	glVertex3f(17, -0.5, -12);   // v8
	glVertex3f(17, -0.5, 0);     // v8aux
	glVertex3f(0, -0.5, 0);      // v2
	glEnd();

	// P2 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(17, -0.5, 0);     // v8aux
	glVertex3f(17, -0.5, -12);   // v8
	glVertex3f(34, -0.5, -12);   // v7
	glVertex3f(34, -0.5, 0);   // v7aux
	glEnd();
	// P3 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(34, -0.5, 0);   // v7aux
	glVertex3f(34, -0.5, -12);   // v7
	glVertex3f(52, -0.5, -19);   // v6
	glVertex3f(54, -0.5, -19);   // v6aux
	glVertex3f(54, -0.5, 0);     // v3
	glEnd();
	// P4 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(52, -0.5, -19);   // v6
	glVertex3f(52, -0.5, -40);   // v5
	glVertex3f(54, -0.5, -40);   // v4
	glVertex3f(54, -0.5, -19);   // v6aux
	glEnd();

	// CARA 1
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);      // v2
	glVertex3f(0, 0, -40);    // v1
	glVertex3f(0, -0.5, -40);    // v1
	glVertex3f(0, -0.5, 0);      // v2
	glEnd();
	// CARA 2
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -40);    // v1
	glVertex3f(2, 0, -40);    // v10
	glVertex3f(2, -0.5, -40);    // v10
	glVertex3f(0, -0.5, -40);    // v1
	glEnd();
	// CARA 3
	glBegin(GL_POLYGON);
	glVertex3f(2, 0, -40);    // v10
	glVertex3f(2, 0, -19);    // v9
	glVertex3f(2, -0.5, -19);    // v9
	glVertex3f(2, -0.5, -40);    // v10
	glEnd();
	// CARA 4
	glBegin(GL_POLYGON);
	glVertex3f(2, 0, -19);    // v9
	glVertex3f(17, 0, -12);   // v8
	glVertex3f(17, -0.5, -12);   // v8
	glVertex3f(2, -0.5, -19);    // v9
	glEnd();
	// CARA 5
	glBegin(GL_POLYGON);
	glVertex3f(17, 0, -12);   // v8
	glVertex3f(34, 0, -12);   // v7
	glVertex3f(34, -0.5, -12);   // v7
	glVertex3f(17, -0.5, -12);   // v8
	glEnd();
	// CARA 6
	glBegin(GL_POLYGON);
	glVertex3f(34, 0, -12);   // v7
	glVertex3f(52, 0, -19);   // v6
	glVertex3f(52, -0.5, -19);   // v6
	glVertex3f(34, -0.5, -12);   // v7
	glEnd();
	// CARA 7
	glBegin(GL_POLYGON);
	glVertex3f(52, 0, -19);   // v6
	glVertex3f(52, 0, -40);   // v5
	glVertex3f(52, -0.5, -40);   // v5
	glVertex3f(52, -0.5, -19);   // v6
	glEnd();
	// CARA 8
	glBegin(GL_POLYGON);
	glVertex3f(52, 0, -40);   // v5
	glVertex3f(54, 0, -40);   // v4
	glVertex3f(54, -0.5, -40);   // v4
	glVertex3f(52, -0.5, -40);   // v5
	glEnd();
	// CARA 9
	glBegin(GL_POLYGON);
	glVertex3f(54, 0, -40);   // v4
	glVertex3f(54, 0, 0);     // v3
	glVertex3f(54, -0.5, 0);     // v3
	glVertex3f(54, -0.5, -40);   // v4
	glEnd();
	// CARA 10
	glBegin(GL_POLYGON);
	glVertex3f(54, 0, 0);     // v3
	glVertex3f(0, 0, 0);      // v2
	glVertex3f(0, -0.5, 0);      // v2
	glVertex3f(54, -0.5, 0);     // v3
	glEnd();
	/*
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);      // v2
	glVertex3f(0, 0, -40);    // v1
	glVertex3f(2, 0, -40);    // v10
	glVertex3f(2, 0, -19);    // v9
	glVertex3f(17, 0, -12);   // v8
	glVertex3f(34, 0, -12);   // v7
	glVertex3f(52, 0, -19);   // v6
	glVertex3f(52, 0, -40);   // v5
	glVertex3f(54, 0, -40);   // v4
	glVertex3f(54, 0, 0);     // v3
	glVertex3f(0, 0, 0);      // v2
	glEnd();
	*/

}

void cube() {

	glTranslatef(-0.5, -0.5, 0.5);

	GLfloat frontFace[4][3] = {
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		1.0, 1.0, 0.0,
		1.0, 0.0, 0.0
	};
	GLfloat backFace[4][3] = {
		0.0, 0.0, -1.0,
		0.0, 1.0, -1.0,
		1.0, 1.0, -1.0,
		1.0, 0.0, -1.0
	};

	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 0.0);
	// FRENTE
	glVertex3fv(frontFace[0]); // Vertice 1
	glVertex3fv(frontFace[1]); // Vertice 2
	glVertex3fv(frontFace[2]); // Vertice 3
	glVertex3fv(frontFace[3]); // Vertice 4
							   //glColor3f(0.0, 1.0, 0.0);
							   // ATRAS 
	glVertex3fv(backFace[0]); // Vertice 8
	glVertex3fv(backFace[1]); // Vertice 7
	glVertex3fv(backFace[2]); // Vertice 6
	glVertex3fv(backFace[3]); // Vertice 5
							  //glColor3f(0.0, 0.0, 1.0);
							  // IZQUIERDA
	glVertex3fv(frontFace[0]);
	glVertex3fv(frontFace[1]);
	glVertex3fv(backFace[1]);
	glVertex3fv(backFace[0]);
	//glColor3f(1.0, 1.0, 0.0);
	// DERECHA
	glVertex3fv(frontFace[2]);
	glVertex3fv(frontFace[3]);
	glVertex3fv(backFace[3]);
	glVertex3fv(backFace[2]);
	//glColor3f(0.0, 1.0, 1.0);
	// ARRIBA
	glVertex3fv(frontFace[1]);
	glVertex3fv(frontFace[2]);
	glVertex3fv(backFace[2]);
	glVertex3fv(backFace[1]);
	//glColor3f(1.0, 0.0, 1.0);
	// ABAJO
	glVertex3fv(frontFace[0]);
	glVertex3fv(frontFace[3]);
	glVertex3fv(backFace[3]);
	glVertex3fv(backFace[0]);

	glEnd();
}

void carril_entrada() {

	// Prisma 1
	glPushMatrix();
	glTranslatef(0.0, -16, 8.5);
	glTranslatef(2.5, -17, -37.5);
	glTranslatef(-3, 86, 143.5);
	glRotatef(6, 1, 0, 0);
	glTranslatef(3, -86, -143.5);
	glScalef(1, 1, 76);
	cube();
	glPopMatrix();
	// Prisma 2
	glPushMatrix();
	glTranslatef(9.5, -15, -1);
	glTranslatef(-5, 85, 97);
	glRotatef(6, 1.0, 0.0, 0.0);
	glTranslatef(5, -85, -97);
	glTranslatef(-5, 85, 97);
	glScalef(1,1,96);
	cube();
	glPopMatrix();
	// Prisma 3
	glPushMatrix();
	glTranslatef(6.5, -20.25, 45.5);
	glTranslatef(-5, 85, 97);
	glRotatef(Sx, 1.0, 0.0, 0.0);
	glTranslatef(5, -85, -97);
	glTranslatef(-5, 85, 97);
	glScalef(7, 1, 3);
	cube();
	glPopMatrix();
}

void structTabb() {

	// P1 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);  // v1
	glVertex3f(7,0,-12);  // v2
	glVertex3f(7,0,-26);  // v3
	glVertex3f(3.5,0,-32);  // v4
	glVertex3f(0, 0, -32);  // v4.1
	glEnd();
	// P2 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -32);  // v4.1
	glVertex3f(3.5, 0, -32);  // v4
	glVertex3f(3.5, 0, -53);  // v5
	glVertex3f(0, 0, -53);  // v5.1
	glEnd();
	// P3 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -53);  // v5.1
	glVertex3f(3.5, 0, -53);  // v5
	glVertex3f(15, 0, -65);  // v6
	glVertex3f(15, 0, -74);  // v6.1
	glVertex3f(0, 0, -74);  // v11
	glEnd();
	// P4 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(15, 0, -65);  // v6
	glVertex3f(36.5, 0, -65);  // v7
	glVertex3f(36.5, 0, -74);  // v7.1
	glVertex3f(15, 0, -74);  // v6.1	
	glEnd();
	// P5 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(36.5, 0, -65);  // v7
	glVertex3f(50, 0, -57);  // v8
	glVertex3f(54.0, 0, -54);  // v8.5
	glVertex3f(54.0, 0, -74);  // v8.5.1
	glVertex3f(36.5, 0, -74);  // v7.1
	glEnd();
	// P6 ARRIBA
	glBegin(GL_POLYGON);
	glVertex3f(54.0, 0, -54);  // v8.5
	glVertex3f(58.5, 0, -52);  // v9
	glVertex3f(58.5, 0, -74);  // v10
	glVertex3f(54.0, 0, -74);  // v8.5.1
	glEnd();

	// P1 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(0, -0.5, 0);  // v1
	glVertex3f(7, -0.5, -12);  // v2
	glVertex3f(7, -0.5, -26);  // v3
	glVertex3f(3.5, -0.5, -32);  // v4
	glVertex3f(0, -0.5, -32);  // v4.1
	glEnd();
	// P2 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(0, -0.5, -32);  // v4.1
	glVertex3f(3.5, -0.5, -32);  // v4
	glVertex3f(3.5, -0.5, -53);  // v5
	glVertex3f(0, -0.5, -53);  // v5.1
	glEnd();
	// P3 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(0, -0.5, -53);  // v5.1
	glVertex3f(3.5, -0.5, -53);  // v5
	glVertex3f(15, -0.5, -65);  // v6
	glVertex3f(15, -0.5, -74);  // v6.1
	glVertex3f(0, -0.5, -74);  // v11
	glEnd();
	// P4 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(15, -0.5, -65);  // v6
	glVertex3f(36.5, -0.5, -65);  // v7
	glVertex3f(36.5, -0.50, -74);  // v7.1
	glVertex3f(15, -0.5, -74);  // v6.1	
	glEnd();
	// P5 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(36.5, -0.50, -65);  // v7
	glVertex3f(50, -0.5, -57);  // v8
	glVertex3f(54.0, -0.5, -54);  // v8.5
	glVertex3f(54.0, -0.5, -74);  // v8.5.1
	glVertex3f(36.5, -0.5, -74);  // v7.1
	glEnd();
	// P6 ABAJO
	glBegin(GL_POLYGON);
	glVertex3f(54.0, -0.50, -54);  // v8.5
	glVertex3f(58.5, -0.5, -52);  // v9
	glVertex3f(58.5, -0.5, -74);  // v10
	glVertex3f(54.0, -0.5, -74);  // v8.5.1
	glEnd();

	// CARA 1
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);  // v1
	glVertex3f(0, 0, -74);  // v11
	glVertex3f(0, -0.5, -74);  // v11
	glVertex3f(0, -0.5, 0);  // v1
	glEnd();
	// CARA 2
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -74);  // v11
	glVertex3f(58.5, 0, -74);  // v10
	glVertex3f(58.5, -0.5, -74);  // v10
	glVertex3f(0, -0.5, -74);  // v11
	glEnd();
	// CARA 3
	glBegin(GL_POLYGON);
	glVertex3f(58.5, 0, -74);  // v10
	glVertex3f(58.5, 0, -52);  // v9
	glVertex3f(58.5, -0.5, -52);  // v9
	glVertex3f(58.5, -0.5, -74);  // v10
	glEnd();
	// CARA 4
	glBegin(GL_POLYGON);
	glVertex3f(58.5, 0, -74);  // v10
	glVertex3f(58.5, 0, -52);  // v9
	glVertex3f(58.5, -0.5, -52);  // v9
	glVertex3f(58.5, -0.5, -74);  // v10
	glEnd();
	// CARA 5
	glBegin(GL_POLYGON);
	glVertex3f(58.5, 0, -52);  // v9
	glVertex3f(54.0, 0, -54);  // v8.5
	glVertex3f(54.0, -0.5, -54);  // v8.5
	glVertex3f(58.5, -0.5, -52);  // v9
	glEnd();
	// CARA 6
	glBegin(GL_POLYGON);
	glVertex3f(50, 0, -57);  // v8
	glVertex3f(36.5, 0, -65);  // v7
	glVertex3f(36.5, -0.5, -65);  // v7
	glVertex3f(50, -0.5, -57);  // v8
	glEnd();
	// CARA 7
	glBegin(GL_POLYGON);
	glVertex3f(36.5, 0, -65);  // v7
	glVertex3f(15, 0, -65);  // v6
	glVertex3f(15, -0.5, -65);  // v6
	glVertex3f(36.5, -0.5, -65);  // v7
	glEnd();
	// CARA 8
	glBegin(GL_POLYGON);
	glVertex3f(15, 0, -65);  // v6
	glVertex3f(3.5, 0, -53);  // v5
	glVertex3f(3.5, -0.5, -53);  // v5
	glVertex3f(15, -0.5, -65);  // v6
	glEnd();
	// CARA 9
	glBegin(GL_POLYGON);
	glVertex3f(3.5, 0, -53);  // v5
	glVertex3f(3.5, 0, -32);  // v4
	glVertex3f(3.5, -0.5, -32);  // v4
	glVertex3f(3.5, -0.5, -53);  // v5
	glEnd();
	// CARA 10
	glBegin(GL_POLYGON);
	glVertex3f(3.5, 0, -32);  // v4
	glVertex3f(7, 0, -26);  // v3
	glVertex3f(7, -0.5, -26);  // v3
	glVertex3f(3.5, -0.5, -32);  // v4
	glEnd();
	// CARA 11
	glBegin(GL_POLYGON);
	glVertex3f(7, 0, -26);  // v3
	glVertex3f(7, 0, -12);  // v2
	glVertex3f(7, -0.5, -12);  // v2
	glVertex3f(7, -0.5, -26);  // v3
	glEnd();
	// CARA 12
	glBegin(GL_POLYGON);
	glVertex3f(7, 0, -12);  // v2
	glVertex3f(0, 0, 0);  // v1
	glVertex3f(0, -0.5, 0);  // v1
	glVertex3f(7, -0.5, -12);  // v2
	glEnd();
	/*
	glVertex3f(0,0,0);  // v1
	glVertex3f(7,0,-12);  // v2
	glVertex3f(7,0,-26);  // v3
	glVertex3f(3.5,0,-32);  // v4
	glVertex3f(3.5,0,-53);  // v5
	glVertex3f(15,0,-65);  // v6
	glVertex3f(36.5,0,-65);  // v7
	glVertex3f(50,0,-57);  // v8
	glVertex3f(54.0,0,-54);  // v8.5
	glVertex3f(58.5,0,-52);  // v9
	glVertex3f(58.5,0,-74);  // v10
	glVertex3f(0,0,-74);  // v11

	*/
}

void obsHJKR(int shape) {

	if (shape == 1) {
		glPushMatrix();
		glTranslatef(0.5, 0.5, -3);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-0.5, -0.5, 3);
		glTranslatef(0.5, 0.5, -3);
		c1_.cilindro(0.5, 3, 50, 0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.5, 3, -3);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-0.5, -3, 3);
		glTranslatef(0.5, 3, -3);
		c2_.cilindro(0.5, 3, 50, 0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(6.5, 0.5, -3);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-6.5, -0.5, 3);
		glTranslatef(6.5, 0.5, -3);
		c3_.cilindro(0.5, 3, 50, 0);
		glPopMatrix();

		// Triangulo 1
		glPushMatrix();
		glScalef(3, 2, 1);
		// Arriba
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glEnd();
		// Abajo
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, -0.5); // v1
		glVertex3f(3, 0, -0.5); // v2
		glVertex3f(0, 2, -0.5); // v3
		glEnd();
		// Cara 1
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(3, 0, -0.5);  //v2
		glVertex3f(0, 0, -0.5);  //v1
		glEnd();
		// Cara 2
		glBegin(GL_POLYGON);
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 2, -0.5);  // v3
		glVertex3f(3, 0, -0.5);  //v2
		glEnd();
		// Cara 3
		glBegin(GL_POLYGON);
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(0, 0, -0.5);  //v1
		glVertex3f(0, 2, -0.5);  // v3
		glEnd();
		glPopMatrix();

		// Triangulo 2
		glPushMatrix();
		glTranslatef(0, 0, -1);
		glScalef(3, 2, 1);
		// Arriba
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glEnd();
		// Abajo
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, -0.5); // v1
		glVertex3f(3, 0, -0.5); // v2
		glVertex3f(0, 2, -0.5); // v3
		glEnd();
		// Cara 1
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(3, 0, -0.5);  //v2
		glVertex3f(0, 0, -0.5);  //v1
		glEnd();
		// Cara 2
		glBegin(GL_POLYGON);
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 2, -0.5);  // v3
		glVertex3f(3, 0, -0.5);  //v2
		glEnd();
		// Cara 3
		glBegin(GL_POLYGON);
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(0, 0, -0.5);  //v1
		glVertex3f(0, 2, -0.5);  // v3
		glEnd();
		glPopMatrix();

		// Triangulo 3
		glPushMatrix();
		glTranslatef(0, 0, -2);
		glScalef(3, 2, 1);
		// Arriba
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glEnd();
		// Abajo
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, -0.5); // v1
		glVertex3f(3, 0, -0.5); // v2
		glVertex3f(0, 2, -0.5); // v3
		glEnd();
		// Cara 1
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(3, 0, -0.5);  //v2
		glVertex3f(0, 0, -0.5);  //v1
		glEnd();
		// Cara 2
		glBegin(GL_POLYGON);
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 2, -0.5);  // v3
		glVertex3f(3, 0, -0.5);  //v2
		glEnd();
		// Cara 3
		glBegin(GL_POLYGON);
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(0, 0, -0.5);  //v1
		glVertex3f(0, 2, -0.5);  // v3
		glEnd();
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(0.5, 0.5, -2.5);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-0.5, -0.5, 2.5);
		glTranslatef(0.5,0.5,-2.5);
		c1_.cilindro(0.5, 3, 50, 0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.5, 3, -2.5);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-0.5, -3, 2.5);
		glTranslatef(0.5, 3, -2.5);
		c2_.cilindro(0.5, 3, 50, 0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(6.5,0.5,-2.5);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-6.5,-0.5,2.5);
		glTranslatef(6.5, 0.5, -2.5);
		c3_.cilindro(0.5, 3, 50, 0);
		glPopMatrix();

		// Triangulo 1
		glPushMatrix();
		glScalef(3, 2, 1);
		// Arriba
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glEnd();
		// Abajo
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, -0.5); // v1
		glVertex3f(3, 0, -0.5); // v2
		glVertex3f(0, 2, -0.5); // v3
		glEnd();
		// Cara 1
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(3, 0, -0.5);  //v2
		glVertex3f(0, 0, -0.5);  //v1
		glEnd();
		// Cara 2
		glBegin(GL_POLYGON);
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 2, -0.5);  // v3
		glVertex3f(3, 0, -0.5);  //v2
		glEnd();
		// Cara 3
		glBegin(GL_POLYGON);
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(0, 0, -0.5);  //v1
		glVertex3f(0, 2, -0.5);  // v3
		glEnd();
		glPopMatrix();

		// Triangulo 2
		glPushMatrix();
		glTranslatef(0, 0, -1);
		glScalef(3, 2, 1);
		// Arriba
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glEnd();
		// Abajo
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, -0.5); // v1
		glVertex3f(3, 0, -0.5); // v2
		glVertex3f(0, 2, -0.5); // v3
		glEnd();
		// Cara 1
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(3, 0, -0.5);  //v2
		glVertex3f(0, 0, -0.5);  //v1
		glEnd();
		// Cara 2
		glBegin(GL_POLYGON);
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 2, -0.5);  // v3
		glVertex3f(3, 0, -0.5);  //v2
		glEnd();
		// Cara 3
		glBegin(GL_POLYGON);
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(0, 0, -0.5);  //v1
		glVertex3f(0, 2, -0.5);  // v3
		glEnd();
		glPopMatrix();

		// Triangulo 3
		glPushMatrix();
		glTranslatef(0, 0, -2);
		glScalef(3, 2, 1);
		// Arriba
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glEnd();
		// Abajo
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, -0.5); // v1
		glVertex3f(3, 0, -0.5); // v2
		glVertex3f(0, 2, -0.5); // v3
		glEnd();
		// Cara 1
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(3, 0, -0.5);  //v2
		glVertex3f(0, 0, -0.5);  //v1
		glEnd();
		// Cara 2
		glBegin(GL_POLYGON);
		glVertex3f(3, 0, 0);  //v2
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 2, -0.5);  // v3
		glVertex3f(3, 0, -0.5);  //v2
		glEnd();
		// Cara 3
		glBegin(GL_POLYGON);
		glVertex3f(0, 2, 0);  // v3
		glVertex3f(0, 0, 0);  //v1
		glVertex3f(0, 0, -0.5);  //v1
		glVertex3f(0, 2, -0.5);  // v3
		glEnd();
		glPopMatrix();
	}
}

void block() {
	glScalef(4,1,0.5);
	cube();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	if (_view_1) {

		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	}
	else {
		gluLookAt(objCamera_2.mPos.x, objCamera_2.mPos.y, objCamera_2.mPos.z,
			objCamera_2.mView.x, objCamera_2.mView.y, objCamera_2.mView.z,
			objCamera_2.mUp.x, objCamera_2.mUp.y, objCamera_2.mUp.z);

	}

	// ==================== FUENTES DE LUZ ==============================================
	// ---------------------------------------------------------------    FUENTE DE LUZ 1
	glPushMatrix();  

	glTranslatef(-97,-22,-123.5);
	glTranslatef(-17.5+92, 19.0+101.5, -90.5+290.5);

	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDirection);

	glPushMatrix();

	glDisable(GL_LIGHTING);

	if (!luz_1) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}

	glPopMatrix();
	glPopMatrix();   
	// ----------------------------------------------------------------   FUENTE DE LUZ 2
	glPushMatrix();  

	glTranslatef(16,9.5,-37);
	glTranslatef(8,-35,0);
	glTranslatef(-3,86,143.5);

	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);

	glPushMatrix();

	glDisable(GL_LIGHTING);

	if (!luz_2) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT1);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
	}

	glPopMatrix();
	glPopMatrix();                       
 // ----------------------------------------------------------------   FUENTE DE LUZ 3
	glPushMatrix();

	glTranslatef(-22.5,-24,-8);
	glTranslatef(-3, 86, 143.5);

	glLightfv(GL_LIGHT2, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, LightDirection);

	glPushMatrix();

	glDisable(GL_LIGHTING);

	if (!luz_3) {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT2);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT2);
	}

	glPopMatrix();
	glPopMatrix();                         // Termina fuente de luz
	// -----------------------------------------------------------  Termina fuente de luz



	// ==================================================================================

	glPushMatrix(); // ----------------   Carcasa PINBALL

		// Pata 1  (Colocada en el origen)
		glPushMatrix();
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_emerald);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_emerald);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_emerald);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_emerald);
				//glColor3f(0.5, 0.5, 0.5);
				glScalef(5.0, 50.0, 5.0);
				cube();
			glPopMatrix();
			// Pata 2
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_emerald);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_emerald);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_emerald);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_emerald);
				//glColor3f(0.5, 0.5, 0.5);
				glTranslatef(0.0, 0.0, 140.0);
				glScalef(5.0, 50.0, 5.0);
				cube();
			glPopMatrix();
			// Pata 3
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_emerald);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_emerald);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_emerald);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_emerald);
				//glColor3f(0.5, 0.5, 0.5);
				glTranslatef(-50.0, 0.0, 0.0);
				glScalef(5.0, 50.0, 5.0);
				cube();
			glPopMatrix();
				// Pata 4
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_emerald);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_emerald);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_emerald);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_emerald);
				//glColor3f(0.5, 0.5, 0.5);
				glTranslatef(-50.0, 0.0, 140.0);
				glScalef(5.0, 50.0, 5.0);
				cube();
			glPopMatrix();
			// Contenedor del score
			glPushMatrix();
			glTranslatef(-22,55.5,-118.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(180,0,1,0);
			glTranslatef(3,-86,-143.5);
			glTranslatef(-3, 86, 143.5);
			glScalef(28,7,1);
			glDisable(GL_LIGHTING);
			tabScore.prisma2(score.GLindex, back1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

		glPopMatrix();

		// Mesa 
		glPushMatrix();			

		// --> Cristal
		glPushMatrix();
		// ***** Habilitar transparencia
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		// *********************************
		glPushMatrix();
		glTranslatef(-55.0, 65.0, 144.0);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		glScalef(60.0, 20.0, 120.0);
		glDisable(GL_LIGHTING);
		vidrioTablero.prisma_rectangulo(glass.GLindex, back1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glDisable(GL_ALPHA_TEST);
		glDisable(GL_BLEND);

			// Parte A
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_chrome);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_chrome);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_chrome);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_chrome);
			glTranslatef(-25.0, 45, 69.5);
			glScalef(60.0, 40.0, 150.0);
			cube();
			glPopMatrix();
			// Parte B
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_obsidian);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_obsidian);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_obsidian);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_obsidian);
			glTranslatef(-25.0, 115.0, 9.5);
			glScalef(60.0, 60.0, 30.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glDisable(GL_LIGHTING);
			cabecera.prisma2(cabRnM.GLindex, back1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			// Parte B.1
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_chrome);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_chrome);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_chrome);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_chrome);
			glTranslatef(-25.0, 74.5, 9.5);
			glScalef(60.0, 21.0, 30.0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			cube();
			glPopMatrix();

			// ------- Palanca del resorte ------
			glPushMatrix();
			glTranslatef(0,0,movPal);
			glTranslatef(6.5, -22.5, -2);
			glTranslatef(-3, 86, 143.5);
			glRotatef(90,1,0,0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			palanca.cilindro(0.5,4,50,back2.GLindex);
			glPopMatrix();
			// ----------------------------------

			// Tablero	----------------------------------------
			glPushMatrix();

			// Prisma rectangular del tablero
			glPushMatrix();
			glTranslatef(-25.0, 64.5 + 6, 84.5);  //
			glRotatef(6.0, 1.0, 0.0, 0.0);  // Rotar para que este inclinado
			glTranslatef(25.0, -64.5, -85.0); //
			glTranslatef(-25.0, 64.5, 85.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(59.0, 119.0, 1.5);
			glDisable(GL_LIGHTING);
			tablero.prisma2(tabTextmain.GLindex, back1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			// Flipper 1
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);

			// MAX RX = 42

			glTranslatef(-22.5 - 18.5-4-2, 94.0 - 26.5, 39.0 + 85-2-2);
			glRotatef(rotF1, 0.0, 1.0, 0.0);
			glTranslatef(-(-22.5 - 18.5-4-2), -(94.0 - 26.5), -(39.0 + 85-2-2));

			glTranslatef(-4.5+2.5, 0.0, 0.0);
			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(-26, 0.0, 1.0, 0.0);
			glTranslatef(-(-22.5 - 18.5), -(94.0 - 26.5), -(39.0 + 85));

			glTranslatef(-4.5, 0.0, 0.0);
			glTranslatef(-22.5 -18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(10, 1.0, 0.0, 0.0);
			glTranslatef(-(-22.5 -18.5), -(94.0 - 26.5), -(39.0 + 85));
			
			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(11 * 0.1, 11 * 0.1, 1.0);
			flipper();
			glPopMatrix();


			// Flipper 2
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);

			// MAX RX = -42

			glTranslatef(-7,67.5,121.5);
			glRotatef(rotF2, 0.0, 1.0, 0.0);
			glTranslatef(-(-7), -(67.5), -(121.5));


			glTranslatef(33, 0.0, -2.0);
			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(26, 0.0, 1.0, 0.0);
			glTranslatef(-(-22.5 - 18.5), -(94.0 - 26.5), -(39.0 + 85));

			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(10, 1.0, 0.0, 0.0);
			glTranslatef(-(-22.5 - 18.5), -(94.0 - 26.5), -(39.0 + 85));

			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(180, 0.0, 1.0, 0.0);
			glTranslatef(-(-22.5 - 18.5), -(94.0 - 26.5), -(39.0 + 85));

			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(11 * 0.1, 11 * 0.1, 1.0);
			flipper();
			glPopMatrix();

			// Flipper 3
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);

			// MAX RX = 42
			glTranslatef(-38,73.5,69);
			glRotatef(rotF3, 0.0, 1.0, 0.0);
			glTranslatef(38,-73.5,-69);

			glTranslatef(9.5, 6, -53);

			glTranslatef(-4.5 + 2.5, 0.0, 0.0);
			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(-26, 0.0, 1.0, 0.0);
			glTranslatef(-(-22.5 - 18.5), -(94.0 - 26.5), -(39.0 + 85));

			glTranslatef(-4.5, 0.0, 0.0);
			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(10, 1.0, 0.0, 0.0);
			glTranslatef(-(-22.5 - 18.5), -(94.0 - 26.5), -(39.0 + 85));

			glTranslatef(-22.5 - 18.5, 94.0 - 26.5, 39.0 + 85);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(0.1*4, 0.1*4, 0.1*4);
			flipper();
			glPopMatrix();

			// Estructura debajo de flippers
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);
			glTranslatef(0, -3, -0.5);
			glTranslatef(-55, 68, 144.5);
			glRotatef(7, 1.0, 0.0, 0.0);
			glTranslatef(55, -68, -144.5);
			glTranslatef(-55, 68, 144.5);
			structFlip();
			glPopMatrix();

			// Carril de entrada 
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);
			glPushMatrix();
			glTranslatef(-3, 86, 143.5);
			carril_entrada();
			glPopMatrix();

			// ==============   Estruras del tablero   ===================
			glPushMatrix();
			//glTranslatef(-3+Cx, 86+Cy, 143.5+Cz);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);
			glTranslatef(-3-45.5, 86 - 16.5, 143.5 - 31);
			glRotatef(7, 1.0, 0.0, 0.0);
			glTranslatef(-(-3 -45.5), -(86 - 16.5), -(143.5 - 31));
			glTranslatef(-3 - 45.5, 86 - 16.5, 143.5 - 31);
			glScalef(3, 2, 18);
			cube();
			glPopMatrix();

			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);
			glTranslatef(-3 - 45.5+41.5, 86 - 16.5, 143.5 - 31);
			glRotatef(7, 1.0, 0.0, 0.0);
			glTranslatef(-(-3 - 45.5+41.5), -(86 - 16.5), -(143.5 - 31));
			glTranslatef(-3 - 45.5+41.5, 86 - 16.5, 143.5 - 31);
			glScalef(3, 2, 18);
			cube();
			glPopMatrix();

			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);
			glTranslatef(-3 - 51.5, 86 - 16, 143.5 - 45);
			glRotatef(7, 1.0, 0.0, 0.0);
			glTranslatef(-(-3 - 51.5), -(86 - 16), -(143.5 - 45));
			glTranslatef(-3 - 51.5, 86 - 16, 143.5 - 45);
			structTabb();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.5, -0.5, -1.5);
			glTranslatef(-3 + 1, 86 - 14.5, 143.5 - 57.5);
			glRotatef(7-1, 1,0,0);
			glTranslatef(-(-3 + 1), -(86 - 14.5), -(143.5 - 57.5));
			glTranslatef(-3 + 1, 86 - 14.5, 143.5 - 57.5);
			glScalef(3, 1, 58);
			cube();
			glPopMatrix();

			glPushMatrix();

			glTranslatef(-3 - 3, 86 - 11, 143.5 - 91);
			glRotatef(55, 0, 1, 0);
			glTranslatef(-(-3 -3), -(86 - 11), -(143.5 - 91));
			glTranslatef(-3 -3, 86 - 11, 143.5 - 91);
			glRotatef(7, 1, 0, 0);
			glTranslatef(-(-3 - 3), -(86 -11), -(143.5 - 91));
			glTranslatef(-3 - 3, 86 -11, 143.5 - 91);
			glScalef(3, 1, 14);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -33, 86-9, 143.5 -101.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -33), -(86 -9), -(143.5-101.5));
			glTranslatef(-3 -33, 86 -9, 143.5-101.5);
			glScalef(9, 3, 1);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -39.5, 86 -9, 143.5 -99.5);
			glRotatef(42, 0, 1, 0);
			glTranslatef(-(-3 -39.5), -(86 -9), -(143.5-99.5));
			glTranslatef(-3 -39.5, 86 -9, 143.5 -99.5);
			glRotatef(-4, 1, 0, 0);
			glTranslatef(-(-3 -39.5), -(86 -9), -(143.5-99.5));
			glTranslatef(-3 - 39.5, 86 -9, 143.5-99.5);
			glScalef(6, 3, 1);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -41.5, 86-10, 143.5-87);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -41.5), -(86-10), -(143.5-87));
			glTranslatef(-3 -41.5, 86-10, 143.5-87);
			glScalef(1, 3, 22);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -40.5, 86 -11.5, 143.5 -74);
			glRotatef(28, 0, 1, 0);
			glTranslatef(-(-3 -40.5), -(86 -11.5), -(143.5 -74));
			glTranslatef(-3 - 40.5, 86 - 11.5 , 143.5 -74);
			glRotatef(Rx, 1, 0, 0);
			glTranslatef(-(-3 -40.5), -(86 -11.5), -(143.5 -74));
			glTranslatef(-3 -40.5, 86 -11.5, 143.5 -74);
			glScalef(1, 3, 5);
			cube();
			glPopMatrix();

			glPushMatrix();

			glTranslatef(4.5,-0.5,1);
			glTranslatef(-3 - 31, 86 - 12, 143.5 - 68);
			glRotatef(-58, 0, 1, 0);
			glTranslatef(-(-3 - 31), -(86 - 12), -(143.5 - 68));

			glTranslatef(-3 -31, 86 -12, 143.5 -68);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -31), -(86 -12), -(143.5-68));
			glTranslatef(-3 -31, 86 -12, 143.5 -68);
			glScalef(7, 3, 1);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -30.5, 86 -12, 143.5 -70);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -30.5), -(86 -12), -(143.5 -70));
			glTranslatef(-3 -30.5, 86 -12, 143.5 -70);
			glScalef(6,3, 1);
			cube();
			glPopMatrix();


			glPushMatrix();
			glTranslatef(-3-8.5, 86 -13, 143.5 -63);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3-8.5), -(86-13), -(143.5-63));
			glTranslatef(-3-8.5, 86-13, 143.5-63);
			glScalef(4, 3, 1);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(9, 0.0, 5);
			glTranslatef(-3 - 5.5, 86 -12.5, 143.5 -64.5);
			glRotatef(-28.0, 0, 1, 0);
			glTranslatef(-(-3 + 5.5), -(86 -12.5), -(143.5-64.5));
			glTranslatef(-3 - 5.5, 86 - 12.5, 143.5 - 64.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -5.5), -(86 -12.5), -(143.5-64.5));
			glTranslatef(-3 - 5.5, 86 - 12.5, 143.5 - 64.5);
			glScalef(1, 3, 4);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -5.5, 86 -12, 143.5 -71.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -5.5), -(86 -12), -(143.5 -71.5));
			glTranslatef(-3 -5.5, 86 -12, 143.5 -71.5);
			glScalef(1, 3, 11);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -37, 86 -12, 143.5 -81.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -37), -(86-12), -(143.5-81.5));
			glTranslatef(-3 - 37, 86 - 12, 143.5 - 81.5);
			glScalef(1, 3, 11);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -36, 86-11.5, 143.5-75);
			glRotatef(-36, 0, 1, 0);
			glTranslatef(-(-3 -36), -(86-11), -(143.5-75));
			glTranslatef(-3 - 36, 86 - 11.5, 143.5 - 75);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 - 36), -(86 - 11), -(143.5 - 75));
			glTranslatef(-3 - 36, 86 - 11.5, 143.5 - 75);
			glScalef(3, 3, 1);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(75, -9.5, 37.5);
			glTranslatef(-3 -15.5, 86 -10, 143.5-94);
			glRotatef(62, 0, 1, 0);
			glTranslatef(-(-3 -15.5), -(86-10), -(143.5-94));
			glTranslatef(-3 - 15.5, 86 - 10, 143.5 - 94);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -15.5), -(86-10), -(143.5-9.4));
			glTranslatef(-3 - 15.5, 86 - 10, 143.5 - 94);
			glScalef(6, 3, 1);
			cube();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3 -22.5, 86 -9.5, 143.5 -101.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(-(-3 -22.5), -(86 -9.5), -(143.5 -101.5));
			glTranslatef(-3 - 22.5, 86 - 9.5, 143.5 - 101.5);
			glScalef(6, 3, 1);
			cube();
			glPopMatrix();

			// Objeto jerarquico 1
			glPushMatrix();
			glTranslatef(-38.5,-14,-46);
			glTranslatef(-3, 86, 143.5);
			glRotatef(-24, 0, 1, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(-90,1,0,0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3,86,143.5);
			obsHJKR(1);
			glPopMatrix();
			// Objeto jerarquico 2
			glPushMatrix();
			glTranslatef(-10,-15.5,-45.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(202, 0, 1, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(90, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			obsHJKR(2);
			glPopMatrix();

			// Objeto 3ds 1 (instancia 1)
			glPushMatrix();
			glTranslatef(-27,-14,-48.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(-152, 0, 1, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(6,1,0,0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glScalef(0.01*2, 0.01*2, 0.01*2);
			//sship.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
			// Objeto 3ds 1 (instancia 2)
			glPushMatrix();
			glTranslatef(9,0,0);
			glTranslatef(-27, -14, -48.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(144, 0, 1, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glScalef(0.01 * 2, 0.01 * 2, 0.01 * 2);
			//sship.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			// Objeto 3ds 2 (instancia 2)
			glPushMatrix();
			glTranslatef(-22.5,2,-13.5);
			glTranslatef(-10.5,-12.5,-77.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(182, 0, 1, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(-12,1,0,0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(-10, 0, 0, 1);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3,86,143.5);
			glScalef(0.01*2,0.01*2,0.01*2);
			//space.GLrender(NULL,_SHADED,1.0);
			glPopMatrix();

			// Objeto 3ds 2 (instancia 2)
			glPushMatrix();
			glTranslatef(0,0.5,5);
			glTranslatef(-10.5, -12.5, -77.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(4,0,1,0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(-12, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(-10, 0, 0, 1);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glScalef(0.01 * 2, 0.01 * 2, 0.01 * 2);
			//space.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			// Superficie con textura 1
			glPushMatrix();
			glTranslatef(-26,-20,-5.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(90,1,0,0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glScalef(31,11,0.1);
			glDisable(GL_LIGHTING);
			sup1.prisma2(tx1.GLindex,back2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			// Superficie con textura 2
			glPushMatrix();
			glTranslatef(-33.5,-12.5,-56.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(180, 0, 1, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glScalef(4,6,0.1);
			glDisable(GL_LIGHTING);
			sup2.prisma2(tx2.GLindex,back2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			// Superficie con textura 3
			
			glPushMatrix();
			glTranslatef(-6, -12.5, -56.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(180, 0, 1, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glRotatef(6, 1, 0, 0);
			glTranslatef(3, -86, -143.5);
			glTranslatef(-3, 86, 143.5);
			glScalef(4, 6, 0.1);
			glDisable(GL_LIGHTING);
			sup3.prisma2(tx3.GLindex, back2.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			

			

			// ===================  Resorte  ================================ 

			glPushMatrix();

			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_silver);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_silver);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_silver);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_silver);

			glTranslatef(-20, -2, -8);
			glRotatef(6, 1, 0, 0);
			glTranslatef(20,2,8);
			glTranslatef(-20, -2, -8);

			// A
			glPushMatrix();
			glTranslatef(22, 82.5, 141.5);
			block();
			glPopMatrix();
			
			// B  >> MASTER <<
			glPushMatrix();
			glTranslatef(0, 0, movB);
			glTranslatef(0, 0, -2);
			glTranslatef(22, 82.5, 141.5);
			block();
			glPopMatrix();
			// C
			glPushMatrix();
			glTranslatef(0, 0, movC);
			glTranslatef(0, 0, -4);
			glTranslatef(22, 82.5, 141.5);
			block();
			glPopMatrix();
			// D
			glPushMatrix();
			glTranslatef(0, 0, movD);
			glTranslatef(0, 0, -6);
			glTranslatef(22, 82.5, 141.5);
			block();
			glPopMatrix();
			// E
			glPushMatrix();
			glTranslatef(0, 0, movE);
			glTranslatef(0, 0, -8);
			glTranslatef(22, 82.5, 141.5);
			block();
			glPopMatrix();
			
			// Vertikal
			// vA
			glPushMatrix();
			glTranslatef(0,0,-1);
			glTranslatef(22, 82.5, 141.5);
			glRotatef(90,0,1,0);
			glTranslatef(-22, -82.5, -141.5);
			glTranslatef(22, 82.5, 141.5);
			glScalef(2,1,0.5);
			cube();
			glPopMatrix();
			// vB
			glPushMatrix();
			glTranslatef(0, 0, _movB);
			glTranslatef(0, 0, -3);
			glTranslatef(22, 82.5, 141.5);
			glRotatef(90, 0, 1, 0);
			glTranslatef(-22, -82.5, -141.5);
			glTranslatef(22, 82.5, 141.5);
			glScalef(2, 1, 0.5);
			cube();
			glPopMatrix();
			// vC
			glPushMatrix();
			glTranslatef(0, 0, _movC);
			glTranslatef(0, 0, -5);
			glTranslatef(22, 82.5, 141.5);
			glRotatef(90, 0, 1, 0);
			glTranslatef(-22, -82.5, -141.5);
			glTranslatef(22, 82.5, 141.5);
			glScalef(2, 1, 0.5);
			cube();
			glPopMatrix();
			// vD
			glPushMatrix();
			glTranslatef(0, 0, _movD);
			glTranslatef(0, 0, -7);
			glTranslatef(22, 82.5, 141.5);
			glRotatef(90, 0, 1, 0);
			glTranslatef(-22, -82.5, -141.5);
			glTranslatef(22, 82.5, 141.5);
			glScalef(2, 1, 0.5);
			cube();
			glPopMatrix();
			
			
			glPopMatrix();
			// ==============================================================
			/*
			glPushMatrix();
			glTranslatef(-3+Cx, 86+Cy, 143.5+Cz);
			glRotatef(6, 1,0,0);
			glTranslatef(-(-3 + Cx), -(86 + Cy), -(143.5 + Cz));
			glTranslatef(-3+Cx, 86+Cy, 143.5+Cz);
			glScalef(Sx, 3, Sz);
			cube();
			glPopMatrix();
			*/
			// ===========================================================

			// Canica 1
			glPushMatrix();
			glTranslatef(4.5,-19.3,-11);
			glTranslatef(-3,86,143.5);
			c1_.esfera(0.5, 50, 50, 0);
			glPopMatrix();

			glPopMatrix();  // FIN DEL TABLERO ----------------


		glPopMatrix(); // FIN DE LA MESA

	glPopMatrix(); // -----------------

	glPushMatrix();
	glTranslatef(-26, 159.5, 69);
	glScalef(369, 369, 369);
	glDisable(GL_LIGHTING);
	cuarto.cuboKuarto(pared2.GLindex, pared3.GLindex, pared1.GLindex, pared4.GLindex, piso.GLindex, piso.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glutSwapBuffers();
}

void animacion() {

	if (resorte) {             
		if (up) {                    // Resorte movimiento arriba
			if (i < 15) {
				movB -= 0.1;
			}
			else {
				movB -= 0;
			}
			if (i < 29) {
				movC -= 0.1;
			}
			else {
				movC -= 0;
			}
			if (i < 44) {
				movD -= 0.1;
			}
			else {
				movD -= 0;
			}
			if (i < 59) {
				movE -= 0.1;
			}
			else {
				movE -= 0;
			}
			// Bloques vertikales
			if (i < 18)
				_movB -= 0.1;
			else
				_movB -= 0;
			if (i < 41)
				_movC -= 0.1;
			else
				_movC -= 0;
			if (i < 60)
				_movD -= 0.1;
			else
				_movD -= 0;
			// Palanca
			if (i < 31)
				movPal -= 0.1;
			else
				movPal -= 0;

			if (i == 61) {
				i = 0;
				up = false;
				resorte = false;
			}
			else 
				i += 1;

		}
		else {                       // Resorte movimiento abajo
			// Mocimiento de barras horizontales
			if (i < 1380)
				movB += 0.001;
			else
				movB += 0;
			if (i < 2763)
				movC += 0.001;
			else
				movC += 0;
			if (i < 4164)
				movD += 0.001;
			else
				movD += 0;
			if (i < 5539)
				movE += 0.001;
			else
				movE += 0;
			// Movimiento de barras vecticales
			if (i < 1744)
				_movB += 0.001;
			else
				_movB += 0;
			if (i < 3771)
				_movC += 0.001;
			else
				_movC += 0;
			if (i < 5738)
				_movD += 0.001;
			else
				_movD += 0;

			// Palanca
			if (i < 3000)
				movPal += 0.001;
			else
				movPal += 0;

			if (i == 5738) {
				up = true;
				i = 0;
			}
			i += 1;
		}
	}

	
	glutPostRedisplay();
}

void InitGL(GLvoid) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);

	// --- Fuente de luz
	glLightfv(GL_LIGHT0, GL_POSITION, Light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Light_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light_specular);

	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position_1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_diffuse_1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, Light_ambient_1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Light_specular_1);

	glLightfv(GL_LIGHT2, GL_POSITION, Light_Position_1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Light_diffuse_2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, Light_ambient_2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, Light_specular_2);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	glEnable(GL_BLEND);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	// -- Inicializar texturas
	cabRnM.LoadTGA("tablerornm.tga");
	cabRnM.BuildGLTexture();
	cabRnM.ReleaseImage();

	glass.LoadTGA("glass.tga");
	glass.BuildGLTexture();
	glass.ReleaseImage();

	tabTextmain.LoadTGA("mainTab.tga");
	tabTextmain.BuildGLTexture();
	tabTextmain.ReleaseImage();

	pared1.LoadTGA("pared1.tga");
	pared1.BuildGLTexture();
	pared1.ReleaseImage();

	pared2.LoadTGA("pared2.tga");
	pared2.BuildGLTexture();
	pared2.ReleaseImage();

	pared3.LoadTGA("pared3.tga");
	pared3.BuildGLTexture();
	pared3.ReleaseImage();

	pared4.LoadTGA("pared4.tga");
	pared4.BuildGLTexture();
	pared4.ReleaseImage();

	piso.LoadTGA("floor.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	score.LoadTGA("0segment.tga");
	score.BuildGLTexture();
	score.ReleaseImage();

	tx1.LoadTGA("tx1.tga");
	tx1.BuildGLTexture();
	tx1.ReleaseImage();

	tx2.LoadTGA("tx2.tga");
	tx2.BuildGLTexture();
	tx2.ReleaseImage();

	tx3.LoadTGA("tx3.tga");
	tx3.BuildGLTexture();
	tx3.ReleaseImage();

	back1.LoadTGA("back1.tga");
	back1.BuildGLTexture();
	back1.ReleaseImage();

	back2.LoadTGA("back2.tga");
	back2.BuildGLTexture();
	back2.ReleaseImage();

	sship._3dsLoad("sship.3ds");
	moon._3dsLoad("moon.3ds");
	space._3dsLoad("space.3ds");

	objCamera.Position_Camera(-24, 91.5, 165.5, -24, 31, 0, 0, 1, 0);
	objCamera_2.Position_Camera(-24.5, 75.5, 49.5, -48, 66.5, 376, 0, 1, 0); 

}

void reshape(int width, int height) {

	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-0.05, 0.05, -0.05, 0.05, 0.05, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	// Control de luces
	case '1':
		luz_1 = !luz_1;
		if (luz_1)
			cout << "Luz 1 encendida" << endl;
		else
			cout << "Luz 1 apagada" << endl;
		break;
	case '2':
		luz_2 = !luz_2;
		if (luz_2)
			cout << "Luz 2 encendida" << endl;
		else
			cout << "Luz 2 apagada" << endl;
		break;
	case '3':
		luz_3 = !luz_3;
		if (luz_3)
			cout << "Luz 3 encendida" << endl;
		else
			cout << "Luz 3 apagada" << endl;
		break;
	// Control del resorte
	case 'r':
	case 'R':
		resorte = !resorte;
		if (resorte)
			cout << "Resorte activado" << endl;
		else
			cout << "Resorte desactivado" << endl;
		break;
	// Camara
	case '0':
		_view_1 = !_view_1;
		break;
	//Movimientos de camara
	case 'w':   
	case 'W':
		if (_view_1)
			objCamera.Move_Camera(0.01);
		else {
			if (vDown) {
				objCamera_2.Move_Camera(0.001);
				objCamera_2.UpDown_Camera(-0.003);
			}
			else {
				objCamera_2.Move_Camera(0.001);
				objCamera_2.UpDown_Camera(0.003);
			}
		}
		break;

	case 's':
	case 'S':
		if (_view_1)
			objCamera.Move_Camera(-0.01);
		else {
			if (vDown) {
				objCamera_2.Move_Camera(-0.001);
				objCamera_2.UpDown_Camera(0.003);
			}
			else {
				objCamera_2.Move_Camera(-0.001);
				objCamera_2.UpDown_Camera(-0.003);
			}
		}
		break;

	case 'a':
	case 'A':
		if (_view_1)
			objCamera.Strafe_Camera(-0.01);
		else
			objCamera_2.Strafe_Camera(-0.001);
		break;

	case 'd':
	case 'D':
		if (_view_1)
			objCamera.Strafe_Camera(0.01);
		else 
			objCamera_2.Strafe_Camera(0.001);
		break;
	case 'q':
	case 'Q':
		if (_view_1)
			objCamera.UpDown_Camera(CAMERASPEED + 0.4);
		else
			objCamera_2.UpDown_Camera(CAMERASPEED + 0.4);
		break;
	case 'e':
	case 'E':
		if (_view_1)
			objCamera.UpDown_Camera(-(CAMERASPEED + 0.4));
		else 
			objCamera_2.UpDown_Camera(-(CAMERASPEED + 0.4));
		break;
	// Movimiento de los flippers
	case '4':          // Flipper 1
		flip1 = !flip1;
		if (flip1)
			rotF1 = 42;
		else
			rotF1 = 0;
		break;
	case '5':          // Flipper 2
		flip2 = !flip2;
		if (flip2)
			rotF2 = -42;
		else
			rotF2 = 0;
		break;
	case '6':          // Flipper 3
		flip3 = !flip3;
		if (flip3)
			rotF3 = 42;
		else
			rotF3 = 0;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y) {

	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		if (_view_1)
			objCamera.UpDown_Camera(CAMERASPEED);
		else
			objCamera_2.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		if (_view_1)
			objCamera.UpDown_Camera(-CAMERASPEED);
		else
			objCamera_2.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		if (_view_1)
			objCamera.Rotate_View(-CAMERASPEED);
		else {
			objCamera_2.Rotate_View(-CAMERASPEED);
			rView -= 0.07;
			if (rView >= -4.13 && rView <= -2.24) {
				vDown = false;
			}
			else 
				vDown = true;
		}
		break;

	case GLUT_KEY_RIGHT:
		if (_view_1)
			objCamera.Rotate_View(CAMERASPEED);
		else {
			objCamera_2.Rotate_View(CAMERASPEED);
			rView += 0.07;
			if (rView >= -4.13 && rView <= -2.24) {
				vDown = false;
			}
			else
				vDown = true;
		}
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

	if (button == GLUT_RIGHT_BUTTON) {
		resorte = !resorte;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Pinball");

	InitGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrow_keys);
	glutIdleFunc(animacion);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}
