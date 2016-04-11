void SetFog(float r, float g, float b, float a)
{
	GLfloat fogColor[4]= {(float)r/255.0f, (float)g/255.0f, (float)b/255.0f, (float)a/255.0f};
	glClearColor(r,g,b,a);
	glFogi(GL_FOG_MODE,GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glHint(GL_FOG_HINT, GL_FASTEST);
	glEnable(GL_FOG);
}


void Zrob_Granice()
{
	lewo.Triangle[0].x=0;
	lewo.Triangle[0].y=0;
	lewo.Triangle[0].z=0;
	lewo.Triangle[1].x=128*64;
	lewo.Triangle[1].y=0;
	lewo.Triangle[1].z=0;
	lewo.Triangle[2].x=128*32;
	lewo.Triangle[2].y=30;
	lewo.Triangle[2].z=0;

	prawo.Triangle[0].x=0;
	prawo.Triangle[0].y=0;
	prawo.Triangle[0].z=128*64;
	prawo.Triangle[1].x=128*64;
	prawo.Triangle[1].y=0;
	prawo.Triangle[1].z=128*64;
	prawo.Triangle[2].x=128*32;
	prawo.Triangle[2].y=30;
	prawo.Triangle[2].z=128*64;

	dol.Triangle[0].x=0;
	dol.Triangle[0].y=0;
	dol.Triangle[0].z=0;
	dol.Triangle[1].x=0;
	dol.Triangle[1].y=0;
	dol.Triangle[1].z=128*64;
	dol.Triangle[2].x=0;
	dol.Triangle[2].y=30;
	dol.Triangle[2].z=128*32;

	gora.Triangle[0].x=128*64;
	gora.Triangle[0].y=0;
	gora.Triangle[0].z=0;
	gora.Triangle[1].x=128*64;
	gora.Triangle[1].y=0;
	gora.Triangle[1].z=128*64;
	gora.Triangle[2].x=128*64;
	gora.Triangle[2].y=30;
	gora.Triangle[2].z=128*32;

}





void LoadMap(char* pl)
{
	int plik;
	plik=Assign(pl);
	read(plik,&mapa,sizeof(mapa));
	read(plik,&mapa_kat,sizeof(mapa_kat));
	
	read(plik,&ilosc_band,sizeof(ilosc_band));
	for (i=1;i<=1000;i++)
	{
		read(plik,&ftemp,sizeof(ftemp));bandy[i-1].Triangle[0].x=(ftemp+1)*64;
		read(plik,&ftemp,sizeof(ftemp));bandy[i-1].Triangle[0].z=(ftemp+1)*64;
		read(plik,&ftemp,sizeof(ftemp));bandy[i-1].Triangle[1].x=(ftemp+1)*64;
		read(plik,&ftemp,sizeof(ftemp));bandy[i-1].Triangle[1].z=(ftemp+1)*64;
		bandy[i].Triangle[2].x=bandy[i].Triangle[0].x;
		bandy[i].Triangle[0].y=-0;
		bandy[i].Triangle[1].y=-0;
		bandy[i].Triangle[2].y=30;
		bandy[i].Triangle[2].z=bandy[i].Triangle[0].z;	
	}
	
	read(plik,&ilosc_modeli,sizeof(ilosc_modeli));
	read(plik,&modele,sizeof(modele));

	for (i=0;i<=ilosc_modeli;i++)
	{
		modele[i].x=modele[i].x*64+64;
		modele[i].y=modele[i].y*64+64;
		modele[i].rot=360-modele[i].rot-180;
	}

	read(plik,&meta,sizeof(meta));
	read(plik,&hotrod,sizeof(hotrod));
	meta.x1+=1;meta.x2+=1;meta.y1+=1;meta.y2+=1;
	meta.x1*=64;meta.x2*=64;meta.y1*=64;meta.y2*=64;
	hotrod.x1+=1;hotrod.x2+=1;hotrod.y1+=1;hotrod.y2+=1;
	hotrod.x1*=64;hotrod.x2*=64;hotrod.y1*=64;hotrod.y2*=64;

	METAl.Triangle[0].x=meta.x1;METAl.Triangle[0].z=meta.y1;
	METAl.Triangle[1].x=meta.x2;METAl.Triangle[1].z=meta.y2;
	HOTRODl.Triangle[0].x=hotrod.x1;HOTRODl.Triangle[0].z=hotrod.y1;
	HOTRODl.Triangle[1].x=hotrod.x2;HOTRODl.Triangle[1].z=hotrod.y2;

	METAl.Triangle[0].y=METAl.Triangle[1].y=0;  METAl.Triangle[2].y=30;
	HOTRODl.Triangle[0].y=HOTRODl.Triangle[1].y=0;  HOTRODl.Triangle[2].y=30;
	METAl.Triangle[2].x=METAl.Triangle[0].x;
	METAl.Triangle[2].z=METAl.Triangle[0].z;
	HOTRODl.Triangle[2].x=HOTRODl.Triangle[0].x;
	HOTRODl.Triangle[2].z=HOTRODl.Triangle[0].z;

	read(plik,&gracz.x,sizeof(gracz.x));
	read(plik,&gracz.z,sizeof(gracz.z));
	gracz.x=gracz.x*64+64;
	gracz.z=gracz.z*64+64;

	read(plik,&inteligencja,sizeof(inteligencja));

/*	read(plik,&gracz.katk,sizeof(gracz.katk));
	gracz.katk=(180-gracz.katk)/RAD;
	gracz.kat=gracz.katk;
*/	
	close(plik);
	for (itemp=0;itemp<128;itemp++)
	for (int itemp2=0;itemp2<128;itemp2++)
	{
//		if (mapa[itemp][itemp2]>16) mapa[itemp][itemp2]-=17;
	//	if (mapa[itemp][itemp2]>31 && mapa[itemp][itemp2]<49) mapa[itemp][itemp2]-=32;
	}
}

void dodaj_ikone(char* path)
{
	textureIco[iloscicon]=LoadTexture(path,jakosc_textur,mipmaps,false);
	iloscicon+=1;	
}

void dodaj_ikoneJPG(char* path)
{
	CreateTexture(path,textureIco[iloscicon],jakosc_textur,mipmaps);
	iloscicon+=1;	
}

void LoadSamochody()
{
	samochody[0].accelerationCONST=0.02f;
	samochody[0].hamulec=0.03f;
	samochody[0].max_predkosc=4.2f;
	samochody[0].model_path="modele/cinquecento/cinquecento.3ds";
	samochody[0].modeltexture_path="modele/cinquecento/cinquecento.tga";
	samochody[0].modelItexture_path="modele/cinquecento/inside.tga";
	samochody[0].inside_path="modele/cinquecento/wnetrze.3ds";
	samochody[0].insidetexture_path="modele/cinquecento/wnetrze.bmp";
	samochody[0].kierownica_path="modele/kierownica/kierownica.3ds";
	samochody[0].kierownicatexture_path="modele/kierownica/kierownica.bmp";
	samochody[0].kolo_path="modele/cinquecento/kolo.dat";
	samochody[0].kolotexture_path="modele/cinquecento/kolo.bmp";
	samochody[0].kolo_przod_X=6.5f;
	samochody[0].kolo_tyl_X=-7.3f;
	samochody[0].kola_Y=4.1f;
	samochody[0].grubosc_kol=4.0f;
	samochody[0].wielkosc_kol=3.4f;
	samochody[0].Tx=0;
	samochody[0].Ty=0;
	samochody[0].Tz=-0.8f;
	samochody[0].Sx=0.17f;
	samochody[0].Sy=0.17f;
	samochody[0].Sz=0.17f;
	samochody[0].WTx=-0.3f;
	samochody[0].WTy=0.1f;
	samochody[0].WTz=-0.2f;
	samochody[0].WSx=0.12f;
	samochody[0].WSy=0.12f;
	samochody[0].WSz=0.11f;
	samochody[0].odkrecanie_kierownicy=1.5f;
	samochody[0].KTx=-19.2f;
	samochody[0].KTy=-16.2f;
	samochody[0].KTz=36.0f;
	samochody[0].KSx=0.95f;
	samochody[0].KSy=0.75f;
	samochody[0].KSz=0.95f;
	samochody[0].KatKier=-10;
	samochody[0].LSx=100;
	samochody[0].LSy=100;
	samochody[0].LSz=100;
	samochody[0].LTx=0;
	samochody[0].LTy=-0.3f;
	samochody[0].LTz=-0.27f;
	samochody[0].ALLy=-0.3f;
	samochody[0].linie=11;

	samochody[1].accelerationCONST=0.035f;
	samochody[1].hamulec=0.03f;
	samochody[1].max_predkosc=6.5f;
	samochody[1].model_path="modele/vw/vw.3ds";
	samochody[1].modeltexture_path="modele/vw/karoseria.tga";
	samochody[1].modelItexture_path="modele/vw/inside.tga";
	samochody[1].inside_path="modele/vw/wnetrze.3ds";
	samochody[1].insidetexture_path="modele/vw/wnetrze.bmp";
	samochody[1].kierownica_path="modele/kierownica/kierownica.3ds";
	samochody[1].kierownicatexture_path="modele/kierownica/kierownica.bmp";
	samochody[1].kolo_path="modele/vw/kolo.dat";
	samochody[1].kolotexture_path="modele/vw/kolo.bmp";
	samochody[1].kolo_przod_X=7.5f;
	samochody[1].kolo_tyl_X=-8.1f;
	samochody[1].kola_Y=4.8f;
	samochody[1].grubosc_kol=4.0f;
	samochody[1].wielkosc_kol=4.0f;
	samochody[1].Tx=0;
	samochody[1].Ty=-0.15f;
	samochody[1].Tz=-0.8f;
	samochody[1].Sx=0.22f;
	samochody[1].Sy=0.21f;
	samochody[1].Sz=0.19f;
	samochody[1].WTx=0.0f;
	samochody[1].WTy=0.0f;
	samochody[1].WTz=-0.6f;
	samochody[1].WSx=0.22f;
	samochody[1].WSy=0.20f;
	samochody[1].WSz=0.182f;
	samochody[1].odkrecanie_kierownicy=1.5f;
	samochody[1].KTx=-15.2f;
	samochody[1].KTy=-11.8f;
	samochody[1].KTz=25.0f;
	samochody[1].KSx=0.55f;
	samochody[1].KSy=0.55f;
	samochody[1].KSz=0.55f;
	samochody[1].KatKier=-10;
	samochody[1].LSx=100;
	samochody[1].LSy=100;
	samochody[1].LSz=100;
	samochody[1].LTx=0;
	samochody[1].LTy=-0.28f;
	samochody[1].LTz=-0.27f;
	samochody[1].linie=12.7f;

	samochody[2].accelerationCONST=0.03f;
	samochody[2].hamulec=0.03f;
	samochody[2].max_predkosc=7.0f;
	samochody[2].model_path="modele/audi/audi.3ds";
	samochody[2].modeltexture_path="modele/audi/audi.tga";
	samochody[2].modelItexture_path="modele/audi/inside.tga";
	samochody[2].inside_path="modele/audi/wnetrze.3ds";
	samochody[2].insidetexture_path="modele/audi/wnetrze.bmp";
	samochody[2].kierownica_path="modele/kierownica/kierownica.3ds";
	samochody[2].kierownicatexture_path="modele/kierownica/kierownica.bmp";
	samochody[2].kolo_path="modele/audi/kolo.dat";
	samochody[2].kolotexture_path="modele/audi/kolo.bmp";
	samochody[2].kolo_przod_X=8.5f;
	samochody[2].kolo_tyl_X=-8.8f;
	samochody[2].kola_Y=5.3f;
	samochody[2].grubosc_kol=5.0f;
	samochody[2].wielkosc_kol=4.0f;
	samochody[2].Tx=0;
	samochody[2].Ty=-0.15f;
	samochody[2].Tz=-0.5f;
	samochody[2].Sx=0.15f;
	samochody[2].Sy=0.15f;
	samochody[2].Sz=0.14f;
	samochody[2].WTx=0.5f;
	samochody[2].WTy=-0.16f;
	samochody[2].WTz=-1.2f;
	samochody[2].WSx=0.15f;
	samochody[2].WSy=0.145f;
	samochody[2].WSz=0.15f;
	samochody[2].odkrecanie_kierownicy=1.5f;
	samochody[2].KTx=-18.6f;
	samochody[2].KTy=-20.2f;
	samochody[2].KTz=35.8f;
	samochody[2].KSx=0.85f;
	samochody[2].KSy=0.85f;
	samochody[2].KSz=0.85f;
	samochody[2].KatKier=-20;
	samochody[2].LSx=100;
	samochody[2].LSy=100;
	samochody[2].LSz=100;
	samochody[2].LTx=0;
	samochody[2].LTy=-0.3f;
	samochody[2].LTz=-0.27f;
	samochody[2].linie=14.5f;


	samochody[3].accelerationCONST=0.015f;
	samochody[3].hamulec=0.03f;
	samochody[3].max_predkosc=4.7f;
	samochody[3].model_path="modele/trampek/trampek.3ds";
	samochody[3].modelItexture_path="modele/trampek/inside.tga";
	samochody[3].modeltexture_path="modele/trampek/trampek.tga";
	samochody[3].inside_path="modele/trampek/wnetrze.3ds";
	samochody[3].insidetexture_path="modele/trampek/wnetrze.bmp";
	samochody[3].kierownica_path="modele/kierownica/kierownica.3ds";
	samochody[3].kierownicatexture_path="modele/kierownica/kierownica.bmp";
	samochody[3].kolo_path="modele/trampek/kolo.dat";
	samochody[3].kolotexture_path="modele/trampek/kolo.bmp";
	samochody[3].kolo_przod_X=6.5f;
	samochody[3].kolo_tyl_X=-5.5f;
	samochody[3].kola_Y=5.0f;
	samochody[3].grubosc_kol=3.0f;
	samochody[3].wielkosc_kol=3.6f;
	samochody[3].Tx=0;
	samochody[3].Ty=0.3f;
	samochody[3].Tz=0.0f;
	samochody[3].Sx=0.15f;
	samochody[3].Sy=0.15f;
	samochody[3].Sz=0.15f;
	samochody[3].WTx=1.7f;
	samochody[3].WTy=0.3f;
	samochody[3].WTz=0.14f;
	samochody[3].WSx=0.12f;
	samochody[3].WSy=0.14f;
	samochody[3].WSz=0.10f;
	samochody[3].odkrecanie_kierownicy=1.5f;
	samochody[3].KTx=-15.6f;
	samochody[3].KTy=-16.2f;
	samochody[3].KTz=37.8f;
	samochody[3].KSx=0.85f;
	samochody[3].KSy=0.85f;
	samochody[3].KSz=0.85f;
	samochody[3].KatKier=-5;
	samochody[3].LSx=100;
	samochody[3].LSy=100;
	samochody[3].LSz=100;
	samochody[3].LTx=0;
	samochody[3].LTy=-0.3f;
	samochody[3].LTz=-0.25f;
	samochody[3].linie=13;

	samochody[4].accelerationCONST=0.025f;
	samochody[4].hamulec=0.03f;
	samochody[4].max_predkosc=5.5f;
	samochody[4].model_path="modele/skoda/skoda.3ds";
	samochody[4].modeltexture_path="modele/skoda/skoda.tga";
	samochody[4].modelItexture_path="modele/skoda/inside.tga";
	samochody[4].inside_path="modele/skoda/wnetrze.3ds";
	samochody[4].insidetexture_path="modele/skoda/wnetrze.bmp";
	samochody[4].kierownica_path="modele/kierownica/kierownica.3ds";
	samochody[4].kierownicatexture_path="modele/kierownica/kierownica.bmp";
	samochody[4].kolo_path="modele/skoda/kolo.dat";
	samochody[4].kolotexture_path="modele/skoda/kolo.bmp";
	samochody[4].kolo_przod_X=8.2f;
	samochody[4].kolo_tyl_X=-8.4f;
	samochody[4].kola_Y=5.5f;
	samochody[4].grubosc_kol=4.5f;
	samochody[4].wielkosc_kol=4.0f;
	samochody[4].Tx=0;
	samochody[4].Ty=0.0f;
	samochody[4].Tz=-1.1f;
	samochody[4].Sx=0.15f;
	samochody[4].Sy=0.15f;
	samochody[4].Sz=0.15f;
	samochody[4].WTx=0.0f;
	samochody[4].WTy=0.0f;
	samochody[4].WTz=-0.8f;
	samochody[4].WSx=0.15f;
	samochody[4].WSy=0.15f;
	samochody[4].WSz=0.15f;
	samochody[4].odkrecanie_kierownicy=1.5f;
	samochody[4].KTx=-18.6f;
	samochody[4].KTy=-16.2f;
	samochody[4].KTz=35.8f;
	samochody[4].KSx=0.65f;
	samochody[4].KSy=0.65f;
	samochody[4].KSz=0.65f;
	samochody[4].KatKier=-20;
	samochody[4].LSx=100;
	samochody[4].LSy=100;
	samochody[4].LSz=100;
	samochody[4].LTx=0;
	samochody[4].LTy=-0.3f;
	samochody[4].LTz=-0.27f;
	samochody[4].linie=14;


	samochody[5].accelerationCONST=0.015f;
	samochody[5].hamulec=0.03f;
	samochody[5].max_predkosc=4.5f;
	samochody[5].model_path="modele/fiat/maluch.3ds";
	samochody[5].modeltexture_path="modele/fiat/karoseria.tga";
	samochody[5].modelItexture_path="modele/fiat/inside.tga";
	samochody[5].inside_path="modele/fiat/wnetrze.3ds";
	samochody[5].insidetexture_path="modele/fiat/wnetrze.bmp";
	samochody[5].kierownica_path="modele/kierownica/kierownica.3ds";
	samochody[5].kierownicatexture_path="modele/kierownica/kierownica.bmp";
	samochody[5].kolo_path="modele/fiat/kolo.dat";
	samochody[5].kolotexture_path="modele/fiat/kolo.bmp";
	samochody[5].kolo_przod_X=5.5f;
	samochody[5].kolo_tyl_X=-5.6f;
	samochody[5].kola_Y=4.3f;
	samochody[5].grubosc_kol=4.0f;
	samochody[5].wielkosc_kol=3.0f;
	samochody[5].Tx=0;
	samochody[5].Ty=0.0f;
	samochody[5].Tz=-0.0f;
	samochody[5].Sx=0.16f;
	samochody[5].Sy=0.15f;
	samochody[5].Sz=0.13f;
	samochody[5].WTx=0.0f;
	samochody[5].WTy=0.0f;
	samochody[5].WTz=-0.0f;
	samochody[5].WSx=0.13f;
	samochody[5].WSy=0.15f;
	samochody[5].WSz=0.15f;
	samochody[5].odkrecanie_kierownicy=1.5f;
	samochody[5].KTx=-15.6f;
	samochody[5].KTy=-10.2f;
	samochody[5].KTz=25.8f;
	samochody[5].KSx=0.55f;
	samochody[5].KSy=0.55f;
	samochody[5].KSz=0.55f;
	samochody[5].KatKier=-20;
	samochody[5].LSx=135;
	samochody[5].LSy=115;
	samochody[5].LSz=135;
	samochody[5].LTx=0;
	samochody[5].LTy=-0.3f;
	samochody[5].LTz=-0.29f;
	samochody[5].ALLy=-0.3f;
	samochody[5].linie=11.5;
}
void LoadIkonki()
{
	dodaj_ikoneJPG("textures/ikonki.jpg/trawa.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/woda.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/asfalt.JPG");

	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/1.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/2.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/3.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/0.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/0.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/6.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/7.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/8.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/9.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/10.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/0.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/0.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/0.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/1.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/15.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/16.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/17.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/18.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/19.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/0.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/2.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/6.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/5.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/24.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/25.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/26.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/0.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/4.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/11.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/30.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/31.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/32.JPG");
	
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/8.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/9.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/14.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/15.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/16.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/17.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/18.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/20.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/24.JPG");

	dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/1.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/2.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/3.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/4.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/5.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/6.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/7.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/8.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/9.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/10.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/11.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/12.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/13.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret3/14.JPG");
		
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/33.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/34.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/zakret1/35.JPG");

	dodaj_ikoneJPG("textures/ikonki.jpg/torun/1.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/2.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/3.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/4.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/5.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/6.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/7.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/8.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/9.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/10.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/11.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/12.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/13.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/14.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/15.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/16.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/17.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/18.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/19.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/20.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/21.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/22.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/23.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/24.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/25.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/26.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/27.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/28.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/29.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/30.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/31.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/32.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/33.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/34.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/35.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/36.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/37.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/38.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/39.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/40.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/41.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/42.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/43.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/44.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/45.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/46.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/47.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/48.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/49.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/50.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/51.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/0.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/52.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/53.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/54.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/55.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/56.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/57.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/58.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/torun/59.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/torun/60.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/25.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/26.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/27.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/28.JPG");
	dodaj_ikoneJPG("textures/ikonki.jpg/miasto/29.JPG");dodaj_ikoneJPG("textures/ikonki.jpg/miasto/30.JPG");
}


void LoadTexturesMenu()
{
	menus[0].modele3DS[0].Init_3ds(samochody[0].model_path);	
	LoadTGAFile(&menus[0].modele3DSTGA[0],samochody[0].modeltexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	LoadTGAFile(&menus[0].modele3DSTGA[1],samochody[0].modelItexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	menus[0].modele3DS[1].Init_3ds(samochody[0].inside_path);
	menus[0].modele3DSBMP[1]=LoadTexture(samochody[0].insidetexture_path,2,mipmaps,false);
	menus[0].modele3d[1]=LoadModel3D(samochody[0].kolo_path,samochody[0].kolotexture_path,2,mipmaps,1,false);
	menus[0].modele3DS[2].Init_3ds(samochody[0].kierownica_path);	
	menus[0].modele3DSBMP[2]=LoadTexture(samochody[0].kierownicatexture_path,2,mipmaps,false);

	menus[1].modele3DS[0].Init_3ds(samochody[1].model_path);	
	LoadTGAFile(&menus[1].modele3DSTGA[0],samochody[1].modeltexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	LoadTGAFile(&menus[1].modele3DSTGA[1],samochody[1].modelItexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	menus[1].modele3DS[1].Init_3ds(samochody[1].inside_path);
	menus[1].modele3DSBMP[1]=LoadTexture(samochody[1].insidetexture_path,2,mipmaps,false);
	menus[1].modele3d[1]=LoadModel3D(samochody[1].kolo_path,samochody[1].kolotexture_path,2,mipmaps,1,false);
	menus[1].modele3DS[2].Init_3ds(samochody[1].kierownica_path);	
	menus[1].modele3DSBMP[2]=LoadTexture(samochody[1].kierownicatexture_path,2,mipmaps,false);

	menus[2].modele3DS[0].Init_3ds(samochody[2].model_path);	
	LoadTGAFile(&menus[2].modele3DSTGA[0],samochody[2].modeltexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	LoadTGAFile(&menus[2].modele3DSTGA[1],samochody[2].modelItexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	menus[2].modele3DS[1].Init_3ds(samochody[2].inside_path);
	menus[2].modele3DSBMP[1]=LoadTexture(samochody[2].insidetexture_path,2,mipmaps,false);
	menus[2].modele3d[1]=LoadModel3D(samochody[2].kolo_path,samochody[2].kolotexture_path,2,mipmaps,1,false);
	menus[2].modele3DS[2].Init_3ds(samochody[2].kierownica_path);	
	menus[2].modele3DSBMP[2]=LoadTexture(samochody[2].kierownicatexture_path,2,mipmaps,false);

	menus[3].modele3DS[0].Init_3ds(samochody[3].model_path);	
	LoadTGAFile(&menus[3].modele3DSTGA[0],samochody[3].modeltexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	LoadTGAFile(&menus[3].modele3DSTGA[1],samochody[3].modelItexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	menus[3].modele3DS[1].Init_3ds(samochody[3].inside_path);
	menus[3].modele3DSBMP[1]=LoadTexture(samochody[3].insidetexture_path,2,mipmaps,false);
	menus[3].modele3d[1]=LoadModel3D(samochody[3].kolo_path,samochody[3].kolotexture_path,2,mipmaps,1,false);
	menus[3].modele3DS[2].Init_3ds(samochody[3].kierownica_path);	
	menus[3].modele3DSBMP[2]=LoadTexture(samochody[3].kierownicatexture_path,2,mipmaps,false);

	menus[4].modele3DS[0].Init_3ds(samochody[4].model_path);	
	LoadTGAFile(&menus[4].modele3DSTGA[0],samochody[4].modeltexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	LoadTGAFile(&menus[4].modele3DSTGA[1],samochody[4].modelItexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	menus[4].modele3DS[1].Init_3ds(samochody[4].inside_path);
	menus[4].modele3DSBMP[1]=LoadTexture(samochody[4].insidetexture_path,2,mipmaps,false);
	menus[4].modele3d[1]=LoadModel3D(samochody[4].kolo_path,samochody[4].kolotexture_path,2,mipmaps,1,false);
	menus[4].modele3DS[2].Init_3ds(samochody[4].kierownica_path);	
	menus[4].modele3DSBMP[2]=LoadTexture(samochody[4].kierownicatexture_path,2,mipmaps,false);
	
	menus[5].modele3DS[0].Init_3ds(samochody[5].model_path);	
	LoadTGAFile(&menus[5].modele3DSTGA[0],samochody[5].modeltexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	LoadTGAFile(&menus[5].modele3DSTGA[1],samochody[5].modelItexture_path,mipmaps,2,false); //{1-mipmapy 2-jakosc}
	menus[5].modele3DS[1].Init_3ds(samochody[5].inside_path);
	menus[5].modele3DSBMP[1]=LoadTexture(samochody[5].insidetexture_path,2,mipmaps,false);
	menus[5].modele3d[1]=LoadModel3D(samochody[5].kolo_path,samochody[5].kolotexture_path,2,mipmaps,1,false);
	menus[5].modele3DS[2].Init_3ds(samochody[5].kierownica_path);	
	menus[5].modele3DSBMP[2]=LoadTexture(samochody[5].kierownicatexture_path,2,mipmaps,false);
	

}

void LoadTextures()
{
    CreateTexture("textures/sky.jpg",texture[0],1,1);
	texture[1]=LoadTexture("textures/metal.bmp",1,1,true);	
	CreateTexture("textures/cien.jpg",texture[2],1,1);
	
	//texture[3]=LoadTexture("strzalka2.bmp",2,0,false);
	CreateTexture("textures/hud/strzalka2.jpg",texture[3],1,1);
	texture[4]=LoadTexture("textures/hud/licznik2.bmp",2,0,false);
	//CreateTexture("licznik2.jpg",texture[4],1,1);
	texture[5]=LoadTexture("textures/hud/obrotomierz2.bmp",2,0,false);
	texture[6]=LoadTexture("textures/skrzynia/r.bmp",1,1,false);
	texture[7]=LoadTexture("textures/skrzynia/n.bmp",1,1,false);
	texture[8]=LoadTexture("textures/skrzynia/1.bmp",1,1,false);
	texture[9]=LoadTexture("textures/skrzynia/2.bmp",1,1,false);
	texture[10]=LoadTexture("textures/skrzynia/3.bmp",1,1,false);
	texture[11]=LoadTexture("textures/skrzynia/4.bmp",1,1,false);
	texture[12]=LoadTexture("textures/skrzynia/5.bmp",1,1,false);
	CreateTexture("textures/start/3.jpg",texture[14],1,1);
	CreateTexture("textures/start/2.jpg",texture[15],1,1);
	CreateTexture("textures/start/1.jpg",texture[16],1,1);
	texture[17]=LoadTexture("textures/shadow.bmp",1,1,false);
	CreateTexture("mapy/torun.jpg",texture[20],1,true);
	CreateTexture("mapy/miasto.jpg",texture[21],1,true);
//	CreateTexture("textures/ggate.jpg",texture[22],1,true);





	
	CreateTexture("textures/ludek/bar.jpg",textureLud[6],1,0);
	CreateTexture("textures/ludek/bok.jpg",textureLud[7],1,0);
	CreateTexture("textures/ludek/rekaw1.jpg",textureLud[8],1,0);
	CreateTexture("textures/ludek/rekaw2.jpg",textureLud[9],1,0);
	CreateTexture("textures/ludek/rekaw3.jpg",textureLud[10],1,0);
	CreateTexture("textures/ludek/rekaw4.jpg",textureLud[11],1,0);
	CreateTexture("textures/ludek/rekawica.jpg",textureLud[12],1,0);
	CreateTexture("textures/ludek/noga1.jpg",textureLud[13],1,0);
	CreateTexture("textures/ludek/noga2.jpg",textureLud[14],1,0);
	CreateTexture("textures/ludek/noga3.jpg",textureLud[15],1,0);
	CreateTexture("textures/ludek/noga4.jpg",textureLud[16],1,0);
	CreateTexture("textures/ludek/but.jpg",textureLud[17],1,0);

	modele3DSludek[0].Init_3ds("modele/ludek/head.3ds");
	modele3DSludekBMP[0]=LoadTexture("modele/ludek/head.bmp",2,false,false);



	LoadTGAFile(&textureT[0],"textures/dym.tga",false,2,false);
	LoadTGAFile(&textureT[1],"textures/slad.tga",true,1,false);



	sky=gluNewQuadric();
	gluQuadricNormals(sky,GLU_NONE);
	gluQuadricTexture(sky,GL_TRUE);

	modele3dTGA_ed[1]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/drzewka/drzewko.tga",2,false,4,false);
	modele3dTGA_ed[2]=LoadModel3DTGA("modele/swiat/banda.dat","modele/swiat/banda.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[3]=LoadModel3DTGA("modele/swiat/opony.dat","modele/swiat/opony.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[4]=LoadModel3DTGA("modele/swiat/slupek.dat","modele/swiat/slupek.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[5]=LoadModel3DTGA("modele/swiat/znak1.dat","modele/swiat/znak1.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[6]=LoadModel3DTGA("modele/swiat/znak2.dat","modele/swiat/znak2.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[7]=LoadModel3DTGA("modele/swiat/domek.dat","modele/swiat/domek.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[8]=LoadModel3DTGA("modele/swiat/siatka.dat","modele/swiat/siatka.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[9]=LoadModel3DTGA("modele/swiat/kibice.dat","modele/swiat/kibice.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[10]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/drzewka/drzewko2.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[11]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/drzewka/drzewko3.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[12]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[13]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek2.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[14]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek3.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[15]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek4.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[16]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek5.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[17]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek6.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[18]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek7.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[19]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek8.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[20]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek9.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[21]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek10.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[22]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek11.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[23]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek12.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[24]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/drzewka/drzewko4.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[25]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/drzewka/drzewko5.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[26]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/drzewka/drzewko6.tga",jakosc_textur,mipmaps,3,false);
	modele3dTGA_ed[27]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek13.tga",jakosc_textur,mipmaps,3,false);
	modele3dTGA_ed[28]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/krzaczki/krzaczek14.tga",jakosc_textur,mipmaps,3,false);	
	modele3dTGA_ed[29]=LoadModel3DTGA("modele/swiat/drzewko.dat","modele/swiat/drzewka/drzewko7.tga",jakosc_textur,mipmaps,3,false);
	modele3dTGA_ed[30]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/tlo.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[31]=LoadModel3DTGA("modele/swiat/siatka.dat","modele/swiat/granica.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[32]=LoadModel3DTGA("modele/swiat/blok.dat","modele/swiat/blok.tga",jakosc_textur,mipmaps,4,false);
	modele3dTGA_ed[33]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/1.tga",2,0,4,false);
	modele3dTGA_ed[34]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/2.tga",2,0,4,false);
	modele3dTGA_ed[35]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/3.tga",2,0,4,false);
	modele3dTGA_ed[36]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/4.tga",2,0,4,false);
	modele3dTGA_ed[37]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/5.tga",2,0,4,false);
	modele3dTGA_ed[38]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/6.tga",2,0,4,false);
	modele3dTGA_ed[39]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/7.tga",2,0,4,false);
	modele3dTGA_ed[40]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/8.tga",2,0,4,false);
	modele3dTGA_ed[41]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/9.tga",2,0,4,false);
	modele3dTGA_ed[42]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/10.tga",2,0,4,false);
	modele3dTGA_ed[43]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/11.tga",2,0,4,false);
	modele3dTGA_ed[44]=LoadModel3DTGA("modele/swiat/tlo.dat","modele/swiat/budynki/12.tga",2,0,4,false);
	modele3dTGA_ed[45]=LoadModel3DTGA("modele/swiat/meta.dat","modele/swiat/meta.tga",1,1,4,false);
	modele3dTGA_ed[46]=LoadModel3DTGA("modele/swiat/znaki/znak.dat","modele/swiat/znaki/znak1.tga",1,1,4,false);
	modele3dTGA_ed[47]=LoadModel3DTGA("modele/swiat/t.dat","modele/swiat/trybuna.tga",2,0,4,false);
	modele3dTGA_ed[48]=LoadModel3DTGA("modele/swiat/banda2.dat","modele/swiat/banda2.tga",2,0,4,false);
	modele3dTGA_ed[49]=LoadModel3DTGA("modele/swiat/start.dat","modele/swiat/start_red.tga",2,0,4,false);
	modele3dTGA_ed[50]=LoadModel3DTGA("modele/swiat/start.dat","modele/swiat/start_yellow.tga",2,0,4,false);
	modele3dTGA_ed[51]=LoadModel3DTGA("modele/swiat/start.dat","modele/swiat/start_green.tga",2,0,4,false);
	modele3dTGA_ed[52]=LoadModel3DTGA("modele/swiat/wieza.dat","modele/swiat/wieza.tga",2,0,4,false);
	modele3dTGA_ed[53]=LoadModel3DTGA("modele/swiat/siatka.dat","modele/swiat/granica.tga",2,0,4,false);
	

//aty[0][0][0]=0.99f;katy[0][1][0]=0.99f;
//aty[0][0][1]=0.99f;katy[0][1][1]=0.01f;
//aty[0][0][2]=0.01f;katy[0][1][2]=0.99f;
//aty[0][0][3]=0.01f;katy[0][1][3]=0.01f;

	

	katy[0][0][0]=0.99f;katy[0][1][0]=0.01f;
	katy[0][0][1]=0.99f;katy[0][1][1]=0.99f;
	katy[0][0][2]=0.01f;katy[0][1][2]=0.01f;
	katy[0][0][3]=0.01f;katy[0][1][3]=0.99f;

	katy[1][0][0]=0.99f;katy[1][1][0]=0.99f;
	katy[1][0][1]=0.01f;katy[1][1][1]=0.99f;
	katy[1][0][2]=0.99f;katy[1][1][2]=0.01f;
	katy[1][0][3]=0.01f;katy[1][1][3]=0.01f;

	katy[2][0][0]=0.01f;katy[2][1][0]=0.99f;
	katy[2][0][1]=0.01f;katy[2][1][1]=0.01f;
	katy[2][0][2]=0.99f;katy[2][1][2]=0.99f;
	katy[2][0][3]=0.99f;katy[2][1][3]=0.01f;

	katy[3][0][0]=0.01f;katy[3][1][0]=0.01f;
	katy[3][0][1]=0.99f;katy[3][1][1]=0.01f;
	katy[3][0][2]=0.01f;katy[3][1][2]=0.99f;
	katy[3][0][3]=0.99f;katy[3][1][3]=0.99f;

	katy[4][0][1]=0.01f;katy[4][1][1]=0.01f;
	katy[4][0][0]=0.99f;katy[4][1][0]=0.01f;
	katy[4][0][2]=0.99f;katy[4][1][2]=0.99f;
	katy[4][0][3]=0.01f;katy[4][1][3]=0.99f;
	
	katy[5][0][3]=0.01f;katy[5][1][3]=0.01f;
	katy[5][0][1]=0.99f;katy[5][1][1]=0.01f;
	katy[5][0][0]=0.99f;katy[5][1][0]=0.99f;
	katy[5][0][2]=0.01f;katy[5][1][2]=0.99f;

	katy[6][0][2]=0.01f;katy[6][1][2]=0.01f;
	katy[6][0][3]=0.99f;katy[6][1][3]=0.01f;
	katy[6][0][1]=0.99f;katy[6][1][1]=0.99f;
	katy[6][0][0]=0.01f;katy[6][1][0]=0.99f;

	katy[7][0][0]=0.01f;katy[7][1][0]=0.01f;
	katy[7][0][2]=0.99f;katy[7][1][2]=0.01f;
	katy[7][0][3]=0.99f;katy[7][1][3]=0.99f;
	katy[7][0][1]=0.01f;katy[7][1][1]=0.99f;

	for (int itemp2=0; itemp2<8; itemp2++)
	for (itemp=0; itemp<4; itemp++)
	{
		if (katy[itemp2][1][itemp]==0.01f) katy[itemp2][1][itemp]=0.99f; else katy[itemp2][1][itemp]=0.01f;
	}





	
}



void Save_Model_Coords()
{
	FILE* plik;
	plik=fopen("modele/coords.dat","w");
	fwrite(&modele_y,sizeof(modele_y),1,plik);
	fwrite(&modeleScale,sizeof(modeleScale),1,plik);
	fclose(plik);
}

void Load_Model_Coords()
{
	FILE* plik;
	plik=fopen("modele/coords.dat","r");
	fread(&modele_y,sizeof(modele_y),1,plik);
	fread(&modeleScale,sizeof(modeleScale),1,plik);
	fclose(plik);
}

void Sounds()
{
	if (sounds) {
	if (gracz.bieg!=100){
	if (gracz.obr>0) gracz.obr=0;
	ftemps[5]=(-gracz.obr+200)*200;
	if (gracz.bieg!=0) ftemps[5]+=(gracz.bieg*5000);
	if (ftemps[5]>700000) ftemps[5]=700000;
	if (ftemps[5]<-700000) ftemps[5]=-700000;}
	FSOUND_SetFrequency(gracz.channel2,ftemps[5]);

	if (gracz.pr<0.2) ftemps[5]=0;
	if (gracz.pr>0.2) ftemps[5]=gracz.pr*7000;
//	FSOUND_SetFrequency(gracz.channel1,44100);
//		FSOUND_SetVolume(KOMP.channel1, 0);
//	FSOUND_SetVolume(KOMP.channel2, 0);

	if (KOMP.xtrans>gracz.xtrans) ftemps[1]=KOMP.xtrans-gracz.xtrans;
	if (KOMP.xtrans<gracz.xtrans) ftemps[1]=gracz.xtrans-KOMP.xtrans;
	if (KOMP.ztrans>gracz.ztrans) ftemps[2]=KOMP.ztrans-gracz.ztrans;
	if (KOMP.ztrans<gracz.ztrans) ftemps[2]=gracz.ztrans-KOMP.ztrans;
	ftemp=sqrtf((ftemps[1]*ftemps[1])+(ftemps[2]*ftemps[2]));
	FSOUND_SetVolume(KOMP.channel2, 128-(ftemp/4.7f));
	FSOUND_SetVolume(KOMP.channel1, 128-(ftemp/4.7f));
	FSOUND_SetVolume(KOMP.channel3, 128-(ftemp/4.7f));
	if (ftemp>600) 
	{FSOUND_SetVolume(KOMP.channel2, 0);FSOUND_SetVolume(KOMP.channel1, 0);FSOUND_SetVolume(KOMP.channel3, 0);}
	ftemps[5]=(KOMP.pr+2)*12000;
	ftemps[5]+=KOMP.tempbieg*10000;
	FSOUND_SetFrequency(KOMP.channel2,ftemps[5]);


	if (KOMP2.xtrans>gracz.xtrans) ftemps[1]=KOMP2.xtrans-gracz.xtrans;
	if (KOMP2.xtrans<gracz.xtrans) ftemps[1]=gracz.xtrans-KOMP2.xtrans;
	if (KOMP2.ztrans>gracz.ztrans) ftemps[2]=KOMP2.ztrans-gracz.ztrans;
	if (KOMP2.ztrans<gracz.ztrans) ftemps[2]=gracz.ztrans-KOMP2.ztrans;
	ftemp=sqrtf((ftemps[1]*ftemps[1])+(ftemps[2]*ftemps[2]));
	FSOUND_SetVolume(KOMP2.channel2, 128-(ftemp/4.7f));
	FSOUND_SetVolume(KOMP2.channel1, 128-(ftemp/4.7f));
	FSOUND_SetVolume(KOMP2.channel3, 128-(ftemp/4.7f));
	if (ftemp>600) 	{FSOUND_SetVolume(KOMP2.channel2, 0);FSOUND_SetVolume(KOMP2.channel1, 0);FSOUND_SetVolume(KOMP2.channel3, 0);}
	ftemps[5]=(KOMP2.pr+2)*12000;
	ftemps[5]+=KOMP2.tempbieg*10000;
	FSOUND_SetFrequency(KOMP.channel2,ftemps[5]);


	if (KOMP3.xtrans>gracz.xtrans) ftemps[1]=KOMP3.xtrans-gracz.xtrans;
	if (KOMP3.xtrans<gracz.xtrans) ftemps[1]=gracz.xtrans-KOMP3.xtrans;
	if (KOMP3.ztrans>gracz.ztrans) ftemps[2]=KOMP3.ztrans-gracz.ztrans;
	if (KOMP3.ztrans<gracz.ztrans) ftemps[2]=gracz.ztrans-KOMP3.ztrans;
	ftemp=sqrtf((ftemps[1]*ftemps[1])+(ftemps[2]*ftemps[2]));
	FSOUND_SetVolume(KOMP3.channel2, 128-(ftemp/4.7f));
	FSOUND_SetVolume(KOMP3.channel1, 128-(ftemp/4.7f));
	FSOUND_SetVolume(KOMP3.channel3, 128-(ftemp/4.7f));
	if (ftemp>600) 	{FSOUND_SetVolume(KOMP3.channel2, 0);FSOUND_SetVolume(KOMP3.channel1, 0);FSOUND_SetVolume(KOMP3.channel3, 0);}
	ftemps[5]=(KOMP2.pr+2)*12000;
	ftemps[5]+=KOMP2.tempbieg*10000;
	FSOUND_SetFrequency(KOMP3.channel2,ftemps[5]);

	if (KOMP.zyje==false)
	{
		FSOUND_SetVolume(KOMP.channel2, 0);
		FSOUND_SetVolume(KOMP.channel1, 0);
		FSOUND_SetVolume(KOMP.channel3, 0);
	}
	if (KOMP2.zyje==false)
	{
		FSOUND_SetVolume(KOMP2.channel2, 0);
		FSOUND_SetVolume(KOMP2.channel1, 0);
		FSOUND_SetVolume(KOMP2.channel3, 0);
	}
	if (KOMP3.zyje==false)
	{
		FSOUND_SetVolume(KOMP3.channel2, 0);
		FSOUND_SetVolume(KOMP3.channel1, 0);
		FSOUND_SetVolume(KOMP3.channel3, 0);
	}
	}
}

void Inicjacja_Dzwiekow()
{
	if (sounds) 
	{
	gracz.ENGINE=NULL;gracz.BREAK=NULL;gracz.BOOM=NULL;
	KOMP.ENGINE=NULL;KOMP.BREAK=NULL;KOMP.BOOM=NULL;
	KOMP2.ENGINE=NULL;KOMP2.BREAK=NULL;KOMP2.BOOM=NULL;
	KOMP3.ENGINE=NULL;KOMP3.BREAK=NULL;KOMP3.BOOM=NULL;
	MUSIC=NULL;
	MUSIC2=NULL;

    gracz.channel1=1;gracz.channel2=2;gracz.channel3=9;
	KOMP.channel1=3;KOMP.channel2=4;KOMP.channel3=10;
	KOMP2.channel1=5;KOMP2.channel2=6;KOMP2.channel3=11;
	KOMP3.channel1=7;KOMP3.channel2=8;KOMP3.channel3=12;

	FSOUND_Init(44100, 32, 0);
	gracz.ENGINE=FSOUND_Sample_Load(FSOUND_FREE, "sounds/engine.wav", FSOUND_2D | FSOUND_STREAMABLE, 0);
	gracz.BREAK=FSOUND_Sample_Load(FSOUND_FREE, "sounds/break.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);
	gracz.BOOM=FSOUND_Sample_Load(FSOUND_FREE, "sounds/boom.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);

	KOMP.ENGINE=FSOUND_Sample_Load(FSOUND_FREE, "sounds/engine.wav", FSOUND_2D | FSOUND_STREAMABLE, 0);
	KOMP.BREAK=FSOUND_Sample_Load(FSOUND_FREE, "sounds/break.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);
	KOMP.BOOM=FSOUND_Sample_Load(FSOUND_FREE, "sounds/boom.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);

	KOMP2.ENGINE=FSOUND_Sample_Load(FSOUND_FREE, "sounds/engine.wav", FSOUND_2D | FSOUND_STREAMABLE, 0);
	KOMP2.BREAK=FSOUND_Sample_Load(FSOUND_FREE, "sounds/break.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);
	KOMP2.BOOM=FSOUND_Sample_Load(FSOUND_FREE, "sounds/boom.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);

	KOMP3.ENGINE=FSOUND_Sample_Load(FSOUND_FREE, "sounds/engine.wav", FSOUND_2D | FSOUND_STREAMABLE, 0);
	KOMP3.BREAK=FSOUND_Sample_Load(FSOUND_FREE, "sounds/break.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);
	KOMP3.BOOM=FSOUND_Sample_Load(FSOUND_FREE, "sounds/boom.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);

	

	MUSIC=FSOUND_Sample_Load(FSOUND_FREE, "sounds/menu.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);
	FSOUND_Sample_SetMode(MUSIC, FSOUND_LOOP_NORMAL);
	channelMUSIC = FSOUND_PlaySoundEx(FSOUND_FREE, MUSIC, NULL, TRUE);
	FSOUND_SetPaused(channelMUSIC, FALSE);
	FSOUND_SetVolume(channelMUSIC, 255);
	
	MUSIC2=FSOUND_Sample_Load(FSOUND_FREE, "sounds/wyscig.mp3", FSOUND_2D | FSOUND_STREAMABLE, 0);
	FSOUND_Sample_SetMode(MUSIC2, FSOUND_LOOP_NORMAL);
	channelMUSIC2 = FSOUND_PlaySoundEx(FSOUND_FREE, MUSIC2, NULL, TRUE);
//	FSOUND_SetPaused(channelMUSIC2, FALSE);
	FSOUND_SetVolume(channelMUSIC2, 255);

	FSOUND_Sample_SetMode(gracz.ENGINE, FSOUND_LOOP_NORMAL);
	FSOUND_Sample_SetMode(KOMP.ENGINE, FSOUND_LOOP_NORMAL);
	FSOUND_Sample_SetMode(KOMP2.ENGINE, FSOUND_LOOP_NORMAL);
	FSOUND_Sample_SetMode(KOMP3.ENGINE, FSOUND_LOOP_NORMAL);
	FSOUND_Sample_SetMode(gracz.BOOM, FSOUND_NORMAL);
	FSOUND_Sample_SetMode(KOMP.BOOM, FSOUND_NORMAL);
	FSOUND_Sample_SetMode(KOMP2.BOOM, FSOUND_NORMAL);
	FSOUND_Sample_SetMode(KOMP3.BOOM, FSOUND_NORMAL);
	gracz.channel2 = FSOUND_PlaySoundEx(FSOUND_FREE, gracz.ENGINE, NULL, TRUE);
	gracz.channel3 = FSOUND_PlaySoundEx(FSOUND_FREE, gracz.BOOM, NULL, TRUE);
	KOMP.channel2 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP.ENGINE, NULL, TRUE);
	KOMP.channel3 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP.BOOM, NULL, TRUE);
	KOMP2.channel2 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP2.ENGINE, NULL, TRUE);
	KOMP2.channel3 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP2.BOOM, NULL, TRUE);
	KOMP3.channel2 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP3.ENGINE, NULL, TRUE);
	KOMP3.channel3 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP3.BOOM, NULL, TRUE);
	FSOUND_SetVolume(gracz.channel1, 0);FSOUND_SetVolume(gracz.channel2, 0);FSOUND_SetVolume(gracz.channel3, 0);
	FSOUND_SetVolume(KOMP.channel1, 0);FSOUND_SetVolume(KOMP.channel2, 0);FSOUND_SetVolume(KOMP.channel3, 0);
	FSOUND_SetVolume(KOMP2.channel1, 0);FSOUND_SetVolume(KOMP2.channel2, 0);FSOUND_SetVolume(KOMP2.channel3, 0);
	FSOUND_SetVolume(KOMP3.channel1, 0);FSOUND_SetVolume(KOMP3.channel2, 0);FSOUND_SetVolume(KOMP3.channel3, 0);
	FSOUND_SetPaused(gracz.channel2, FALSE);
	FSOUND_SetPaused(KOMP.channel2, FALSE);
	FSOUND_SetPaused(KOMP2.channel2, FALSE);
	FSOUND_SetPaused(KOMP3.channel2, FALSE);

	FSOUND_Sample_SetMode(gracz.BREAK, FSOUND_LOOP_NORMAL);
	gracz.channel1 = FSOUND_PlaySoundEx(FSOUND_FREE, gracz.BREAK, NULL, TRUE);
	FSOUND_Sample_SetMode(KOMP.BREAK, FSOUND_LOOP_NORMAL);
	KOMP.channel1 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP.BREAK, NULL, TRUE);
	FSOUND_Sample_SetMode(KOMP2.BREAK, FSOUND_LOOP_NORMAL);
	KOMP2.channel1 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP2.BREAK, NULL, TRUE);
	FSOUND_Sample_SetMode(KOMP3.BREAK, FSOUND_LOOP_NORMAL);
	KOMP3.channel1 = FSOUND_PlaySoundEx(FSOUND_FREE, KOMP3.BREAK, NULL, TRUE);
	}
}

void Inicjacja_Dzwiekow_volume()
{
	if (sounds) 
	{
	FSOUND_SetVolume(gracz.channel1, 255);
	FSOUND_SetVolume(gracz.channel2, 60);
	FSOUND_SetVolume(gracz.channel3, 200);
	FSOUND_SetVolume(KOMP.channel1, 255);FSOUND_SetVolume(KOMP.channel2, 60);FSOUND_SetVolume(KOMP.channel3, 200);
	FSOUND_SetVolume(KOMP2.channel1, 255);FSOUND_SetVolume(KOMP2.channel2, 60);FSOUND_SetVolume(KOMP2.channel3, 200);
	FSOUND_SetVolume(KOMP3.channel1, 255);FSOUND_SetVolume(KOMP3.channel2, 60);FSOUND_SetVolume(KOMP3.channel3, 200);
	}
}
void Inicjacja_Dzwiekow_volume0()
{
	if (sounds) 
	{
	FSOUND_SetVolume(gracz.channel1, 0);FSOUND_SetVolume(gracz.channel2, 0);FSOUND_SetVolume(gracz.channel3, 0);
	FSOUND_SetVolume(KOMP.channel1, 0);FSOUND_SetVolume(KOMP.channel2, 0);FSOUND_SetVolume(KOMP.channel3, 0);
	FSOUND_SetVolume(KOMP2.channel1, 0);FSOUND_SetVolume(KOMP2.channel2, 0);FSOUND_SetVolume(KOMP2.channel3, 0);
	FSOUND_SetVolume(KOMP3.channel1, 0);FSOUND_SetVolume(KOMP3.channel2, 0);FSOUND_SetVolume(KOMP3.channel3, 0);
	FSOUND_SetPaused(gracz.channel1, TRUE);
	FSOUND_SetPaused(KOMP.channel1, TRUE);
	FSOUND_SetPaused(KOMP2.channel1, TRUE);
	FSOUND_SetPaused(KOMP3.channel1, TRUE);
	}
}


void InitFog()
{
	SetFog(150,150,150,250);
    glFogf(GL_FOG_DENSITY, 0.0001f);
	glEnable(GL_FOG);
}

void Ustaw_numery_samochodow(int s1, int s2, int s3, int s4, bool shadow_quality)
{
		for (i=0; i<12; i++)
	{
		KOMP.kompRANDOM[i]=false;KOMP2.kompRANDOM[i]=false;KOMP3.kompRANDOM[i]=false;
	}

	gracz.numer_samuchodu=s1;
	gracz.acceleration=samochody[gracz.numer_samuchodu].acceleration;
	gracz.accelerationCONST=samochody[gracz.numer_samuchodu].accelerationCONST;
	gracz.max_predkoscCONST=samochody[gracz.numer_samuchodu].max_predkosc*0.75f;
	gracz.max_predkosc=gracz.max_predkoscCONST;
	gracz.hamulec=samochody[gracz.numer_samuchodu].hamulec;
	gracz.temp_acc=0;
	gracz.bieg1max=gracz.max_predkoscCONST*0.15f;
	gracz.bieg2max=gracz.max_predkoscCONST*0.4f;
	gracz.bieg3max=gracz.max_predkoscCONST*0.6f;
	gracz.bieg4max=gracz.max_predkoscCONST*0.8f;
	gracz.bieg5max=gracz.max_predkoscCONST*1.0f;
	gracz.biegRmax=gracz.max_predkoscCONST*0.10f;
	gracz.biegNmax=0.f;
	gracz.bieg=1;
	gracz.tempbieg=1;
	gracz.katk=-90;
	gracz.nr_biegu=2;
	gracz.nr_sam=1;
	gracz.demage=0;

	tmp=gracz.max_predkosc;
	int poziom_trudnosci=6; //1-slaby 6-mocny
	shadow_quality=shadow_quality;
	randomize();

	KOMP.numer_samuchodu=s2;
	KOMP.acceleration=samochody[KOMP.numer_samuchodu].acceleration*1.25f;
	KOMP.accelerationCONST=samochody[KOMP.numer_samuchodu].accelerationCONST*1.25f;
	KOMP.max_predkoscCONST=samochody[KOMP.numer_samuchodu].max_predkosc*1.25f;
	KOMP.max_predkosc=KOMP.max_predkoscCONST;
	KOMP.hamulec=samochody[KOMP.numer_samuchodu].hamulec;
	KOMP.temp_acc=0;
	KOMP.bieg1max=KOMP.max_predkoscCONST*0.15f;
	KOMP.bieg2max=KOMP.max_predkoscCONST*0.4f;
	KOMP.bieg3max=KOMP.max_predkoscCONST*0.6f;
	KOMP.bieg4max=KOMP.max_predkoscCONST*0.8f;
	KOMP.bieg5max=KOMP.max_predkoscCONST*1.0f;
	KOMP.biegRmax=KOMP.max_predkoscCONST*0.25f;
	KOMP.biegNmax=0.f;
	KOMP.bieg=poziom_trudnosci;
	KOMP.tempbieg=poziom_trudnosci;
	KOMP.x=gracz.x+(Random(0,40)-20);
	KOMP.z=gracz.z-52+(Random(0,40)-20);
	KOMP.katk=-90;
	KOMP.nr_sam=2;
	KOMP.demage=0;

	KOMP2.numer_samuchodu=s3;
	KOMP2.acceleration=samochody[KOMP2.numer_samuchodu].acceleration*1.25f;
	KOMP2.accelerationCONST=samochody[KOMP2.numer_samuchodu].accelerationCONST*1.25f;
	KOMP2.max_predkoscCONST=samochody[KOMP2.numer_samuchodu].max_predkosc*1.25f;
	KOMP2.max_predkosc=KOMP2.max_predkoscCONST;
	KOMP2.hamulec=samochody[KOMP2.numer_samuchodu].hamulec;
	KOMP2.temp_acc=0;
	KOMP2.bieg1max=KOMP2.max_predkoscCONST*0.15f;
	KOMP2.bieg2max=KOMP2.max_predkoscCONST*0.4f;
	KOMP2.bieg3max=KOMP2.max_predkoscCONST*0.6f;
	KOMP2.bieg4max=KOMP2.max_predkoscCONST*0.8f;
	KOMP2.bieg5max=KOMP2.max_predkoscCONST*1.0f;
	KOMP2.biegRmax=KOMP2.max_predkoscCONST*0.25f;
	KOMP2.biegNmax=0.f;
	KOMP2.bieg=poziom_trudnosci;
	KOMP2.tempbieg=poziom_trudnosci;
	KOMP2.x=gracz.x+52+(Random(0,40)-20);
	KOMP2.z=gracz.z-52+(Random(0,40)-20);
	KOMP2.katk=-90;
	KOMP2.nr_sam=3;
	KOMP2.demage=0;

	KOMP3.numer_samuchodu=s4;
	KOMP3.acceleration=samochody[KOMP3.numer_samuchodu].acceleration*1.25f;
	KOMP3.accelerationCONST=samochody[KOMP3.numer_samuchodu].accelerationCONST*1.25f;
	KOMP3.max_predkoscCONST=samochody[KOMP3.numer_samuchodu].max_predkosc*1.25f;
	KOMP3.max_predkosc=KOMP3.max_predkoscCONST;
	KOMP3.hamulec=samochody[KOMP3.numer_samuchodu].hamulec;
	KOMP3.temp_acc=0;
	KOMP3.bieg1max=KOMP3.max_predkoscCONST*0.15f;
	KOMP3.bieg2max=KOMP3.max_predkoscCONST*0.4f;
	KOMP3.bieg3max=KOMP3.max_predkoscCONST*0.6f;
	KOMP3.bieg4max=KOMP3.max_predkoscCONST*0.8f;
	KOMP3.bieg5max=KOMP3.max_predkoscCONST*1.0f;
	KOMP3.biegRmax=KOMP3.max_predkoscCONST*0.25f;
	KOMP3.biegNmax=0.f;
	KOMP3.bieg=poziom_trudnosci;
	KOMP3.tempbieg=poziom_trudnosci;
	KOMP3.x=gracz.x+52+(Random(0,40)-20);
	KOMP3.z=gracz.z+(Random(0,40)-20);
	KOMP3.katk=-90;
	KOMP3.nr_sam=4;
	KOMP3.demage=0;


	gracz.alfa=255;
	KOMP.alfa=255;
	KOMP2.alfa=255;
	KOMP3.alfa=255;


	gracz.zyje=true;
	KOMP.zyje=true;
	KOMP2.zyje=true;
	KOMP3.zyje=true;

	gracz.id1=true;
	KOMP.id1=true;
	KOMP2.id1=true;
	KOMP3.id1=true;

	gracz.id2=false;
	KOMP.id2=false;
	KOMP2.id2=false;
	KOMP3.id2=false;

	gracz.ib1=true;
	KOMP.ib1=true;
	KOMP2.ib1=true;
	KOMP3.ib1=true;

	gracz.ib2=false;
	KOMP.ib2=false;
	KOMP2.ib2=false;
	KOMP3.ib2=false;

}

void Intro()
{
	for (itemp=0;itemp<240;itemp++)
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(0,0,-1);
	BarT(0.55f,-0.41f,0.015f,  
		  0.55f,0.41f,0.015f,
		 -0.55f,0.41f,0.015f,  
	     -0.55f,-0.41f,0.015f,
		  itemp,itemp,itemp,255,texture[22]);
	SwapBuffers(hDC);	
	Sleep(5);
	}
}
void Intro2()
{
	for (itemp=240;itemp>0;itemp--)
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(0,0,-1);
	BarT(0.55f,-0.41f,0.015f,  
		  0.55f,0.41f,0.015f,
		 -0.55f,0.41f,0.015f,  
	     -0.55f,-0.41f,0.015f,
		  itemp,itemp,itemp,255,texture[22]);
	SwapBuffers(hDC);	
	Sleep(5);
	}
}

void LoadScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(0,0,-1);
	BarT(0.55f,-0.41f,0.015f,  
		  0.55f,0.41f,0.015f,
		 -0.55f,0.41f,0.015f,  
	     -0.55f,-0.41f,0.015f,
		  255,255,255,200,texture[19]);
	SwapBuffers(hDC);	
}

void Reset_all_vars()
{
	gracz.HOTRODok=false;
	KOMP.HOTRODok=false;
	KOMP2.HOTRODok=false;
	KOMP3.HOTRODok=false;
	gracz.HOTROD=false;
	KOMP.HOTROD=false;
	KOMP2.HOTROD=false;
	KOMP3.HOTROD=false;
	gracz.w_tabelce=false;
	KOMP.w_tabelce=false;
	KOMP2.w_tabelce=false;
	KOMP3.w_tabelce=false;
	KOMP.x=0;
	KOMP.y=0;
	KOMP.z=0;
	KOMP.rx=0;
	KOMP.ry=0;
	KOMP.srx=0;
	KOMP.sry=0;
	KOMP.pr=0;
	KOMP.obr=0;
	KOMP.kat=0;
	KOMP.katk=0;
	KOMP.rozn=0;
	KOMP.bieg=0;
	KOMP.pobieg=0;
	KOMP.max_predkoscCONST=0;
	KOMP.max_predkosc=0;
	KOMP.acceleration=0;
	KOMP.accelerationCONST=0;
	KOMP.hamulec=0;
	KOMP.temp_acc=0;
	KOMP.bieg1max=0;
	KOMP.bieg2max=0;
	KOMP.bieg3max=0;
	KOMP.bieg4max=0;
	KOMP.bieg5max=0;
	KOMP.biegRmax=0;
	KOMP.biegNmax=0;
	KOMP.nr_biegu=0;
	KOMP.zm_bieg=0;
	KOMP.biegPLUS=0;
	KOMP.biegMINUS=0;
	KOMP.numer_samuchodu=0;
	KOMP.tempbieg=0;
	KOMP.przod=0;
	KOMP.tyl=0;
	KOMP.lewo=0;
	KOMP.prawo=0;
	KOMP.spacja=0;
	KOMP.odchyl=0;
	KOMP.skret=0;
	KOMP.skretP=0;
	KOMP.skretR=0;
	KOMP.podnies=0;
	KOMP.podniesP=0;
	KOMP.podniesR=0;
	KOMP.obrt_tyl=0;
	KOMP.obrt_prz=0;
	KOMP.rot_st=0;
	KOMP.rot_obr=0;
	KOMP.sladON=false;
	KOMP.reczny=false;
	KOMP.katskret=0;
	KOMP.katcam=0;
	KOMP.katcamP=0;
	KOMP.xtrans=0;
	KOMP.ytrans=0;
	KOMP.ztrans=0;
	KOMP.obrTYL=0;
	KOMP.prevP=0;
	KOMP.prevX=0;
	KOMP.prevZ=0;
	KOMP.wheels[0][0]=0;
	KOMP.wheels[1][0]=0;
	KOMP.wheels[2][0]=0;
	KOMP.wheels[0][1]=0;
	KOMP.wheels[1][1]=0;
	KOMP.wheels[2][1]=0;
	KOMP.wheels[0][2]=0;
	KOMP.wheels[1][2]=0;
	KOMP.wheels[2][2]=0;
	KOMP.randomInt=0;
	KOMP.wektorPR=0;
	KOMP.wektorSTR=0;
	KOMP.wektorSTRkat=0; //przesuniecie: przod-tyl i lewo-prawo i kat
	KOMP.ludekX=0;
	KOMP.ludekY=0;
	KOMP.ludekZ=0;
	KOMP.frame=0; // klatka animacji ludka
	KOMP.TIME=0;
	KOMP.TIME2=0;
	KOMP.ttime=0;
	KOMP.okr=0;
	KOMP.nr_sam=0;
	KOMP.podium=0;
	KOMP.demage=0;
	KOMP.alfa=0;
	KOMP.zyje=0;
	KOMP.badaj=0;
	KOMP.sladyRYS=false;
	AA=false;
	BB=true;
	podium[0]=false;
	podium[1]=false;
	podium[2]=false;
	podium[3]=false;
	nrcars=0;
	tmp=0;
	nr_swiatla=0;
	for (itemp=0;itemp<1001;itemp++)
	{
		dym[itemp].x=0;
		dym[itemp].y=0;
		dym[itemp].z=0;
		dym[itemp].rot=0;
		dym[itemp].rot2=0;
		dym[itemp].prawo=0;
		dym[itemp].dl=0;
		dym[itemp].is=false;
		dym[itemp].color=0;
		dym[itemp].gd=0;
		slady[itemp].gd=0;
		slady[itemp].x=0;
		slady[itemp].y=0;
		slady[itemp].z=0;
		slady[itemp].rot=0;
		slady[itemp].rot2=0;
		slady[itemp].prawo=0;
		slady[itemp].dl=0;		
	}
	gracz.x=0;
	gracz.y=0;
	gracz.z=0;
	gracz.rx=0;
	gracz.ry=0;
	gracz.srx=0;
	gracz.sry=0;
	gracz.pr=0;
	gracz.obr=0;
	gracz.kat=0;
	gracz.katk=0;
	gracz.rozn=0;
	gracz.bieg=0;
	gracz.pobieg=0;
	gracz.max_predkoscCONST=0;
	gracz.max_predkosc=0;
	gracz.acceleration=0;
	gracz.accelerationCONST=0;
	gracz.hamulec=0;
	gracz.temp_acc=0;
	gracz.bieg1max=0;
	gracz.bieg2max=0;
	gracz.bieg3max=0;
	gracz.bieg4max=0;
	gracz.bieg5max=0;
	gracz.biegRmax=0;
	gracz.biegNmax=0;
	gracz.nr_biegu=0;
	gracz.zm_bieg=0;
	gracz.biegPLUS=0;
	gracz.biegMINUS=0;
	gracz.numer_samuchodu=0;
	gracz.tempbieg=0;
	gracz.przod=0;
	gracz.tyl=0;
	gracz.lewo=0;
	gracz.prawo=0;
	gracz.spacja=0;
	gracz.odchyl=0;
	gracz.skret=0;
	gracz.skretP=0;
	gracz.skretR=0;
	gracz.podnies=0;
	gracz.podniesP=0;
	gracz.podniesR=0;
	gracz.obrt_tyl=0;
	gracz.obrt_prz=0;
	gracz.rot_st=0;
	gracz.rot_obr=0;
	gracz.sladON=false;
	gracz.reczny=false;
	gracz.katskret=0;
	gracz.katcam=0;
	gracz.katcamP=0;
	gracz.xtrans=0;
	gracz.ytrans=0;
	gracz.ztrans=0;
	gracz.obrTYL=0;
	gracz.prevP=0;
	gracz.prevX=0;
	gracz.prevZ=0;
	gracz.wheels[0][0]=0;
	gracz.wheels[1][0]=0;
	gracz.wheels[2][0]=0;
	gracz.wheels[0][1]=0;
	gracz.wheels[1][1]=0;
	gracz.wheels[2][1]=0;
	gracz.wheels[0][2]=0;
	gracz.wheels[1][2]=0;
	gracz.wheels[2][2]=0;
	gracz.randomInt=0;
	gracz.wektorPR=0;
	gracz.wektorSTR=0;
	gracz.wektorSTRkat=0; //przesuniecie: przod-tyl i lewo-prawo i kat
	gracz.ludekX=0;
	gracz.ludekY=0;
	gracz.ludekZ=0;
	gracz.frame=0; // klatka animacji ludka
	gracz.TIME=0;
	gracz.TIME2=0;
	gracz.ttime=0;
	gracz.okr=0;
	gracz.nr_sam=0;
	gracz.podium=0;
	gracz.demage=0;
	gracz.alfa=0;
	gracz.zyje=0;
	gracz.badaj=0;
	gracz.sladyRYS=false;
		KOMP2.x=0;
	KOMP2.y=0;
	KOMP2.z=0;
	KOMP2.rx=0;
	KOMP2.ry=0;
	KOMP2.srx=0;
	KOMP2.sry=0;
	KOMP2.pr=0;
	KOMP2.obr=0;
	KOMP2.kat=0;
	KOMP2.katk=0;
	KOMP2.rozn=0;
	KOMP2.bieg=0;
	KOMP2.pobieg=0;
	KOMP2.max_predkoscCONST=0;
	KOMP2.max_predkosc=0;
	KOMP2.acceleration=0;
	KOMP2.accelerationCONST=0;
	KOMP2.hamulec=0;
	KOMP2.temp_acc=0;
	KOMP2.bieg1max=0;
	KOMP2.bieg2max=0;
	KOMP2.bieg3max=0;
	KOMP2.bieg4max=0;
	KOMP2.bieg5max=0;
	KOMP2.biegRmax=0;
	KOMP2.biegNmax=0;
	KOMP2.nr_biegu=0;
	KOMP2.zm_bieg=0;
	KOMP2.biegPLUS=0;
	KOMP2.biegMINUS=0;
	KOMP2.numer_samuchodu=0;
	KOMP2.tempbieg=0;
	KOMP2.przod=0;
	KOMP2.tyl=0;
	KOMP2.lewo=0;
	KOMP2.prawo=0;
	KOMP2.spacja=0;
	KOMP2.odchyl=0;
	KOMP2.skret=0;
	KOMP2.skretP=0;
	KOMP2.skretR=0;
	KOMP2.podnies=0;
	KOMP2.podniesP=0;
	KOMP2.podniesR=0;
	KOMP2.obrt_tyl=0;
	KOMP2.obrt_prz=0;
	KOMP2.rot_st=0;
	KOMP2.rot_obr=0;
	KOMP2.sladON=false;
	KOMP2.reczny=false;
	KOMP2.katskret=0;
	KOMP2.katcam=0;
	KOMP2.katcamP=0;
	KOMP2.xtrans=0;
	KOMP2.ytrans=0;
	KOMP2.ztrans=0;
	KOMP2.obrTYL=0;
	KOMP2.prevP=0;
	KOMP2.prevX=0;
	KOMP2.prevZ=0;
	KOMP2.wheels[0][0]=0;
	KOMP2.wheels[1][0]=0;
	KOMP2.wheels[2][0]=0;
	KOMP2.wheels[0][1]=0;
	KOMP2.wheels[1][1]=0;
	KOMP2.wheels[2][1]=0;
	KOMP2.wheels[0][2]=0;
	KOMP2.wheels[1][2]=0;
	KOMP2.wheels[2][2]=0;
	KOMP2.randomInt=0;
	KOMP2.wektorPR=0;
	KOMP2.wektorSTR=0;
	KOMP2.wektorSTRkat=0; //przesuniecie: przod-tyl i lewo-prawo i kat
	KOMP2.ludekX=0;
	KOMP2.ludekY=0;
	KOMP2.ludekZ=0;
	KOMP2.frame=0; // klatka animacji ludka
	KOMP2.TIME=0;
	KOMP2.TIME2=0;
	KOMP2.ttime=0;
	KOMP2.okr=0;
	KOMP2.nr_sam=0;
	KOMP2.podium=0;
	KOMP2.demage=0;
	KOMP2.alfa=0;
	KOMP2.zyje=0;
	KOMP2.badaj=0;
	KOMP2.sladyRYS=false;
	KOMP3.x=0;
	KOMP3.y=0;
	KOMP3.z=0;
	KOMP3.rx=0;
	KOMP3.ry=0;
	KOMP3.srx=0;
	KOMP3.sry=0;
	KOMP3.pr=0;
	KOMP3.obr=0;
	KOMP3.kat=0;
	KOMP3.katk=0;
	KOMP3.rozn=0;
	KOMP3.bieg=0;
	KOMP3.pobieg=0;
	KOMP3.max_predkoscCONST=0;
	KOMP3.max_predkosc=0;
	KOMP3.acceleration=0;
	KOMP3.accelerationCONST=0;
	KOMP3.hamulec=0;
	KOMP3.temp_acc=0;
	KOMP3.bieg1max=0;
	KOMP3.bieg2max=0;
	KOMP3.bieg3max=0;
	KOMP3.bieg4max=0;
	KOMP3.bieg5max=0;
	KOMP3.biegRmax=0;
	KOMP3.biegNmax=0;
	KOMP3.nr_biegu=0;
	KOMP3.zm_bieg=0;
	KOMP3.biegPLUS=0;
	KOMP3.biegMINUS=0;
	KOMP3.numer_samuchodu=0;
	KOMP3.tempbieg=0;
	KOMP3.przod=0;
	KOMP3.tyl=0;
	KOMP3.lewo=0;
	KOMP3.prawo=0;
	KOMP3.spacja=0;
	KOMP3.odchyl=0;
	KOMP3.skret=0;
	KOMP3.skretP=0;
	KOMP3.skretR=0;
	KOMP3.podnies=0;
	KOMP3.podniesP=0;
	KOMP3.podniesR=0;
	KOMP3.obrt_tyl=0;
	KOMP3.obrt_prz=0;
	KOMP3.rot_st=0;
	KOMP3.rot_obr=0;
	KOMP3.sladON=false;
	KOMP3.reczny=false;
	KOMP3.katskret=0;
	KOMP3.katcam=0;
	KOMP3.katcamP=0;
	KOMP3.xtrans=0;
	KOMP3.ytrans=0;
	KOMP3.ztrans=0;
	KOMP3.obrTYL=0;
	KOMP3.prevP=0;
	KOMP3.prevX=0;
	KOMP3.prevZ=0;
	KOMP3.wheels[0][0]=0;
	KOMP3.wheels[1][0]=0;
	KOMP3.wheels[2][0]=0;
	KOMP3.wheels[0][1]=0;
	KOMP3.wheels[1][1]=0;
	KOMP3.wheels[2][1]=0;
	KOMP3.wheels[0][2]=0;
	KOMP3.wheels[1][2]=0;
	KOMP3.wheels[2][2]=0;
	KOMP3.randomInt=0;
	KOMP3.wektorPR=0;
	KOMP3.wektorSTR=0;
	KOMP3.wektorSTRkat=0; //przesuniecie: przod-tyl i lewo-prawo i kat
	KOMP3.ludekX=0;
	KOMP3.ludekY=0;
	KOMP3.ludekZ=0;
	KOMP3.frame=0; // klatka animacji ludka
	KOMP3.TIME=0;
	KOMP3.TIME2=0;
	KOMP3.ttime=0;
	KOMP3.okr=0;
	KOMP3.nr_sam=0;
	KOMP3.podium=0;
	KOMP3.demage=0;
	KOMP3.alfa=0;
	KOMP3.zyje=0;
	KOMP3.badaj=0;
	KOMP3.sladyRYS=false;	

}

