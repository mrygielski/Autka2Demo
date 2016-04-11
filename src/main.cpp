/******************************************************************
* AUTKA 2: RallyCross                                             *
*                                                                 *
* Uwagi:                                                          *
* - we wszystkich samochodach wykasowac katcam w pierwszym translatef
* - zrobic procedury cieni do kazdych samochoduf
*                                                                 *
*******************************************************************/
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include "..\jpeglib.h"
#include "..\jpg.h"
#pragma comment( lib, "winmm.lib" )
#pragma comment(lib, "jpeg.lib")
/////////////////MODU£Y///////
#include "..\files.h"
#include "..\ggate.h"
#include "..\fmod_gg.h"
#include "..\cameraGG.h"
#include "..\3DMath.h"
#include "..\3dsLoader.h"
//////////////////////////////
void BarT2(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4,int r,int g, int b,int a){glColor4ub(r,g,b,a);glBegin(GL_TRIANGLE_STRIP);glTexCoord2f(0.99f,0.01f);glVertex3f(x2,y2,z2);glTexCoord2f(0.99f,0.99f);glVertex3f(x1,y1,z1);glTexCoord2f(0.01f,0.01f);glVertex3f(x3,y3,z3);glTexCoord2f(0.01f,0.99f);glVertex3f(x4,y4,z4);glEnd();}
//////////////////////////////
#include "vars.h"
#include "ludek.h"
#include "rysowanie_sam.h"
#include "rysowanie_swiat.h"
#include "kolizje.h"
#include "fizyka.h"
#include "fizyka_komp.h"
#include "menu.h"
#include "init.h"
#include "resource.h"
//////////////////////////////

BOOL CALLBACK SetupDlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);


FSOUND_SAMPLE	*graczENGINE = NULL;
FSOUND_SAMPLE	*kompENGINE = NULL;
FSOUND_SAMPLE	*komp2ENGINE = NULL;
FSOUND_SAMPLE	*komp3ENGINE = NULL;
int channel1=0;
int channel11=1;
int channel12=2;
int channel13=3;
FSOUND_SAMPLE	*samp2 = NULL;
int channel2=4;

int OknoX,OknoY;
bool fullsc;
int odl_rys;
bool cien_qual;


bool off=false;

