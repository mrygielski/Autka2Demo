
void Inteligencja(Tgracz &zawodnik)
{
	randomize();	

	
	if (zawodnik.pr<0.2f && zawodnik.okr!=maxokr)
	{
		zawodnik.badaj+=1;
		if (zawodnik.badaj==150) zawodnik.demage=100;
	} else zawodnik.badaj=0;

	if (zawodnik.demage==100) zawodnik.badaj=0;
	if (zawodnik.okr==maxokr) zawodnik.demage=0;

	podloga=inteligencja[(int)(zawodnik.x/64)][ (int)((zawodnik.z+128)/64)];
	if (zawodnik.prevX!=(int)(zawodnik.x/64)) 
	{
		zawodnik.prevP=inteligencja[zawodnik.prevX][ (int)((zawodnik.z+128)/64)];
		zawodnik.prevX=(int)(zawodnik.x/64);
		
	}
	if (zawodnik.prevZ!=(int)((zawodnik.z+128)/64)) 
	{
		zawodnik.prevP=inteligencja[(int)(zawodnik.x/64)][zawodnik.prevZ];
		zawodnik.prevZ=(int)((zawodnik.z+128)/64);
		
	}
	kat=(-( (int)(zawodnik.katk) % 360 ));
//	kat=kat+360;
	if (kat<0) kat=360+kat;


	zawodnik.prawo=0;
	zawodnik.lewo=0;
	zawodnik.META=false;  ///kurde
	zawodnik.przod=0;
	if (zawodnik.okr!=maxokr) zawodnik.przod=1;
	if (podloga==15 && zawodnik.pr>1.4f) zawodnik.przod=0;

	if (podloga==1) 
	{
		//
		kat0=0;
		if (kat>0 && kat<180) {zawodnik.lewo=1;}
		if (kat<360 && kat>=180) {zawodnik.prawo=1;}
	}

	if (podloga==2) 
	{
		//
		kat0=90;
		if (kat>90 && kat<270) zawodnik.lewo=1;
		if (kat<90) zawodnik.prawo=1;		
		if (kat>=270 && kat<360) zawodnik.prawo=1;
	}

	if (podloga==3) 
	{
		//
		kat0=180;
		if (kat>180) zawodnik.lewo=1;
		if (kat<180) zawodnik.prawo=1;		
	}
	
	if (podloga==4) 
	{
		//
		kat0=270;
		if (kat>=270) zawodnik.lewo=1;
		if (kat<270 && kat>90) zawodnik.prawo=1;		
		if (kat>-90 && kat<=90) zawodnik.lewo=1;		
	}

	if (podloga==12) 
	{
		
		if (kat>135) zawodnik.lewo=1;
		if (kat<135) zawodnik.prawo=1;		
	}

	if (podloga==11) 
	{
		
		if (kat>45) zawodnik.lewo=1;
		if (kat<45) zawodnik.prawo=1;		
	}

	if (podloga==10) 
	{
		
		if (kat>=315 && kat<=360) zawodnik.lewo=1;
		if (kat<315 && kat>0) zawodnik.prawo=1;
	}

	if (podloga==9) 
	{
		
		if (kat>225) zawodnik.lewo=1;
		if (kat<225 && kat>90) zawodnik.prawo=1;		
		if (kat>-135 && kat<=90) zawodnik.lewo=1;		
	}

	if (podloga==8) 
	{
		
		if (kat>315) zawodnik.lewo=1;
		if (kat<315 && kat>90) zawodnik.prawo=1;		
		if (kat>-45 && kat<=90) zawodnik.lewo=1;		
	}

	if (podloga==5) 
	{
		
		if (kat>=45 && kat<=180 && kat>0) zawodnik.lewo=1;
		if (kat<315 && kat>180) zawodnik.prawo=1;
		if (kat>315 && kat>=180) zawodnik.prawo=1;
		if (kat<45 && kat<=180 && kat>=0) zawodnik.prawo=1;
	}

	if (podloga==6) 
	{
		
		if (kat>135) zawodnik.lewo=1;
		if (kat<135) zawodnik.prawo=1;		
	}

	if (podloga==7) 
	{
		
		if (kat>225) zawodnik.lewo=1;
		if (kat<225) zawodnik.prawo=1;		
	}
	
	if (podloga==13 && zawodnik.biegPLUS==false) 
	{
		if (zawodnik.tempbieg<5)
		{
			zawodnik.biegPLUS=true;
			zawodnik.tempbieg++;
			zawodnik.bieg=zawodnik.tempbieg;
		}
	}
	if (podloga!=13) zawodnik.biegPLUS=false;

	if (podloga==14 && zawodnik.biegMINUS==false) 
	{
		if (zawodnik.tempbieg>1)
		{
			zawodnik.biegMINUS=true;
			zawodnik.tempbieg--;
			zawodnik.bieg=zawodnik.tempbieg;
		}
	}
	if (podloga!=14) zawodnik.biegMINUS=false;

	
	if (podloga==15 && zawodnik.pr>2.2f) zawodnik.tyl=true; else zawodnik.tyl=false;
	zawodnik.spacja=0;
	

	// losowe wybory

    if (podloga==16 && zawodnik.kompRANDOM[0]==false)
	{
		
		zawodnik.randomInt=Random(1,3);
		zawodnik.kompRANDOM[0]=true;
	}

	if (zawodnik.kompRANDOM[0]==true) //gora
	{
		if (zawodnik.randomInt==1) //prawo 45
		{
		
			if (kat>=45 && kat<=180 && kat>0) zawodnik.lewo=1;
			if (kat<315 && kat>180) zawodnik.prawo=1;
			if (kat>315 && kat>=180) zawodnik.prawo=1;
			if (kat<45 && kat<=180 && kat>=0) zawodnik.prawo=1;
		}
		if (zawodnik.randomInt==2) //lewo 45
		{
		
			if (kat>=315 && kat<=360) zawodnik.lewo=1;
			if (kat<315 && kat>0) zawodnik.prawo=1;
		}
		if (zawodnik.randomInt==3)
		{
		
			if (kat>0 && kat<180) zawodnik.lewo=1;
			if (kat<360 && kat>=180) zawodnik.prawo=1;
		}
	}

	if (podloga!=16) zawodnik.kompRANDOM[0]=false;

    if (podloga==17 && zawodnik.kompRANDOM[1]==false)
	{
		
		zawodnik.randomInt=Random(1,3);
		zawodnik.kompRANDOM[1]=true;
	}

	if (zawodnik.kompRANDOM[1]==true) //prawo
	{
		if (zawodnik.randomInt==1) //prawo 45
		{
		
			if (kat>135) zawodnik.lewo=1;
			if (kat<135) zawodnik.prawo=1;
		}
		if (zawodnik.randomInt==2) //lewo 45
		{
		
			if (kat>45) zawodnik.lewo=1;
			if (kat<45) zawodnik.prawo=1;	
		}
		if (zawodnik.randomInt==3)
		{
		
			if (kat>90) zawodnik.lewo=1;
			if (kat<90) zawodnik.prawo=1;	
		}
	}

	if (podloga!=17) zawodnik.kompRANDOM[1]=false;

	if (podloga==18 && zawodnik.kompRANDOM[2]==false)
	{
		
		zawodnik.randomInt=Random(1,3);
		zawodnik.kompRANDOM[2]=true;
	}

	if (zawodnik.kompRANDOM[2]==true) //prawo
	{
		if (zawodnik.randomInt==1) //prawo 45
		{
		
			if (kat>135) zawodnik.lewo=1;
			if (kat<135) zawodnik.prawo=1;	
		}
		if (zawodnik.randomInt==2) //lewo 45
		{
		
			if (kat>225) zawodnik.lewo=1;
			if (kat<225) zawodnik.prawo=1;
		}
		if (zawodnik.randomInt==3)
		{
		
			if (kat>180) zawodnik.lewo=1;
			if (kat<180) zawodnik.prawo=1;
		}
	}

	if (podloga!=18) zawodnik.kompRANDOM[2]=false;

	if (podloga==19 && zawodnik.kompRANDOM[3]==false)
	{
		
		zawodnik.randomInt=Random(1,3);
		zawodnik.kompRANDOM[3]=true;
	}

	if (zawodnik.kompRANDOM[3]==true) //prawo
	{
		if (zawodnik.randomInt==1) //prawo 45
		{
		
			if (kat>315) zawodnik.lewo=1;
			if (kat<315 && kat>90) zawodnik.prawo=1;		
			if (kat>-45 && kat<=90) zawodnik.lewo=1;
		}
		if (zawodnik.randomInt==2) //lewo 45
		{
		
			if (kat>225) zawodnik.lewo=1;
			if (kat<225 && kat>90) zawodnik.prawo=1;		
			if (kat>-135 && kat<=90) zawodnik.lewo=1;
		}
		if (zawodnik.randomInt==3)
		{
		
			if (kat>270) zawodnik.lewo=1;
			if (kat<270 && kat>90) zawodnik.prawo=1;		
			if (kat>-90 && kat<=90) zawodnik.lewo=1;	
		}	
	}

	if (podloga!=19) zawodnik.kompRANDOM[3]=false;

	if (podloga==20 && zawodnik.kompRANDOM[4]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[4]=true;
	}

	if (zawodnik.kompRANDOM[4]==true) //gora
	{
		if (zawodnik.randomInt==1)
		{
		
			if (kat>0 && kat<180) zawodnik.lewo=1;
			if (kat<360 && kat>=180) zawodnik.prawo=1;
		}
		if (zawodnik.randomInt==2) //prawo 45
		{
		
			if (kat>=45 && kat<=180 && kat>0) zawodnik.lewo=1;
			if (kat<315 && kat>180) zawodnik.prawo=1;
			if (kat>315 && kat>=180) zawodnik.prawo=1;
			if (kat<45 && kat<=180 && kat>=0) zawodnik.prawo=1;
		}
	}

	if (podloga!=20) zawodnik.kompRANDOM[4]=false;

	if (podloga==21 && zawodnik.kompRANDOM[5]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[5]=true;
	}

	if (zawodnik.kompRANDOM[5]==true) //gora
	{
		if (zawodnik.randomInt==1) 
		{
		
			if (kat>0 && kat<180) zawodnik.lewo=1;
			if (kat<360 && kat>=180) zawodnik.prawo=1;
		}

		if (zawodnik.randomInt==2) //lewo 45
		{
		
			if (kat>=315 && kat<=360) zawodnik.lewo=1;
			if (kat<315 && kat>0) zawodnik.prawo=1;
		}
	}

	if (podloga!=21) zawodnik.kompRANDOM[5]=false;

	if (podloga==22 && zawodnik.kompRANDOM[6]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[6]=true;
	}

	if (zawodnik.kompRANDOM[6]==true) //prawo
	{
		if (zawodnik.randomInt==1) //
		{
		
			if (kat>90) zawodnik.lewo=1;
			if (kat<90) zawodnik.prawo=1;				
		}
		if (zawodnik.randomInt==2) //prawo 45
		{
		
			if (kat>135) zawodnik.lewo=1;
			if (kat<135) zawodnik.prawo=1;
		}
	}

	if (podloga!=22) zawodnik.kompRANDOM[6]=false;

	if (podloga==23 && zawodnik.kompRANDOM[7]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[7]=true;
	}

	if (zawodnik.kompRANDOM[7]==true) //prawo
	{
		if (zawodnik.randomInt==1) //lewo 45
		{
		
			if (kat>45) zawodnik.lewo=1;
			if (kat<45) zawodnik.prawo=1;	
		}
		if (zawodnik.randomInt==2)
		{
		
			if (kat>90) zawodnik.lewo=1;
			if (kat<90) zawodnik.prawo=1;
		}
	}

	if (podloga!=23) zawodnik.kompRANDOM[7]=false;

	if (podloga==24 && zawodnik.kompRANDOM[8]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[8]=true;
	}

	if (zawodnik.kompRANDOM[8]==true) //prawo
	{
		if (zawodnik.randomInt==1) 
		{
		
			if (kat>180) zawodnik.lewo=1;
			if (kat<180) zawodnik.prawo=1;							
		}
		if (zawodnik.randomInt==2) //prawo 45
		{
		
			if (kat>135) zawodnik.lewo=1;
			if (kat<135) zawodnik.prawo=1;	
		}
	}

	if (podloga!=24) zawodnik.kompRANDOM[8]=false;

	if (podloga==25 && zawodnik.kompRANDOM[9]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[9]=true;
	}

	if (zawodnik.kompRANDOM[9]==true) //prawo
	{
		if (zawodnik.randomInt==1) 
		{
		
			if (kat>180) zawodnik.lewo=1;
			if (kat<180) zawodnik.prawo=1;			
		}

		if (zawodnik.randomInt==2) //lewo 45
		{
		
			if (kat>225) zawodnik.lewo=1;
			if (kat<225) zawodnik.prawo=1;
		}
	}

	if (podloga!=25) zawodnik.kompRANDOM[9]=false;

	if (podloga==26 && zawodnik.kompRANDOM[10]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[10]=true;
	}

	if (zawodnik.kompRANDOM[10]==true) //prawo
	{
		if (zawodnik.randomInt==1) 
		{
		
		if (kat>270) zawodnik.lewo=1;
		if (kat<270 && kat>90) zawodnik.prawo=1;		
		if (kat>-90 && kat<=90) zawodnik.lewo=1;							
		}
		if (zawodnik.randomInt==2) //prawo 45
		{
		
			if (kat>315) zawodnik.lewo=1;
			if (kat<315 && kat>90) zawodnik.prawo=1;		
			if (kat>-45 && kat<=90) zawodnik.lewo=1;
		}
	}

	if (podloga!=26) zawodnik.kompRANDOM[10]=false;


		if (podloga==27 && zawodnik.kompRANDOM[27]==false)
	{
		
		zawodnik.randomInt=Random(1,2);
		zawodnik.kompRANDOM[27]=true;
	}

	if (zawodnik.kompRANDOM[27]==true) //prawo
	{

		if (zawodnik.randomInt==1) 
		{
		
			if (kat>270) zawodnik.lewo=1;
			if (kat<270 && kat>90) zawodnik.prawo=1;		
			if (kat>-90 && kat<=90) zawodnik.lewo=1;		
		}
		if (zawodnik.randomInt==2) //lewo 45
		{
		
			if (kat>225) zawodnik.lewo=1;
			if (kat<225 && kat>90) zawodnik.prawo=1;		
			if (kat>-135 && kat<=90) zawodnik.lewo=1;
		}
	
	}

	if (podloga!=27) zawodnik.kompRANDOM[11]=false;

	
//	if ((zawodnik.lewo || zawodnik.prawo) && zawodnik.pr>samochody[zawodnik.numer_samuchodu].max_predkosc*0.95f) zawodnik.spacja=1;
	if ((zawodnik.lewo || zawodnik.prawo) && zawodnik.pr>samochody[zawodnik.numer_samuchodu].max_predkosc*0.7f && abs(kat0-kat)>45) {zawodnik.przod=0;zawodnik.tyl=1;}
	//if ((zawodnik.lewo || zawodnik.prawo) && zawodnik.pr>samochody[zawodnik.numer_samuchodu].max_predkosc*0.5f && abs(kat0-kat)>60) zawodnik.przod=0;
	if ((zawodnik.lewo || zawodnik.prawo) && zawodnik.pr>samochody[zawodnik.numer_samuchodu].max_predkosc*0.5f && abs(kat0-kat)>80) {zawodnik.przod=0;zawodnik.tyl=1;}
	//if ((zawodnik.lewo || zawodnik.prawo) && zawodnik.pr>samochody[zawodnik.numer_samuchodu].max_predkosc*0.9f && abs(kat0-kat)>15) zawodnik.spacja=1;


}


