void Zrob_Sam_Linie(Tgracz &zawodnik,float dl)
{

	headingRAD=(zawodnik.katk*RAD)+(27*RAD);
	sins[0]=sinf(headingRAD)*(dl);
	coss[0]=cosf(headingRAD)*(dl);
	
	zawodnik.vLine[0].x=zawodnik.x-sins[0];
	zawodnik.vLine[0].y=0;
	zawodnik.vLine[0].z=zawodnik.z-coss[0];
	zawodnik.vLine2[0].x=zawodnik.x+sins[0];
	zawodnik.vLine2[0].y=0;
	zawodnik.vLine2[0].z=zawodnik.z+coss[0];
	zawodnik.vLine3[0].x=zawodnik.x+sins[0];
	zawodnik.vLine3[0].y=0;
	zawodnik.vLine3[0].z=zawodnik.z+coss[0];
	zawodnik.vLine4_[0].x=zawodnik.x-sins[0];
	zawodnik.vLine4_[0].y=0;
	zawodnik.vLine4_[0].z=zawodnik.z-coss[0];

	
	headingRAD=(zawodnik.katk*RAD)-(27*RAD);
	sins[0]=sinf(headingRAD)*(dl);
	coss[0]=cosf(headingRAD)*(dl);

	zawodnik.vLine[1].x=zawodnik.x-sins[0];
	zawodnik.vLine[1].y=0;
	zawodnik.vLine[1].z=zawodnik.z-coss[0];
	zawodnik.vLine2[1].x=zawodnik.x+sins[0];
	zawodnik.vLine2[1].y=0;
	zawodnik.vLine2[1].z=zawodnik.z+coss[0];
	

	headingRAD=(zawodnik.katk*RAD)-(90*RAD);
	sins[0]=sinf(headingRAD)*(dl/2.2f);
	coss[0]=cosf(headingRAD)*(dl/2.2f);
	zawodnik.vLine3[1].x=zawodnik.x-sins[0];
	zawodnik.vLine3[1].y=0;
	zawodnik.vLine3[1].z=zawodnik.z-coss[0];

	headingRAD=(zawodnik.katk*RAD)-(90*RAD);
	sins[0]=sinf(headingRAD)*(dl/2.2f);
	coss[0]=cosf(headingRAD)*(dl/2.2f);
	zawodnik.vLine4_[1].x=zawodnik.x+sins[0];
	zawodnik.vLine4_[1].y=0;
	zawodnik.vLine4_[1].z=zawodnik.z+coss[0];



	zawodnik.vLine3_[1].x=zawodnik.vLine3[1].x;
	zawodnik.vLine3_[1].y=zawodnik.vLine3[1].y;
	zawodnik.vLine3_[1].z=zawodnik.vLine3[1].z;
	zawodnik.vLine3_[0].x=zawodnik.vLine[1].x;
	zawodnik.vLine3_[0].y=zawodnik.vLine[1].y;
	zawodnik.vLine3_[0].z=zawodnik.vLine[1].z;

	zawodnik.vLine4[1].x=zawodnik.vLine4_[1].x;
	zawodnik.vLine4[1].y=zawodnik.vLine4_[1].y;
	zawodnik.vLine4[1].z=zawodnik.vLine4_[1].z;
	zawodnik.vLine4[0].x=zawodnik.vLine2[1].x;
	zawodnik.vLine4[0].y=zawodnik.vLine2[1].y;
	zawodnik.vLine4[0].z=zawodnik.vLine2[1].z;

	ftemps[1]=(zawodnik.katk+180)*RAD;
	ftemps[2]=(sinf(ftemps[1])*10);
	ftemps[3]=(cosf(ftemps[1])*10);
	zawodnik.vLine[0].x+=ftemps[2];
	zawodnik.vLine[0].z+=ftemps[3];
	zawodnik.vLine[1].x+=ftemps[2];
	zawodnik.vLine[1].z+=ftemps[3];
	zawodnik.vLine2[0].x+=ftemps[2];
	zawodnik.vLine2[0].z+=ftemps[3];
	zawodnik.vLine2[1].x+=ftemps[2];
	zawodnik.vLine2[1].z+=ftemps[3];
	zawodnik.vLine3[0].x+=ftemps[2];
	zawodnik.vLine3[0].z+=ftemps[3];
	zawodnik.vLine3[1].x+=ftemps[2];
	zawodnik.vLine3[1].z+=ftemps[3];
	zawodnik.vLine4[0].x+=ftemps[2];
	zawodnik.vLine4[0].z+=ftemps[3];
	zawodnik.vLine4[1].x+=ftemps[2];
	zawodnik.vLine4[1].z+=ftemps[3];
	zawodnik.vLine3_[0].x+=ftemps[2];
	zawodnik.vLine3_[0].z+=ftemps[3];
	zawodnik.vLine3_[1].x+=ftemps[2];
	zawodnik.vLine3_[1].z+=ftemps[3];
	zawodnik.vLine4_[0].x+=ftemps[2];
	zawodnik.vLine4_[0].z+=ftemps[3];
	zawodnik.vLine4_[1].x+=ftemps[2];
	zawodnik.vLine4_[1].z+=ftemps[3];
	
	headingRAD=ftemps[0];
}