void DrawGLScene()
{
	ChangeFOV(60);
	glClear(GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	g_Camera.Look();
	

	gracz.kolizja1=false;gracz.kolizja2=false;gracz.kolizja3=false;gracz.kolizjaGR=false;
	KOMP.kolizjaGR=false;KOMP.kolizja2=false;KOMP.kolizja3=false;KOMP.kolizja=false;KOMP.kolizja1=false;
	KOMP2.kolizja1=false;KOMP2.kolizjaGR=false;KOMP2.kolizja3=false;KOMP2.kolizja=false;KOMP2.kolizja2=false;
	KOMP3.kolizja1=false;KOMP3.kolizjaGR=false;KOMP3.kolizja3=false;KOMP3.kolizja=false;KOMP3.kolizja2=false;
	if (gracz.alfa>20)	Zrob_Sam_Linie(gracz,samochody[gracz.numer_samuchodu].linie);
	if (KOMP.alfa>20)	Zrob_Sam_Linie(KOMP,samochody[KOMP.numer_samuchodu].linie);
	if (KOMP2.alfa>20)	Zrob_Sam_Linie(KOMP2,samochody[KOMP2.numer_samuchodu].linie);
	if (KOMP3.alfa>20)	Zrob_Sam_Linie(KOMP3,samochody[KOMP3.numer_samuchodu].linie);
	if (gracz.alfa<20) gracz.zyje=false;
	if (KOMP.alfa<20) KOMP.zyje=false;
	if (KOMP2.alfa<20) KOMP2.zyje=false;
	if (KOMP3.alfa<20) KOMP3.zyje=false;
	Wykryj_kolizje_NEW(gracz,gracz.kolizja,KOMP.zyje,KOMP2.zyje,KOMP3.zyje,0);
	Wykryj_kolizje_NEW(KOMP,KOMP.kolizja,  0,KOMP2.zyje,KOMP3.zyje,gracz.zyje);
	Wykryj_kolizje_NEW(KOMP2,KOMP2.kolizja,KOMP.zyje,0,KOMP3.zyje,gracz.zyje);
	Wykryj_kolizje_NEW(KOMP3,KOMP3.kolizja,KOMP.zyje,KOMP3.zyje,0,gracz.zyje);
	
	glDisable(GL_DEPTH_TEST);
	Rysuj_niebo();
	glEnable(GL_DEPTH_TEST);
	Rysuj_mape();

	RysujSlady(slady,gracz);

//	Rysuj_Linie_TEST();
//	Rysuj_Linie_TEST_CAR(gracz);
//	Rysuj_Linie_TEST_CAR(KOMP);
//	Rysuj_Linie_TEST_CAR(KOMP2);
//	Rysuj_Linie_TEST_CAR(KOMP3);
	

	if (gracz.zyje)
	{
		glPushMatrix();
		gracz.xtrans = gracz.x;
		gracz.ztrans = gracz.z;
		drawObjectShadow(gracz,gracz.alfa);
		glPopMatrix();
		glPushMatrix();
		gracz.xtrans = gracz.x;
		gracz.ztrans = gracz.z;
		Rysuj_Samochod(gracz,gracz.alfa);
		glPopMatrix();
	}
		
	if (KOMP.zyje)
	{
		glPushMatrix();
		KOMP.xtrans = KOMP.x;
		KOMP.ztrans = KOMP.z;
		drawObjectShadow(KOMP,KOMP.alfa);
		glPopMatrix();
		glPushMatrix();
		KOMP.xtrans = KOMP.x;
		KOMP.ztrans = KOMP.z;
		Rysuj_Samochod(KOMP,KOMP.alfa);
		glPopMatrix();
	}
	if (KOMP2.zyje)
	{
		glPushMatrix();
		KOMP2.xtrans = KOMP2.x;
		KOMP2.ztrans = KOMP2.z;
		drawObjectShadow(KOMP2,KOMP2.alfa);
		glPopMatrix();
		glPushMatrix();
		KOMP2.xtrans = KOMP2.x;
		KOMP2.ztrans = KOMP2.z;
		Rysuj_Samochod(KOMP2,KOMP2.alfa);
		glPopMatrix();
	}

	if (KOMP3.zyje)
	{
		glPushMatrix();
		KOMP3.xtrans = KOMP3.x;
		KOMP3.ztrans = KOMP3.z;
		drawObjectShadow(KOMP3,KOMP3.alfa);
		glPopMatrix();
		glPushMatrix();
		KOMP3.xtrans = KOMP3.x;
		KOMP3.ztrans = KOMP3.z;
		Rysuj_Samochod(KOMP3,KOMP3.alfa);
		glPopMatrix();
	}

	Rysuj_dym(0);
	ChangeFOV(45);

	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();



	glTranslatef(0,0,-1);
	glAlphaFunc(GL_GREATER, 0.5f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);
	piszTXT(0.42f,0.40f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "%.1ffps",FPS);
//	piszTXT(-0.54f,0.30f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "X=%f Y=%f Z=%f  NUMER=%i",modeleScale[nr_mod].x,modeleScale[nr_mod].y,modeleScale[nr_mod].z,nr_mod);
	if (gracz.okr!=maxokr) piszTXT(-0.54f,0.40f,0.015f,0.03f,0.03f,0,175,250,fonttexture.texID, "OKRAZENIA=%d/%d",gracz.okr+1,maxokr);
	else piszTXT(-0.54f,0.40f,0.015f,0.03f,0.03f,0,255,105,fonttexture.texID, "OKRAZENIA=%d/%d",gracz.okr,maxokr);
	if (gracz.demage<100) piszTXT(-0.54f,0.37f,0.015f,0.03f,0.03f,0,175,250,fonttexture.texID, "USZKODZENIA=%d",gracz.demage);
	else piszTXT(-0.54f,0.37f,0.015f,0.03f,0.03f,255,0,0,fonttexture.texID, "USZKODZENIA=100%",gracz.demage);
	if (gracz.okr>=maxokr || gracz.zyje==false) ShowPodium();
	glDisable(GL_BLEND);
	glAlphaFunc(GL_GREATER, 0.0f);
	Show_Kontrolki2();

	if (gracz.META==false)
	{
		gracz.TIME=TimerGetTime()/1000;
		gracz.TIME2=TimerGetTime()/1000;
		gracz.ttime=TimerGetTime()-(gracz.TIME*1000);
	}
	if (off==true) if (gracz.TIME2%100==1) {nr_swiatla=1;}
	if (off==true) if (gracz.TIME2%100==2) {nr_swiatla=2;}
	if (off==true) if (gracz.TIME2%100>=3) {off=false;}

	Draw_FPS();
}
void DrawGLScene2Trening()
{
	ChangeFOV(55);
	glClear(GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	g_Camera.Look();

	gracz.kolizja1=false;gracz.kolizja2=false;gracz.kolizja3=false;gracz.kolizjaGR=false;
//	KOMP.kolizjaGR=false;KOMP.kolizja2=false;KOMP.kolizja3=false;KOMP.kolizja=false;KOMP.kolizja1=false;
//	KOMP2.kolizja1=false;KOMP2.kolizjaGR=false;KOMP2.kolizja3=false;KOMP2.kolizja=false;KOMP2.kolizja2=false;
//	KOMP3.kolizja1=false;KOMP3.kolizjaGR=false;KOMP3.kolizja3=false;KOMP3.kolizja=false;KOMP3.kolizja2=false;
	if (gracz.alfa>20)	Zrob_Sam_Linie(gracz,samochody[gracz.numer_samuchodu].linie);
//	if (KOMP.alfa>20)	Zrob_Sam_Linie(KOMP,samochody[KOMP.numer_samuchodu].linie);
//	if (KOMP2.alfa>20)	Zrob_Sam_Linie(KOMP2,samochody[KOMP2.numer_samuchodu].linie);
//	if (KOMP3.alfa>20)	Zrob_Sam_Linie(KOMP3,samochody[KOMP3.numer_samuchodu].linie);
	if (gracz.alfa<20) gracz.zyje=false;
//	if (KOMP.alfa<20) KOMP.zyje=false;
//	if (KOMP2.alfa<20) KOMP2.zyje=false;
//	if (KOMP3.alfa<20) KOMP3.zyje=false;
	Wykryj_kolizje_NEW(gracz,gracz.kolizja,KOMP.zyje,KOMP2.zyje,KOMP3.zyje,0);
//	Wykryj_kolizje_NEW(KOMP,KOMP.kolizja,  0,KOMP2.zyje,KOMP3.zyje,gracz.zyje);
//	Wykryj_kolizje_NEW(KOMP2,KOMP2.kolizja,KOMP.zyje,0,KOMP3.zyje,gracz.zyje);
//	Wykryj_kolizje_NEW(KOMP3,KOMP3.kolizja,KOMP.zyje,KOMP3.zyje,0,gracz.zyje);

	glDisable(GL_DEPTH_TEST);
	Rysuj_niebo();
	glEnable(GL_DEPTH_TEST);
	Rysuj_mape();

	RysujSlady(slady,gracz);

	KOMP.pr=0;KOMP2.pr=0;KOMP3.pr=0;

	if (gracz.zyje)
	{
		glPushMatrix();
		gracz.xtrans = gracz.x;
		gracz.ztrans = gracz.z;
		drawObjectShadow(gracz,gracz.alfa);
		glPopMatrix();
		glPushMatrix();
		gracz.xtrans = gracz.x;
		gracz.ztrans = gracz.z;
		Rysuj_Samochod(gracz,gracz.alfa);
		glPopMatrix();
	}
		

	Rysuj_dym(0);
	ChangeFOV(45);

	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();



	glTranslatef(0,0,-1);
	glAlphaFunc(GL_GREATER, 0.5f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(255,255,255,255);

	piszTXT(0.42f,0.40f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "%.1ffps",FPS);
//	piszTXT(-0.54f,0.30f,0.015f,0.03f,0.03f,255,255,0,fonttexture.texID, "X=%f Y=%f Z=%f  NUMER=%i",modeleScale[nr_mod].x,modeleScale[nr_mod].y,modeleScale[nr_mod].z,nr_mod);
	if (gracz.okr!=maxokr) piszTXT(-0.54f,0.40f,0.015f,0.03f,0.03f,0,175,250,fonttexture.texID, "OKRAZENIA=%d/%d",gracz.okr+1,maxokr);
	else piszTXT(-0.54f,0.40f,0.015f,0.03f,0.03f,0,255,105,fonttexture.texID, "OKRAZENIA=%d/%d",gracz.okr,maxokr);
	if (gracz.demage<100) piszTXT(-0.54f,0.37f,0.015f,0.03f,0.03f,0,175,250,fonttexture.texID, "USZKODZENIA=%d%  ",gracz.demage);
	else piszTXT(-0.54f,0.37f,0.015f,0.03f,0.03f,255,0,0,fonttexture.texID, "USZKODZENIA=100%",gracz.demage);
	if (gracz.okr>=maxokr || gracz.zyje==false) ShowPodium();
	glDisable(GL_BLEND);
	glAlphaFunc(GL_GREATER, 0.0f);
	Show_Kontrolki2();

	if (gracz.META==false)
	{
		gracz.TIME=TimerGetTime()/1000;
		gracz.TIME2=TimerGetTime()/1000;
		gracz.ttime=TimerGetTime()-(gracz.TIME*1000);
	}
	if (off==true) if (gracz.TIME2%100==1) {nr_swiatla=1;}
	if (off==true) if (gracz.TIME2%100==2) {nr_swiatla=2;}
	if (off==true) if (gracz.TIME2%100>=3) {off=false;}

	Draw_FPS();
}
void GRA(int iloscokr,char* mapaFILE)
{
	FSOUND_StopSound(channelMUSIC);
	channelMUSIC2 = FSOUND_PlaySoundEx(FSOUND_FREE, MUSIC2, NULL, FALSE);
	FSOUND_SetVolume(channelMUSIC2, 255);
	tablicaW[1]="-";
	tablicaW[2]="-";
	tablicaW[3]="-";
	tablicaW[4]="-";
	KAMERA=2;
	InitFog();	
    plikLud=Assign("modele/skoczek.ani");
    read(plikLud,&ludek,sizeof(ludek));
    close(plikLud);
	Load_Model_Coords();
	LoadMap(mapaFILE);
	Ustaw_numery_samochodow(gracz.numer_samuchodu,KOMP.numer_samuchodu,KOMP2.numer_samuchodu,KOMP3.numer_samuchodu,shadow_quality);
	Zrob_Granice();
	TimerInit();
	gracz.frame=0;
	swiatla[0]=49;
	swiatla[1]=50;
	swiatla[2]=51;
	off=true;
	maxokr=iloscokr;
	ChangeFOV(45);
	Inicjacja_Dzwiekow_volume();

	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			if (gracz.okr>=maxokr && gracz.w_tabelce==false)
			{		
				gracz.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="GRACZ"; else
				if (tablicaW[2]=="-") tablicaW[2]="GRACZ"; else
				if (tablicaW[3]=="-") tablicaW[3]="GRACZ"; else
				if (tablicaW[4]=="-") tablicaW[4]="GRACZ"; 
			}
			if (gracz.zyje==false && gracz.w_tabelce==false)
			{		
				gracz.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="GRACZ WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="GRACZ WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="GRACZ WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="GRACZ WYKLUCZONY"; 
			}

			if (KOMP.okr>=maxokr && KOMP.w_tabelce==false)
			{		
				KOMP.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="KOMP"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP"; else
				if (tablicaW[4]=="-") tablicaW[4]="KOMP"; 
			}
			if (KOMP.zyje==false && KOMP.w_tabelce==false)
			{		
				KOMP.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="KOMP WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="KOMP WYKLUCZONY"; 
			}
			if (KOMP2.okr>=maxokr && KOMP2.w_tabelce==false)
			{		
				KOMP2.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="KOMP2"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP2"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP2"; else
				if (tablicaW[4]=="-") tablicaW[4]="KOMP2"; 
			}
			if (KOMP2.zyje==false && KOMP2.w_tabelce==false)
			{		
				KOMP2.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="KOMP2 WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP2 WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP2 WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="KOMP2 WYKLUCZONY"; 
			}
			if (KOMP3.okr>=maxokr && KOMP3.w_tabelce==false)
			{		
				KOMP3.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="KOMP3"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP3"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP3"; else
				if (tablicaW[4]=="-") tablicaW[4]="KOMP3"; 
			}
			if (KOMP3.zyje==false && KOMP3.w_tabelce==false)
			{		
				KOMP3.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="KOMP3 WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP3 WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP3 WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="KOMP3 WYKLUCZONY"; 
			}

			
			Sounds();
			ftemps[0]=gracz.katk*RAD;
			Kamery();

			DrawGLScene();
			
			SwapBuffers(hDC);
	

/*			if (keys['I']) {Sleep(100);nr_mod++;}
			if (keys['O']) {Sleep(100);nr_mod--;}
			if (keys['T']) {modeleScale[nr_mod].x+=0.005f;}
			if (keys['G']) {modeleScale[nr_mod].x-=0.005f;}
			if (keys['Y']) {modeleScale[nr_mod].y+=0.005f;}
			if (keys['H']) {modeleScale[nr_mod].y-=0.005f;}
			if (keys['U']) {modeleScale[nr_mod].z+=0.005f;}
			if (keys['J']) {modeleScale[nr_mod].z-=0.005f;}
			if (keys['R']) {modele_y[nr_mod]+=0.05f;}
			if (keys['F']) {modele_y[nr_mod]-=0.05f;}
*/


//			if (keys['H']) {gracz.alfa+=1;}
//			if (keys['G']) {gracz.alfa-=1;}

//			if (keys['Q']) {framerate=.00f;} else framerate=.03f;





			if (nr_swiatla>=2)
			{
			Inteligencja(KOMP);kat_global=kat;kat=0;
			if (KOMP.alfa>0) Fizyka_gryKOMP(KOMP,1,0,0);
			Inteligencja(KOMP2);kat_global=kat;kat=0;
			if (KOMP2.alfa>0) Fizyka_gryKOMP(KOMP2,0,1,0);
			Inteligencja(KOMP3);kat_global=kat;kat=0;
			if (KOMP3.alfa>0) Fizyka_gryKOMP(KOMP3,0,0,1);
			}
			
			if (nr_swiatla>=2 && gracz.alfa>0) Fizyka_gry(gracz);
		
			if (keys[VK_ESCAPE]) done=TRUE;
		}
	}
	Inicjacja_Dzwiekow_volume0();
	done=FALSE;
	Reset_all_vars();
	//	Save_Model_Coords();
	FSOUND_StopSound(channelMUSIC2);
	channelMUSIC = FSOUND_PlaySoundEx(FSOUND_FREE, MUSIC, NULL, FALSE);

}
void GRA2trening(int iloscokr, char *path)
{
	FSOUND_StopSound(channelMUSIC);
	channelMUSIC2 = FSOUND_PlaySoundEx(FSOUND_FREE, MUSIC2, NULL, FALSE);
	FSOUND_SetVolume(channelMUSIC2, 255);
	tablicaW[1]="-";
	tablicaW[2]="-";
	tablicaW[3]="-";
	tablicaW[4]="-";
	KAMERA=2;
	InitFog();	
    plikLud=Assign("modele/skoczek.ani");
    read(plikLud,&ludek,sizeof(ludek));
    close(plikLud);
	Load_Model_Coords();
	LoadMap(path);
	Ustaw_numery_samochodow(gracz.numer_samuchodu,KOMP.numer_samuchodu,KOMP2.numer_samuchodu,KOMP3.numer_samuchodu,shadow_quality);
	Zrob_Granice();
	TimerInit();
	gracz.frame=0;
	swiatla[0]=49;
	swiatla[1]=50;
	swiatla[2]=51;
	off=true;
	maxokr=iloscokr;
	ChangeFOV(45);
	Inicjacja_Dzwiekow_volume();
	KOMP.zyje=false;
	KOMP2.zyje=false;
	KOMP3.zyje=false;

	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			if (gracz.okr>=maxokr && gracz.w_tabelce==false)
			{		
				gracz.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="GRACZ"; else
				if (tablicaW[2]=="-") tablicaW[2]="GRACZ"; else
				if (tablicaW[3]=="-") tablicaW[3]="GRACZ"; else
				if (tablicaW[4]=="-") tablicaW[4]="GRACZ"; 
			}
			if (gracz.zyje==false && gracz.w_tabelce==false)
			{		
				gracz.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="GRACZ WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="GRACZ WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="GRACZ WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="GRACZ WYKLUCZONY"; 
			}

			if (KOMP.okr>=maxokr && KOMP.w_tabelce==false)
			{		
				KOMP.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="KOMP"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP"; else
				if (tablicaW[4]=="-") tablicaW[4]="KOMP"; 
			}
			if (KOMP.zyje==false && KOMP.w_tabelce==false)
			{		
				KOMP.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="KOMP WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="KOMP WYKLUCZONY"; 
			}
			if (KOMP2.okr>=maxokr && KOMP2.w_tabelce==false)
			{		
				KOMP2.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="KOMP2"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP2"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP2"; else
				if (tablicaW[4]=="-") tablicaW[4]="KOMP2"; 
			}
			if (KOMP2.zyje==false && KOMP2.w_tabelce==false)
			{		
				KOMP2.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="KOMP2 WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP2 WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP2 WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="KOMP2 WYKLUCZONY"; 
			}
			if (KOMP3.okr>=maxokr && KOMP3.w_tabelce==false)
			{		
				KOMP3.w_tabelce=true;
				if (tablicaW[1]=="-") tablicaW[1]="KOMP3"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP3"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP3"; else
				if (tablicaW[4]=="-") tablicaW[4]="KOMP3"; 
			}
			if (KOMP3.zyje==false && KOMP3.w_tabelce==false)
			{		
				KOMP3.w_tabelce=true;
				if (tablicaW[4]=="-") tablicaW[4]="KOMP3 WYKLUCZONY"; else
				if (tablicaW[3]=="-") tablicaW[3]="KOMP3 WYKLUCZONY"; else
				if (tablicaW[2]=="-") tablicaW[2]="KOMP3 WYKLUCZONY"; else
				if (tablicaW[1]=="-") tablicaW[1]="KOMP3 WYKLUCZONY"; 
			}

			
			Sounds();
			ftemps[0]=gracz.katk*RAD;
			Kamery();

			DrawGLScene2Trening();
			
			SwapBuffers(hDC);
	

/*			if (keys['I']) {Sleep(100);nr_mod++;}
			if (keys['O']) {Sleep(100);nr_mod--;}
			if (keys['T']) {modeleScale[nr_mod].x+=0.005f;}
			if (keys['G']) {modeleScale[nr_mod].x-=0.005f;}
			if (keys['Y']) {modeleScale[nr_mod].y+=0.005f;}
			if (keys['H']) {modeleScale[nr_mod].y-=0.005f;}
			if (keys['U']) {modeleScale[nr_mod].z+=0.005f;}
			if (keys['J']) {modeleScale[nr_mod].z-=0.005f;}
			if (keys['R']) {modele_y[nr_mod]+=0.05f;}
			if (keys['F']) {modele_y[nr_mod]-=0.05f;}



			if (keys['H']) {gracz.alfa+=1;}
			if (keys['G']) {gracz.alfa-=1;}

			if (keys['Q']) {framerate=.00f;} else framerate=.03f;


*/


			if (nr_swiatla>=2)
			{
			Inteligencja(KOMP);kat_global=kat;kat=0;
			Inteligencja(KOMP2);kat=0;
			Inteligencja(KOMP3);kat=0;
			}
			
			if (nr_swiatla>=2 && gracz.alfa>0) Fizyka_gry(gracz);
		
			if (KOMP.alfa>0) Fizyka_gryKOMP(KOMP,1,0,0);
		    if (KOMP2.alfa>0) Fizyka_gryKOMP(KOMP2,0,1,0);
			if (KOMP3.alfa>0) Fizyka_gryKOMP(KOMP3,0,0,1);

			if (keys[VK_ESCAPE]) done=TRUE;
		}
	}
	Inicjacja_Dzwiekow_volume0();
	done=FALSE;
	Reset_all_vars();
	//	Save_Model_Coords();
	FSOUND_StopSound(channelMUSIC2);
	channelMUSIC = FSOUND_PlaySoundEx(FSOUND_FREE, MUSIC, NULL, FALSE);
}
void MENU_mapa()
{
	Sleep(200);
	menu[3].x=-0.50f;menu[3].y=0.15f; 
	menu[3].info="Wybierz tor";menu[3].color=-100;
	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="TORUN - rallycross";menu[0].color=255;
	menu[1].x=-0.50f;menu[1].y=0.0f; 
	menu[1].info="MIASTECZKO";menu[1].color=255;
	menu[2].x=-0.50f;menu[2].y=-0.05f; 
	menu[2].info="powrot";menu[2].color=255;
	for (int i=4; i<10; i++ )menu[i].x=0;
	nropcji=0; //rally
	move=false;
	for (i=0; i<6; i++) menu[i].move=false;
	ChangeFOV(45);
	glClearColor(0.0, 0.0, 0.3f, 0.0);
	while(!done2)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu_mapa();
			
			SwapBuffers(hDC);

			if (keys[VK_DOWN]) {delay+=10; if (delay>=30) {if (nropcji<2) {nropcji++;}delay=0;}}
			if (keys[VK_UP]) {delay+=10; if (delay>=30) {if (nropcji>0) {nropcji--;}delay=0;}}
			
			if (nropcji==0) nr_mapy=0;
			if (nropcji==1) nr_mapy=1;

			if (nropcji==0 && keys[VK_RETURN])
			{
				LoadSamochody();
				KOMP.numer_samuchodu=nropcji2;
				KOMP2.numer_samuchodu=nropcji2;
				KOMP3.numer_samuchodu=nropcji2;
				GRA(4,"mapy/torun.dat");
				done2=true;
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;
				Sleep(200);nropcji=0;
			}
			if (nropcji==1 && keys[VK_RETURN])
			{
				LoadSamochody();
				KOMP.numer_samuchodu=nropcji2;
				KOMP2.numer_samuchodu=nropcji2;
				KOMP3.numer_samuchodu=nropcji2;
				GRA(4,"mapy/miasto.dat");
				done2=true;
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;
				Sleep(200);nropcji=0;
			}
			
			
			for (int i=0; i<4; i++)	

			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}
			if (nropcji==2 && keys[VK_RETURN]) 
			{
				done2=true;
				
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;

				Sleep(200);nropcji=0;
			}
		}
	}
}