void Fizyka_gryKOMP(Tgracz &zawodnik,bool k1,bool k2,bool k3)
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


	if (zawodnik.METAok==false) {AA=false;}
	if (zawodnik.METAok && AA==false) {if (zawodnik.HOTROD){zawodnik.okr++;
	if (zawodnik.okr==maxokr) nrcars++; zawodnik.podium=nrcars;} AA=true; zawodnik.HOTROD=false;}
	if (zawodnik.HOTRODok==false) {BB=false;}
	if (zawodnik.HOTRODok && BB==false) {zawodnik.HOTROD=true;BB=true;}



	zawodnik.ztrans=zawodnik.z;
	zawodnik.xtrans=zawodnik.x;
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

	if (zawodnik.METAok) zawodnik.META=true;
	if (zawodnik.kolizja) zawodnik.ytrans=zawodnik.pr/8;
	if (zawodnik.ytrans>0.1f) zawodnik.ytrans-=0.1f; //podskakiwanie
	if (zawodnik.ib2==true && zawodnik.ib1==true)
	{
		zawodnik.ib1=false;
		
		zawodnik.channel3 = FSOUND_PlaySound(FSOUND_FREE, zawodnik.BOOM);
	}
	if (zawodnik.kolizja) {zawodnik.ib2=true; zawodnik.ytrans=zawodnik.pr/8; zawodnik.demage=zawodnik.demage+(int)zawodnik.pr*5;}
	else {zawodnik.ib1=true; zawodnik.ib2=false; }
	if (zawodnik.kolizja1 || zawodnik.kolizja2 || zawodnik.kolizja3 || zawodnik.kolizjaGR) {zawodnik.ib2=true; zawodnik.ytrans=zawodnik.pr/8; zawodnik.demage=zawodnik.demage+(int)zawodnik.pr;}
