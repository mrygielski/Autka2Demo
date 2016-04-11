int aaa;
void RysujSlady(XYslad SLADY[], Tgracz GRACZ)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);	
	for (itemp=0;itemp<1000;itemp++)
	{
			float xx,xx2,zz,zz2,a1,a2,a3,a4;
			a1=a2=a3=a4=odleglosc_rysowania2;
			ftemp=GRACZ.xtrans/64;
			xx=(ftemp)-a1; if (xx<0) xx=0;
			xx2=(ftemp)+a2; if (xx2>128) xx2=128;
			ftemp=GRACZ.ztrans/64;
			zz=(ftemp)-a3; if (zz<0) zz=0;
			zz2=(ftemp)+a4; if (zz2>128) zz2=128;
			if ((SLADY[itemp].x>xx*64 && SLADY[itemp].x<xx2*64)&&
			    (SLADY[itemp].z>zz*64 && SLADY[itemp].z<zz2*64))
			{
				glPushMatrix();
				glTranslatef(SLADY[itemp].x,SLADY[itemp].y,SLADY[itemp].z);
				glRotatef(SLADY[itemp].rot,0,1,0);
				
				if (SLADY[itemp].gd==1) glTranslatef(samochody[GRACZ.numer_samuchodu].kolo_przod_X,0,samochody[GRACZ.numer_samuchodu].kola_Y*SLADY[itemp].prawo);
				else glTranslatef(samochody[GRACZ.numer_samuchodu].kolo_tyl_X,0,samochody[GRACZ.numer_samuchodu].kola_Y*SLADY[itemp].prawo);
				
				glRotatef(SLADY[itemp].rot2,0,1,0);
				
				BarT(-SLADY[itemp].dl,0,-0.5f,
				SLADY[itemp].dl,0,-0.5f,
				SLADY[itemp].dl,0,+0.5f,
				-SLADY[itemp].dl,0,+0.5f,
				64,64,64,255,textureT[1].texID);
				glPopMatrix();
			}
	}
	glDisable(GL_BLEND);	
	SetTextures(true);
}


void Draw_FPS()
{
	if (framerate_limit)
	{
	Time2 = TimerGetTime()/1000;
    DiffTime = ABS(Time2-Time1);
 	while (DiffTime < framerate) // limits framerate to about 65 FPS
    {
		    //Sleep(1);
			Time2 = TimerGetTime()/1000;
			DiffTime = ABS(Time2-Time1);				
	}	
    Time1 = TimerGetTime()/1000;     
    FPS = 1/(DiffTime);
	}
}

void Rysuj_dym(float size)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);	
	for (i=ile_dymu;i>=1;i--)
	{
	 if (dym[i].is==true) 
	 {
		glPushMatrix();
		
		glTranslatef(dym[i].x,dym[i].y,dym[i].z);
	
		glRotatef(dym[i].rot,0,1,0);
		
		if (dym[i].gd==-1) glTranslatef(samochody[gracz.numer_samuchodu].kolo_przod_X,0,samochody[gracz.numer_samuchodu].kola_Y*dym[i].prawo);
		else glTranslatef(samochody[gracz.numer_samuchodu].kolo_tyl_X,0,samochody[gracz.numer_samuchodu].kola_Y*dym[i].prawo);
		
		
		size=(255-dym[i].color)/70;
	//	glRotatef(_3d_2d,0,1,0);
		glRotatef(90,0,1,0);

		BarT(-size,-0.3f-size,0,
			  size,-0.3f-size,0,
			  size,-0.3f+size,0,
			  -size,-0.3f+size,0,
			  255,255,255,dym[i].color,textureT[0].texID);
		dym[i].color-=5.0f;
		dym[i].y+=0.05f;
		if (dym[i].color<0.0f) dym[i].is=false;
		glPopMatrix();
	 }
	}
	glDisable(GL_BLEND);
	SetTextures(true);	
}