void MENU_mapa2()
{
	Sleep(200);
	menu[3].x=-0.50f;menu[3].y=0.15f; 
	menu[3].info="Wybierz tor";menu[3].color=-100;
	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="TORUN - rallycross";menu[0].color=255;
	menu[1].x=-0.50f;menu[1].y=0.0f; 
	menu[1].info="MIASTECZKO";menu[1].color=255;
	menu[2].x=-0.50f;menu[2].y=-0.05f; 
	menu[2].info="powrot";menu[2].color=255;
	for (int i=4; i<10; i++ )menu[i].x=0;
	nropcji=0; //rally
	move=false;
	for (i=0; i<6; i++) menu[i].move=false;
	ChangeFOV(45);
	glClearColor(0.0, 0.0, 0.3f, 0.0);
	while(!done2)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu_mapa();
			
			SwapBuffers(hDC);

			if (keys[VK_DOWN]) {delay+=10; if (delay>=30) {if (nropcji<2) {nropcji++;}delay=0;}}
			if (keys[VK_UP]) {delay+=10; if (delay>=30) {if (nropcji>0) {nropcji--;}delay=0;}}
			
			if (nropcji==0) nr_mapy=0;
			if (nropcji==1) nr_mapy=1;

			if (nropcji==0 && keys[VK_RETURN])
			{
				LoadSamochody();
				KOMP.numer_samuchodu=nropcji2;
				KOMP2.numer_samuchodu=nropcji2;
				KOMP3.numer_samuchodu=nropcji2;
				GRA2trening(2,"mapy/torun.dat");
				done2=true;
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;
				Sleep(200);nropcji=0;
			}
			if (nropcji==1 && keys[VK_RETURN])
			{
				LoadSamochody();
				KOMP.numer_samuchodu=nropcji2;
				KOMP2.numer_samuchodu=nropcji2;
				KOMP3.numer_samuchodu=nropcji2;
				GRA2trening(2,"mapy/miasto.dat");
				done2=true;
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;
				Sleep(200);nropcji=0;
			}
			
			
			for (int i=0; i<4; i++)	

			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}
			if (nropcji==2 && keys[VK_RETURN]) 
			{
				done2=true;
				
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;

				Sleep(200);nropcji=0;
			}
		}
	}
}