//	else {zawodnik.ib1=true; zawodnik.ib2=false; }	
	
	ftemps[4]=zawodnik.pr;
	
	if (zawodnik.kolizja1 && !k1)
	{
		if (zawodnik._bCollided[1] && zawodnik._bCollided4_[1]==false && zawodnik._bCollided3_[1]==false) {zawodnik.wektorPR=-0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided2[1] && zawodnik._bCollided4[1]==false && zawodnik._bCollided3[1]==false) {zawodnik.wektorPR=0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided[1] && zawodnik._bCollided4_[1]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided[1] && zawodnik._bCollided3_[1]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided[1]==false && zawodnik._bCollided4_[1]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided[1]==false && zawodnik._bCollided3_[1]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
		if (zawodnik._bCollided2[1] && zawodnik._bCollided4[1]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[1] && zawodnik._bCollided3[1]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[1]==false && zawodnik._bCollided4[1]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided2[1]==false && zawodnik._bCollided3[1]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
/*		if (zawodnik.pr>0)
		{
		if (zawodnik.wektorPR==0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorPR==-0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==-0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		}
*/		//zawodnik.pr=0;
	}

	if (zawodnik.kolizja2 && !k2)
	{
		if (zawodnik._bCollided[2] && zawodnik._bCollided4_[2]==false && zawodnik._bCollided3_[2]==false) {zawodnik.wektorPR=-0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided2[2] && zawodnik._bCollided4[2]==false && zawodnik._bCollided3[2]==false) {zawodnik.wektorPR=0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided[2] && zawodnik._bCollided4_[2]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided[2] && zawodnik._bCollided3_[2]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided[2]==false && zawodnik._bCollided4_[2]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided[2]==false && zawodnik._bCollided3_[2]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
		if (zawodnik._bCollided2[2] && zawodnik._bCollided4[2]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[2] && zawodnik._bCollided3[2]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[2]==false && zawodnik._bCollided4[2]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided2[2]==false && zawodnik._bCollided3[2]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
/*		if (zawodnik.pr>0)
		{
		if (zawodnik.wektorPR==0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorPR==-0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==-0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		}
*/		//zawodnik.pr=0;
	}

	if (zawodnik.kolizja3 && !k3)
	{
		if (zawodnik._bCollided[3] && zawodnik._bCollided4_[3]==false && zawodnik._bCollided3_[3]==false) {zawodnik.wektorPR=-0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided2[3] && zawodnik._bCollided4[3]==false && zawodnik._bCollided3[3]==false) {zawodnik.wektorPR=0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided[3] && zawodnik._bCollided4_[3]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided[3] && zawodnik._bCollided3_[3]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided[3]==false && zawodnik._bCollided4_[3]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided[3]==false && zawodnik._bCollided3_[3]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
		if (zawodnik._bCollided2[3] && zawodnik._bCollided4[3]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[3] && zawodnik._bCollided3[3]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[3]==false && zawodnik._bCollided4[3]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided2[3]==false && zawodnik._bCollided3[3]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
/*		if (zawodnik.pr>0)
		{
		if (zawodnik.wektorPR==0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorPR==-0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==-0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		}*/
		//zawodnik.pr=0;
	}
	if (zawodnik.kolizjaGR)
	{
		if (zawodnik._bCollided[0] && zawodnik._bCollided4_[0]==false && zawodnik._bCollided3_[0]==false) {zawodnik.wektorPR=-0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided2[0] && zawodnik._bCollided4[0]==false && zawodnik._bCollided3[0]==false) {zawodnik.wektorPR=0.5f;zawodnik.pr=0;}
		if (zawodnik._bCollided[0] && zawodnik._bCollided4_[0]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided[0] && zawodnik._bCollided3_[0]) {zawodnik.wektorPR=-0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided[0]==false && zawodnik._bCollided4_[0]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided[0]==false && zawodnik._bCollided3_[0]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
		if (zawodnik._bCollided2[0] && zawodnik._bCollided4[0]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[0] && zawodnik._bCollided3[0]) {zawodnik.wektorPR=0.5f;zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;zawodnik.pr=0;}
		if (zawodnik._bCollided2[0]==false && zawodnik._bCollided4[0]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=-90;}
		if (zawodnik._bCollided2[0]==false && zawodnik._bCollided3[0]) {zawodnik.wektorSTR=0.5f;zawodnik.wektorSTRkat=90;}
/*		if (zawodnik.pr>0)
		{
		if (zawodnik.wektorPR==0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorPR==-0.5f) zawodnik.wektorPR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		if (zawodnik.wektorSTR==-0.5f) zawodnik.wektorSTR=zawodnik.pr*0.75f;
		}
*/		//zawodnik.pr=0;
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
	
	
	zawodnik.acceleration=zawodnik.accelerationCONST;//*(1-(ftemps[7]/5));
	
	

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
	
		if (zawodnik.spacja==0)
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
	if (zawodnik.przod==1)
	{
		if (zawodnik.tempbieg>0 && zawodnik.pobieg>=0) Forward(zawodnik,zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==-1) Forward(zawodnik,-zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==100) Forward(zawodnik,zawodnik.pr,0);
		if (zawodnik.tempbieg==1 && zawodnik.pobieg==-1 && zawodnik.bieg==100) Forward(zawodnik,-zawodnik.pr,0);

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
		if (zawodnik.tempbieg>0 && zawodnik.pobieg>=0) Forward(zawodnik,zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==-1) Forward(zawodnik,-zawodnik.pr,0);
		if (zawodnik.tempbieg==-1 && zawodnik.pobieg==0 && zawodnik.bieg==100) Forward(zawodnik,zawodnik.pr,0);
		if (zawodnik.tempbieg==1 && zawodnik.pobieg==-1 && zawodnik.bieg==100) Forward(zawodnik,-zawodnik.pr,0);
		
		if (zawodnik.podnies<0) zawodnik.podnies+=0.05f;
		if (zawodnik.obr<0) zawodnik.obr+=zawodnik.max_predkosc/zawodnik.pr;
	}
	if (zawodnik.pr<0) zawodnik.pr=0;
	
	if (zawodnik.tempbieg==0 && zawodnik.pr==0) {zawodnik.rot_obr+=3;zawodnik.obr+=3;}

	if (zawodnik.tyl==1) 
	{
		if (zawodnik.pr>zawodnik.accelerationCONST) AddBackSmoke(zawodnik);
		if (zawodnik.pr>0 && zawodnik.przod==false) zawodnik.pr-=zawodnik.hamulec;
		if (zawodnik.podnies<1.5f && zawodnik.tempbieg!=0 && zawodnik.pr>0) zawodnik.podnies+=0.05f;
	} 
	else
	{
		if (zawodnik.podnies>0) zawodnik.podnies-=0.05f;
	}

	
	
	ftemps[9]=zawodnik.pr/zawodnik.max_predkoscCONST;
	ftemps[8]=1.3f-ftemps[9];
	if (zawodnik.pr<1.0f) ftemps[8]=zawodnik.pr/1.0f;
	ftemp3=zawodnik.skret*0.050f*ftemps[8];     //SKRECANIE
	ftemp4=zawodnik.skret*0.051f*ftemps[8];     //SKRÊCANIE
	
	if (zawodnik.lewo==1)
	{
		if (zawodnik.pr>zawodnik.acceleration)
		{
		zawodnik.katk=zawodnik.katk+ftemp4;
		if (zawodnik.rozn>90) {zawodnik.katk-=(zawodnik.rozn-90);zawodnik.rozn=90;}
		if (zawodnik.rozn<-90) {zawodnik.katk-=(zawodnik.rozn+90);zawodnik.rozn=-90;}
		if (zawodnik.rozn>-1)
		{
			zawodnik.kat=zawodnik.kat+ftemp3;
			if (zawodnik.pr>0.3f) zawodnik.pr-=zawodnik.accelerationCONST*0.5;
		}
		if (zawodnik.tempbieg>0) {if (zawodnik.odchyl<5) zawodnik.odchyl+=0.2f;} else if (zawodnik.odchyl>-5) zawodnik.odchyl-=0.2f;
		}
		
		if (zawodnik.skret<41) zawodnik.skret+=8.0f;
		
	} 
	else {if (zawodnik.skret>0) zawodnik.skret-=16;  if (zawodnik.tempbieg>0) {if (zawodnik.odchyl<0) zawodnik.odchyl+=0.1f;}else if (zawodnik.odchyl>0) zawodnik.odchyl-=0.1f;}

	
	if (zawodnik.prawo==1)
	{
		if (zawodnik.pr>zawodnik.acceleration)
		{
		zawodnik.katk=zawodnik.katk+ftemp4;
		if (zawodnik.rozn>90) {zawodnik.katk-=(zawodnik.rozn-90);zawodnik.rozn=90;}
		if (zawodnik.rozn<-90) {zawodnik.katk-=(zawodnik.rozn+90);zawodnik.rozn=-90;}
		if (zawodnik.rozn<1)
		{
			zawodnik.kat=zawodnik.kat+ftemp3;
			if (zawodnik.pr>0.3f) zawodnik.pr-=zawodnik.accelerationCONST*0.5;
		}
		if (zawodnik.tempbieg>0) {if (zawodnik.odchyl>-5) zawodnik.odchyl-=0.2f;} else if (zawodnik.odchyl<5) zawodnik.odchyl+=0.2f;	
		}	
		
		if (zawodnik.skret>-41) zawodnik.skret-=8.0f;
		
	} 
	else {if (zawodnik.skret<0) zawodnik.skret+=16; if (zawodnik.tempbieg>0) {if (zawodnik.odchyl>0) zawodnik.odchyl-=0.1f;}else if (zawodnik.odchyl<0) zawodnik.odchyl+=0.1f;}

	if (abs(kat0-kat_global)>355 && abs(kat0-kat_global)<361) {zawodnik.kat=0;zawodnik.katk=0;}
	
	if (zawodnik.lewo==0 && zawodnik.prawo==0)
	{
		zawodnik.katk=zawodnik.katk+ftemp4;
		if (zawodnik.skret<=16 && zawodnik.skret>=-16) zawodnik.skret=0;

		if (zawodnik.rozn>=3.0f) zawodnik.kat+=3.0f;
		if (zawodnik.rozn<=-3.0f) zawodnik.kat-=3.0f;
		if (zawodnik.rozn>-3.0f && zawodnik.rozn<3.0f) zawodnik.kat=zawodnik.katk;
	}
	
	if (zawodnik.pr<=zawodnik.accelerationCONST) zawodnik.kat=zawodnik.katk;
	if (zawodnik.rozn<-5 || zawodnik.rozn>5) if (zawodnik.tempbieg>0) AddBackSmoke(zawodnik); else AddFrontSmoke(zawodnik);

	if (zawodnik.id2==true && zawodnik.id1==true)
	{
		zawodnik.id1=false;
		//FSOUND_Sample_SetMode(zawodnik.BREAK, FSOUND_LOOP_NORMAL);
		//zawodnik.channel1 = FSOUND_PlaySoundEx(FSOUND_FREE, zawodnik.BREAK, NULL, TRUE);
		FSOUND_SetPaused(zawodnik.channel1, FALSE);
	}
	if (zawodnik.spacja==1)
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
