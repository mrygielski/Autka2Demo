#ifndef _GLunit
#define _GLunit


void Ustaw_widok()
{
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();
	glOrtho(0.0f,windowX,windowY,0.0f,-1.0f,1.0f);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();
}

#endif