void MENU_wyscig2()
{
	Sleep(200);

	menu[7].x=-0.50f;menu[7].y=0.15f; 
	menu[7].info="Samochody przeciwnikow";menu[7].color=-100;

	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="CINQUECENTO";menu[0].color=255;
	menu[1].x=-0.50f;menu[1].y=0.0f; 
	menu[1].info="VW GOLF";menu[1].color=255;
	menu[2].x=-0.50f;menu[2].y=-0.05f; 
	menu[2].info="AUDI";menu[2].color=255;
	menu[3].x=-0.50f;menu[3].y=-0.10f; 
	menu[3].info="TRABANT";menu[3].color=255;
	menu[4].x=-0.50f;menu[4].y=-0.15f; 
	menu[4].info="SKODA";menu[4].color=255;
	menu[5].x=-0.50f;menu[5].y=-0.20f;
	menu[5].info="FIAT 126p";menu[5].color=255;
	menu[6].x=-0.50f;menu[6].y=-0.25f;
	menu[6].info="powrot";menu[6].color=255;




	nropcji=0; //rally

	move=false;

	for (i=0; i<7; i++) menu[i].move=false;
	done2=false;
	nropcji2=0;
	while(!done2)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu1();
			
			SwapBuffers(hDC);

			if (keys[VK_DOWN]) {delay+=10; if (delay>=30) {if (nropcji<6) {nropcji++;nropcji2++;}delay=0;}}
			if (keys[VK_UP]) {delay+=10; if (delay>=30) {if (nropcji>0) {nropcji--;nropcji2--;}delay=0;}}



			for (int i=0; i<7; i++)	
				
			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}

  	
			if (nropcji<6 && keys[VK_RETURN])
			{
				nropcji=0;
				MENU_mapa();
			}
	
			if (nropcji==6 && keys[VK_RETURN]) 
			{
				done2=true;				
				
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;

				Sleep(200);nropcji=0;
			}
		}
	}
}