void Rysuj_mape()
{
	SetTextures(true);
	
	float x,y,xx,xx2,yy,yy2,a1,a2,a3,a4;
	a1=a2=a3=a4=odleglosc_rysowania;


	ftemp=gracz.xtrans/64;
	xx=(ftemp)-a1; if (xx<0) xx=0;
	xx2=(ftemp)+a2; if (xx2>128) xx2=128;
	ftemp=gracz.ztrans/64;
	yy=(ftemp)-a3; if (yy<0) yy=0;
	yy2=(ftemp)+a4; if (yy2>128) yy2=128;

	glPolygonMode(GL_BACK, GL_POINT);
	SetTextures(true);
	glColor4ub(255,255,255,255);
	for (mx=(int)xx;mx<xx2;mx++)
	for (my=(int)yy;my<yy2;my++)
	{
		glBindTexture(GL_TEXTURE_2D,textureIco[mapa[mx][my]]);
		x=(float)(mx<<6);
		y=(float)(my<<6);
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(katy[mapa_kat[mx][my]][0][0],katy[mapa_kat[mx][my]][1][0]);glVertex3f((x+64),-3,(y+64));
		glTexCoord2f(katy[mapa_kat[mx][my]][0][1],katy[mapa_kat[mx][my]][1][1]);glVertex3f((x+64),-3,y);
		glTexCoord2f(katy[mapa_kat[mx][my]][0][2],katy[mapa_kat[mx][my]][1][2]);glVertex3f(x,-3,(y+64));
		glTexCoord2f(katy[mapa_kat[mx][my]][0][3],katy[mapa_kat[mx][my]][1][3]);glVertex3f(x,-3,y);
		glEnd();
	}

/*	for (mx=(int)xx;mx<xx2;mx++)
	for (my=(int)yy;my<yy2;my++)
	{
		if (inteligencja[mx][my]>0)
		{
		if (inteligencja[mx][my]>0 && inteligencja[mx][my]<100) glBindTexture(GL_TEXTURE_2D,textureTT[inteligencja[mx][my]].texID);
		x=(float)(mx<<6);
		y=(float)(my<<6)-128;
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(1,0);glVertex3f((x+64),-3,(y+64));
		glTexCoord2f(1,1);glVertex3f((x+64),-3,y);
		glTexCoord2f(0,0);glVertex3f(x,-3,(y+64));
		glTexCoord2f(0,1);glVertex3f(x,-3,y);
		glEnd();
		}
	}
*/


	glPolygonMode( GL_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);
	SetTextures(true);
	glPolygonMode(GL_BACK,GL_POINT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);
	xx=xx*64;yy=yy*64;
	xx2=xx2*64;yy2=yy2*64;
	for (i=1;i<=ilosc_modeli;i++)
	 if ((modele[i].x>xx && modele[i].x<xx2)&&
		 (modele[i].y>yy && modele[i].y<yy2))
	 {
		glPushMatrix();
		glColor3ub(255,255,255);
		glTranslatef(modele[i].x,modele_y[modele[i].numer],modele[i].y);
		glScalef(64,64,64);
		glRotatef(-90,1,0,0);
		glRotatef(modele[i].rot,0,0,1);
		glScalef(modeleScale[modele[i].numer].x,modeleScale[modele[i].numer].y,modeleScale[modele[i].numer].z);
		if (modele[i].numer==49) {glBindTexture(GL_TEXTURE_2D, modele3dTGA_ed[swiatla[nr_swiatla]].textura.texID);}
		else {glBindTexture(GL_TEXTURE_2D, modele3dTGA_ed[modele[i].numer].textura.texID);}
		glCallList(modele3dTGA_ed[modele[i].numer].model);
		glPopMatrix();	
	 }
	glDisable(GL_BLEND);
	SetTextures(true);
	glPolygonMode(GL_BACK,GL_FILL);
}

void Rysuj_niebo()
{
	SetTextures(true);
	glPushMatrix();
	glTranslatef(gracz.xtrans,gracz.ytrans,gracz.ztrans);
	glRotatef(90,1,0,0);
	glBindTexture(GL_TEXTURE_2D,texture[0]);
	glColor4ub(255,255,255,255);
	glPolygonMode(GL_FRONT,GL_POINT);	
	gluSphere(sky,1750,8,4);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPopMatrix();
}

