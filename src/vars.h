MSG	msg;
BOOL done=FALSE, done2=false;
void DrawGLScene();
int kat,podloga;
int kat0;
float kat_global;
int odleglosc_rysowania=25,odleglosc_rysowania2=6;
bool mipmaps=false;
int jakosc_textur=2;// {1 albo 2}
bool shadow_quality;
bool sounds=true;
int nr_mapy,nropcji2;
//////////////////////////////
float RAD2=180.0f/3.1415926535897932385f;
//CAR's vars//
const float RAD = 0.01745f;
int ttexture;
	

FSOUND_SAMPLE	*MUSIC = NULL;
int channelMUSIC=13;
FSOUND_SAMPLE	*MUSIC2 = NULL;
int channelMUSIC2=14;


///////////////////ZMIENNE////
struct Tgracz
{
	float x,y,z;
	float rx,ry;
	float srx,sry;
	float pr;
	float obr;
	float kat,katk;
	float rozn;
	int bieg;
	int pobieg;
	float max_predkoscCONST;
	float max_predkosc;
	float acceleration;
	float accelerationCONST;
	float hamulec;
	float temp_acc;
	float bieg1max;
	float bieg2max;
	float bieg3max;
	float bieg4max;
	float bieg5max;
	float biegRmax;
	float biegNmax;
	int nr_biegu;
	bool zm_bieg;
	bool biegPLUS,biegMINUS;
	int numer_samuchodu;
	int tempbieg;
	model3D modele3d[20];
	model3Dtga modele3dTGA[5];
	C3dsLoader modele3DS[5];
	TextureImage modele3DSTGA[5];
	int modele3DSBMP[5];
	int przod,tyl,lewo,prawo,spacja;
	float odchyl,skret,skretP,skretR,podnies, podniesP,podniesR;
	float obrt_tyl, obrt_prz;
	float rot_st, rot_obr;
	CVector2 vLine[2],vLine2[2],vLine3[2],vLine4[2],vLine_[2],vLine2_[2],vLine3_[2],vLine4_[2];
	bool kolizja,kolizjaGR,kolizja1,kolizja2,kolizja3;
	bool sladON;
	bool reczny;
	float katskret, katcam, katcamP;
	float xtrans,ytrans,ztrans;
	float obrTYL;
	bool bCollided, bCollided2, bCollided3, bCollided4, bCollided3_, bCollided4_;
	bool _bCollided[5], _bCollided2[5], _bCollided3[5], _bCollided4[5], _bCollided3_[5], _bCollided4_[5];
	int prevP;
	int prevX,prevZ;
	bool METAok,HOTRODok,META,HOTROD;
	float wheels[2][2];
	bool kompRANDOM[12];
	int randomInt;
	float wektorPR,wektorSTR,wektorSTRkat; //przesuniecie: przod-tyl i lewo-prawo i kat
	float ludekX,ludekY,ludekZ;
	int frame; // klatka animacji ludka
	int TIME, TIME2,ttime;
	int okr;
	int nr_sam, podium;
	int demage;
	int alfa;
	bool zyje;
	int badaj;
	FSOUND_SAMPLE	*ENGINE, *BREAK, *BOOM;
	int channel1, channel2, channel3;
	bool id1, id2, ib1, ib2;
	bool sladyRYS;
	bool w_mecie;
	bool w_tabelce;
};

struct TmenuG
{
	float x,y,z;
	float katk;
	int numer_samuchodu;
	model3D modele3d[20];
	model3Dtga modele3dTGA[5];
	C3dsLoader modele3DS[5];
	TextureImage modele3DSTGA[5];
	int modele3DSBMP[5];
	float odchyl,skret,skretR,podnies, podniesR;
	float obrt_tyl, obrt_prz;
	float wheels[2][2];
};

Tgracz gracz,KOMP,KOMP2,KOMP3;

TmenuG menus[10];

C3dsLoader modele3DSludek[5];
int modele3DSludekBMP[5];

short nr_swiatla;
short swiatla[3];
char* tablicaW[5];
int maxokr;
bool AA,BB=true;
bool podium[4];
int nrcars;
float tmp;
float ooorrr;

struct Tmenu
{
	float x;
	float y;
	char *info;
	int color;
	bool move;
};	


Tmenu menu[10];
int nropcji;
bool move;

int delay;



struct Tcars
{
	float max_predkosc;
	float acceleration;
	float accelerationCONST;
	float hamulec;
	char* model_path;
	char* modeltexture_path;
	char* modelItexture_path;
	char* inside_path;
	char* insidetexture_path;
	char* kierownica_path;
	char* kierownicatexture_path;
	char* kolo_path;
	char* kolotexture_path;
	float kolo_tyl_X;
	float kolo_przod_X;
	float kola_Y;
	float grubosc_kol;
	float ALLy;
	float wielkosc_kol;
	float Tx,Ty,Tz,Sx,Sy,Sz;
	float WTx,WTy,WTz,WSx,WSy,WSz;
	float odkrecanie_kierownicy;
	float KatKier;
	float KTx,KTy,KTz,KSx,KSy,KSz;
	float LSx,LSy,LSz,LTx,LTy,LTz;
	float linie;
};
Tcars samochody[10];

