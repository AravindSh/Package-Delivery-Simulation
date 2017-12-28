//#include<stdio.h>
//#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<Windows.h>

int sh1 = 11 ;
int sh2 = 12 ;
int sh3 = 13 ;
int sh4 = 14 ;

int dh1 = 21 ;
int dh2 = 22 ;
int dh3 = 23 ;
int dh4 = 24 ;

float speed=1;

char city[4][20]={{"city1"},{"city2"},{"city3"},{"city4"}};

float city_vtx[4][3];


char area[8][20]={{"a1"},{"a2"},{"a3"},{"a4"},{"a5"},{"a6"},{"a7"},{"a8"}};


char house[16][20]={{"h1"},{"h2"},{"h3"},{"h4"},{"h5"},{"h6"},{"h7"},{"h8"},
{"h9"},{"h10"},{"h11"},{"h12"},{"h13"},{"h14"},{"h15"},{"h16"}};

float house_vtx[16][3];


//char src_city[20],dest_city[20],src_area[20],
//	 dest_area[20],src_house[20],dest_house[20];

int src_city_index,dest_city_index,src_area_index,dest_area_index,
	src_house_index,dest_house_index;


int start_area_index_src,start_house_index_src,
	start_area_index_dest,start_house_index_dest;


double x, y, z, x1, y12, z1, x11, y11, z11;

int sh = 0,dh = 0;

float flag = 0.0;

int disp_flag=0;

double CONV=3.14159/180.0;


GLfloat theta[15] = {0.0};

GLdouble viewer_eye[15][3] = {0.0};

GLfloat colors[8][3] = { { 1, 1, 0 }, { 1.5, 0.1, 1 }, 
					{ 0, 1.2, 1 }, { 0, 1, 0.5 }, { 0, 0.8, 0 }, { 0.2, 1, 1.5 }, 
					{ 1, 0, 1.9 }, { 1, 0, 0 } };


void drawMapTexti(char*string1=NULL,double x=0.0,double y=0.0,double z=0.0
					 ,double scale=0.0)
{
	  unsigned int i;
	  
	  glPushMatrix();
	  glTranslatef(x,y,z);
	  glScalef(scale,scale,scale);
	 
	  for (i = 0; i<strlen(string1); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string1[i]);

	  glPopMatrix();
}


void map_draw()
{
	int x,y,j=-1;
	

	glColor3f(1,0,1);
	//city main offices
	for (x = 0; x <= (12 * 3); x += 12)
	{
		j++;
		drawMapTexti(city[j],6+x,17.2,0,0.007);
		glBegin(GL_POLYGON);
		glVertex3f(6 + x, 17, 0);
		glVertex3f(8 + x, 17, 0);
		glVertex3f(8 + x, 15, 0);
		glVertex3f(6 + x, 15, 0);
		glEnd();

	}
	j=0;
	glColor3f(0, 0, 1);
	//1st area post offices
	for (x = 0; x <= (12 * 3); x += 12)
	{

		drawMapTexti(area[j],2+x,10.2,0,0.007);
		j+=2;
		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(4 + x, 10, 0);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(2 + x, 8, 0);
		glEnd();

	}

		j=1;
	//2nd area post offices
	for (x = 0; x <= (12 * 3); x += 12)
	{
		drawMapTexti(area[j],6+x,10.2,0,0.007);
		j+=2;

		x = x + 4;

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(4 + x, 10, 0);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(2 + x, 8, 0);
		glEnd();
		x = x - 4;
	}

	glColor3f(0,0.6,0);
	j=0;
	//1 st houses

	for (x = 0; x <= (12 * 3); x += 12)
	{
		drawMapTexti(house[j],3.5+x,2,0,0.007);
		j+=4;

		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();
	}

	j=1;
	//2 nd houses

	for (x = 0; x <= (12 * 3); x += 12)
	{
		drawMapTexti(house[j],5.5+x,2,0,0.007);
		j+=4;

		x += 2;
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();

		x -= 2;
	}

	//3rd houses
	j=2;
	for (x = 0; x <= (12 * 3); x += 12)
	{
		drawMapTexti(house[j],7.5+x,2,0,0.007);
		j+=4;

		x += 4;
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();

		x -= 4;
	}

	//4th houses
	j=3;
	for (x = 0; x <= (12 * 3); x += 12)
	{
		drawMapTexti(house[j],9.5+x,2,0,0.007);
		j+=4;

		x += 6;
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();

		x -= 6;
	}

	glColor3f(1,0,0);

	//horizontal  line to connect cities
	//middle line

	glBegin(GL_LINE_STRIP);
	glVertex2f(7, 14);
	glVertex2f(43, 14);
	glEnd();

	//top line

	for (x = 0; x <= (12 * 2); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 14.5);
		glVertex2f(18.5 + x, 14.5);

		glEnd();
	}

	//bottom line
	for (x = 0; x <= (12 * 2); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 13.5);
		glVertex2f(18.5 + x, 13.5);

		glEnd();
	}

	//middle road line


	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7 + x, 15);
		glVertex2f(7 + x, 12);
		glVertex2f(5 + x, 12);
		glVertex2f(5 + x, 6);
		glVertex2f(4 + x, 6);
		glVertex2f(4 + x, 5);
		glEnd();
	}

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(5 + x, 6);
		glVertex2f(6 + x, 6);
		glVertex2f(6 + x, 5);
		glEnd();
	}

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7 + x, 12);
		glVertex2f(9 + x, 12);
		glVertex2f(9 + x, 6);
		glVertex2f(10 + x, 6);
		glVertex2f(10 + x, 5);
		glEnd();
	}

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(9 + x, 6);
		glVertex2f(8 + x, 6);
		glVertex2f(8 + x, 5);
		glEnd();
	}

	//road left outer

	//1 part
	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(6.5 + x, 15);
		glVertex2f(6.5 + x, 14.5);
		glEnd();
	}

	//2 part
	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(6.5 + x, 13.5);
		glVertex2f(6.5 + x, 12.5);
		glVertex2f(4.5 + x, 12.5);
		glVertex2f(4.5 + x, 9.5);
		glVertex2f(4 + x, 9.5);
		glEnd();
	}

	//3 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(4 + x, 8.5);
		glVertex2f(4.5 + x, 8.5);
		glVertex2f(4.5 + x, 6.5);
		glVertex2f(3.5 + x, 6.5);
		glVertex2f(3.5 + x, 5);
		glEnd();
	}
	//road middle outer 1

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(4.5 + x, 5);
		glVertex2f(4.5 + x, 5.5);
		glVertex2f(5.5 + x, 5.5);
		glVertex2f(5.5 + x, 5);
		glEnd();
	}



	//road middle outer 2

	for (x = 0; x <= (12 * 3); x += 12)
	{
		x += 4;
		glBegin(GL_LINE_STRIP);
		glVertex2f(4.5 + x, 5);
		glVertex2f(4.5 + x, 5.5);
		glVertex2f(5.5 + x, 5.5);
		glVertex2f(5.5 + x, 5);
		glEnd();
		x -= 4;
	}

	//road right outer


	//1 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 15);
		glVertex2f(7.5 + x, 14.5);
		glEnd();
	}

	//2 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 13.5);
		glVertex2f(7.5 + x, 12.5);
		glVertex2f(9.5 + x, 12.5);
		glVertex2f(9.5 + x, 6.5);
		glVertex2f(10.5 + x, 6.5);
		glVertex2f(10.5 + x, 5);
		glEnd();
	}

	//inner road

	//1 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(6.5 + x, 5);
		glVertex2f(6.5 + x, 6.5);
		glVertex2f(5.5 + x, 6.5);
		glVertex2f(5.5 + x, 11.5);
		glVertex2f(8.5 + x, 11.5);
		glVertex2f(8.5 + x, 9.5);
		glVertex2f(8 + x, 9.5);
		glEnd();
	}

	//2 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(8 + x, 8.5);
		glVertex2f(8.5 + x, 8.5);
		glVertex2f(8.5 + x, 6.5);
		glVertex2f(7.5 + x, 6.5);
		glVertex2f(7.5 + x, 5);
		glEnd();
	}

}




