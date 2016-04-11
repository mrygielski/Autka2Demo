

void Rysuj_Samochod(Tgracz zawodnik, int alfa)
{        
	glEnable(GL_BLEND);	
	glTranslatef(zawodnik.xtrans, zawodnik.ytrans+samochody[zawodnik.numer_samuchodu].ALLy, zawodnik.ztrans);
	
	headingRAD=(zawodnik.katk+180)*RAD;
	glTranslatef((sinf(headingRAD)*10),-1,(cosf(headingRAD)*10));
	
	glRotatef(zawodnik.katk,0,1,0);
	glRotatef(90,0,1,0);
	glRotatef(-90,1,0,0);
	glPolygonMode(GL_BACK,GL_POINT);
	glColor3ub(255,255,255);
	glBindTexture(GL_TEXTURE_2D,menus[zawodnik.numer_samuchodu].modele3d[1].textura);
	
	//kolo tyl
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_tyl_X,samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.obrt_tyl,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[0][1],0,0,1);
	glColor4ub(255,255,255,alfa);
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_tyl_X,-samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.obrt_tyl,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[1][1],0,0,1);
	glColor4ub(255,255,255,alfa);
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
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
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_przod_X,-samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.skretR,0,0,1);
	glRotatef(zawodnik.obrt_prz,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[1][0],0,0,1);
	glColor4ub(255,255,255,alfa);
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
	glPopMatrix();

	// kierownica i wnetrze (musi tak byc aby bylo dobrze)
	glPushMatrix();
	//wnetrze
	glTranslatef(samochody[zawodnik.numer_samuchodu].WTx,samochody[zawodnik.numer_samuchodu].WTy,samochody[zawodnik.numer_samuchodu].WTz);
	glScalef(samochody[zawodnik.numer_samuchodu].WSx,samochody[zawodnik.numer_samuchodu].WSy,samochody[zawodnik.numer_samuchodu].WSz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR,0,1,0);
	glRotatef(180,0,0,1);
	glBindTexture(GL_TEXTURE_2D,menus[zawodnik.numer_samuchodu].modele3DSBMP[1]);
	glColor4ub(255,255,255,alfa);
	menus[zawodnik.numer_samuchodu].modele3DS[1].Render_3ds();
	//kierownica
	glTranslatef(samochody[zawodnik.numer_samuchodu].KTx,samochody[zawodnik.numer_samuchodu].KTy,samochody[zawodnik.numer_samuchodu].KTz);
	glScalef(samochody[zawodnik.numer_samuchodu].KSx,samochody[zawodnik.numer_samuchodu].KSy,samochody[zawodnik.numer_samuchodu].KSz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(samochody[zawodnik.numer_samuchodu].KatKier,1,0,0);
	glRotatef(-zawodnik.skretR*4,0,1,0);
	glBindTexture(GL_TEXTURE_2D,menus[zawodnik.numer_samuchodu].modele3DSBMP[2]);
	glColor4ub(255,255,255,alfa);
	menus[zawodnik.numer_samuchodu].modele3DS[2].Render_3ds();
	
	glPopMatrix();
	glPolygonMode(GL_BACK,GL_FILL);

	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].WTx,samochody[zawodnik.numer_samuchodu].WTy,samochody[zawodnik.numer_samuchodu].WTz);
	glScalef(samochody[zawodnik.numer_samuchodu].WSx,samochody[zawodnik.numer_samuchodu].WSy,samochody[zawodnik.numer_samuchodu].WSz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR,0,1,0);
	glRotatef(180,0,0,1);
	glTranslatef(samochody[zawodnik.numer_samuchodu].KTx,samochody[zawodnik.numer_samuchodu].KTy,samochody[zawodnik.numer_samuchodu].KTz);
	glScalef(samochody[zawodnik.numer_samuchodu].KSx,samochody[zawodnik.numer_samuchodu].KSy,samochody[zawodnik.numer_samuchodu].KSz);
	//glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR,0,1,0);
	glRotatef(90,0,0,1);
	//glRotatef(samochody[zawodnik.numer_samuchodu].KatKier,1,0,0);
	
	//glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(180,0,0,1);
	glRotatef(90,1,0,0);
	
	
	glScalef(samochody[zawodnik.numer_samuchodu].LSx,samochody[zawodnik.numer_samuchodu].LSy,samochody[zawodnik.numer_samuchodu].LSz);
	glTranslatef(samochody[zawodnik.numer_samuchodu].LTx,samochody[zawodnik.numer_samuchodu].LTy,samochody[zawodnik.numer_samuchodu].LTz);
	glColor4ub(255,255,255,alfa);
	Rysuj_ludkaRENDER(zawodnik,alfa);
	glPopMatrix();
	SetTextures(true);



	// karoseria
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].Tx,samochody[zawodnik.numer_samuchodu].Ty,samochody[zawodnik.numer_samuchodu].Tz);
	glScalef(samochody[zawodnik.numer_samuchodu].Sx,samochody[zawodnik.numer_samuchodu].Sy,samochody[zawodnik.numer_samuchodu].Sz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(zawodnik.podniesR+1,0,1,0);
	glRotatef(180,0,0,1);
	glBindTexture(GL_TEXTURE_2D,menus[zawodnik.numer_samuchodu].modele3DSTGA[0].texID);
	glPolygonMode(GL_BACK,GL_POINT);
	glColor4ub(255,255,255,alfa);
	menus[zawodnik.numer_samuchodu].modele3DS[0].Render_3ds();
	glPolygonMode(GL_BACK,GL_FILL);
	

	glBindTexture(GL_TEXTURE_2D,menus[zawodnik.numer_samuchodu].modele3DSTGA[1].texID);
	glPolygonMode(GL_FRONT,GL_POINT);
	glColor4ub(255,255,255,alfa);
	menus[zawodnik.numer_samuchodu].modele3DS[0].Render_3ds();
	glPolygonMode(GL_FRONT,GL_FILL);
	glDisable(GL_BLEND);

 	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D,texture[1]);
	glColor4ub(255,255,255,(alfa/2.55));
	menus[zawodnik.numer_samuchodu].modele3DS[0].Render_3ds();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_BLEND);
	glPopMatrix();
	
	


	if (shadow_quality==false)
	{
	// cien
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(0,GL_SRC_COLOR);
	glRotatef(90,1,0,0);
	glBindTexture(GL_TEXTURE_2D,texture[2]);
	SetTextures(true);
	glBegin(GL_QUADS);
		glTexCoord2f(0.01f,0.01f);glVertex3f(-samochody[zawodnik.numer_samuchodu].linie-1,-1.5f,-samochody[zawodnik.numer_samuchodu].linie*0.6f);
		glTexCoord2f(0.99f,0.01f);glVertex3f(samochody[zawodnik.numer_samuchodu].linie+1,-1.5f,-samochody[zawodnik.numer_samuchodu].linie*0.6f);
		glTexCoord2f(0.99f,0.99f);glVertex3f(samochody[zawodnik.numer_samuchodu].linie+1,-1.5f,samochody[zawodnik.numer_samuchodu].linie*0.6f);
		glTexCoord2f(0.01f,0.99f);glVertex3f(-samochody[zawodnik.numer_samuchodu].linie-1,-1.5f,samochody[zawodnik.numer_samuchodu].linie*0.6f);
	glEnd();
	glDisable(GL_BLEND);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPopMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	} 
	SetTextures(true);	

	glPopMatrix();
	glPolygonMode(GL_BACK,GL_FILL);
}