void Rysuj_Linie_TEST()
{
	glColor3ub(255,255,0);
	SetTextures(false);
	glBegin(GL_QUADS);
	for (i=1;i<=ilosc_band;i++)
	{
		glVertex3f(bandy[i].Triangle[0].x,bandy[i].Triangle[0].y,bandy[i].Triangle[0].z);
		glVertex3f(bandy[i].Triangle[1].x,bandy[i].Triangle[1].y,bandy[i].Triangle[1].z);

	/**/glVertex3f(bandy[i].Triangle[1].x,bandy[i].Triangle[1].y-3,bandy[i].Triangle[1].z);
	/**/glVertex3f(bandy[i].Triangle[0].x,bandy[i].Triangle[0].y-3,bandy[i].Triangle[0].z);
	}

		glColor3ub(255,0,50);
		glVertex3f(METAl.Triangle[0].x,METAl.Triangle[0].y,METAl.Triangle[0].z);
		glVertex3f(METAl.Triangle[1].x,METAl.Triangle[1].y,METAl.Triangle[1].z);

	/**/glVertex3f(METAl.Triangle[1].x,METAl.Triangle[1].y-3,METAl.Triangle[1].z);
	/**/glVertex3f(METAl.Triangle[0].x,METAl.Triangle[0].y-3,METAl.Triangle[0].z);
	
	glEnd();
	glBegin(GL_LINES);
		glColor3f(1,1,1);	
		glVertex3f(lewo.Triangle[0].x,lewo.Triangle[0].y,lewo.Triangle[0].z);
		glVertex3f(lewo.Triangle[1].x,lewo.Triangle[1].y,lewo.Triangle[1].z);
		
		glVertex3f(prawo.Triangle[0].x,prawo.Triangle[0].y,prawo.Triangle[0].z);
		glVertex3f(prawo.Triangle[1].x,prawo.Triangle[1].y,prawo.Triangle[1].z);
		
		glVertex3f(gora.Triangle[0].x,gora.Triangle[0].y,gora.Triangle[0].z);
		glVertex3f(gora.Triangle[1].x,gora.Triangle[1].y,gora.Triangle[1].z);

		glVertex3f(dol.Triangle[0].x,dol.Triangle[0].y,dol.Triangle[0].z);
		glVertex3f(dol.Triangle[1].x,dol.Triangle[1].y,dol.Triangle[1].z);





	glColor3ub(0, 200, 200);
	glVertex3f(meta.x1,0,meta.y1);glVertex3f(meta.x2,0,meta.y2);
	glVertex3f(hotrod.x1,0,hotrod.y1);glVertex3f(hotrod.x2,0,hotrod.y2);


	glEnd();
	
	SetTextures(true);
}

