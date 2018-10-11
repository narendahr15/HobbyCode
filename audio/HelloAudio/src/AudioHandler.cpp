#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <iostream>

#include <sndfile.hh>
#include "AudioHandler.h"

namespace {
const uint32_t  BUFFER_LEN = 1024;
const uint32_t  AUDIO_CHANNELS = 2;
const uint32_t  SAMPLE_RATE = 44100;
const uint32_t  SAMPLE_COUNT = SAMPLE_RATE * 1;
const float     AMPLITUDE = 1.0 * 0x7F000000;
const float     LEFT_FREQ = 344.0 / SAMPLE_RATE;
const float     RIGHT_FREQ = 466.0 / SAMPLE_RATE;
}

/*
* Function for creating a sine wave
*/
void 
AudioHandler::createSineWaveFile(
    const char* fileName, 
    int format
) {
    static int buffer[2 * SAMPLE_COUNT];
    SndfileHandle file;
    // SF_INFO sfInfo;
    // memset(&sfInfo, 0, sizeof(sfInfo));

    // sfInfo.samplerate = SAMPLE_RATE;
    // sfInfo.frames = SAMPLE_COUNT;
    // sfInfo.channels = AUDIO_CHANNELS;
    // sfInfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_24;

    file = SndfileHandle(fileName, SFM_WRITE, format, AUDIO_CHANNELS, SAMPLE_RATE);
    printf("File created with error %s\n", file.strError());        
    memset(buffer, 0, sizeof(buffer));

    for (int k = 0 ; k < SAMPLE_COUNT ; k++)
    {	buffer [2 * k] = AMPLITUDE * tan (LEFT_FREQ * 2 * k * M_PI) ;
        buffer [2 * k + 1] = AMPLITUDE * tan (RIGHT_FREQ * 2 * k * M_PI) ;
        // std::cout<<buffer[2 * k]<<" "<<buffer[2 * k + 1]<<std::endl;
    }

    sf_count_t fileBytes = file.write(buffer, 2 * SAMPLE_COUNT);
    printf("Created a new file %s with %ld bytes with error %s\n", fileName, fileBytes, file.strError());
}

/*
* Function to read the wav files
*/
void
AudioHandler::readWavefile(
    const char* fileName
) {
    static int buffer[2 * SAMPLE_COUNT];
    SndfileHandle file;
    file = SndfileHandle(fileName);
    printf ("Opened file '%s'\n", fileName) ;
	printf ("Sample rate : %d\n", file.samplerate ()) ;
	printf ("Channels    : %d\n", file.channels ()) ;
    file.read(buffer, 2 * SAMPLE_COUNT);
    // for (int k = 0 ; k < SAMPLE_COUNT ; k++)
    // {	
    //     std::cout<<buffer[2 * k]<<" "<<buffer[2 * k + 1]<<std::endl;
    // }
    puts("");
}