void city_draw()
{
	int x,y;
	
	//city main offices
	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_POLYGON);
		glColor3fv(colors[0]);
		glVertex3f(6 + x, 17, 0);
		glVertex3f(8 + x, 17, 0);
		glVertex3f(8 + x, 15, 0);
		glVertex3f(6 + x, 15, 0);
		glEnd();


		glColor3fv(colors[4]);

		glBegin(GL_POLYGON);
		glVertex3f(6 + x, 17, 0);
		glVertex3f(6 + x, 17, 4);
		glVertex3f(8 + x, 17, 4);
		glVertex3f(8 + x, 17, 0);
		glEnd();

		//front face of main building
		glColor3fv(colors[5]);

		glBegin(GL_POLYGON);
		glVertex3f(6 + x, 15, 0);
		glVertex3f(8 + x, 15, 0);
		glVertex3f(8 + x, 15, 4);
		glVertex3f(6 + x, 15, 4);
		glEnd();

		//front face design start
		//door
		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(6.5 + x, 15 - 0.0001, 0);
		glVertex3f(7.5 + x, 15 - 0.0001, 0);
		glVertex3f(7.5 + x, 15 - 0.0001, 1);
		glVertex3f(6.5 + x, 15 - 0.0001, 1);

		glEnd();

		//windows
		for (y = 0; y < 2; y++)
		{


			glColor3fv(colors[6]);
			glBegin(GL_POLYGON);
			glVertex3f(6.2 + y + x, 15 - 0.0001, 1.5);
			glVertex3f(6.7 + y + x, 15 - 0.0001, 1.5);
			glVertex3f(6.7 + y + x, 15 - 0.0001, 2);
			glVertex3f(6.2 + y + x, 15 - 0.0001, 2);
			glEnd();

			glColor3fv(colors[6]);
			glBegin(GL_POLYGON);
			glVertex3f(6.2 + y + x, 15 - 0.0001, 2.5);
			glVertex3f(6.7 + y + x, 15 - 0.0001, 2.5);
			glVertex3f(6.7 + y + x, 15 - 0.0001, 3);
			glVertex3f(6.2 + y + x, 15 - 0.0001, 3);
			glEnd();


		}

		//front face design ends
		glColor3fv(colors[2]);

		glBegin(GL_POLYGON);
		glVertex3f(6 + x, 17, 0);
		glVertex3f(6 + x, 15, 0);
		glVertex3f(6 + x, 15, 4);
		glVertex3f(6 + x, 17, 4);
		glEnd();


		glColor3fv(colors[3]);

		glBegin(GL_POLYGON);
		glVertex3f(8 + x, 15, 0);
		glVertex3f(8 + x, 17, 0);
		glVertex3f(8 + x, 17, 4);
		glVertex3f(8 + x, 15, 4);
		glEnd();

		glColor3fv(colors[3]);

		glBegin(GL_POLYGON);
		glVertex3f(6 + x, 17, 4);
		glVertex3f(6 + x, 15, 4);
		glVertex3f(8 + x, 15, 4);
		glVertex3f(8 + x, 17, 4);
		glEnd();


	}
	glColor3f(0.0, 0.0, 0.0);
	//1st area post offices
	for (x = 0; x <= (12 * 3); x += 12)
	{
		glColor3fv(colors[0]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(4 + x, 10, 0);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(2 + x, 8, 0);
		glEnd();

		glColor3fv(colors[4]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(2 + x, 10, 3);
		glVertex3f(4 + x, 10, 3);
		glVertex3f(4 + x, 10, 0);
		glEnd();

		glColor3fv(colors[2]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(2 + x, 8, 0);
		glVertex3f(2 + x, 8, 3);
		glVertex3f(2 + x, 10, 3);
		glEnd();

		glColor3fv(colors[3]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 8, 0);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(4 + x, 8, 3);
		glVertex3f(2 + x, 8, 3);
		glEnd();

		glColor3fv(colors[4]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 3);
		glVertex3f(2 + x, 8, 3);
		glVertex3f(4 + x, 8, 3);
		glVertex3f(4 + x, 10, 3);
		glEnd();

		//front face
		glColor3fv(colors[5]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(4 + x, 10, 0);
		glVertex3f(4 + x, 10, 3);
		glVertex3f(4 + x, 8, 3);
		glEnd();

		//front design starts
		//door

		glColor3fv(colors[7]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + 0.0001 + x, 8.5, 0);
		glVertex3f(4 + 0.0001 + x, 9.5, 0);
		glVertex3f(4 + 0.0001 + x, 9.5, 0.8);
		glVertex3f(4 + 0.0001 + x, 8.5, 0.8);
		glEnd();

		//windows

		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + 0.0001 + x, 8.2, 1.5);
		glVertex3f(4 + 0.0001 + x, 8.8, 1.5);
		glVertex3f(4 + 0.0001 + x, 8.8, 2);
		glVertex3f(4 + 0.0001 + x, 8.2, 2);
		glEnd();

		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + 0.0001 + x, 9.2, 1.5);
		glVertex3f(4 + 0.0001 + x, 9.8, 1.5);
		glVertex3f(4 + 0.0001 + x, 9.8, 2);
		glVertex3f(4 + 0.0001 + x, 9.2, 2);
		glEnd();

		//design ends





	}

	//2nd area post offices
	for (x = 0; x <= (12 * 3); x += 12)
	{
		x = x + 4;

		glColor3fv(colors[0]);
		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(4 + x, 10, 0);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(2 + x, 8, 0);
		glEnd();

		glColor3fv(colors[4]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(2 + x, 10, 3);
		glVertex3f(4 + x, 10, 3);
		glVertex3f(4 + x, 10, 0);
		glEnd();

		glColor3fv(colors[2]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 0);
		glVertex3f(2 + x, 8, 0);
		glVertex3f(2 + x, 8, 3);
		glVertex3f(2 + x, 10, 3);
		glEnd();

		glColor3fv(colors[3]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 8, 0);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(4 + x, 8, 3);
		glVertex3f(2 + x, 8, 3);
		glEnd();

		glColor3fv(colors[4]);

		glBegin(GL_POLYGON);
		glVertex3f(2 + x, 10, 3);
		glVertex3f(2 + x, 8, 3);
		glVertex3f(4 + x, 8, 3);
		glVertex3f(4 + x, 10, 3);
		glEnd();

		//front face
		glColor3fv(colors[5]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + x, 8, 0);
		glVertex3f(4 + x, 10, 0);
		glVertex3f(4 + x, 10, 3);
		glVertex3f(4 + x, 8, 3);
		glEnd();

		//front design starts
		//door

		glColor3fv(colors[7]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + 0.0001 + x, 8.5, 0);
		glVertex3f(4 + 0.0001 + x, 9.5, 0);
		glVertex3f(4 + 0.0001 + x, 9.5, 0.8);
		glVertex3f(4 + 0.0001 + x, 8.5, 0.8);
		glEnd();

		//windows

		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + 0.0001 + x, 8.2, 1.5);
		glVertex3f(4 + 0.0001 + x, 8.8, 1.5);
		glVertex3f(4 + 0.0001 + x, 8.8, 2);
		glVertex3f(4 + 0.0001 + x, 8.2, 2);
		glEnd();

		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4 + 0.0001 + x, 9.2, 1.5);
		glVertex3f(4 + 0.0001 + x, 9.8, 1.5);
		glVertex3f(4 + 0.0001 + x, 9.8, 2);
		glVertex3f(4 + 0.0001 + x, 9.2, 2);
		glEnd();

		//design ends


		x = x - 4;
	}
	//1 st houses

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glColor3fv(colors[4]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();

		//front face of house
		glColor3fv(colors[2]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//front design start
		//door
		glColor3fv(colors[7]);

		glBegin(GL_POLYGON);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0.5);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0.5);
		glEnd();

		//windows


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.9);
		glEnd();


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.9);
		glEnd();

		//design ends

		glColor3fv(colors[2]);				//left side face
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();

		glColor3fv(colors[2]);
		glBegin(GL_POLYGON);				//back face
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glEnd();