void Rysuj_Linie_TEST_CAR(Tgracz &zawodnik)
{
	glColor3ub(255,255,0);
	SetTextures(false);
	glBegin(GL_LINES);
	if(zawodnik.bCollided) glColor3ub(0, 255, 0); else glColor3ub(255, 255, 0);glVertex3f(zawodnik.vLine[1].x,zawodnik.vLine[1].y,zawodnik.vLine[1].z);glVertex3f(zawodnik.vLine[0].x,zawodnik.vLine[0].y,zawodnik.vLine[0].z);
	if(zawodnik.bCollided2) glColor3ub(0, 255, 0); else glColor3ub(255, 255, 0);glVertex3f(zawodnik.vLine2[1].x,zawodnik.vLine2[1].y,zawodnik.vLine2[1].z);glVertex3f(zawodnik.vLine2[0].x,zawodnik.vLine2[0].y,zawodnik.vLine2[0].z);
	if(zawodnik.bCollided3) glColor3ub(0, 255, 0); else glColor3ub(255, 255, 0);glVertex3f(zawodnik.vLine3[1].x,zawodnik.vLine3[1].y,zawodnik.vLine3[1].z);glVertex3f(zawodnik.vLine3[0].x,zawodnik.vLine3[0].y,zawodnik.vLine3[0].z);
	if(zawodnik.bCollided4) glColor3ub(0, 255, 0); else glColor3ub(255, 255, 0);glVertex3f(zawodnik.vLine4[1].x,zawodnik.vLine4[1].y,zawodnik.vLine4[1].z);glVertex3f(zawodnik.vLine4[0].x,zawodnik.vLine4[0].y,zawodnik.vLine4[0].z);
	if(zawodnik.bCollided3_) glColor3ub(0, 200, 0); else glColor3ub(200, 200, 0);glVertex3f(zawodnik.vLine3_[1].x,zawodnik.vLine3_[1].y,zawodnik.vLine3_[1].z);glVertex3f(zawodnik.vLine3_[0].x,zawodnik.vLine3_[0].y,zawodnik.vLine3_[0].z);
	if(zawodnik.bCollided4_) glColor3ub(0, 200, 0); else glColor3ub(200, 200, 0);glVertex3f(zawodnik.vLine4_[1].x,zawodnik.vLine4_[1].y,zawodnik.vLine4_[1].z);glVertex3f(zawodnik.vLine4_[0].x,zawodnik.vLine4_[0].y,zawodnik.vLine4_[0].z);

	glEnd();
	
	SetTextures(true);
}



void Show_Kontrolki()
{
		glBlendFunc(0,GL_SRC_COLOR);
	// predkosciomierz
	glPushMatrix();
	glTranslatef(0.43f,-0.292f,0);	
	glEnable(GL_BLEND);
	BarT(0.10f,0.10f,0.015f,
	     0.10f,-0.10f,0.015f,
	    -0.10f,-0.10f,0.015f,
	    -0.10f,0.10f,0.015f,		 
		 255,255,255,255,texture[4]);
	glDisable(GL_BLEND);
	glPopMatrix();

	gracz.rot_st=-gracz.pr*45;
	glPushMatrix();
	glEnable(GL_BLEND);	
	glTranslatef(0.43f,-0.292f,0);
	glRotatef(gracz.rot_st,0,0,1);
	BarT(-0.10f,-0.10f,0.015f,
	 	  0.10f,-0.10f,0.015f,
		  0.10f,0.10f,0.015f,
		 -0.10f,0.10f,0.015f,
		 255,255,255,255,texture[3]);
	glDisable(GL_BLEND);
	glPopMatrix();

	// obrotomierz
	glPushMatrix();
	glTranslatef(0.38f,-0.350f,0);	
	glEnable(GL_BLEND);
	BarT(0.05f,0.05f,0.015f,
	     0.05f,-0.05f,0.015f,
	    -0.05f,-0.05f,0.015f,
	    -0.05f,0.05f,0.015f,		 
		 255,255,255,255,texture[5]);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_BLEND);	
	glTranslatef(0.38f,-0.350f,0);
	glRotatef(-180+gracz.rot_obr,0,0,1);
	BarT(0.05f,0.05f,0.015f,
	     0.05f,-0.05f,0.015f,
	    -0.05f,-0.05f,0.015f,
	    -0.05f,0.05f,0.015f,	 
		 255,255,255,255,texture[3]);
	glDisable(GL_BLEND);
	glPopMatrix();


	//bieg

