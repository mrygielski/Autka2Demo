#ifndef FMOD_GG
#define FMOD_GG

#include <fmod.h>

#define MUZYKA FMUSIC_MODULE
#define DZWIEK FSOUND_STREAM

//INIT AND CLOSE
void Init_FMOD(int resample,int ch);
void Close_FMOD();

// MUSIC
FMUSIC_MODULE* Load_Music(char *plik);
void Play_Music(FMUSIC_MODULE* music);
void Stop_Music(FMUSIC_MODULE* music);
void Music_Volume(FMUSIC_MODULE *mod,int volume);

//SAMPLES
FSOUND_STREAM* Load_Sample(char *plik);
void Play_Sample(FSOUND_STREAM* sample,int ch);
void Stop_Sample(int ch);
bool Is_Playing(int ch);
void Volume(int ch, unsigned char value);
float Sample_CPU_Usage();
void Sample_Echo(int fxid,float WetDryMix,float Feedback,float LeftDelay,float RightDelay,int PanDelay);
void Sample_Gargle(int ch,int RateHz,int WaveShape);





void Init_FMOD(int resample,int ch)
{
     FSOUND_Init(resample, ch, FSOUND_INIT_GLOBALFOCUS);
}

void Close_FMOD()
{
     FSOUND_Close();
}

FMUSIC_MODULE* Load_Music(char *plik)
{
     return FMUSIC_LoadSong(plik);
}

void Play_Music(FMUSIC_MODULE* music)
{
     FMUSIC_PlaySong(music);
}

void Stop_Music(FMUSIC_MODULE* music)
{
     FMUSIC_StopSong(music);
}

void Music_Volume(FMUSIC_MODULE *mod,int volume)
{
     FMUSIC_SetMasterVolume(mod,volume);
}
FSOUND_STREAM* Load_Sample(char *plik)
{
     return FSOUND_Stream_OpenFile(plik,FSOUND_2D,0);
}

void Play_Sample(FSOUND_STREAM* sample,int ch)
{
     FSOUND_Stream_Play(ch,sample);
}

void Stop_Sample(int ch)
{
     FSOUND_StopSound(ch);
}

bool Is_Playing(int ch)
{
	if (FSOUND_IsPlaying(ch)==TRUE) return true;else return false;
}

void Volume(int ch, unsigned char value)
{
     FSOUND_SetVolume(ch,value);
}

float Sample_CPU_Usage()
{
      return FSOUND_GetCPUUsage();
}

void Sample_Echo(int fxid,float WetDryMix,float Feedback,float LeftDelay,float RightDelay,int PanDelay)
{
     FSOUND_FX_SetEcho(fxid,WetDryMix,Feedback,LeftDelay,RightDelay,PanDelay);
}

void Sample_Gargle(int ch,int RateHz,int WaveShape)
{
     FSOUND_FX_SetGargle(ch,RateHz,WaveShape);
}
#endif