void MENU_wyscig()
{
	Sleep(200);

	menu[7].x=-0.50f;menu[7].y=0.15f; 
	menu[7].info="Wybierz swoj samochod";menu[7].color=-100;

	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="CINQUECENTO";menu[0].color=255;
	menu[1].x=-0.50f;menu[1].y=0.0f; 
	menu[1].info="VW GOLF";menu[1].color=255;
	menu[2].x=-0.50f;menu[2].y=-0.05f; 
	menu[2].info="AUDI";menu[2].color=255;
	menu[3].x=-0.50f;menu[3].y=-0.10f; 
	menu[3].info="TRABANT";menu[3].color=255;
	menu[4].x=-0.50f;menu[4].y=-0.15f; 
	menu[4].info="SKODA";menu[4].color=255;
	menu[5].x=-0.50f;menu[5].y=-0.20f;
	menu[5].info="FIAT 126p";menu[5].color=255;
	menu[6].x=-0.50f;menu[6].y=-0.25f;
	menu[6].info="powrot";menu[6].color=255;




	nropcji=0; //rally

	move=false;

	for (i=0; i<7; i++) menu[i].move=false;
	done2=false;
	while(!done2)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu1();
			
			SwapBuffers(hDC);

			if (keys[VK_DOWN]) {delay+=10; if (delay>=30) {if (nropcji<6) nropcji++;delay=0;}}
			if (keys[VK_UP]) {delay+=10; if (delay>=30) {if (nropcji>0) nropcji--;delay=0;}}


			for (int i=0; i<7; i++)	
				
			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}

  	
			if (nropcji<6 && keys[VK_RETURN])
			{
				
				LoadSamochody();
				gracz.numer_samuchodu=nropcji;
				MENU_wyscig2();
				done2=true;
			}
	
			if (nropcji==6 && keys[VK_RETURN]) 
			{
				done2=true;				
				
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;

				Sleep(200);nropcji=0;
			}
		}
	}
}