/*		glColor3fv(colors[5]);		//top face
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();
*/

		glColor3fv(colors[2]);
		glBegin(GL_POLYGON);				//ri8 face
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//triangle roof

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();
	}

	//2 nd houses

	for (x = 0; x <= (12 * 3); x += 12)
	{
		x += 2;
		glColor3fv(colors[4]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();

		//front face of house
		glColor3fv(colors[2]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//front design start
		//door
		glColor3fv(colors[7]);

		glBegin(GL_POLYGON);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0.5);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0.5);
		glEnd();

		//windows


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.9);
		glEnd();


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.9);
		glEnd();

		//design ends

		glColor3fv(colors[2]);
		glBegin(GL_POLYGON);			//left
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();

		glColor3fv(colors[2]);			//back
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glEnd();

/*		glColor3fv(colors[5]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();
*/

		glColor3fv(colors[2]);					//ri8
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//triangle roof

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();
		x -= 2;
	}

	//3rd houses

	for (x = 0; x <= (12 * 3); x += 12)
	{
		x += 4;
		glColor3fv(colors[4]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();

		//front face of house
		glColor3fv(colors[2]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//front design start
		//door
		glColor3fv(colors[7]);

		glBegin(GL_POLYGON);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0.5);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0.5);
		glEnd();

		//windows


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.9);
		glEnd();


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.9);
		glEnd();

		//design ends

		glColor3fv(colors[2]);		//left
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();

		glColor3fv(colors[2]);			//back
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glEnd();

