

int xx2,yy2,zz2,col;
float xxx=-35,yyy=-4;

void Show_Background()
{
//	col++;

		BarT(  
			 -42,-11.1f,15,-42,51.1f,15,   42,51.1f,15,42,-11.1f,15,
			 255,255,255,255,texture[18]);
}


void rysowanie_tekstow_menu()
{
	for (int i=0; i<10; i++)
	{
//		piszTXT2(menu[i].x,menu[i].y,25,25,20,155,100+menu[i].color,255,fonttexture.texID,"%s",menu[i].info);
		if (menu[i].x!=0 && menu[i].y<0.10f) piszTXT(menu[i].x,menu[i].y,0.015f,0.03f,0.03f,255,255,100+menu[i].color,fonttexture.texID,"%s",menu[i].info);
		if (menu[i].x!=0 && menu[i].y>=0.1f) {piszTXT(menu[i].x,menu[i].y, 0.017f,0.03f,0.05f, 255,255,100,fonttexture.texID,"%s",menu[i].info);}
	}
	
}
void DrawGLMenu_mapa()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	g_Camera.Look();

	glEnable(GL_DEPTH_TEST);


	g_Camera.PositionCamera(0,20,-60, 0,20,0,0,1,0);


	BarT(  
			 -15-21,-9.1f+13,13,   -15-21,12.1f+13,13, 
 			 
        	  15-21,12.1f+13,13,      15-21,-9.1f+13,13,
			 255,255,255,255,texture[20+nr_mapy]);

	Show_Background();

	SetTextures(true);



	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();

	
	glTranslatef(0,0,-1);
	glAlphaFunc(GL_GREATER, 0.5f);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);	

	rysowanie_tekstow_menu();

	glDisable(GL_BLEND);

	Draw_FPS();
}
void DrawGLMenu()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	g_Camera.Look();

	glEnable(GL_DEPTH_TEST);


	g_Camera.PositionCamera(0,20,-60, 0,20,0,0,1,0);

	Show_Background();

	SetTextures(true);



	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();

	
	glTranslatef(0,0,-1);
	glAlphaFunc(GL_GREATER, 0.5f);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);	

	rysowanie_tekstow_menu();

	glDisable(GL_BLEND);

	Draw_FPS();
}