void MENU_trening()
{
	Sleep(200);

	menu[7].x=-0.50f;menu[7].y=0.15f; 
	menu[7].info="Wybierz swoj samochod";menu[7].color=-100;

	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="CINQUECENTO";menu[0].color=255;
	menu[1].x=-0.50f;menu[1].y=0.0f; 
	menu[1].info="VW GOLF";menu[1].color=255;
	menu[2].x=-0.50f;menu[2].y=-0.05f; 
	menu[2].info="AUDI";menu[2].color=255;
	menu[3].x=-0.50f;menu[3].y=-0.10f; 
	menu[3].info="TRABANT";menu[3].color=255;
	menu[4].x=-0.50f;menu[4].y=-0.15f; 
	menu[4].info="SKODA";menu[4].color=255;
	menu[5].x=-0.50f;menu[5].y=-0.20f;
	menu[5].info="FIAT 126p";menu[5].color=255;
	menu[6].x=-0.50f;menu[6].y=-0.25f;
	menu[6].info="powrot";menu[6].color=255;




	nropcji=0; //rally

	move=false;

	for (i=0; i<7; i++) menu[i].move=false;
	done2=false;
	while(!done2)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu1();
			
			SwapBuffers(hDC);

			if (keys[VK_DOWN]) {delay+=10; if (delay>=30) {if (nropcji<6) nropcji++;delay=0;}}
			if (keys[VK_UP]) {delay+=10; if (delay>=30) {if (nropcji>0) nropcji--;delay=0;}}


			for (int i=0; i<7; i++)	
				
			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}

  	
			if (nropcji<6 && keys[VK_RETURN])
			{
				
				LoadSamochody();
				gracz.numer_samuchodu=nropcji;
				MENU_mapa2();
				done2=true;
			}
	
			if (nropcji==6 && keys[VK_RETURN]) 
			{
				done2=true;				
				
				menu[7].x=0; menu[6].x=0; 					
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;
				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;

				Sleep(200);nropcji=2;
			}
		}
	}
}