/*		glColor3fv(colors[5]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();
*/

		glColor3fv(colors[2]);			//ri8
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//triangle roof

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();
		x -= 4;
	}

	//4th houses

	for (x = 0; x <= (12 * 3); x += 12)
	{
		x += 6;
		glColor3fv(colors[4]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glEnd();

		//front face of house
		glColor3fv(colors[2]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//front design start
		//door
		glColor3fv(colors[7]);

		glBegin(GL_POLYGON);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0);
		glVertex3f(4.2 + x, 4.5 + 0.0001, 0.5);
		glVertex3f(3.8 + x, 4.5 + 0.0001, 0.5);
		glEnd();

		//windows


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(3.9 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(3.6 + x, 4.5 + 0.0001, 0.9);
		glEnd();


		glColor3fv(colors[6]);

		glBegin(GL_POLYGON);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.7);
		glVertex3f(4.4 + x, 4.5 + 0.0001, 0.9);
		glVertex3f(4.1 + x, 4.5 + 0.0001, 0.9);
		glEnd();

		//design ends

		glColor3fv(colors[2]);				//left
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 0);
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();

		glColor3fv(colors[2]);			//back
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glEnd();

/*		glColor3fv(colors[5]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glEnd();
*/

		glColor3fv(colors[2]);		//ri8
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 0);
		glVertex3f(4.5 + x, 4.5, 0);
		glEnd();

		//triangle roof

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 3.5, 1);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(4.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();

		glColor3fv(colors[7]);
		glBegin(GL_POLYGON);
		glVertex3f(3.5 + x, 4.5, 1);
		glVertex3f(3.5 + x, 3.5, 1);
		glVertex3f(4 + x, 4, 2);
		glEnd();
		x -= 6;
	}

	//horizontal  line to connect cities
	//middle line

	glBegin(GL_LINE_STRIP);
	glVertex2f(7, 14);
	glVertex2f(43, 14);
	glEnd();

	//top line

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 14.5);
		glVertex2f(18.5 + x, 14.5);

		glEnd();
	}

	//bottom line
	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 13.5);
		glVertex2f(18.5 + x, 13.5);

		glEnd();
	}

	//middle road line


	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7 + x, 15);
		glVertex2f(7 + x, 12);
		glVertex2f(5 + x, 12);
		glVertex2f(5 + x, 6);
		glVertex2f(4 + x, 6);
		glVertex2f(4 + x, 5);
		glEnd();
	}

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(5 + x, 6);
		glVertex2f(6 + x, 6);
		glVertex2f(6 + x, 5);
		glEnd();
	}

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7 + x, 12);
		glVertex2f(9 + x, 12);
		glVertex2f(9 + x, 6);
		glVertex2f(10 + x, 6);
		glVertex2f(10 + x, 5);
		glEnd();
	}

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(9 + x, 6);
		glVertex2f(8 + x, 6);
		glVertex2f(8 + x, 5);
		glEnd();
	}

	//road left outer

	//1 part
	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(6.5 + x, 15);
		glVertex2f(6.5 + x, 14.5);
		glEnd();
	}

	//2 part
	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(6.5 + x, 13.5);
		glVertex2f(6.5 + x, 12.5);
		glVertex2f(4.5 + x, 12.5);
		glVertex2f(4.5 + x, 9.5);
		glVertex2f(4 + x, 9.5);
		glEnd();
	}

	//3 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(4 + x, 8.5);
		glVertex2f(4.5 + x, 8.5);
		glVertex2f(4.5 + x, 6.5);
		glVertex2f(3.5 + x, 6.5);
		glVertex2f(3.5 + x, 5);
		glEnd();
	}
	//road middle outer 1

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(4.5 + x, 5);
		glVertex2f(4.5 + x, 5.5);
		glVertex2f(5.5 + x, 5.5);
		glVertex2f(5.5 + x, 5);
		glEnd();
	}



	//road middle outer 2

	for (x = 0; x <= (12 * 3); x += 12)
	{
		x += 4;
		glBegin(GL_LINE_STRIP);
		glVertex2f(4.5 + x, 5);
		glVertex2f(4.5 + x, 5.5);
		glVertex2f(5.5 + x, 5.5);
		glVertex2f(5.5 + x, 5);
		glEnd();
		x -= 4;
	}

	//road right outer


	//1 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 15);
		glVertex2f(7.5 + x, 14.5);
		glEnd();
	}

	//2 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(7.5 + x, 13.5);
		glVertex2f(7.5 + x, 12.5);
		glVertex2f(9.5 + x, 12.5);
		glVertex2f(9.5 + x, 6.5);
		glVertex2f(10.5 + x, 6.5);
		glVertex2f(10.5 + x, 5);
		glEnd();
	}

	//inner road

	//1 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(6.5 + x, 5);
		glVertex2f(6.5 + x, 6.5);
		glVertex2f(5.5 + x, 6.5);
		glVertex2f(5.5 + x, 11.5);
		glVertex2f(8.5 + x, 11.5);
		glVertex2f(8.5 + x, 9.5);
		glVertex2f(8 + x, 9.5);
		glEnd();
	}

	//2 part

	for (x = 0; x <= (12 * 3); x += 12)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(8 + x, 8.5);
		glVertex2f(8.5 + x, 8.5);
		glVertex2f(8.5 + x, 6.5);
		glVertex2f(7.5 + x, 6.5);
		glVertex2f(7.5 + x, 5);
		glEnd();
	}

}


void drawStrokeText1(char*string1,char*string2, 
					 double x, double y, double z, double scale)//city text
{
	unsigned int i;
	glPushMatrix();

	glColor3f(0, 0, 0);

	glTranslatef(x, y, z);
	glRotatef(90, 1, 0, 0);
	glScalef(scale, scale, scale);

	for (i = 0; i<strlen(string1); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string1[i]);

	for (i = 0; i<strlen(string2); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string2[i]);

	glPopMatrix();
}

void drawStrokeText2(char*string1,char*string2,
					 double x, double y, double z, double scale)//area text
{
	unsigned int i;
	glPushMatrix();

	glColor3f(0, 0, 0);

	glTranslatef(x, y, z);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(scale, scale, scale);
	
	for (i = 0; i<strlen(string1); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string1[i]);

	for (i = 0; i<strlen(string2); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string2[i]);

	glPopMatrix();
}

void drawStrokeText3(char*string, double x,
					 double y, double z, double scale)//house text
{
	unsigned int i;
	glPushMatrix();

	glColor3f(0, 0, 0);

	glTranslatef(x, y, z);
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glScalef(scale, scale, scale);

	for (i = 0; i<strlen(string); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);

	glPopMatrix();
}

void drawStrokeTexti(char*string1=NULL,char*string2=NULL,
					 double x=0.0,double y=0.0,double z=0.0
					 ,double scale=0.0)
{
	  unsigned int i;
	  
	  glPushMatrix();
	  glTranslatef(x,y,z);
	  glScalef(scale,scale,scale);
	 
	  for (i = 0; i<strlen(string1); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string1[i]);

	  for (i = 0; i<strlen(string2); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string2[i]);
	  
	  glPopMatrix();
}

float eyex=0,eyey=0.5,eyez=0,atx=0,aty=0.5,atz=-2;
void mydisplay()
{
	if(disp_flag==0)
	{
		//menu projection matrix setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluOrtho2D(0.0,12.0,1.0,12.0);
	glMatrixMode(GL_MODELVIEW);
	
	glClearColor(0,0,0,0);

		glClear(GL_COLOR_BUFFER_BIT|
			GL_DEPTH_BUFFER_BIT);
		glColor3f(0,1,0);

			
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		drawStrokeTexti("","Computer Graphics And Visualization",2,11,0,0.0036);
		drawStrokeTexti("","Simulation of Package Delivery",3.4,10,0,0.0030);
		drawStrokeTexti("","Press 'n' to start",4.1,9,0,0.0027);
		drawStrokeTexti("","Guided by :",1,5.5,0,0.0022);
		drawStrokeTexti("","Mrs. Sunitha.B.K.",1,5,0,0.0022);
		drawStrokeTexti("","(B.E, M.Tech, Asst.Professor, C.S.E)",1,4.5,0,0.0022);
		drawStrokeTexti("","Simulated by :",7,5.5,0,0.0022);
		drawStrokeTexti("","1.Abhishek D",7,5,0,0.0022);
		drawStrokeTexti("","2.Sanjeet Gaglani",7,4.5,0,0.0022);
		drawStrokeTexti("","3.Aashish Radhakrishnan",7,4,0,0.0022);
		drawStrokeTexti("","4.Aravind Sharma",7,3.5,0,0.0022);


		glFlush();
		glutSwapBuffers(); 	
		
	}


	if(disp_flag==1)
	{
		//menu projection matrix setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluOrtho2D(0.0,12.0,1.0,12.0);
	glMatrixMode(GL_MODELVIEW);

		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0,1,0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	
		gluOrtho2D(0.0,12.0,1.0,12.0);
		glMatrixMode(GL_MODELVIEW);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		drawStrokeTexti("","CHOOSE AMONG SOURCE CITIES",2,11,0,0.0036);
		drawStrokeTexti("1.",city[0],2,9,0,0.0026);
		drawStrokeTexti("2.",city[1],2,7,0,0.0026);
		drawStrokeTexti("3.",city[2],2,5,0,0.0026);
		drawStrokeTexti("4.",city[3],2,3,0,0.0026);
		
		glFlush();
		glutSwapBuffers(); 	
	}
	

	if(disp_flag==2)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0,1,0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	
		gluOrtho2D(0.0,12.0,1.0,12.0);
		glMatrixMode(GL_MODELVIEW);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		drawStrokeTexti("","CHOOSE AMONG SOURCE AREAS",2,11,0,0.0036);
		drawStrokeTexti("1.",area[start_area_index_src+0],2,9,0,0.0026);
		drawStrokeTexti("2.",area[start_area_index_src+1],2,7,0,0.0026);
			
		glFlush();
		glutSwapBuffers(); 	
	}
	

	if(disp_flag==3)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0,1,0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	
		gluOrtho2D(0.0,12.0,1.0,12.0);
		glMatrixMode(GL_MODELVIEW);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		drawStrokeTexti("","CHOOSE AMONG SOURCE HOUSES",2,11,0,0.0036);
		drawStrokeTexti("1.",house[start_house_index_src+0],2,9,0,0.0026);
		drawStrokeTexti("2.",house[start_house_index_src+1],2,7,0,0.0026);
			
		glFlush();
		glutSwapBuffers(); 	
	}

