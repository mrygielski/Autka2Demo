void Kamery()
{
//	if (keys['L']==false){
	headingRAD=ftemps[0];_3d_2d=ftemps[0];
//}
//	else {headingRAD=ftemps[0]+PI;_3d_2d=ftemps[0]+PI;}

	if (KAMERA==1) g_Camera.PositionCamera(camX,camY,camZ, gracz.x,gracz.y,gracz.z,0,1,0); // kamera a'la colin
	if (KAMERA==2) g_Camera.PositionCamera(
		(gracz.x)+(sinf(headingRAD)*30),
		gracz.y+15,(gracz.z)+(cosf(headingRAD)*30),
		gracz.x,gracz.y+10,gracz.z,0,1,0); //camera z bliska
	if (KAMERA==3) g_Camera.PositionCamera(
		(gracz.x)+(sinf(headingRAD)*40),
		gracz.y+20,(gracz.z)+(cosf(headingRAD)*40),
		gracz.x,gracz.y+10,gracz.z,0,1,0); //camera z bliska


	if (keys['1']) KAMERA=2;
	if (keys['2']) KAMERA=3;
}


void Dodaj_dymek(float x, float y, float z,float rot,int pr, int gd)
{
	for (i=1;i<ile_dymu;i++)
		if (dym[i].is==false)
		{
			dym[i].x=x;
			dym[i].y=y;
			dym[i].z=z;
			dym[i].is=true;
			dym[i].color=255.0f; 
			dym[i].rot=rot;
			dym[i].prawo=pr;
			dym[i].gd=gd;
			return;
		}
}


int nrnr=0;
void DodajSlad(float x,float y,float z,float rot, float prawo, float dl, int gd)
{
		itemp=sladnr;
		sladnr++;
		if (sladnr==1000) sladnr=0;
		
		slady[itemp].x=x;
		slady[itemp].y=y+0.1f;
		slady[itemp].z=z;
		slady[itemp].rot=rot;
		slady[itemp].rot2=-gracz.rozn;
		slady[itemp].dl=dl;
		slady[itemp].prawo=prawo;
		slady[itemp].gd=gd;
}

void DodajSladTyl(Tgracz &zawodnik)
{
	zawodnik.sladyRYS=true;
	if (zawodnik.obrTYL>30)
	{
		float x,y,z,rot,rot2,xx;
		x=y=z=rot=rot2=0;

		x+=zawodnik.xtrans;
		z+=zawodnik.ztrans;
		headingRAD=(zawodnik.katk+180)*RAD;
		x+=sinf(headingRAD)*10;
		z+=cosf(headingRAD)*10;
		rot+=zawodnik.katk+90;
		y=-3;
	
		xx=((zawodnik.obrTYL)/30.0f)*(0.05f*(zawodnik.pr)+1.2f);
		DodajSlad(x,y,z,rot,-1, xx ,-1);
		DodajSlad(x,y,z,rot,1, xx ,-1);
		
		zawodnik.obrTYL=0;
	}
}


void DodajSladPrzod(Tgracz &zawodnik)
{
	zawodnik.sladyRYS=true;
	if (zawodnik.obrTYL>30)
	{
		float x,y,z,rot,rot2,xx;
		x=y=z=rot=rot2=0;

		x+=zawodnik.xtrans;
		z+=zawodnik.ztrans;
		headingRAD=(zawodnik.katk+180)*RAD;
		x+=sinf(headingRAD)*10;
		z+=cosf(headingRAD)*10;
		rot+=zawodnik.katk+90;
		y=-3;
	
		xx=((zawodnik.obrTYL)/30.0f)*(0.05f*(zawodnik.pr)+1.2f);
		DodajSlad(x,y,z,rot,-1, xx ,1);
		DodajSlad(x,y,z,rot,1, xx ,1);
		
		zawodnik.obrTYL=0;
	}
}



int odst;

void AddBackSmoke(Tgracz &zawodnik)
{
	zawodnik.sladON=true;
	DodajSladTyl(zawodnik);
	odst++;
	if (odst<3) return;
	if (zawodnik.odchyl<0 && zawodnik.wheels[0][1]<20) zawodnik.wheels[0][1]+=0.0025f;
	if (zawodnik.odchyl>0 && zawodnik.wheels[1][1]<20) zawodnik.wheels[1][1]+=0.0025f;
		
	float x,y,z,rot;
	x=y=z=rot=0;

	x+=zawodnik.xtrans;
	z+=zawodnik.ztrans;
	headingRAD=(zawodnik.katk+180)*RAD;
	x+=sinf(headingRAD)*10;
	z+=cosf(headingRAD)*10;
	rot+=zawodnik.katk+90;
	y=-3;
	Dodaj_dymek(x,y,z,rot,1,1);
	Dodaj_dymek(x,y,z,rot,-1,1);
	odst=0;
}