/*	if (gracz.pr<0 || tempbieg==-1) nr_biegu=1;
	if (tempbieg==1)
	{
		if (gracz.pr==0) nr_biegu=2;
		if (gracz.pr>0 && gracz.pr<0.2) nr_biegu=3;
		if (gracz.pr>0.2 && gracz.pr<1) nr_biegu=4;
		if (gracz.pr>1 && gracz.pr<2.2) nr_biegu=5;
		if (gracz.pr>2.2 && gracz.pr<3) nr_biegu=6;
		if (gracz.pr>3 && gracz.pr<4) nr_biegu=7;
	}

*/
	if (gracz.nr_biegu==1) ttexture=6;
	if (gracz.nr_biegu==2) ttexture=7;
	if (gracz.nr_biegu==3) ttexture=8;
	if (gracz.nr_biegu==4) ttexture=9;
	if (gracz.nr_biegu==5) ttexture=10;
	if (gracz.nr_biegu==6) ttexture=11;
	if (gracz.nr_biegu==7) ttexture=12;

	glPushMatrix();
	glTranslatef(0.52f,-0.38f,0);	
	glEnable(GL_BLEND);
	BarT(0.025f,0.025f,0.015f,
	     0.025f,-0.025f,0.015f,
	    -0.025f,-0.025f,0.015f,
	    -0.025f,0.025f,0.015f,255,255,255,255,texture[ttexture]);
	glDisable(GL_BLEND);
	glPopMatrix();

	SetTextures(false);
	glPushMatrix();
	glColor4ub(255,255,255,255);
	glTranslatef(0,-4,-10);
	glBegin(GL_LINES);
		glVertex3f(-2.1f,0,0);
		glVertex3f(2.1f,0,0);
		glVertex3f(0,-0.25f,0);
		glVertex3f(0,0.25f,0);
		glColor4ub(255,55,155,255);
		glVertex3f(-gracz.skret/20,-0.25f,0);
		glVertex3f(-gracz.skret/20,0.25f,0);
	glEnd();
	glPopMatrix();
	SetTextures(true);
	
	glEnable(GL_DEPTH_TEST);

}


#define DOXZPLANE      1
#define DEG2RAD(D)     (D*0.035f)

enum
{
    MENU_CAMERA,
    MENU_LIGHT,
    MENU_ZOOM,
    MENU_XZPLANE,
    MENU_YZPLANE,
    MENU_XYPLANE,
    MENU_DEPTHCOMPARE,
    MENU_BACKFACECULL,
    MENU_TEAPOT
};

GLfloat light_position[4] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */

// Offset of shadow from plane.
float   fPlaneOffset[3] = { -10.0f, -2.80f, -10.0f };

float   *calcShadowMatrix( float light_pos[3], float object_pos[3], int iPlane )
{
    static float    matrix[16];
    static float    identity[16] =
                    {
                        1.0f, 0.0f, 0.0f, 0.0f,
                        0.0f, 1.0f, 0.0f, 0.0f,
                        0.0f, 0.0f, 1.0f, 0.0f,
                        0.0f, 0.0f, 0.0f, 1.0f
                    };

    float   dx, dy, dz;

    dx = light_pos[0] - object_pos[0];
    dy = light_pos[1] - object_pos[1];
    dz = light_pos[2] - object_pos[2];

    memcpy( matrix, identity, sizeof( matrix ) );

    switch ( iPlane )
    {
        case MENU_XZPLANE:
            matrix[4] = -dx/dy;
            matrix[5] = 0.0f;
            matrix[6] = -dz/dy;

            matrix[12] = fPlaneOffset[1]*dx/dy;
            matrix[13] = fPlaneOffset[1] + 0.1f;  
            matrix[14] = fPlaneOffset[1]*dz/dy;
        break;
     }

    return matrix;
}

void drawObjectShadow(Tgracz GRACZ, int alfa)
{
	if (shadow_quality==true)
	{
	float   object_pos[3] = { 0.0f, 0.0f, 0.0f };
    float   *pfMatrix;

    glDepthFunc( GL_LESS );

    #if DOXZPLANE
    if ( light_position[1] > fPlaneOffset[1] )
    {
        glPushMatrix();
        pfMatrix = calcShadowMatrix( light_position, object_pos, MENU_XZPLANE );
        glMultMatrixf( pfMatrix );
        Rysuj_Samochod_SH(GRACZ,(alfa/2.55));
		glPopMatrix();
    }
    #endif

	glEnable(GL_DEPTH_TEST);
	glDepthFunc( GL_LEQUAL );
	}
}