bool Colission_NEW(Tgracz &zawodnik, SCIANA wall_)
{
	zawodnik.bCollided = IntersectedPolygon(wall_.Triangle, zawodnik.vLine, 3);
	zawodnik.bCollided2 = IntersectedPolygon(wall_.Triangle, zawodnik.vLine2, 3);
	zawodnik.bCollided3 = IntersectedPolygon(wall_.Triangle, zawodnik.vLine3, 3);
	zawodnik.bCollided4 = IntersectedPolygon(wall_.Triangle, zawodnik.vLine4, 3);
	zawodnik.bCollided3_ = IntersectedPolygon(wall_.Triangle, zawodnik.vLine3_, 3);
	zawodnik.bCollided4_ = IntersectedPolygon(wall_.Triangle, zawodnik.vLine4_, 3);
	if (zawodnik.bCollided||zawodnik.bCollided2||zawodnik.bCollided3||zawodnik.bCollided4||zawodnik.bCollided3_||zawodnik.bCollided4_) return true; else return false;
}




void Wykryj_kolizje_NEW(Tgracz &zawodnik,bool &kolizja,bool k1,bool k2,bool k3,bool kGR)
{
	zawodnik.METAok=false;zawodnik.HOTRODok=false;
	SCIANA stemp;
	
	
if (k1)
{
	if (zawodnik.kolizja1==false) 
	{
	stemp.Triangle[0].x=KOMP.vLine[0].x;
	stemp.Triangle[1].x=KOMP.vLine[1].x;
	stemp.Triangle[0].z=KOMP.vLine[0].z;
	stemp.Triangle[1].z=KOMP.vLine[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja1 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[1]=zawodnik.bCollided;
	zawodnik._bCollided2[1]=zawodnik.bCollided2;
	zawodnik._bCollided3[1]=zawodnik.bCollided3;
	zawodnik._bCollided4[1]=zawodnik.bCollided4;
	zawodnik._bCollided3_[1]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[1]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja1==false) 
	{
	stemp.Triangle[0].x=KOMP.vLine2[0].x;
	stemp.Triangle[1].x=KOMP.vLine2[1].x;
	stemp.Triangle[0].z=KOMP.vLine2[0].z;
	stemp.Triangle[1].z=KOMP.vLine2[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja1 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[1]=zawodnik.bCollided;
	zawodnik._bCollided2[1]=zawodnik.bCollided2;
	zawodnik._bCollided3[1]=zawodnik.bCollided3;
	zawodnik._bCollided4[1]=zawodnik.bCollided4;
	zawodnik._bCollided3_[1]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[1]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja1==false) 
	{
	stemp.Triangle[0].x=KOMP.vLine3[0].x;
	stemp.Triangle[1].x=KOMP.vLine3[1].x;
	stemp.Triangle[0].z=KOMP.vLine3[0].z;
	stemp.Triangle[1].z=KOMP.vLine3[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja1 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[1]=zawodnik.bCollided;
	zawodnik._bCollided2[1]=zawodnik.bCollided2;
	zawodnik._bCollided3[1]=zawodnik.bCollided3;
	zawodnik._bCollided4[1]=zawodnik.bCollided4;
	zawodnik._bCollided3_[1]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[1]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja1==false) 
	{
	stemp.Triangle[0].x=KOMP.vLine3_[0].x;
	stemp.Triangle[1].x=KOMP.vLine3_[1].x;
	stemp.Triangle[0].z=KOMP.vLine3_[0].z;
	stemp.Triangle[1].z=KOMP.vLine3_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja1 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[1]=zawodnik.bCollided;
	zawodnik._bCollided2[1]=zawodnik.bCollided2;
	zawodnik._bCollided3[1]=zawodnik.bCollided3;
	zawodnik._bCollided4[1]=zawodnik.bCollided4;
	zawodnik._bCollided3_[1]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[1]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja1==false) 
	{
	stemp.Triangle[0].x=KOMP.vLine4[0].x;
	stemp.Triangle[1].x=KOMP.vLine4[1].x;
	stemp.Triangle[0].z=KOMP.vLine4[0].z;
	stemp.Triangle[1].z=KOMP.vLine4[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja1 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[1]=zawodnik.bCollided;
	zawodnik._bCollided2[1]=zawodnik.bCollided2;
	zawodnik._bCollided3[1]=zawodnik.bCollided3;
	zawodnik._bCollided4[1]=zawodnik.bCollided4;
	zawodnik._bCollided3_[1]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[1]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja1==false) 
	{
	stemp.Triangle[0].x=KOMP.vLine4_[0].x;
	stemp.Triangle[1].x=KOMP.vLine4_[1].x;
	stemp.Triangle[0].z=KOMP.vLine4_[0].z;
	stemp.Triangle[1].z=KOMP.vLine4_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja1 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[1]=zawodnik.bCollided;
	zawodnik._bCollided2[1]=zawodnik.bCollided2;
	zawodnik._bCollided3[1]=zawodnik.bCollided3;
	zawodnik._bCollided4[1]=zawodnik.bCollided4;
	zawodnik._bCollided3_[1]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[1]=zawodnik.bCollided4_;
	}
}
if (k2)
{
	if (zawodnik.kolizja2==false) {
	stemp.Triangle[0].x=KOMP2.vLine[0].x;
	stemp.Triangle[1].x=KOMP2.vLine[1].x;
	stemp.Triangle[0].z=KOMP2.vLine[0].z;
	stemp.Triangle[1].z=KOMP2.vLine[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja2 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[2]=zawodnik.bCollided;
	zawodnik._bCollided2[2]=zawodnik.bCollided2;
	zawodnik._bCollided3[2]=zawodnik.bCollided3;
	zawodnik._bCollided4[2]=zawodnik.bCollided4;
	zawodnik._bCollided3_[2]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[2]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja2==false) {
	stemp.Triangle[0].x=KOMP2.vLine2[0].x;
	stemp.Triangle[1].x=KOMP2.vLine2[1].x;
	stemp.Triangle[0].z=KOMP2.vLine2[0].z;
	stemp.Triangle[1].z=KOMP2.vLine2[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja2 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[2]=zawodnik.bCollided;
	zawodnik._bCollided2[2]=zawodnik.bCollided2;
	zawodnik._bCollided3[2]=zawodnik.bCollided3;
	zawodnik._bCollided4[2]=zawodnik.bCollided4;
	zawodnik._bCollided3_[2]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[2]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja2==false) {
	stemp.Triangle[0].x=KOMP2.vLine3[0].x;
	stemp.Triangle[1].x=KOMP2.vLine3[1].x;
	stemp.Triangle[0].z=KOMP2.vLine3[0].z;
	stemp.Triangle[1].z=KOMP2.vLine3[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja2 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[2]=zawodnik.bCollided;
	zawodnik._bCollided2[2]=zawodnik.bCollided2;
	zawodnik._bCollided3[2]=zawodnik.bCollided3;
	zawodnik._bCollided4[2]=zawodnik.bCollided4;
	zawodnik._bCollided3_[2]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[2]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja2==false) {
	stemp.Triangle[0].x=KOMP2.vLine3_[0].x;
	stemp.Triangle[1].x=KOMP2.vLine3_[1].x;
	stemp.Triangle[0].z=KOMP2.vLine3_[0].z;
	stemp.Triangle[1].z=KOMP2.vLine3_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja2 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[2]=zawodnik.bCollided;
	zawodnik._bCollided2[2]=zawodnik.bCollided2;
	zawodnik._bCollided3[2]=zawodnik.bCollided3;
	zawodnik._bCollided4[2]=zawodnik.bCollided4;
	zawodnik._bCollided3_[2]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[2]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja2==false) {
	stemp.Triangle[0].x=KOMP2.vLine4[0].x;
	stemp.Triangle[1].x=KOMP2.vLine4[1].x;
	stemp.Triangle[0].z=KOMP2.vLine4[0].z;
	stemp.Triangle[1].z=KOMP2.vLine4[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja2 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[2]=zawodnik.bCollided;
	zawodnik._bCollided2[2]=zawodnik.bCollided2;
	zawodnik._bCollided3[2]=zawodnik.bCollided3;
	zawodnik._bCollided4[2]=zawodnik.bCollided4;
	zawodnik._bCollided3_[2]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[2]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja2==false) {
	stemp.Triangle[0].x=KOMP2.vLine4_[0].x;
	stemp.Triangle[1].x=KOMP2.vLine4_[1].x;
	stemp.Triangle[0].z=KOMP2.vLine4_[0].z;
	stemp.Triangle[1].z=KOMP2.vLine4_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja2 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[2]=zawodnik.bCollided;
	zawodnik._bCollided2[2]=zawodnik.bCollided2;
	zawodnik._bCollided3[2]=zawodnik.bCollided3;
	zawodnik._bCollided4[2]=zawodnik.bCollided4;
	zawodnik._bCollided3_[2]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[2]=zawodnik.bCollided4_;
	}
}
if (k3)
{
	if (zawodnik.kolizja3==false) {
	stemp.Triangle[0].x=KOMP3.vLine[0].x;
	stemp.Triangle[1].x=KOMP3.vLine[1].x;
	stemp.Triangle[0].z=KOMP3.vLine[0].z;
	stemp.Triangle[1].z=KOMP3.vLine[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja3 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[3]=zawodnik.bCollided;
	zawodnik._bCollided2[3]=zawodnik.bCollided2;
	zawodnik._bCollided3[3]=zawodnik.bCollided3;
	zawodnik._bCollided4[3]=zawodnik.bCollided4;
	zawodnik._bCollided3_[3]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[3]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja3==false) {
	stemp.Triangle[0].x=KOMP3.vLine2[0].x;
	stemp.Triangle[1].x=KOMP3.vLine2[1].x;
	stemp.Triangle[0].z=KOMP3.vLine2[0].z;
	stemp.Triangle[1].z=KOMP3.vLine2[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja3 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[3]=zawodnik.bCollided;
	zawodnik._bCollided2[3]=zawodnik.bCollided2;
	zawodnik._bCollided3[3]=zawodnik.bCollided3;
	zawodnik._bCollided4[3]=zawodnik.bCollided4;
	zawodnik._bCollided3_[3]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[3]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja3==false) {
	stemp.Triangle[0].x=KOMP3.vLine3[0].x;
	stemp.Triangle[1].x=KOMP3.vLine3[1].x;
	stemp.Triangle[0].z=KOMP3.vLine3[0].z;
	stemp.Triangle[1].z=KOMP3.vLine3[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja3 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[3]=zawodnik.bCollided;
	zawodnik._bCollided2[3]=zawodnik.bCollided2;
	zawodnik._bCollided3[3]=zawodnik.bCollided3;
	zawodnik._bCollided4[3]=zawodnik.bCollided4;
	zawodnik._bCollided3_[3]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[3]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja3==false) {
	stemp.Triangle[0].x=KOMP3.vLine3_[0].x;
	stemp.Triangle[1].x=KOMP3.vLine3_[1].x;
	stemp.Triangle[0].z=KOMP3.vLine3_[0].z;
	stemp.Triangle[1].z=KOMP3.vLine3_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja3 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[3]=zawodnik.bCollided;
	zawodnik._bCollided2[3]=zawodnik.bCollided2;
	zawodnik._bCollided3[3]=zawodnik.bCollided3;
	zawodnik._bCollided4[3]=zawodnik.bCollided4;
	zawodnik._bCollided3_[3]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[3]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja3==false) {
	stemp.Triangle[0].x=KOMP3.vLine4[0].x;
	stemp.Triangle[1].x=KOMP3.vLine4[1].x;
	stemp.Triangle[0].z=KOMP3.vLine4[0].z;
	stemp.Triangle[1].z=KOMP3.vLine4[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja3 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[3]=zawodnik.bCollided;
	zawodnik._bCollided2[3]=zawodnik.bCollided2;
	zawodnik._bCollided3[3]=zawodnik.bCollided3;
	zawodnik._bCollided4[3]=zawodnik.bCollided4;
	zawodnik._bCollided3_[3]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[3]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizja3==false) {
	stemp.Triangle[0].x=KOMP3.vLine4_[0].x;
	stemp.Triangle[1].x=KOMP3.vLine4_[1].x;
	stemp.Triangle[0].z=KOMP3.vLine4_[0].z;
	stemp.Triangle[1].z=KOMP3.vLine4_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizja3 = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[3]=zawodnik.bCollided;
	zawodnik._bCollided2[3]=zawodnik.bCollided2;
	zawodnik._bCollided3[3]=zawodnik.bCollided3;
	zawodnik._bCollided4[3]=zawodnik.bCollided4;
	zawodnik._bCollided3_[3]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[3]=zawodnik.bCollided4_;
	}
}
if (kGR)
{
	if (zawodnik.kolizjaGR==false) {
	stemp.Triangle[0].x=gracz.vLine[0].x;
	stemp.Triangle[1].x=gracz.vLine[1].x;
	stemp.Triangle[0].z=gracz.vLine[0].z;
	stemp.Triangle[1].z=gracz.vLine[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizjaGR = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[0]=zawodnik.bCollided;
	zawodnik._bCollided2[0]=zawodnik.bCollided2;
	zawodnik._bCollided3[0]=zawodnik.bCollided3;
	zawodnik._bCollided4[0]=zawodnik.bCollided4;
	zawodnik._bCollided3_[0]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[0]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizjaGR==false) {
	stemp.Triangle[0].x=gracz.vLine2[0].x;
	stemp.Triangle[1].x=gracz.vLine2[1].x;
	stemp.Triangle[0].z=gracz.vLine2[0].z;
	stemp.Triangle[1].z=gracz.vLine2[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizjaGR = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[0]=zawodnik.bCollided;
	zawodnik._bCollided2[0]=zawodnik.bCollided2;
	zawodnik._bCollided3[0]=zawodnik.bCollided3;
	zawodnik._bCollided4[0]=zawodnik.bCollided4;
	zawodnik._bCollided3_[0]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[0]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizjaGR==false) {
	stemp.Triangle[0].x=gracz.vLine3[0].x;
	stemp.Triangle[1].x=gracz.vLine3[1].x;
	stemp.Triangle[0].z=gracz.vLine3[0].z;
	stemp.Triangle[1].z=gracz.vLine3[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizjaGR = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[0]=zawodnik.bCollided;
	zawodnik._bCollided2[0]=zawodnik.bCollided2;
	zawodnik._bCollided3[0]=zawodnik.bCollided3;
	zawodnik._bCollided4[0]=zawodnik.bCollided4;
	zawodnik._bCollided3_[0]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[0]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizjaGR==false) {
	stemp.Triangle[0].x=gracz.vLine3_[0].x;
	stemp.Triangle[1].x=gracz.vLine3_[1].x;
	stemp.Triangle[0].z=gracz.vLine3_[0].z;
	stemp.Triangle[1].z=gracz.vLine3_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizjaGR = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[0]=zawodnik.bCollided;
	zawodnik._bCollided2[0]=zawodnik.bCollided2;
	zawodnik._bCollided3[0]=zawodnik.bCollided3;
	zawodnik._bCollided4[0]=zawodnik.bCollided4;
	zawodnik._bCollided3_[0]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[0]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizjaGR==false) {
	stemp.Triangle[0].x=gracz.vLine4[0].x;
	stemp.Triangle[1].x=gracz.vLine4[1].x;
	stemp.Triangle[0].z=gracz.vLine4[0].z;
	stemp.Triangle[1].z=gracz.vLine4[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizjaGR = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[0]=zawodnik.bCollided;
	zawodnik._bCollided2[0]=zawodnik.bCollided2;
	zawodnik._bCollided3[0]=zawodnik.bCollided3;
	zawodnik._bCollided4[0]=zawodnik.bCollided4;
	zawodnik._bCollided3_[0]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[0]=zawodnik.bCollided4_;
	}
	if (zawodnik.kolizjaGR==false) {
	stemp.Triangle[0].x=gracz.vLine4_[0].x;
	stemp.Triangle[1].x=gracz.vLine4_[1].x;
	stemp.Triangle[0].z=gracz.vLine4_[0].z;
	stemp.Triangle[1].z=gracz.vLine4_[1].z;
	stemp.Triangle[2].z=stemp.Triangle[0].z;stemp.Triangle[2].x=stemp.Triangle[0].x;stemp.Triangle[0].y=0;stemp.Triangle[1].y=0;stemp.Triangle[2].y=5;
	zawodnik.kolizjaGR = Colission_NEW(zawodnik,stemp);
	zawodnik._bCollided[0]=zawodnik.bCollided;
	zawodnik._bCollided2[0]=zawodnik.bCollided2;
	zawodnik._bCollided3[0]=zawodnik.bCollided3;
	zawodnik._bCollided4[0]=zawodnik.bCollided4;
	zawodnik._bCollided3_[0]=zawodnik.bCollided3_;
	zawodnik._bCollided4_[0]=zawodnik.bCollided4_;
	}
}

	zawodnik.METAok=Colission_NEW(zawodnik,METAl);
	zawodnik.HOTRODok=Colission_NEW(zawodnik,HOTRODl);
	kolizja = Colission_NEW(zawodnik,lewo);
	if (kolizja==false) kolizja = Colission_NEW(zawodnik,dol);
	if (kolizja==false) kolizja = Colission_NEW(zawodnik,prawo);
	if (kolizja==false) kolizja = Colission_NEW(zawodnik,gora);

	if (kolizja==false) 
	{
		for (i=1;i<=ilosc_band;i++)
		{
			kolizja = Colission_NEW(zawodnik,bandy[i]);
			if (kolizja) break;
		}
	}
}