void AddFrontSmoke(Tgracz &zawodnik)
{
	zawodnik.sladON=true;
	DodajSladTyl(zawodnik);	
	odst++;
	if (odst<4) return;
	if (zawodnik.odchyl<0 && zawodnik.wheels[0][1]<20) zawodnik.wheels[0][1]+=0.0025f;
	if (zawodnik.odchyl>0 && zawodnik.wheels[1][1]<20) zawodnik.wheels[1][1]+=0.0025f;
		
	float x,y,z,rot;
	x=y=z=rot=0;

	x+=zawodnik.xtrans;
	z+=zawodnik.ztrans;
	headingRAD=(zawodnik.katk+180)*RAD;
	x+=sinf(headingRAD)*10;
	z+=cosf(headingRAD)*10;
	rot+=zawodnik.katk+90;
	y=-3;
	Dodaj_dymek(x,y,z,rot,1,-1);
	Dodaj_dymek(x,y,z,rot,-1,-1);
	odst=0;
}

void Forward(Tgracz &zawodnik,float szybkosc,float kat)
{
	headingRAD=(zawodnik.kat+kat)*RAD;
	zawodnik.x -= (sinf(headingRAD)*szybkosc);
	zawodnik.z -= (cosf(headingRAD)*szybkosc);
	headingRAD=ftemps[0];
}

void Strafe(Tgracz &zawodnik,float kat,float szybkosc)
{
	zawodnik.x=zawodnik.x-(sinf( (zawodnik.kat+kat)*RAD )*szybkosc);
	zawodnik.z=zawodnik.z-(cosf( (zawodnik.kat+kat)*RAD )*szybkosc);
}

int nn;