void Rysuj_Samochod_SH(Tgracz zawodnik, int alfa)
{
	glTranslatef(zawodnik.xtrans, zawodnik.ytrans, zawodnik.ztrans);

	headingRAD=(zawodnik.katk+180)*RAD;
	glTranslatef((sinf(headingRAD)*10),-1,(cosf(headingRAD)*10));
	
	glRotatef(zawodnik.katk,0,1,0);
	glRotatef(90,0,1,0);
	glRotatef(-90,1,0,0);
	glPolygonMode(GL_BACK,GL_POINT);
	glColor3ub(255,255,255);
	glBindTexture(GL_TEXTURE_2D,texture[17]);

	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,alfa);
	
	//kolo tyl
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_tyl_X,samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.obrt_tyl,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[0][1],0,0,1);
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_tyl_X,-samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.obrt_tyl,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[1][1],0,0,1);
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
	glPopMatrix();

	//kolo przod
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_przod_X,samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.skretR,0,0,1);
	glRotatef(zawodnik.obrt_prz,0,1,0);	
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[0][0],0,0,1);
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].kolo_przod_X,-samochody[zawodnik.numer_samuchodu].kola_Y,0.3f);
	glScalef(samochody[zawodnik.numer_samuchodu].wielkosc_kol,samochody[zawodnik.numer_samuchodu].grubosc_kol,samochody[zawodnik.numer_samuchodu].wielkosc_kol);
	glRotatef(zawodnik.skretR,0,0,1);
	glRotatef(zawodnik.obrt_prz,0,1,0);
	glRotatef(90,0,0,1);
	glRotatef(zawodnik.wheels[1][0],0,0,1);
	glCallList(menus[zawodnik.numer_samuchodu].modele3d[1].model);
	glPopMatrix();

	// karoseria
	glPolygonMode(GL_BACK,GL_FILL);
	glPushMatrix();
	glTranslatef(samochody[zawodnik.numer_samuchodu].Tx,samochody[zawodnik.numer_samuchodu].Ty,samochody[zawodnik.numer_samuchodu].Tz);
	glScalef(samochody[zawodnik.numer_samuchodu].Sx,samochody[zawodnik.numer_samuchodu].Sy,samochody[zawodnik.numer_samuchodu].Sz);
	glRotatef(zawodnik.odchyl,1,0,0);
	glRotatef(menus[zawodnik.numer_samuchodu].podniesR+1,0,1,0);
	glRotatef(180,0,0,1);
	
	glBindTexture(GL_TEXTURE_2D,texture[17]);
	menus[zawodnik.numer_samuchodu].modele3DS[0].Render_3ds();
 	glPopMatrix();
	glDisable(GL_BLEND);

	glPolygonMode(GL_BACK,GL_FILL);
}


