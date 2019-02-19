#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <tuple>

#include "AudioHandler.h"
#include "GuiHandler.h"
#include <sndfile.hh>

int main() {
    const char* fileName = "test.wav";
    puts("Example for using snd file\n");

    AudioHandler audioHandler;
    audioHandler.createSineWaveFile(fileName, SF_FORMAT_WAV | SF_FORMAT_PCM_24);
    audioHandler.readWavefile(fileName);//"testSample.wav");

    int error = 0; uint32_t currentVolume = 0;
    std::tie(error, currentVolume) = audioHandler.getVolume();
    std::cout <<"Current Master volume is : " << currentVolume <<std::endl;
    
    return 0;
}
