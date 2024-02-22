#pragma once
#pragma comment(lib, "Winmm.lib")

/*
https://stackoverflow.com/questions/22253074/how-to-play-or-open-mp3-or-wav-sound-file-in-c-program
*/

#define WAV_FILES_PATH L"audio/wav/"
#define WAV_10_PATH WAV_FILES_PATH ## "10.wav" // ## token concatenation
#define WAV_11_PATH WAV_FILES_PATH ## "11.wav"
#define WAV_12_PATH WAV_FILES_PATH ## "12.wav"
#define WAV_13_PATH WAV_FILES_PATH ## "13.wav"
#define WAV_14_PATH WAV_FILES_PATH ## "14.wav"
#define WAV_15_PATH WAV_FILES_PATH ## "15.wav"
#define WAV_16_PATH WAV_FILES_PATH ## "16.wav"
#define WAV_17_PATH WAV_FILES_PATH ## "17.wav"
#define WAV_18_PATH WAV_FILES_PATH ## "18.wav"
#define WAV_19_PATH WAV_FILES_PATH ## "19.wav"
#define WAV_20_PATH WAV_FILES_PATH ## "20.wav"
#define WAV_21_PATH WAV_FILES_PATH ## "21.wav"
#define WAV_22_PATH WAV_FILES_PATH ## "22.wav"
#define WAV_23_PATH WAV_FILES_PATH ## "23.wav"
#define WAV_24_PATH WAV_FILES_PATH ## "24.wav"

typedef struct WavFiles {
	BYTE* wav_10;
	BYTE* wav_11;
	BYTE* wav_12;
	BYTE* wav_13;
	BYTE* wav_14;
	BYTE* wav_15;
	BYTE* wav_16;
	BYTE* wav_17;
	BYTE* wav_18;
	BYTE* wav_19;
	BYTE* wav_20;
	BYTE* wav_21;
	BYTE* wav_22;
	BYTE* wav_23;
	BYTE* wav_24;
} WavFiles;

void playFramesAudio(int frames);
LPCWSTR getWavResourcePath(int frames);
LPCWSTR getWavFilePath(int frames);
WavFiles* loadWavFiles();
char* loadWavFile(char* path);