if(disp_flag==4)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0,1,0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	
		gluOrtho2D(0.0,12.0,1.0,12.0);
		glMatrixMode(GL_MODELVIEW);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		drawStrokeTexti("","CHOOSE AMONG DESTINATION CITIES",2,11,0,0.0036);
		drawStrokeTexti("1.",city[0],2,9,0,0.0026);
		drawStrokeTexti("2.",city[1],2,7,0,0.0026);
		drawStrokeTexti("3.",city[2],2,5,0,0.0026);
		drawStrokeTexti("4.",city[3],2,3,0,0.0026);
		
		glFlush();
		glutSwapBuffers(); 	
	}
	

	if(disp_flag==5)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0,1,0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	
		gluOrtho2D(0.0,12.0,1.0,12.0);
		glMatrixMode(GL_MODELVIEW);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		drawStrokeTexti("","CHOOSE AMONG DESTINATION AREAS",2,11,0,0.0036);
		drawStrokeTexti("1.",area[start_area_index_dest+0],2,9,0,0.0026);
		drawStrokeTexti("2.",area[start_area_index_dest+1],2,7,0,0.0026);
			
		glFlush();
		glutSwapBuffers(); 	
	}
	

	if(disp_flag==6)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0,1,0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	
		gluOrtho2D(0.0,12.0,1.0,12.0);
		glMatrixMode(GL_MODELVIEW);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		drawStrokeTexti("","CHOOSE AMONG DESTINATION HOUSES",2,11,0,0.0036);
		drawStrokeTexti("1.",house[start_house_index_dest+0],2,9,0,0.0026);
		drawStrokeTexti("2.",house[start_house_index_dest+1],2,7,0,0.0026);
		drawStrokeTexti("","PRESS 'C' OR 'c' TO CHANGE CAMERA VIEW",1,3,0,0.0036);
			
		glFlush();
		glutSwapBuffers(); 	
	}


	if(disp_flag==7)										//delivery starts
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();

		gluLookAt(eyex, eyey, eyez,
			atx, aty, atz,
			0, 1, 0);

		glPushMatrix();
		glTranslatef(-viewer_eye[15][0], -viewer_eye[15][1], -viewer_eye[15][2]);
		glRotatef(theta[15], 0, 1, 0);

		glTranslatef(-viewer_eye[14][0], -viewer_eye[14][1], -viewer_eye[14][2]);
		glRotatef(theta[14], 0, 1, 0);

		glTranslatef(-viewer_eye[13][0], -viewer_eye[13][1], -viewer_eye[13][2]);
		glRotatef(theta[13], 0, 1, 0);

		glTranslatef(-viewer_eye[12][0], -viewer_eye[12][1], -viewer_eye[12][2]);
		glRotatef(theta[12], 0, 1, 0);

		
		glTranslatef(-viewer_eye[11][0], -viewer_eye[11][1], -viewer_eye[11][2]);
		glRotatef(theta[11], 0, 1, 0);


		glTranslatef(-viewer_eye[10][0], -viewer_eye[10][1], -viewer_eye[10][2]);
		glRotatef(theta[10], 0, 1, 0);
		
		glTranslatef(-viewer_eye[9][0], -viewer_eye[9][1], -viewer_eye[9][2]);
		glRotatef(theta[9], 0, 1, 0);
		
		glTranslatef(-viewer_eye[8][0], -viewer_eye[8][1], -viewer_eye[8][2]);
		glRotatef(theta[8], 0, 1, 0);

		glTranslatef(-viewer_eye[7][0], -viewer_eye[7][1], -viewer_eye[7][2]);
		glRotatef(theta[7], 0, 1, 0);

		
		glTranslatef(-viewer_eye[6][0], -viewer_eye[6][1], -viewer_eye[6][2]);
		glRotatef(theta[6], 0, 1, 0);

		glTranslatef(-viewer_eye[5][0], -viewer_eye[5][1], -viewer_eye[5][2]);
		glRotatef(theta[5], 0, 1, 0);

		glTranslatef(-viewer_eye[4][0], -viewer_eye[4][1], -viewer_eye[4][2]);
		glRotatef(theta[4], 0, 1, 0);

		glTranslatef(-viewer_eye[3][0], -viewer_eye[3][1], -viewer_eye[3][2]);
		glRotatef(theta[3], 0, 1, 0);

		glTranslatef(-viewer_eye[2][0], -viewer_eye[2][1], -viewer_eye[2][2]);
		glRotatef(theta[2], 0, 1, 0);

		
		glTranslatef(-viewer_eye[1][0], -viewer_eye[1][1], -viewer_eye[1][2]);
		glRotatef(theta[1], 0, 1, 0);


		glTranslatef(-viewer_eye[0][0], -viewer_eye[0][1], -viewer_eye[0][2]);
		glRotatef(theta[0], 0, 1, 0);


		glTranslatef(-(x11), -(y11), -(z11));
		//bring eye point at zero 

		glRotatef(180, 0, 1, 0);//flip 180 about y             

		glRotatef(-90, 1, 0, 0);//rotate 90deg clock about x

		glTranslatef(-28, -9, 0);//bring city to midpoint


		city_draw();
		

		drawStrokeText1(city[0]," P.O.", 6 , 15, 4.2, 0.0023);
		drawStrokeText1(city[1]," P.O.", 6 + 12 , 15, 4.2, 0.0023);
		drawStrokeText1(city[2]," P.O.", 6 + 24, 15, 4.2, 0.0023);
		drawStrokeText1(city[3]," P.O.", 6 + 36, 15, 4.2, 0.0023);

			
		drawStrokeText2(area[0]," P.O.", 4, 8, 3.2, 0.0022);
		drawStrokeText2(area[1]," P.O.", 8, 8, 3.2, 0.0022);
		drawStrokeText2(area[2]," P.O.", 4 + 12, 8, 3.2, 0.0022);
		drawStrokeText2(area[3]," P.O.", 8 + 12, 8, 3.2, 0.0022);
		drawStrokeText2(area[4]," P.O.", 4 + 24, 8, 3.2, 0.0022);
		drawStrokeText2(area[5]," P.O.", 8 + 24, 8, 3.2, 0.0022);
		drawStrokeText2(area[6]," P.O.", 4 + 36, 8, 3.2, 0.0022);
		drawStrokeText2(area[7]," P.O.", 8 + 36, 8, 3.2, 0.0022);


		drawStrokeText3(house[0], 4.2, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[1], 6.2, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[2], 8.2, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[3], 10.2, 4.5, 1.6, 0.0022);

		drawStrokeText3(house[4], 4.2 + 12, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[5], 6.2 + 12, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[6], 8.2 + 12, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[7], 10.2 + 12, 4.5, 1.6, 0.0022);

		drawStrokeText3(house[8], 4.2 + 24, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[9], 6.2 + 24, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[10], 8.2 + 24, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[11], 10.2 + 24, 4.5, 1.6, 0.0022);

		drawStrokeText3(house[12], 4.2 + 36, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[13], 6.2 + 36, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[14], 8.2 + 36, 4.5, 1.6, 0.0022);
		drawStrokeText3(house[15], 10.2 + 36, 4.5, 1.6, 0.0022);
		
		glPopMatrix();

	
		glPushMatrix();

		
		glColor3f(0,0,0);			//arrow
		glBegin(GL_POLYGON);
		glVertex3f(-0.2,0,0);
		glVertex3f(0.2,0,0);
		glVertex3f(0,0,-0.5);
		glEnd();

		glPopMatrix();
		

		glFlush();
		glutSwapBuffers(); 	
	}
	
	if(disp_flag==8)						//delivery starts
	{
		     //projection matrix setup
		glMatrixMode(GL_PROJECTION);				//map display
		glLoadIdentity();	
		gluOrtho2D(-28,+28,-9,+9);
		glMatrixMode(GL_MODELVIEW);
		
		glClearColor(1,1,1,1);


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();

		
		glScalef(0.7,0.7,0.7);
		glTranslatef(-28, -9, 0);//bring city to midpoint


		map_draw();

		glColor3f(0,0,0);
	
		drawMapTexti("PRESS 'N' TO SELECT SRC AND DEST",16,0,0,0.007);
		drawMapTexti("MAP",24,18,0,0.02);
		
		glFlush();
		glutSwapBuffers(); 	
	}

}