bool Apressed=false;
bool Zpressed=false;
float _3d_2d;

CCamera g_Camera;

int texture[50],textureIco[500];
int textureL[50],textureLud[20];
TextureImage textureT[50];
TextureImage textureTT[100];
TextureImage fonttexture,fonttexture2;




GLUquadricObj *sky;

// CHODZENIE
float headingRAD;

int fps;
bool keys2[256];
struct XYdym
{
	float x,y,z;
	float rot,rot2,prawo,dl;
	bool is;
	float color;
	int gd;
};

struct XYslad
{
	float x,y,z;
	float rot,rot2,prawo,dl;
	int gd;
};
int sladnr;
XYslad slady[1000];


struct SCIANA
{
  CVector2 Triangle[3];
};

int ile_dymu=1000,max_dym;
XYdym dym[1001];



int i,itemp;
float ftemp,ftemp2,ftemp3,ftemp4;
float kattemp;

bool lewy,prawy;

int KAMERA;



SCIANA lewo,prawo,gora,dol;
int ilosc_band;
SCIANA bandy[1000];

SCIANA METAl,HOTRODl;





unsigned short mapa[129][129];
unsigned short mapa_kat[129][129];
unsigned short inteligencja[129][129];
float katy[10][2][4];

FILE* plik;
int iloscicon=0;
int mx,my;


model3Dtga modele3dTGA_ed[255];
struct Tmodel
{
	float x,y,rot;
	unsigned short numer;
};
Tmodel modele[10000];
int nrmodelu=1,ilosc_modeli=1;
float modele_y[10000];
struct modeleSCALE
{
	float x,y,z;
};
modeleSCALE modeleScale[10000];
int nr_mod=1;


float camX,camY,camZ;

int licznik_klatek,max_klatek;


struct STARTMETA
{
	float x1,x2,y1,y2;
};

STARTMETA meta,hotrod;



float sins[10],coss[10];
float ftemps[100];




int DIFF = 1;
GLfloat length;
float DiffTime,FPS;
bool  framerate_limit = true;
float framerate;
float Time2,Time1;


inline GLfloat Hypot(GLfloat A, GLfloat B)
{
  return sqrt(A*A+B*B);
}
inline GLfloat ABS(GLfloat A)
{
  if (A < 0)
  A = -A; 
  return A;
}







// Create A Structure For The Timer Information
struct
{
  __int64       frequency;          // Timer Frequency
  GLfloat            resolution;          // Timer Resolution
  unsigned long mm_timer_start;     
  
  // Multimedia Timer Start Value
  unsigned long mm_timer_elapsed;      // Multimedia Timer Elapsed Time
  bool   performance_timer;    
  
  // Using The Performance Timer?
  __int64       performance_timer_start;      // Performance Timer Start Value
  __int64       performance_timer_elapsed; // Performance Timer Elapsed Time
} timer;

// Initialize Our Timer
inline void TimerInit(void)
{
     memset(&timer, 0, sizeof(timer));   
 // Clear Our Timer Structure
     // Check To See If A Performance Counter Is Available
     // If One Is Available The Timer Frequency Will Be Updated
     if (!QueryPerformanceFrequency((LARGE_INTEGER *) &timer.frequency))
     {
          // No Performace Counter Available
          timer.performance_timer = FALSE;                      // Set Performance Timer To FALSE
          timer.mm_timer_start = timeGetTime();                 // Use timeGetTime()
          timer.resolution  = 1.0f/1000.0f;                           // Set Our Timer Resolution To .001f
          timer.frequency   = 1000;                                     // Set Our Timer Frequency To 1000
          timer.mm_timer_elapsed = timer.mm_timer_start; // Set The Elapsed Time
     }
     else
     {
          // Performance Counter Is Available, Use It Instead Of The Multimedia Timer
          // Get The Current Time And Store It In performance_timer_start
          QueryPerformanceCounter((LARGE_INTEGER *) &timer.performance_timer_start);
          timer.performance_timer   = TRUE;    // Set Performance Timer To TRUE
          // Calculate The Timer Resolution Using The Timer Frequency
          timer.resolution    = (GLfloat) (((double)1.0f)/((double)timer.frequency));
          // Set The Elapsed Time To The Current Time
          timer.performance_timer_elapsed = timer.performance_timer_start;
     }
}

// Get Time In Milliseconds
inline GLfloat TimerGetTime()
{
     __int64 time;                                  // 'time' Will Hold A 64 Bit Integer
     if (timer.performance_timer)           // Are We Using The Performance Timer?
     {
          QueryPerformanceCounter((LARGE_INTEGER *) &time); // Current Performance Time
          // Return The Time Elapsed since TimerInit was called
          return ( (GLfloat) ( time - timer.performance_timer_start) * timer.resolution)*1000.0f;
     }
     else
     {
          // Return The Time Elapsed since TimerInit was called
          return ( (GLfloat) ( timeGetTime() - timer.mm_timer_start) * timer.resolution)*1000.0f;
     }
}