void Show_Kontrolki2()
{
	glBlendFunc(0,GL_SRC_COLOR);
	// predkosciomierz
	glPushMatrix();
	glTranslatef(0.43f,-0.292f,0);	
	glEnable(GL_BLEND);
	BarT(0.10f,0.10f,0.015f,
	     0.10f,-0.10f,0.015f,
	    -0.10f,-0.10f,0.015f,
	    -0.10f,0.10f,0.015f,		 
		 255,255,255,255,texture[4]);
	glDisable(GL_BLEND);
	glPopMatrix();

	gracz.rot_st=-gracz.pr*45;
	glPushMatrix();
	glEnable(GL_BLEND);	
	glTranslatef(0.43f,-0.292f,0);
	glRotatef(gracz.rot_st+76,0,0,1);
	BarT(-0.10f,-0.10f,0.015f,
	 	  0.10f,-0.10f,0.015f,
		  0.10f,0.10f,0.015f,
		 -0.10f,0.10f,0.015f,
		 255,255,255,255,texture[3]);
	glDisable(GL_BLEND);
	glPopMatrix();

	// obrotomierz
	glPushMatrix();
	glTranslatef(0.30f,-0.350f,0);	
	glEnable(GL_BLEND);
	BarT(0.05f,0.05f,0.015f,
	     0.05f,-0.05f,0.015f,
	    -0.05f,-0.05f,0.015f,
	    -0.05f,0.05f,0.015f,		 
		 255,255,255,255,texture[5]);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_BLEND);	
	glTranslatef(0.30f,-0.350f,0);
	glRotatef(-180+gracz.rot_obr,0,0,1);
	BarT(0.05f,0.05f,0.015f,
	     0.05f,-0.05f,0.015f,
	    -0.05f,-0.05f,0.015f,
	    -0.05f,0.05f,0.015f,	 
		 255,255,255,255,texture[3]);
	glDisable(GL_BLEND);
	glPopMatrix();


	if (gracz.nr_biegu==1) ttexture=6;
	if (gracz.nr_biegu==2) ttexture=7;
	if (gracz.nr_biegu==3) ttexture=8;
	if (gracz.nr_biegu==4) ttexture=9;
	if (gracz.nr_biegu==5) ttexture=10;
	if (gracz.nr_biegu==6) ttexture=11;
	if (gracz.nr_biegu==7) ttexture=12;

	glPushMatrix();
	glTranslatef(0.52f,-0.38f,0);	
	glEnable(GL_BLEND);
	BarT(0.025f,0.025f,0.015f,
	     0.025f,-0.025f,0.015f,
	    -0.025f,-0.025f,0.015f,
	    -0.025f,0.025f,0.015f,255,255,255,255,texture[ttexture]);
	glDisable(GL_BLEND);
	glPopMatrix();

/*	SetTextures(false);
	glPushMatrix();
	glColor4ub(255,255,255,255);
	glTranslatef(0,-4,-10);
	glBegin(GL_LINES);
		glVertex3f(-2.1f,0,0);
		glVertex3f(2.1f,0,0);
		glVertex3f(0,-0.25f,0);
		glVertex3f(0,0.25f,0);
		glColor4ub(255,55,155,255);
		glVertex3f(-gracz.skret/20,-0.25f,0);
		glVertex3f(-gracz.skret/20,0.25f,0);
	glEnd();
	glPopMatrix();
	SetTextures(true);
*/	
	glEnable(GL_DEPTH_TEST);

}

void ShowPodium()
{
	glEnable(GL_BLEND);
	glBlendFunc(0,GL_SRC_COLOR);
	BarT(-0.32f,0.20f,0.015f,  0.32f,0.20f,0.015f,
		  0.32f,-0.20f,0.015f,  -0.32f,-0.20f,0.015f,
		  255,255,255,200,texture[2]);
		glDisable(GL_BLEND);
	SetTextures(TRUE);

	piszTXT(-0.05f,0.12f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "PODIUM");

    piszTXT(-0.13f,0.05f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "1 - %s",tablicaW[1]);
	piszTXT(-0.13f,0.01f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "2 - %s",tablicaW[2]);
	piszTXT(-0.13f,-0.03f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "3 - %s",tablicaW[3]);
	piszTXT(-0.13f,-0.07f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "4 - %s",tablicaW[4]);


}