void Rysuj_Samochod_MENU(TmenuG zawodnik, int alfa)
{        
	glEnable(GL_BLEND);	
	glTranslatef(-17,7,0);
	
	headingRAD=(zawodnik.katk+180)*RAD;
	glTranslatef(0,0,0);
	
	glRotatef(zawodnik.katk,0,1,0);
	glRotatef(90,0,1,0);
	glRotatef(-90,1,0,0);
	glPolygonMode(GL_BACK,GL_POINT);
	glColor3ub(255,255,255);
	SetTextures(true);
	glBindTexture(GL_TEXTURE_2D,zawodnik.modele3d[1].textura);
	
	//kolo tyl
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_tyl_X,samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.obrt_tyl,0,1,0);
	glRotatef(90,0,0,1);
	glColor4ub(255,255,255,alfa);
	glCallList(zawodnik.modele3d[1].model);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_tyl_X,-samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.obrt_tyl,0,1,0);
	glRotatef(90,0,0,1);
	glColor4ub(255,255,255,alfa);
	glCallList(zawodnik.modele3d[1].model);
	glPopMatrix();

	//kolo przod
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_przod_X,samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.skretR,0,0,1);
	glRotatef(zawodnik.obrt_prz,0,1,0);	
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[0][0],0,0,1);
	glColor4ub(255,255,255,alfa);
	glCallList(zawodnik.modele3d[1].model);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_przod_X,-samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.skretR,0,0,1);
	glRotatef(zawodnik.obrt_prz,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[1][0],0,0,1);
	glColor4ub(255,255,255,alfa);
	glCallList(zawodnik.modele3d[1].model);
	glPopMatrix();

	// kierownica i wnetrze (musi tak byc aby bylo dobrze)
	glPushMatrix();
	//wnetrze
	glTranslatef(samochody[zawodnik.numer_samuchodu].WTx,samochody[zawodnik.numer_samuchodu].WTy,samochody[zawodnik.numer_samuchodu].WTz);
	glScalef(samochody[zawodnik.numer_samuchodu].WSx,samochody[zawodnik.numer_samuchodu].WSy,samochody[zawodnik.numer_samuchodu].WSz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR,0,1,0);
	glRotatef(180,0,0,1);
	glBindTexture(GL_TEXTURE_2D,zawodnik.modele3DSBMP[1]);
	glColor4ub(255,255,255,alfa);
	zawodnik.modele3DS[1].Render_3ds();
	//kierownica
	glTranslatef(samochody[zawodnik.numer_samuchodu].KTx,samochody[zawodnik.numer_samuchodu].KTy,samochody[zawodnik.numer_samuchodu].KTz);
	glScalef(samochody[zawodnik.numer_samuchodu].KSx,samochody[zawodnik.numer_samuchodu].KSy,samochody[zawodnik.numer_samuchodu].KSz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(samochody[zawodnik.numer_samuchodu].KatKier,1,0,0);
	glRotatef(-zawodnik.skretR*4,0,1,0);
	glBindTexture(GL_TEXTURE_2D,zawodnik.modele3DSBMP[2]);
	glColor4ub(255,255,255,alfa);
	zawodnik.modele3DS[2].Render_3ds();
	
	glPopMatrix();
	glPolygonMode(GL_BACK,GL_FILL);


	SetTextures(true);


	// karoseria
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].Tx,samochody[zawodnik.numer_samuchodu].Ty,samochody[zawodnik.numer_samuchodu].Tz);
	glScalef(samochody[zawodnik.numer_samuchodu].Sx,samochody[zawodnik.numer_samuchodu].Sy,samochody[zawodnik.numer_samuchodu].Sz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR+1,0,1,0);
	glRotatef(180,0,0,1);
	glBindTexture(GL_TEXTURE_2D,zawodnik.modele3DSTGA[0].texID);

	glPolygonMode(GL_BACK,GL_POINT);
	glColor4ub(255,255,255,alfa);
	zawodnik.modele3DS[0].Render_3ds();
	glPolygonMode(GL_BACK,GL_FILL);

	
	glBindTexture(GL_TEXTURE_2D,zawodnik.modele3DSTGA[1].texID);
	glPolygonMode(GL_FRONT,GL_POINT);
	glColor4ub(255,255,255,alfa);
	zawodnik.modele3DS[0].Render_3ds();
	glPolygonMode(GL_FRONT,GL_FILL);
	glDisable(GL_BLEND);

 	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D,texture[1]);
	glColor4ub(255,255,255,100);//(alfa/2.55));
	zawodnik.modele3DS[0].Render_3ds();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_BLEND);
	glPopMatrix();

	SetTextures(true);	

	glPopMatrix();
	glPolygonMode(GL_BACK,GL_FILL);
}


float floorColor[]	  = {1.0f,1.0f,1.0f,0.5f};
void DrawGLMenu1()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	g_Camera.Look();
	glEnable(GL_DEPTH_TEST);
	g_Camera.PositionCamera(0,20,-60, 0,20,0,0,1,0);
	//menu
	Show_Background();
	ooorrr+=2;
	menus[nropcji].katk=ooorrr;
	Rysuj_Samochod_MENU(menus[nropcji],255);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(0,0,-1);
	glAlphaFunc(GL_GREATER, 0.5f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);	
	rysowanie_tekstow_menu();
	glDisable(GL_BLEND);
	Draw_FPS();
}


void DrawGLMenu2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	g_Camera.Look();
	glEnable(GL_DEPTH_TEST);
	g_Camera.PositionCamera(0,20,-60, 0,20,0,0,1,0);
	Show_Background();
	SetTextures(true);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(0,0,-1);
	glAlphaFunc(GL_GREATER, 0.5f);
	glTranslatef(0.0f,-0.1f,0);
	piszTXT(0.08f,0.15f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "grupa programistyczna");
	piszTXT(0.15f,0.10f,0.015f,0.03f,0.03f,255,225,0,fonttexture.texID, "GOLDEN GATE");
	piszTXT(0.07f,0.0f,0.015f,0.03f,0.03f,255,195,0,fonttexture.texID, "TOMASZ           MICHAL");
	piszTXT(0.08f,-0.05f,0.015f,0.03f,0.03f,255,195,0,fonttexture.texID, "FIDOS          RYGIELSKI");
	piszTXT(0.11f,-0.15f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "http://ggate.prv.pl");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);
	glPushMatrix();		
	glTranslatef(0.25f,0.292f,0);
	BarT(0.10f,0.10f,0.015f,
	     0.10f,-0.10f,0.015f,
	    -0.10f,-0.10f,0.015f,
	    -0.10f,0.10f,0.015f,		 
		 255,255,255,255,textureT[2].texID);
	glDisable(GL_BLEND);
	glPopMatrix();
	SetTextures(true);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);	
	rysowanie_tekstow_menu();
	glDisable(GL_BLEND);
	Draw_FPS();
}