void some_more_init()
{
	int i;
	//1.determining the src house(setting sh)

	for (i = 0; i <= 12; i += 4)
	{
		if (src_house_index == i)
			sh = sh1;  //src house 1
	}

	for (i = 1; i <=13; i += 4)
	{
		if (src_house_index == i)
			sh = sh2;  //src house 2
	}

	for (i = 2; i <=14; i += 4)
	{
		if (src_house_index == i)
			sh = sh3;  //src house 3
	}

	for (i = 3; i <=15; i += 4)
	{
		if (src_house_index == i)
			sh = sh4;  //src house 4
	}

	//2.determining the dest house(setting dh)

	for (i = 0; i <= 12; i += 4)
	{
		if (dest_house_index == i)
			dh = dh1;  //dest house 1
	}

	for (i = 1; i <=13; i += 4)
	{
		if (dest_house_index == i)
			dh = dh2;  //dest house 2
	}

	for (i = 2; i <=14; i += 4)
	{
		if (dest_house_index == i)
			dh = dh3;  //dest house 3
	}

	for (i = 3; i <=15; i += 4)
	{
		if (dest_house_index == i)
			dh = dh4;  //dest house 4
	}

	//3.setting initial view point

	//bringing to zero

	x = house_vtx[src_house_index][0] - 28;
	y = house_vtx[src_house_index][1] - 9;
	z = house_vtx[src_house_index][2] - 0;

	//Rotate -90' about x axis

	x1 = x;
	y12 = y*cos(-90* CONV) - z*sin(-90 * CONV);
	z1 = y*sin(-90* CONV) + z*cos(-90 * CONV);
	
	//Rotate 180' about y axis

	x11 = x1*cos(180* CONV) + z1*sin(180* CONV);
	y11 = y12;
	z11 = -1.0*x1*sin(180* CONV) + z1*cos(180* CONV);


}


void myKey(unsigned char key, int x, int y)
{
	//display main page
	if(disp_flag==0)
	{
		if(key=='n')
		{
			disp_flag=8;
			glutPostRedisplay();
		}
		
	}
	else if(disp_flag==8)
	{
		if(key=='n')
		{
			disp_flag=1;
			glutPostRedisplay();
		}
	}

	else if(disp_flag==1)			//src city options selection
	{
		   
		if(key=='1' ||key=='2' ||key=='3' ||key=='4')
		{
			src_city_index=(key-48)-1;
			start_area_index_src=src_city_index*2;
			disp_flag=2;
			glutPostRedisplay();
		}
	}

	else if(disp_flag==2)		//src area options selection
	{
		if(key=='1' ||key=='2')
		{
			src_area_index=start_area_index_src+(key-48)-1;
			start_house_index_src=src_area_index*2;
			disp_flag=3;
			glutPostRedisplay();
		}
	}


	else if(disp_flag==3)			//src house options selection
	{
		if(key=='1' ||key=='2')
		{
			src_house_index=start_house_index_src+(key-48)-1;
			disp_flag=4;
			glutPostRedisplay();
		}
	}
	

	else if(disp_flag==4)					//dest city options selection
	{
		if(key=='1' ||key=='2' ||key=='3' ||key=='4')
		{
			dest_city_index=(key-48)-1;
			start_area_index_dest=dest_city_index*2;
			disp_flag=5;
			glutPostRedisplay();
		}
	}

	else if(disp_flag==5)			//dest area options selection
	{
		if(key=='1' ||key=='2')
		{
			dest_area_index=start_area_index_dest+(key-48)-1;
			start_house_index_dest=dest_area_index*2;
			disp_flag=6;
			glutPostRedisplay();
		}
	}


	else if(disp_flag==6)			//dest house options selection
	{
		if(key=='1' ||key=='2')
		{
			dest_house_index=start_house_index_dest+(key-48)-1;
			
			some_more_init();

			eyex=0,eyey=0.5,eyez=0,atx=0,aty,0.5,atz=-2;

			//city projection matrix setup
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glFrustum(-0.8, 0.8, -0.6, 2.5, 0.2, 5);
			glMatrixMode(GL_MODELVIEW);

			glClearColor(1.0, 1.0, 1.0, 1.0);

			disp_flag=7;
			glutPostRedisplay();
		}
	}

	else if(disp_flag==7)			//dest house options selection
	{
		if(key=='c')
		{
			eyex=0;eyey=0.5;eyez=0;atx=0;aty=0.5;atz=-2;
			
			//city projectio n matrix setup
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glFrustum(-0.8, 0.8, -0.6, 2.5, 0.2, 5);
			glMatrixMode(GL_MODELVIEW);

			glutPostRedisplay();

			
		}
		else if(key=='C')
		{
			eyex=0;eyey=5;eyez=5;atx=0;aty=0;atz=0;

			//city projection matrix setup
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-8, 8, -8, 8, 1, 10);
			glMatrixMode(GL_MODELVIEW);

			glutPostRedisplay();

		}
	}


}

