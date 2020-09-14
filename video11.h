#pragma once
#pragma once
#include <stdio.h>
#include <cstdlib>
#include <queue>
#include "al.h"
#include "alc.h"


extern "C" {
#include "libavformat/avformat.h"	
#include "libavcodec/avcodec.h"
#include "libswresample/swresample.h"
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_main.h>
};


#define MAX_AUDIO_FARME_SIZE 96000
#define NUMBUFFERS (4)

#define SFM_REFRESH_EVENT  (SDL_USEREVENT + 1)
#define SFM_BREAK_EVENT  (SDL_USEREVENT + 2)


typedef struct _tFrame {
	void* data;
	int size;
	int samplerate;
	double audio_clock;
	int64_t audio_timestamp;
}TFRAME, * PTFRAME;

//��ʼ��
void setopenal(ALuint source);
//�����̣߳�������Ƶ����
int sfp_refresh_thread(int timeInterval, bool& faster, bool& slower);
int SoundCallback(ALuint& bufferID);//�ص�����
void forward_func(double second);
int sfp_control_thread(float& volumn, bool& volumnChange);