void MENU_rally()
{
	Sleep(200);

	menu[5].x=-0.50f;menu[1].y=0.20f; 
	menu[5].info="RALLY";menu[1].color=-100;

	menu[7].x=0;
	menu[2].x=0;
	menu[3].x=0;
	menu[4].x=0;
	menu[6].x=0;
	menu[7].x=0;
	menu[8].x=0;
	menu[9].x=0;
	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="NIE DOSTEPNE";menu[0].color=255;
	menu[1].x=-0.50f;menu[1].y=0.0f; 
	menu[1].info="W DEMIE";menu[1].color=255;
	menu[2].x=-0.50f;menu[2].y=-0.10f; 
	menu[2].info="powrot";menu[2].color=255;
	



	nropcji=2; //rally

	move=false;

	for (i=0; i<3; i++) menu[i].move=false;
	done2=false;
	while(!done2)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu();
			
			SwapBuffers(hDC);

			for (int i=0; i<3; i++)	
				
			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}

	
  	
			if (nropcji==2 && keys[VK_RETURN]) 
			{
				done2=true;				
				
				menu[7].x=0; menu[6].x=0; 				
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;

				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;
				Sleep(200);nropcji=1;
			}
		}
	}
}



void MENU_autorzy()
{
	Sleep(200);

	menu[1].x=-0.50f;menu[1].y=0.20f; 
	menu[1].info="O autorach";menu[1].color=-100;

	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="powrot";menu[0].color=255;
	menu[7].x=0;
	menu[2].x=0;
	menu[3].x=0;
	menu[4].x=0;
	menu[5].x=0;
	menu[6].x=0;
	menu[7].x=0;
	menu[8].x=0;
	menu[9].x=0;




	nropcji=0; //rally

	move=false;

	for (i=0; i<1; i++) menu[i].move=false;
	done2=false;
	while(!done2)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu2();
			
			SwapBuffers(hDC);

			for (int i=0; i<1; i++)	
				
			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}

	
  	
			if (nropcji==0 && keys[VK_RETURN]) 
			{
				done2=true;				
				
				menu[7].x=0; menu[6].x=0; 				
				menu[5].x=-0.50f;menu[5].y=0.15f; 
				menu[5].info="MENU";menu[5].color=-100;

				menu[0].x=-0.50f;menu[0].y=0.05f; 
				menu[0].info="pojedynczy wyscig";menu[0].color=255;
				menu[1].x=-0.50f;menu[1].y=0.0f; 
				menu[1].info="rally";menu[1].color=255;
				menu[2].x=-0.50f;menu[2].y=-0.05f; 
				menu[2].info="trening";menu[2].color=255;
				menu[3].x=-0.50f;menu[3].y=-0.10f; 
				menu[3].info="autorzy";menu[3].color=255;
				menu[4].x=-0.50f;menu[4].y=-0.15f; 
				menu[4].info="wyjscie";menu[4].color=255;
				Sleep(200);nropcji=3;
			}
		}
	}
}


void MENU()
{
	menu[5].x=-0.50f;menu[5].y=0.15f; 
	menu[5].info="MENU";menu[5].color=-100;
	menu[0].x=-0.50f;menu[0].y=0.05f; 
	menu[0].info="pojedynczy wyscig";menu[0].color=255;
	menu[1].x=-0.50f;menu[1].y=0.0f; 
	menu[1].info="rally";menu[1].color=255;
	menu[2].x=-0.50f;menu[2].y=-0.05f; 
	menu[2].info="trening";menu[2].color=255;
	menu[3].x=-0.50f;menu[3].y=-0.10f; 
	menu[3].info="autorzy";menu[3].color=255;
	menu[4].x=-0.50f;menu[4].y=-0.15f; 
	menu[4].info="wyjscie";menu[4].color=255;
	nropcji=0; //rally
	move=false;
	for (i=0; i<6; i++) menu[i].move=false;
	ChangeFOV(45);
	glClearColor(0.0, 0.0, 0.3f, 0.0);
	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}
		else
		{
			DrawGLMenu();
			
			SwapBuffers(hDC);

			if (keys[VK_DOWN]) {delay+=10; if (delay>=30) {if (nropcji<4) nropcji++;delay=0;}}
			if (keys[VK_UP]) {delay+=10; if (delay>=30) {if (nropcji>0) nropcji--;delay=0;}}
			for (int i=0; i<5; i++)	
			{
				if (nropcji==i) menu[i].move=true; else menu[i].move=false;
			
				if (menu[i].move==true)
				{
					if (menu[i].x<-0.45) {menu[i].x+=0.01f;menu[i].color+=20;}
				} else if (menu[i].x>-0.50) {menu[i].x-=0.01f;menu[i].color-=20;}

			}
	     	if (nropcji==0 && keys[VK_RETURN]) {MENU_wyscig();done=false;}
			if (nropcji==1 && keys[VK_RETURN]) {MENU_rally();done=false;}
			if (nropcji==2 && keys[VK_RETURN]) {MENU_trening();done=false;}
			if (nropcji==3 && keys[VK_RETURN]) {MENU_autorzy();done=false;}
			if (nropcji==4 && keys[VK_RETURN]) done=true;
		}
	}
}




/////////////////////////////////////////////////////////////////////////////////////////////
int op1,op2,op3;
void SaveOp()
{
	FILE* plik;
	plik=fopen("rally.cfg","w");
	fwrite(&op1,sizeof(op1),1,plik);
	fwrite(&op2,sizeof(op2),1,plik);
	fwrite(&op3,sizeof(op3),1,plik);
	fclose(plik);
}
void LoadOp()
{
	FILE* plik;
	plik=fopen("rally.cfg","r");
	fread(&op1,sizeof(op1),1,plik);
	fread(&op2,sizeof(op2),1,plik);
	fread(&op3,sizeof(op3),1,plik);
	fclose(plik);
}