void myinit()
{
	int i;
	for(i=0;i<4;i++)   //assigning city vertex
	{
		city_vtx[i][2]=0;
		city_vtx[i][1]=14;
		city_vtx[i][0]=7+(i*12);
	}
	int j;

	for(i=0;i<16;i++)   //assigning house vertex
	{
		j=i/4;

			house_vtx[i][2]=0;
			house_vtx[i][1]=6;

			if(i==0||i==4||i==8||i==12)
			house_vtx[i][0]=4+(j*12);

			if(i==1||i==5||i==9||i==13)
			house_vtx[i][0]=6+(j*12);

			if(i==2||i==6||i==10||i==14)
			house_vtx[i][0]=8+(j*12);

			if(i==3||i==7||i==11||i==15)
			house_vtx[i][0]=10+(j*12);
	}
     
	
}



void navigation()
{
	if(disp_flag==7)
	{
		if (flag == 0)
		{
			Sleep(1000);
			flag = 1;
		}

		if (flag == 1)
		{
			if (sh == sh1 || sh == sh3)  //clockwise
			{
				if (theta[0] > -90)
				{
					theta[0] -= 0.05*speed;
					
					if(theta[0]<-90)
						theta[0]=-90;
				}
				else
					flag = 2;
			}

			else if (sh == sh2 || sh == sh4)  //anticlockwise
			{
				if (theta[0] < 90)
				{
					theta[0] += 0.05*speed;
					if(theta[0]>90)
						theta[0]=90;
				}
				else
					flag = 2;
			}

		}
		if (flag == 2)
		{
			if (viewer_eye[0][2] > -1)
			{
				viewer_eye[0][2] -= 0.01*speed;
				if(viewer_eye[0][2]<-1)
					viewer_eye[0][2]=-1;
			}
			else
				flag = 3;
		}

		if (flag == 3)
		{
			if (sh == sh1 || sh == sh3)  //clockwise
			{
				if (theta[1] > -90)
				{
					theta[1] -= 0.05*speed;
					
					if(theta[1]<-90)
						theta[1]=-90;
				}
				else
					flag = 4;
			}

			else if (sh == sh2 || sh == sh4)  //anticlockwise
			{
				if (theta[1] < 90)
				{
					theta[1] += 0.05*speed;
					if(theta[1]>90)
						theta[1]=90;
				}
				else
					flag = 4;
			}

		}

		if (flag == 4)
		{
			if (viewer_eye[1][2] > -3)
			{
				viewer_eye[1][2] -= 0.01*speed;
				if(viewer_eye[1][2]<-3)
					viewer_eye[1][2]=-3;
			}
			else
				flag = 5;
		}

		if (flag == 5)
		{

			if (theta[2] > -90)
			{
					theta[2] -= 0.05*speed;
					
					if(theta[2]<-90)
						theta[2]=-90;
				}
			else
				flag = 6;
		}

		if (flag == 6)
		{
			Sleep(1000);
			flag = 7;
		}

		if (flag == 7)
		{

			if (theta[3] < 90)
			{
					theta[3] += 0.05*speed;
					if(theta[3]>90)
						theta[3]=90;
				}
			else
				flag = 8;
		}


		if (flag == 8)
		{
			if (viewer_eye[3][2] > -3)
			{
				viewer_eye[3][2] -= 0.01*speed;
				if(viewer_eye[3][2]<-3)
					viewer_eye[3][2]=-3;
			}
			else
				flag = 9;
		}

		if (flag == 9)
		{
			if (sh == sh1 || sh == sh2)
			{
				if (theta[4] < 90)
				{
					theta[4] += 0.05*speed;
					if(theta[4]>90)
						theta[4]=90;
				}
				else
					flag = 10;

			}
			else if (sh == sh3 || sh == sh4)
			{
				if (theta[4] > -90)
				{
					theta[4] -= 0.05*speed;
					
					if(theta[4]<-90)
						theta[4]=-90;
				}
				else
					flag = 10;
			}
		}
		if (flag == 10)
		{
			if (viewer_eye[4][2] > -2)
			{
				viewer_eye[4][2] -= 0.01*speed;
				if(viewer_eye[4][2]<-2)
					viewer_eye[4][2]=-2;
			}
			else
				flag = 11;
		}

		if (flag == 11)
		{
			if (sh == sh1 || sh == sh2)
			{

				if (theta[5] > -90)
				{
					theta[5] -= 0.05*speed;
					
					if(theta[5]<-90)
						theta[5]=-90;
				}
				else
					flag = 12;

			}
			else if (sh == sh3 || sh == sh4)
			{
				if (theta[5] < 90)
				{
					theta[5] += 0.05*speed;
					if(theta[5]>90)
						theta[5]=90;
				}
				else
					flag = 12;
			}
		}
		if (flag == 12)
		{
			if (viewer_eye[5][2] > -2)
			{
				viewer_eye[5][2] -= 0.01*speed;
				if(viewer_eye[5][2]<-2)
					viewer_eye[5][2]=-2;
			}
			else
				flag = 12.5;
		}
		if (flag == 12.5)
		{
			Sleep(1000);
			flag = 13;
		}

		if (flag == 13)
		{
			if (city_vtx[src_city_index][0] > city_vtx[dest_city_index][0])
			{
				if (theta[6] > -90)
				{
					theta[6] -= 0.05*speed;
					
					if(theta[6]<-90)
						theta[6]=-90;
				}
				else
					flag = 14;
			}

			else if (city_vtx[src_city_index][0] < city_vtx[dest_city_index][0])
			{
				if (theta[6] < 90)
				{
					theta[6] += 0.05*speed;
					if(theta[6]>90)
						theta[6]=90;
				}
				else
					flag = 14;
			}
			else if (city_vtx[src_city_index][0] == city_vtx[dest_city_index][0])
			{
				flag=14;
			}

		}

		if (flag == 14)
		{
			if (viewer_eye[6][2] > -abs(city_vtx[src_city_index][0] - 
										city_vtx[dest_city_index][0]))
			{
				viewer_eye[6][2] -= 0.01*speed;
				if(viewer_eye[6][2]<-abs(city_vtx[src_city_index][0] - 
										city_vtx[dest_city_index][0]))

					viewer_eye[6][2]=-abs(city_vtx[src_city_index][0] - 
										city_vtx[dest_city_index][0]);
			}
			else
				flag = 15;
		}

		if (flag == 15)
		{
			if (city_vtx[src_city_index][0] > city_vtx[dest_city_index][0])
			{
				if (theta[7] < 90)
				{
					theta[7] += 0.05*speed;
					if(theta[7]>90)
						theta[7]=90;
				}
				else
					flag = 15.5;
			}

			else if (city_vtx[src_city_index][0] < city_vtx[dest_city_index][0])
			{
				if (theta[7] > -90)
				{
					theta[7] -= 0.05*speed;
					
					if(theta[7]<-90)
						theta[7]=-90;
				}
				else
					flag = 15.5;
			}
			if (city_vtx[src_city_index][0] == city_vtx[dest_city_index][0])
			{
				flag=16;
			}
			

		}
		
		if (flag == 15.5)
		{
			Sleep(1000);
			flag = 16;
		}


		if (flag == 16)
		{

			if (theta[8] < 180)
			{
					theta[8] += 0.05*speed;
					if(theta[8]>180)
						theta[8]=180;
				}
			else
				flag = 17;
		}

		if (flag == 17)
		{
			if (viewer_eye[8][2] > -2)
			{
				viewer_eye[8][2] -= 0.01*speed;
				if(viewer_eye[8][2]<-2)
					viewer_eye[8][2]=-2;
			}
			else
				flag = 18;
		}

		if (flag == 18)
		{
			if (dh == dh1 || dh == dh2)
			{

				if (theta[9] < 90)
				{
					theta[9] += 0.05*speed;
					if(theta[9]>90)
						theta[9]=90;
				}
				else
					flag = 19;

			}
			else if (dh == dh3 || dh == dh4)
			{
				if (theta[9] > -90)
				{
					theta[9] -= 0.05*speed;
					
					if(theta[9]<-90)
						theta[9]=-90;
				}
				else
					flag = 19;
			}
		}
		if (flag == 19)
		{
			if (viewer_eye[9][2] > -2)
			{
				viewer_eye[9][2] -= 0.01*speed;
				if(viewer_eye[9][2]<-2)
					viewer_eye[9][2]=-2;
			}
			else
				flag = 20;
		}


		if (flag == 20)
		{
			if (dh == dh1 || dh == dh2)
			{

				if (theta[10] > -90)
				{
					theta[10] -= 0.05*speed;
					
					if(theta[10]<-90)
						theta[10]=-90;
				}
				else
					flag = 21;
			}

			else if (dh == dh3 || dh == dh4)
			{
				if (theta[10] < 90)
				{
					theta[10] += 0.05*speed;
					if(theta[10]>90)
						theta[10]=90;
				}
				else
					flag = 21;
			}
		}

		if (flag == 21)
		{
			if (viewer_eye[10][2] > -3)
			{
				viewer_eye[10][2] -= 0.01*speed;
				if(viewer_eye[10][2]<-3)
					viewer_eye[10][2]=-3;
			}
			else
				flag = 22;
		}

		if (flag == 22)
		{

			if (theta[11] < 90)
			{
					theta[11] += 0.05*speed;
					if(theta[11]>90)
						theta[11]=90;
				}
			else
				flag = 22.5;
		}
		
		if (flag == 22.5)
		{
			Sleep(1000);
			flag = 23;
		}


		if (flag == 23)
		{

			if (theta[12] > -90)
			{
					theta[12] -= 0.05*speed;
					
					if(theta[12]<-90)
						theta[12]=-90;
				}
			else
				flag = 24;
		}

		if (flag == 24)
		{
			if (viewer_eye[12][2] > -3)
			{
				viewer_eye[12][2] -= 0.01*speed;
				if(viewer_eye[12][2]<-3)
					viewer_eye[12][2]=-3;
			}
			else
				flag = 25;
		}

		if (flag == 25)
		{
			if (dh == dh1 || dh == dh3)
			{

				if (theta[13] < 90)
				{
					theta[13] += 0.05*speed;
					if(theta[13]>90)
						theta[13]=90;
				}
				else
					flag = 26;

			}
			else if (dh == dh2 || dh == dh4)
			{
				if (theta[13] > -90)
				{
					theta[13] -= 0.05*speed;
					
					if(theta[13]<-90)
						theta[13]=-90;
				}
				else
					flag = 26;
			}
		}


		if (flag == 26)
		{
			if (viewer_eye[13][2] > -1)
			{
				viewer_eye[13][2] -= 0.01*speed;
				if(viewer_eye[13][2]<-1)
					viewer_eye[13][2]=-1;
			}
			else
				flag = 27;
		}

		if (flag == 27)
		{
			if (dh == dh1 || dh == dh3)                                            
			{

				if (theta[14] > -90)
				{
					theta[14] -= 0.05*speed;
					
					if(theta[14]<-90)
						theta[14]=-90;
				}
				else
					flag = 28;

			}
			else if (dh == dh2 || dh == dh4)
			{

				if (theta[14] < 90)
				{
					theta[14] += 0.05*speed;
					if(theta[14]>90)
						theta[14]=90;
				}
				else
					flag = 28;

			}
		}

		if (flag == 28)
		{
			if (viewer_eye[14][2] > -1.0)
			{
				viewer_eye[14][2] -= 0.01*speed;
				if(viewer_eye[14][2]<-1)
					viewer_eye[14][2]=-1;
			}
			else
				flag = 29;
		}

		glutPostRedisplay();
	}
}

void inc_dec(int key,int x,int y)
{
	if(key==GLUT_KEY_UP)
		speed +=0.5;

	else if(key==GLUT_KEY_DOWN)
	{
		speed -=0.5;
		
		if(speed<0)
			speed=0;
	}

}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("cg project");
	glutSpecialFunc(inc_dec);
	glutIdleFunc(navigation);
	glutKeyboardFunc(myKey);
	glEnable(GL_DEPTH_TEST | GL_LINE_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(mydisplay);
	myinit();
	glutMainLoop();
}