void Fizyka_gry(Tgracz &zawodnik)
{
	if (zawodnik.zyje==false)
	{
		FSOUND_StopSound(zawodnik.channel1);
		FSOUND_StopSound(zawodnik.channel2);
		FSOUND_StopSound(zawodnik.channel3);
	}
	zawodnik.sladyRYS=false;
	if (zawodnik.demage>=100)
	{
		if (zawodnik.alfa>0) zawodnik.alfa-=5;

	}
	if (zawodnik.okr==maxokr) {zawodnik.demage=0;zawodnik.w_mecie=true;}
	


	if (gracz.pr>=gracz.max_predkosc && gracz.tempbieg<5 && gracz.tempbieg>=1) {gracz.tempbieg++;gracz.bieg++;zawodnik.obr+=120;if (zawodnik.obr>0) zawodnik.obr=0;}
	if (gracz.tempbieg==2 && gracz.pr<=gracz.bieg1max)  {gracz.tempbieg--;gracz.bieg--;}
	if (gracz.tempbieg==3 && gracz.pr<=gracz.bieg2max)  {gracz.tempbieg--;gracz.bieg--;}
	if (gracz.tempbieg==4 && gracz.pr<=gracz.bieg3max)  {gracz.tempbieg--;gracz.bieg--;}
	if (gracz.tempbieg==5 && gracz.pr<=gracz.bieg4max)  {gracz.tempbieg--;gracz.bieg--;}

	
	if (zawodnik.wektorSTR>0 && zawodnik.wektorSTR<=0.0125f) zawodnik.wektorSTR=0;
	if (zawodnik.wektorSTR<0 && zawodnik.wektorSTR>=-0.0125f) zawodnik.wektorSTR=0;
	if (zawodnik.wektorPR>0 && zawodnik.wektorPR<=0.0075f) zawodnik.wektorPR=0;
	if (zawodnik.wektorPR<0 && zawodnik.wektorPR>=-0.0075f) zawodnik.wektorPR=0;
	if (zawodnik.wektorPR>0) zawodnik.wektorPR-=0.0075f;
	if (zawodnik.wektorSTR>0) zawodnik.wektorSTR-=0.0125f;
	if (zawodnik.wektorPR<0) zawodnik.wektorPR+=0.0075f;
	if (zawodnik.wektorSTR<0) zawodnik.wektorSTR+=0.0125f;
	if (zawodnik.wektorPR!=0) Forward(zawodnik,zawodnik.wektorPR,0);
	if (zawodnik.wektorSTR!=0) Strafe(zawodnik,zawodnik.wektorSTRkat,zawodnik.wektorSTR);


	if (gracz.wektorPR!=0) Forward(gracz,gracz.wektorPR,0);
	if (gracz.wektorSTR!=0) Strafe(gracz,gracz.wektorSTRkat,gracz.wektorSTR);
	if (zawodnik.METAok==false) {AA=false;}
	if (zawodnik.METAok && AA==false) {if (zawodnik.HOTROD)
	{zawodnik.okr++;
	if (zawodnik.okr==maxokr) nrcars++; zawodnik.podium=nrcars;} AA=true; zawodnik.HOTROD=false;}
	if (zawodnik.HOTRODok==false) {BB=false;}
	if (zawodnik.HOTRODok && BB==false) {zawodnik.HOTROD=true;BB=true;}

	nn=mapa[ (int)((zawodnik.x)/64) ][ (int)((zawodnik.z)/64) ];

	//wolniej nie po trasie
	if ((nn==0 || nn==71 || nn==88 || nn==111 || nn==70 
		 || nn==70 || nn==94 || nn==66 || nn==107 ||
		 nn==105 || nn==99 || nn==89 || nn==113 ||
		 nn==97 || nn==68 || nn==78 || nn==62 || nn==61) && zawodnik.pr>1.8) zawodnik.pr=zawodnik.pr-0.05;

	if (zawodnik.ib2==true && zawodnik.ib1==true)
	{
		zawodnik.ib1=false;
		
		gracz.channel3 = FSOUND_PlaySound(FSOUND_FREE, gracz.BOOM);
	}
	if (zawodnik.kolizja) {zawodnik.ib2=true; zawodnik.ytrans=zawodnik.pr/8; zawodnik.demage=zawodnik.demage+(int)zawodnik.pr*10;} 
	else {zawodnik.ib1=true; zawodnik.ib2=false; }
	if (zawodnik.kolizja1 || zawodnik.kolizja2 || zawodnik.kolizja3) {zawodnik.ib2=true; zawodnik.ytrans=zawodnik.pr/8; zawodnik.demage=zawodnik.demage+(int)zawodnik.pr*2;}
//	else {zawodnik.ib1=true; zawodnik.ib2=false; }
	if (zawodnik.ytrans>0.1f) zawodnik.ytrans-=0.1f; //podskakiwanie
	
	if (KAMERA==1)
	{
		if (camX>zawodnik.xtrans) ftemps[15]=camX-zawodnik.xtrans; else ftemps[15]=zawodnik.xtrans-camX;
		if (camZ>zawodnik.ztrans) ftemps[16]=camZ-zawodnik.ztrans; else ftemps[16]=zawodnik.ztrans-camZ;
		ftemps[14]=sqrt( 
				(ftemps[15]*ftemps[15])+ 
				(ftemps[16]*ftemps[16]));
	}
	
	if (ftemps[14]>350)
	{
		{camX=zawodnik.xtrans-(Random(0,200)-100);camZ=zawodnik.ztrans-(Random(0,200)-100);camY=Random(30,70);keys2['0']=true;}
	}
	ftemps[4]=zawodnik.pr;
	

	if (zawodnik.kolizja1)
	{
		if (zawodnik._bCollided[1] && zawodnik._bCollided4_[1]==false && zawodnik._bCollided3_[1]==false) {zawodnik.pr=0;}
		if (zawodnik._bCollided2[1] && zawodnik._bCollided4[1]==false && zawodnik._bCollided3[1]==false) {zawodnik.wektorPR=0.2f;zawodnik.pr=0;}
		if (zawodnik._bCollided[1] && zawodnik._bCollided4_[1]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided[1] && zawodnik._bCollided3_[1]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided[1]==false && zawodnik._bCollided4_[1]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided[1]==false && zawodnik._bCollided3_[1]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;}
		if (zawodnik._bCollided2[1] && zawodnik._bCollided4[1]) {zawodnik.wektorPR=0.2f;zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[1] && zawodnik._bCollided3[1]) {zawodnik.wektorPR=0.2f;zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[1]==false && zawodnik._bCollided4[1]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided2[1]==false && zawodnik._bCollided3[1]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;}
		zawodnik.wektorPR=0;
	}

	if (zawodnik.kolizja2)
	{
		if (zawodnik._bCollided[2] && zawodnik._bCollided4_[2]==false && zawodnik._bCollided3_[2]==false) {zawodnik.pr=0;}
		if (zawodnik._bCollided2[2] && zawodnik._bCollided4[2]==false && zawodnik._bCollided3[2]==false) {zawodnik.wektorPR=0.2f;zawodnik.pr=0;}
		if (zawodnik._bCollided[2] && zawodnik._bCollided4_[2]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided[2] && zawodnik._bCollided3_[2]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided[2]==false && zawodnik._bCollided4_[2]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided[2]==false && zawodnik._bCollided3_[2]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;}
		if (zawodnik._bCollided2[2] && zawodnik._bCollided4[2]) {zawodnik.wektorPR=0.2f;zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[2] && zawodnik._bCollided3[2]) {zawodnik.wektorPR=0.2f;zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[2]==false && zawodnik._bCollided4[2]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided2[2]==false && zawodnik._bCollided3[2]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;}
		zawodnik.wektorPR=0;
	}

	if (zawodnik.kolizja3)
	{
		if (zawodnik._bCollided[3] && zawodnik._bCollided4_[3]==false && zawodnik._bCollided3_[3]==false) {zawodnik.pr=0;}
		if (zawodnik._bCollided2[3] && zawodnik._bCollided4[3]==false && zawodnik._bCollided3[3]==false) {zawodnik.wektorPR=0.2f;zawodnik.pr=0;}
		if (zawodnik._bCollided[3] && zawodnik._bCollided4_[3]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided[3] && zawodnik._bCollided3_[3]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided[3]==false && zawodnik._bCollided4_[3]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided[3]==false && zawodnik._bCollided3_[3]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;}
		if (zawodnik._bCollided2[3] && zawodnik._bCollided4[3]) {zawodnik.wektorPR=0.2f;zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[3] && zawodnik._bCollided3[3]) {zawodnik.wektorPR=0.2f;zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[3]==false && zawodnik._bCollided4[3]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided2[3]==false && zawodnik._bCollided3[3]) {zawodnik.wektorSTR=0.2f;zawodnik.wektorSTRkat=90;}
		zawodnik.wektorPR=0;
	}

	if ( (zawodnik.kolizja) &&
		 (ftemps[4]>zawodnik.accelerationCONST))
	{
		ftemp=0;
		if ((zawodnik.bCollided3==false && zawodnik.bCollided4==true) || (zawodnik.bCollided3_==false && zawodnik.bCollided4_==true)) //lewa
		{
			if (zawodnik.tempbieg>0 && zawodnik.bieg>0) ftemp=90;
			if (zawodnik.tempbieg<0 && zawodnik.bieg<0) ftemp=-90;
			if (zawodnik.tempbieg>0 && zawodnik.bieg==0) ftemp=-90;
			if (zawodnik.tempbieg<0 && zawodnik.bieg==0) ftemp=90;
		} else
		if ((zawodnik.bCollided3==true && zawodnik.bCollided4==false) || (zawodnik.bCollided3_==true && zawodnik.bCollided4_==false)) //prawa
		{
			if (zawodnik.tempbieg>0 && zawodnik.bieg>0) ftemp=-90;
			if (zawodnik.tempbieg<0 && zawodnik.bieg<0) ftemp=90;
			if (zawodnik.tempbieg>0 && zawodnik.bieg==0) ftemp=90;
			if (zawodnik.tempbieg<0 && zawodnik.bieg==0) ftemp=-90;
		}
		if (zawodnik.tempbieg>0 && zawodnik.bieg==0) Forward(zawodnik,zawodnik.pr+ftemps[4],ftemp);
		if (zawodnik.tempbieg<0 && zawodnik.bieg==-1) Forward(zawodnik,-zawodnik.pr+ftemps[4],ftemp);
		if (zawodnik.tempbieg==-1 && zawodnik.bieg==0) Forward(zawodnik,-zawodnik.pr-ftemps[4],ftemp);
		zawodnik.pr=0.0f;
		if (zawodnik.tempbieg<0 && zawodnik.bieg==-1) Forward(zawodnik,ftemps[4],ftemp);
		if (zawodnik.tempbieg==1 && zawodnik.bieg==1) Forward(zawodnik,-ftemps[4],ftemp);
	}
	else
	{
	if (zawodnik.kolizja) 
	{
		
		if (zawodnik.tempbieg>0 && zawodnik.bieg>0 && (zawodnik.bCollided3_==true || zawodnik.bCollided4_==true)) zawodnik.pr=-0.2f;
		if (zawodnik.tempbieg>0 && zawodnik.bieg==0 && (zawodnik.bCollided3_==true || zawodnik.bCollided4_==true)) zawodnik.pr=0.2f;
		if (zawodnik.tempbieg>0 && zawodnik.bieg>0 && (zawodnik.bCollided3==true || zawodnik.bCollided4==true)) zawodnik.pr=0.2f;
		if (zawodnik.tempbieg>0 && zawodnik.bieg==0 && (zawodnik.bCollided3==true || zawodnik.bCollided4==true)) zawodnik.pr=-0.2f;

		if (zawodnik.tempbieg<0 && zawodnik.bieg<0 && (zawodnik.bCollided3==true || zawodnik.bCollided4==true)) zawodnik.pr=-0.2f;
		if (zawodnik.tempbieg<0 && zawodnik.bieg==0 && (zawodnik.bCollided3==true || zawodnik.bCollided4==true)) zawodnik.pr=0.2f;
		if (zawodnik.tempbieg<0 && zawodnik.bieg<0 && (zawodnik.bCollided3_==true || zawodnik.bCollided4_==true)) zawodnik.pr=0.2f;
		if (zawodnik.tempbieg<0 && zawodnik.bieg==0 && (zawodnik.bCollided3_==true || zawodnik.bCollided4_==true)) zawodnik.pr=-0.2f;
	}
	
	if (zawodnik.tempbieg==1) ftemps[8]=0;
	if (zawodnik.tempbieg==2) ftemps[8]=zawodnik.bieg1max;
	if (zawodnik.tempbieg==3) ftemps[8]=zawodnik.bieg2max;
	if (zawodnik.tempbieg==4) ftemps[8]=zawodnik.bieg3max;
	if (zawodnik.tempbieg==5) ftemps[8]=zawodnik.bieg4max;
	if (zawodnik.tempbieg==-1) ftemps[8]=zawodnik.biegRmax;
	if (zawodnik.pr>0 && zawodnik.pr<zawodnik.bieg1max) ftemps[7]=1;
	if (zawodnik.pr>zawodnik.bieg1max && zawodnik.pr<zawodnik.bieg2max) ftemps[7]=2;
	if (zawodnik.pr>zawodnik.bieg2max && zawodnik.pr<zawodnik.bieg3max) ftemps[7]=3;
	if (zawodnik.pr>zawodnik.bieg3max && zawodnik.pr<zawodnik.bieg4max) ftemps[7]=4;
	if (zawodnik.pr>zawodnik.bieg4max && zawodnik.pr<zawodnik.bieg5max) ftemps[7]=5;
	ftemps[7]=zawodnik.tempbieg-ftemps[7];
	zawodnik.acceleration=zawodnik.accelerationCONST*(1-(ftemps[7]/5));
	

	if (keys['A']==false) {Apressed=false;}
	if (keys['Z']==false) {Zpressed=false;}

	if (zawodnik.kolizja1) zawodnik.kolizja=true;
	if (zawodnik.kolizja2) zawodnik.kolizja=true;
	if (zawodnik.kolizja3) zawodnik.kolizja=true;
	if (zawodnik.kolizjaGR) zawodnik.kolizja=true;

	
/*	if (keys['A'] && zawodnik.pr>=0 && zawodnik.kolizja==false && Apressed==false && zawodnik.tempbieg==zawodnik.bieg) 

	{zawodnik.pobieg=zawodnik.tempbieg;zawodnik.tempbieg+=1;if (zawodnik.tempbieg==0) 
	{zawodnik.tempbieg=1;zawodnik.pobieg=-1;}zawodnik.bieg=100;Apressed=true;
	zawodnik.zm_bieg=true;zawodnik.obr+=120;if (zawodnik.obr>0) zawodnik.obr=0;}
*/
	if (keys['A'] && zawodnik.pr>=0 && zawodnik.kolizja==false && Apressed==false && zawodnik.tempbieg==-1) 
	

	{zawodnik.pobieg=zawodnik.tempbieg;zawodnik.tempbieg+=1;if (zawodnik.tempbieg==0) 
	{zawodnik.tempbieg=1;zawodnik.pobieg=-1;}zawodnik.bieg=100;Apressed=true;
	zawodnik.zm_bieg=true;zawodnik.obr+=120;if (zawodnik.obr>0) zawodnik.obr=0;}

	if (keys['Z'] && zawodnik.pr>=0 && zawodnik.kolizja==false && Zpressed==false && zawodnik.tempbieg==zawodnik.bieg && zawodnik.bieg==1) 
	{
		zawodnik.pobieg=zawodnik.tempbieg;
		
		zawodnik.tempbieg-=1;
		
		if (zawodnik.tempbieg==0) {zawodnik.tempbieg=-1;zawodnik.pobieg=0;}zawodnik.bieg=100;Zpressed=true;zawodnik.zm_bieg=true;
	
		if (zawodnik.tempbieg!=0){zawodnik.obr-=120;if (zawodnik.obr<-275) zawodnik.obr=-275;}
	
	}
	

	if (zawodnik.bieg>5 && zawodnik.bieg!=100) zawodnik.bieg=5;
	if (zawodnik.bieg<-1) zawodnik.bieg=-1;
	if (zawodnik.bieg==100 && zawodnik.pr<=0) zawodnik.bieg=zawodnik.tempbieg;
	if (zawodnik.bieg==-1 && zawodnik.pobieg<0 && zawodnik.bieg==100) zawodnik.pobieg=0;
	if (zawodnik.bieg==-1 && zawodnik.pobieg<0) zawodnik.pobieg=0;
	if (zawodnik.bieg==1 && zawodnik.pobieg==-1) zawodnik.pobieg=0;
	if (zawodnik.bieg==100)
	{
		if (zawodnik.tempbieg>0 && zawodnik.pobieg>-1)
		{
			zawodnik.bieg=zawodnik.tempbieg;
		}
		if (zawodnik.tempbieg==0 && zawodnik.pobieg==1)
		{
			zawodnik.bieg=zawodnik.tempbieg;
		}
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.pr>0)
		{
			zawodnik.pr-=zawodnik.hamulec*2;
			if (zawodnik.pr<=0) zawodnik.bieg=zawodnik.tempbieg;
		}
		if (zawodnik.tempbieg>=1 && zawodnik.pobieg==-1 && zawodnik.pr>0)
		{
			zawodnik.pr-=zawodnik.hamulec*2;
			if (zawodnik.pr<=0) {zawodnik.tempbieg=1;zawodnik.pobieg=0; zawodnik.bieg=zawodnik.tempbieg;}
		}
	}
	

	
	//if (zawodnik.bieg=0 && zawodnik.tempbieg==-1) {zawodnik.pr=0;}

	//zawodnik.bieg=zawodnik.tempbieg;
	if (zawodnik.tempbieg<-1) zawodnik.tempbieg=-1;
	if (zawodnik.tempbieg>=5) zawodnik.tempbieg=5;

	zawodnik.nr_biegu=zawodnik.tempbieg+2;


	if (zawodnik.bieg==1) {zawodnik.max_predkosc=zawodnik.bieg1max;}
	if (zawodnik.bieg==2) {zawodnik.max_predkosc=zawodnik.bieg2max;}
	if (zawodnik.bieg==3) {zawodnik.max_predkosc=zawodnik.bieg3max;}
	if (zawodnik.bieg==4) {zawodnik.max_predkosc=zawodnik.bieg4max;}
	if (zawodnik.bieg==5) {zawodnik.max_predkosc=zawodnik.bieg5max;}
	if (zawodnik.bieg==-1) {zawodnik.max_predkosc=zawodnik.biegRmax;}
	if (zawodnik.bieg==0) {zawodnik.max_predkosc=0;}


	if (zawodnik.wektorPR>0) ftemps[9]=zawodnik.pr+zawodnik.wektorPR;
	if (zawodnik.wektorPR<0) ftemps[9]=zawodnik.pr-zawodnik.wektorPR;
	if (zawodnik.wektorPR==0) ftemps[9]=zawodnik.pr;
	if (ftemps[9]>=zawodnik.acceleration)
	{
		ftemp=(zawodnik.pr+zawodnik.wektorPR)*14.f;
		if (zawodnik.tempbieg<0) zawodnik.obrt_prz=-zawodnik.obrt_prz;
		zawodnik.obrt_prz+=ftemp; 
		if (zawodnik.tempbieg<0) zawodnik.obrt_prz=-zawodnik.obrt_prz;
	
		if (keys[VK_SPACE]==false)
		{
			if (zawodnik.tempbieg<0) zawodnik.obrt_tyl=-zawodnik.obrt_tyl;
			zawodnik.obrt_tyl+=ftemp; 
			if (zawodnik.tempbieg<0) zawodnik.obrt_tyl=-zawodnik.obrt_tyl;
		
		}
		if (zawodnik.sladON) zawodnik.obrTYL+=ftemp;
		zawodnik.sladON=false;
	}

	
	if (zawodnik.tempbieg==0 && zawodnik.pr>0)
	{
		zawodnik.pr-=0.01f;
		Forward(zawodnik,zawodnik.pr,0);
		if (zawodnik.podnies<0) zawodnik.podnies+=0.1f;
	}
	if (zawodnik.pr>zawodnik.max_predkosc) {zawodnik.pr-=0.01f;}

	//if (zawodnik.pr>max_predkosc-0.05f) {zawodnik.pr+=(Random(0,10)-5)/100.0f;}

	zawodnik.rot_obr=zawodnik.obr;
	if (zawodnik.rot_obr>0) zawodnik.rot_obr=0;
	if (zawodnik.rot_obr<-275) zawodnik.rot_obr=-275;
	if (keys[VK_UP] && gracz.okr<maxokr)
	{
		//if (zawodnik.tempbieg>=0 && zawodnik.bieg!=100) Forward(zawodnik.pr,0); 
		//if (zawodnik.tempbieg<0 && zawodnik.bieg!=100) Forward(-zawodnik.pr,0);
		//if (zawodnik.tempbieg>0 && zawodnik.bieg==100) Forward(-zawodnik.pr,0); 
		//if (zawodnik.tempbieg<0 && zawodnik.bieg==100) Forward(zawodnik.pr,0);
		if (zawodnik.tempbieg>0 && zawodnik.pobieg>=0) Forward(zawodnik,zawodnik.pr,0);
		//if (zawodnik.tempbieg>0 && zawodnik.pobieg==-1) Forward(zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==-1) Forward(zawodnik,-zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==100) Forward(zawodnik,zawodnik.pr,0);
		if (zawodnik.tempbieg==1 && zawodnik.pobieg==-1 && zawodnik.bieg==100) Forward(zawodnik,-zawodnik.pr,0);
		//if (zawodnik.tempbieg==0 && zawodnik.pobieg==-1) Forward(-zawodnik.pr,0);

		if (zawodnik.pr<zawodnik.max_predkosc && zawodnik.pr<=zawodnik.max_predkosc) zawodnik.pr+=zawodnik.acceleration;
		if (zawodnik.podnies>-1.5f && zawodnik.tempbieg!=0 && zawodnik.pr>0.05f) zawodnik.podnies-=0.05f;
		if (zawodnik.zm_bieg==false)
		{
			if (zawodnik.obr>-275) {if (zawodnik.tempbieg!=0)zawodnik.obr-=3; else zawodnik.obr+=3;}
		} else if (zawodnik.obr<=0) {zawodnik.obr+=9;}
		if (zawodnik.obr>=-90) zawodnik.zm_bieg=false;
	} 
	else 
	{
		if (zawodnik.pr>0) zawodnik.pr-=0.01f;
		if (zawodnik.pr<0) zawodnik.pr=0;
		//if (zawodnik.tempbieg>=0 && zawodnik.bieg!=100) Forward(zawodnik.pr,0); 
		//if (zawodnik.tempbieg<0 && zawodnik.bieg!=100) Forward(-zawodnik.pr,0);
		//if (zawodnik.tempbieg>=0 && zawodnik.bieg==100) Forward(-zawodnik.pr,0); 
		//if (zawodnik.tempbieg<0 && zawodnik.bieg==100) Forward(zawodnik.pr,0);
		if (zawodnik.tempbieg>0 && zawodnik.pobieg>=0) Forward(zawodnik,zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==-1) Forward(zawodnik,-zawodnik.pr,0);
		//if (zawodnik.tempbieg>0 && zawodnik.pobieg=-1) Forward(zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==100) Forward(zawodnik,zawodnik.pr,0);
		//if (zawodnik.tempbieg==0 && zawodnik.pobieg==-1 && zawodnik.bieg!=-1) Forward(-zawodnik.pr,0);
		if (zawodnik.tempbieg==1 && zawodnik.pobieg==-1 && zawodnik.bieg==100) Forward(zawodnik,-zawodnik.pr,0);
		
		if (zawodnik.podnies<0) zawodnik.podnies+=0.05f;
		if (zawodnik.obr<0) zawodnik.obr+=zawodnik.max_predkosc/zawodnik.pr;
	}
	
	if (zawodnik.tempbieg==0 && zawodnik.pr==0) {zawodnik.rot_obr+=3;zawodnik.obr+=3;}
	//if (zawodnik.tempbieg==0) zawodnik.zm_bieg=true;

	if (keys[VK_DOWN] && gracz.okr<maxokr) 
	{
		if (zawodnik.pr>zawodnik.accelerationCONST) {AddBackSmoke(zawodnik);}
		if (zawodnik.pr>0) zawodnik.pr-=zawodnik.hamulec;
		if (zawodnik.podnies<1.5f && zawodnik.tempbieg!=0 && zawodnik.pr>0) zawodnik.podnies+=0.05f;
	} 
	else
	{
		if (zawodnik.podnies>0) zawodnik.podnies-=0.05f;

	}

	
	if (zawodnik.tempbieg>=0 && zawodnik.pobieg>=0)
	{
		lewy=keys[VK_LEFT];
		prawy=keys[VK_RIGHT];

	} 
	if (zawodnik.tempbieg<0 && zawodnik.pobieg==0)
	{
		prawy=keys[VK_LEFT];
		lewy=keys[VK_RIGHT];
	}
	
	if (zawodnik.tempbieg>-1 && zawodnik.pobieg<0)
	{
		prawy=keys[VK_LEFT];
		lewy=keys[VK_RIGHT];
	}

	if (lewy && prawy) {lewy=false;prawy=false;}

	
	
	ftemps[9]=zawodnik.pr/zawodnik.max_predkoscCONST;
	ftemps[8]=1.3f-ftemps[9];
	if (zawodnik.pr<1.0f) ftemps[8]=zawodnik.pr/1.0f;
	ftemp3=zawodnik.skret*0.050f*ftemps[8];     //SKRECANIE
	ftemp4=zawodnik.skret*0.051f*ftemps[8];     //SKRÊCANIE
	//if (keys[VK_SPACE]==false && zawodnik.rozn!=0) zawodnik.rozn=0;
	
	if (lewy)
	{
		if (zawodnik.pr>zawodnik.acceleration)
		{
		zawodnik.katk=zawodnik.katk+ftemp4;
		if (zawodnik.rozn>90) {zawodnik.katk-=(zawodnik.rozn-90);zawodnik.rozn=90;}
		if (zawodnik.rozn<-90) {zawodnik.katk-=(zawodnik.rozn+90);zawodnik.rozn=-90;}
		if (zawodnik.rozn>-1)
		{
			zawodnik.kat=zawodnik.kat+ftemp3;
			if (zawodnik.pr>0) zawodnik.pr-=zawodnik.accelerationCONST*0.5;
		}
		if (zawodnik.tempbieg>0) {if (zawodnik.odchyl<4) zawodnik.odchyl+=0.4f;} else if (zawodnik.odchyl>-5) zawodnik.odchyl-=0.2f;
		}
		if (zawodnik.skret<40.5f) zawodnik.skret+=2.5f;
		
	} 
	else {if (zawodnik.skret>0) zawodnik.skret-=samochody[zawodnik.numer_samuchodu].odkrecanie_kierownicy;  if (zawodnik.tempbieg>0) {if (zawodnik.odchyl<0) zawodnik.odchyl+=0.1f;}else if (zawodnik.odchyl>0) zawodnik.odchyl-=0.4f;}

	
	if (prawy)
	{
		if (zawodnik.pr>zawodnik.acceleration)
		{
		zawodnik.katk=zawodnik.katk+ftemp4;
		if (zawodnik.rozn>90) {zawodnik.katk-=(zawodnik.rozn-90);zawodnik.rozn=90;}
		if (zawodnik.rozn<-90) {zawodnik.katk-=(zawodnik.rozn+90);zawodnik.rozn=-90;}
		if (zawodnik.rozn<1)
		{
			zawodnik.kat=zawodnik.kat+ftemp3;
			if (zawodnik.pr>0) zawodnik.pr-=zawodnik.accelerationCONST*0.5;
		}
		if (zawodnik.tempbieg>0) {if (zawodnik.odchyl>-4) zawodnik.odchyl-=0.4f;} else if (zawodnik.odchyl<5) zawodnik.odchyl+=0.2f;	
		}	
		if (zawodnik.skret>-40.5f) zawodnik.skret-=2.5f;
		
	} 
	else {if (zawodnik.skret<0) zawodnik.skret+=samochody[zawodnik.numer_samuchodu].odkrecanie_kierownicy; if (zawodnik.tempbieg>0) {if (zawodnik.odchyl>0) zawodnik.odchyl-=0.1f;}else if (zawodnik.odchyl<0) zawodnik.odchyl+=0.4f;}

	if (zawodnik.skret>=-1 && zawodnik.skret<=1 && !prawy && !lewy) zawodnik.skret=0;
	
	if (!keys[VK_LEFT] && !keys[VK_RIGHT])
	{
		zawodnik.katk=zawodnik.katk+ftemp4;

		if (zawodnik.rozn>=3.0f) zawodnik.kat+=3.0f;
		if (zawodnik.rozn<=-3.0f) zawodnik.kat-=3.0f;
		if (zawodnik.rozn>-3.0f && zawodnik.rozn<3.0f) zawodnik.kat=zawodnik.katk;
	}
	
	if (zawodnik.pr<=zawodnik.accelerationCONST) zawodnik.kat=zawodnik.katk;
	if (zawodnik.rozn<-5 || zawodnik.rozn>5) if (zawodnik.tempbieg>0) AddBackSmoke(zawodnik); else AddFrontSmoke(zawodnik);


	if (zawodnik.id2==true && zawodnik.id1==true)
	{
		zawodnik.id1=false;
		
		FSOUND_SetPaused(zawodnik.channel1, FALSE);
	}
	if (keys[VK_SPACE])
	{	
		
		zawodnik.katk+=ftemp4*0.75f*ftemps[9];
		if (zawodnik.rozn>90) {zawodnik.katk-=(zawodnik.rozn-90);zawodnik.rozn=90;}
		if (zawodnik.rozn<-90) {zawodnik.katk-=(zawodnik.rozn+90);zawodnik.rozn=-90;}

		if (zawodnik.tempbieg>0) AddBackSmoke(zawodnik); else AddFrontSmoke(zawodnik);
		if (zawodnik.pr>0) zawodnik.pr-=zawodnik.accelerationCONST*1.2f;
		if (zawodnik.rozn==0) zawodnik.pr-=zawodnik.accelerationCONST*0.75f;
		if (zawodnik.pr<=0.1f) zawodnik.kat=zawodnik.katk;
	} else 
	{
		zawodnik.reczny=false;
	}
	if (zawodnik.sladyRYS)
	{
		zawodnik.id2=true;
		zawodnik.reczny=true;
	} else
	{
		zawodnik.id1=true;
		//FSOUND_StopSound(zawodnik.channel1);
		//FSOUND_SetVolume(zawodnik.channel1, 0);
		FSOUND_SetPaused(zawodnik.channel1, TRUE);
		zawodnik.id2=false;
	}

	if (zawodnik.rozn>10 || zawodnik.rozn<-10)
	{
		zawodnik.katk+=ftemp4*0.5f;
		if (zawodnik.tempbieg>0) AddBackSmoke(zawodnik); else AddFrontSmoke(zawodnik);
		if (zawodnik.pr>0) zawodnik.pr-=zawodnik.accelerationCONST*1.0f;
		if (zawodnik.pr<=0.1f) zawodnik.kat=zawodnik.katk;
	}

	zawodnik.rozn=(zawodnik.katk-zawodnik.kat);
	

	zawodnik.katcamP=-zawodnik.rozn;
	if (zawodnik.katcam<zawodnik.katcamP) zawodnik.katcam+=0.25f;
	if (zawodnik.katcam>zawodnik.katcamP) zawodnik.katcam-=0.25f;

	licznik_klatek++;
	if (licznik_klatek==max_klatek) licznik_klatek=0;


	if (zawodnik.tempbieg>0) zawodnik.podniesP=zawodnik.podnies; else zawodnik.podniesP=-zawodnik.podnies;
	if (zawodnik.podniesR<zawodnik.podniesP) zawodnik.podniesR+=0.2f;
	if (zawodnik.podniesR>zawodnik.podniesP) zawodnik.podniesR-=0.2f;

	if (zawodnik.tempbieg>0) zawodnik.skretP=zawodnik.skret; else zawodnik.skretP=-zawodnik.skret;
	if (zawodnik.skretR<zawodnik.skretP) zawodnik.skretR+=1.5f;
	if (zawodnik.skretR>zawodnik.skretP) zawodnik.skretR-=1.5f;
	
	if (zawodnik.obr<-275) zawodnik.obr=-275;
	if (zawodnik.obr>0) zawodnik.obr=0;
	if (zawodnik.rot_obr>0) zawodnik.rot_obr=0;
	if (zawodnik.rot_obr<-275) zawodnik.rot_obr=-275;
	if (zawodnik.bieg==0) zawodnik.obr=zawodnik.rot_obr=0;
	}	

	
}