int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	OknoX=800;OknoY=600;fullsc=false;
	LoadOp();
	if(DialogBox(NULL, MAKEINTRESOURCE(IDD_SETUP), NULL, SetupDlgProc) <= 0) exit(0);
	

	if (CreateGLWindow("RallyCross 1.0 /GG_engine/",OknoX,OknoY,16,fullsc)==FALSE)
	{
		return 0;
	}
	CreateTexture("textures/menu.jpg",texture[18],1,true);
	CreateTexture("textures/loading.jpg",texture[19],1,true);
	LoadTGAFile(&textureT[2],"textures/logo.tga",true,1,false);
	LoadTGAFile(&fonttexture,"textures/font.tga",false,2,false);
	CreateTexture("textures/ggate.jpg",texture[22],1,true);
	//Intro();Intro2();
	LoadScreen();

	LoadIkonki();

	menus[0].numer_samuchodu=0;
	menus[1].numer_samuchodu=1;
	menus[2].numer_samuchodu=2;
	menus[3].numer_samuchodu=3;
	menus[4].numer_samuchodu=4;
	menus[5].numer_samuchodu=5;
	
	LoadSamochody();
	Load_Model_Coords();
	
	LoadTexturesMenu();

	if (sounds) Inicjacja_Dzwiekow();
	LoadTextures();
	Zrob_Granice();
	TimerInit();
	framerate=.01f;
	
	MENU();

	KillGLWindow();
	if (sounds) {
	FSOUND_Sample_Free(gracz.ENGINE);FSOUND_Sample_Free(gracz.BREAK);
	FSOUND_Sample_Free(KOMP.ENGINE);FSOUND_Sample_Free(KOMP.BREAK);
	FSOUND_Sample_Free(KOMP2.ENGINE);FSOUND_Sample_Free(KOMP2.BREAK);
	FSOUND_Sample_Free(KOMP3.ENGINE);FSOUND_Sample_Free(KOMP3.BREAK);
	FSOUND_Sample_Free(MUSIC);FSOUND_Sample_Free(MUSIC2);
	Close_FMOD();
	}
	return (msg.wParam);
}

TCHAR mode[25];


BOOL CALLBACK SetupDlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	static HWND hwndResolution, hwndCien, hwndRys,hwndSounds;
	int option[3];

	switch(message) {
	case WM_INITDIALOG:
		//initialize the dialog box by getting handles to all the combo boxes
		hwndResolution = GetDlgItem(hwndDlg, ID_RESOLUTION);
		hwndCien = GetDlgItem(hwndDlg, ID_CIEN);
		hwndRys = GetDlgItem(hwndDlg, ID_ODL);
		hwndSounds = GetDlgItem(hwndSounds, ID_SOUNDS);

		//fill in all options
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"320x240x16 windowed");
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"640x480x16 windowed");
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"800x600x16 windowed");
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"1024x768x16 windowed");
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"320x240x16 fullscreen");
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"640x480x16 fullscreen");
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"800x600x16 fullscreen");
		SendMessage(hwndResolution, CB_ADDSTRING, 0, (LPARAM)"1024x768x16 fullscreen");
		SendMessage(hwndCien, CB_ADDSTRING, 0, (LPARAM)"LOW");
		SendMessage(hwndCien, CB_ADDSTRING, 0, (LPARAM)"HIGH");
		SendMessage(hwndRys, CB_ADDSTRING, 0, (LPARAM)"blisko");
		SendMessage(hwndRys, CB_ADDSTRING, 0, (LPARAM)"œrednio");
		SendMessage(hwndRys, CB_ADDSTRING, 0, (LPARAM)"daleko");
		
		
		//fill in currently selected values
		SendMessage(hwndResolution, CB_SETCURSEL, op1, 0);
		SendMessage(hwndCien, CB_SETCURSEL, op2, 0);
		SendMessage(hwndRys, CB_SETCURSEL, op3, 0);
		
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam)) {
		case ID_SOUNDS:
			if(IsDlgButtonChecked(hwndDlg, ID_SOUNDS)) sounds=false; else sounds=true;
		break;

		case ID_OK:

			//format the option string
			option[0] = (int)SendMessage(hwndResolution, CB_GETCURSEL, 0, 0);
			op1=option[0];
			option[1] = (int)SendMessage(hwndCien, CB_GETCURSEL, 0, 0);
			op2=option[1];
			option[2] = (int)SendMessage(hwndRys, CB_GETCURSEL, 0, 0);
			op3=option[2];
			SaveOp();

			//format the mode string
			//get the resolution
			switch(option[0]) {
			case 0:
				OknoX=320;
				OknoY=240;
				fullsc=false;
				break;
			case 1:
				OknoX=640;
				OknoY=480;
				fullsc=false;
				break;
			case 2:
				OknoX=800;
				OknoY=600;
				fullsc=false;
				break;
			case 3:
				OknoX=1024;
				OknoY=768;
				fullsc=false;
				break;
			case 4:
				OknoX=320;
				OknoY=240;
				fullsc=true;
				break;
			case 5:
				OknoX=640;
				OknoY=480;
				fullsc=true;
				break;
			case 6:
				OknoX=800;
				OknoY=600;
				fullsc=true;
				break;
			case 7:
				OknoX=1024;
				OknoY=768;
				fullsc=true;
				break;
			}

			//get the bpp
			switch(option[1]) {
			case 0:
				shadow_quality=false;
				break;
			case 1:
				shadow_quality=true;
				break;
			}
			
			//get the refresh rate
			switch(option[2]) {
			case 0:
				odleglosc_rysowania=18;
				odleglosc_rysowania2=3;
				break;
			case 1:
				odleglosc_rysowania=25;
				odleglosc_rysowania2=6;
				break;
			case 2:
				odleglosc_rysowania=28;
				odleglosc_rysowania2=12;
				break;

			}
			EndDialog(hwndDlg, 1);
			return TRUE;
			break;

		case ID_CANCEL:
			option[0] = (int)SendMessage(hwndResolution, CB_GETCURSEL, 0, 0);
			op1=option[0];
			option[1] = (int)SendMessage(hwndCien, CB_GETCURSEL, 0, 0);
			op2=option[1];
			option[2] = (int)SendMessage(hwndRys, CB_GETCURSEL, 0, 0);
			op3=option[2];
			SaveOp();
			EndDialog(hwndDlg, 0);
			return TRUE;
			break;		
		}
		break;
	}
	return FALSE;
}





