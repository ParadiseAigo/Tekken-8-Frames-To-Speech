#include "frames-to-speech.h"
#include "resource.h"
#include "audio.h"

void playFramesAudio(int frames) {
	LPCWSTR path = getWavResourcePath(frames);
	if (path != 0) {
		PlaySound(path, GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
		//PlaySound(path, GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC); //directly from a file
	}
	//PlaySound(path, GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
	//char* buffer = loadWavFile((char*)WAV_14_PATH);
	//PlaySound(buffer, GetModuleHandle(NULL), SND_MEMORY);
}

// HOW TO ADD NEW .WAV FILES AS A RESOURCE:
// 1. first copy your new files to the audio/wav/ folder
// 2. MAKE SURE YOU CLOSE THE "resource.h" FILE IN THE VISUAL STUDIO EDITOR OR YOU WILL GET THE ACCESS DENIED ERROR DURING THE NEXT STEP
// 3. Inside Visual Studio > *right click* your "Resource Files" folder > Add > Resource... > *select* "WAVE" (sometimes there is no "WAVE" option...) > Import...

LPCWSTR getWavResourcePath(int frames) {
	LPCWSTR path = 0;
	switch (frames) {
	case 5:
		path = MAKEINTRESOURCE(IDR_WAVE1);
		break;
	case 6:
		path = MAKEINTRESOURCE(IDR_WAVE2);
		break;
	case 7:
		path = MAKEINTRESOURCE(IDR_WAVE3);
		break;
	case 8:
		path = MAKEINTRESOURCE(IDR_WAVE4);
		break;
	case 9:
		path = MAKEINTRESOURCE(IDR_WAVE5);
		break;
	case 10:
		path = MAKEINTRESOURCE(IDR_WAVE6);
		break;
	case 11:
		path = MAKEINTRESOURCE(IDR_WAVE7);
		break;
	case 12:
		path = MAKEINTRESOURCE(IDR_WAVE8);
		break;
	case 13:
		path = MAKEINTRESOURCE(IDR_WAVE9);
		break;
	case 14:
		path = MAKEINTRESOURCE(IDR_WAVE10);
		break;
	case 15:
		path = MAKEINTRESOURCE(IDR_WAVE11);
		break;
	case 16:
		path = MAKEINTRESOURCE(IDR_WAVE12);
		break;
	case 17:
		path = MAKEINTRESOURCE(IDR_WAVE13);
		break;
	case 18:
		path = MAKEINTRESOURCE(IDR_WAVE14);
		break;
	case 19:
		path = MAKEINTRESOURCE(IDR_WAVE15);
		break;
	case 20:
		path = MAKEINTRESOURCE(IDR_WAVE16);
		break;
	case 21:
		path = MAKEINTRESOURCE(IDR_WAVE17);
		break;
	case 22:
		path = MAKEINTRESOURCE(IDR_WAVE18);
		break;
	case 23:
		path = MAKEINTRESOURCE(IDR_WAVE19);
		break;
	case 24:
		path = MAKEINTRESOURCE(IDR_WAVE20);
		break;
	}
	return path;
}

// not used
LPCWSTR getWavFilePath(int frames) {
	LPCWSTR path = 0;
	switch (frames) {
	case 10:
		path = WAV_10_PATH;
		break;
	case 11:
		path = WAV_11_PATH;
		break;
	case 12:
		path = WAV_12_PATH;
		break;
	case 13:
		path = WAV_13_PATH;
		break;
	case 14:
		path = WAV_14_PATH;
		break;
	case 15:
		path = WAV_15_PATH;
		break;
	case 16:
		path = WAV_16_PATH;
		break;
	case 17:
		path = WAV_17_PATH;
		break;
	case 18:
		path = WAV_18_PATH;
		break;
	case 19:
		path = WAV_19_PATH;
		break;
	case 20:
		path = WAV_20_PATH;
		break;
	case 21:
		path = WAV_21_PATH;
		break;
	case 22:
		path = WAV_22_PATH;
		break;
	case 23:
		path = WAV_23_PATH;
		break;
	case 24:
		path = WAV_24_PATH;
		break;
	}
	return path;
}

// not used
/*
WavFiles* loadWavFiles() {
	WavFiles* result;
	return result;
}
*/

// not used
char* loadWavFile(char* path) {
	char* result;
	FILE* file;
	unsigned long sizeFile, i;
	char c;
	errno_t errorCode;
	if (0 != (errorCode = fopen_s(&file, path, "r"))) {
		printf("Error, code: %d, loadWavFile(char*) failed to open file: %s\n", errorCode, path);
		system("pause");
		exit(0);
	}
	fseek(file, 0L, SEEK_END);
	sizeFile = ftell(file);
	rewind(file);
	result = (char*) malloc((sizeFile + 1) * sizeof(char));
	i = 0;
	while ( (c = fgetc(file)) != EOF) {
		result[i] = fgetc(file);
		i++;
	}
	result[++i] = '\0';
	return result;
}






