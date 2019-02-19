#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <tuple>

// Headers for volume control
#include <unistd.h>
#include <fcntl.h>
#include <alsa/asoundlib.h>

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

/*
* Sets the volume
*/
void
AudioHandler::setVolume(
    uint32_t volume
) {
    // snd_mixer_t* handle;
    // snd_mixer_elem_t* elem;
    // snd_mixer_selem_id_t* sid;

    // static const char* mix_name = "Master";
    // static const char* card = "default";
    // static int mix_index = 0;

    // long pmin, pmax;
    // long get_vol, set_vol;
    // float f_multi;

    // snd_mixer_selem_id_alloca(&sid);

    // //sets simple-mixer index and name
    // snd_mixer_selem_id_set_index(sid, mix_index);
    // snd_mixer_selem_id_set_name(sid, mix_name);

    //     if ((snd_mixer_open(&handle, 0)) < 0)
    //     return -1;
    // if ((snd_mixer_attach(handle, card)) < 0) {
    //     snd_mixer_close(handle);
    //     return -2;
    // }
    // if ((snd_mixer_selem_register(handle, NULL, NULL)) < 0) {
    //     snd_mixer_close(handle);
    //     return -3;
    // }
    // ret = snd_mixer_load(handle);
    // if (ret < 0) {
    //     snd_mixer_close(handle);
    //     return -4;
    // }
    // elem = snd_mixer_find_selem(handle, sid);
    // if (!elem) {
    //     snd_mixer_close(handle);
    //     return -5;
    // }

    // long minv, maxv;

    // snd_mixer_selem_get_playback_volume_range (elem, &minv, &maxv);
    // fprintf(stderr, "Volume range <%i,%i>\n", minv, maxv);

    // if(action == AUDIO_VOLUME_GET) {
    //     if(snd_mixer_selem_get_playback_volume(elem, 0, outvol) < 0) {
    //         snd_mixer_close(handle);
    //         return -6;
    //     }

    //     fprintf(stderr, "Get volume %i with status %i\n", *outvol, ret);
    //     /* make the value bound to 100 */
    //     *outvol -= minv;
    //     maxv -= minv;
    //     minv = 0;
    //     *outvol = 100 * (*outvol) / maxv; // make the value bound from 0 to 100
    // }
    // else if(action == AUDIO_VOLUME_SET) {
    //     if(*outvol < 0 || *outvol > VOLUME_BOUND) // out of bounds
    //         return -7;
    //     *outvol = (*outvol * (maxv - minv) / (100-1)) + minv;

    //     if(snd_mixer_selem_set_playback_volume(elem, 0, *outvol) < 0) {
    //         snd_mixer_close(handle);
    //         return -8;
    //     }
    //     if(snd_mixer_selem_set_playback_volume(elem, 1, *outvol) < 0) {
    //         snd_mixer_close(handle);
    //         return -9;
    //     }
    //     fprintf(stderr, "Set volume %i with status %i\n", *outvol, ret);
    // }

    // snd_mixer_close(handle);

}

/*
* Gets the current volume of the system
*/
std::tuple<int32_t, uint32_t>
AudioHandler::getVolume() {
    snd_mixer_t* handle;
    snd_mixer_elem_t* elem;
    snd_mixer_selem_id_t* sid;

    static const char* mix_name = "Master";
    static const char* card = "default";
    static int mix_index = 0;

    long pmin, pmax;
    long outVol = 0;
    float f_multi;

    snd_mixer_selem_id_alloca(&sid);

    //sets simple-mixer index and name
    snd_mixer_selem_id_set_index(sid, mix_index);
    snd_mixer_selem_id_set_name(sid, mix_name);

    if ((snd_mixer_open(&handle, 0)) < 0)
        return std::make_tuple(-1, outVol);
    if ((snd_mixer_attach(handle, card)) < 0) {
        snd_mixer_close(handle);
        return std::make_tuple(-2, outVol);
    }
    if ((snd_mixer_selem_register(handle, NULL, NULL)) < 0) {
        snd_mixer_close(handle);
        return std::make_tuple(-3, outVol);
    }
    int32_t ret = snd_mixer_load(handle);
    if (ret < 0) {
        snd_mixer_close(handle);
        return std::make_tuple(-4, outVol);
    }
    elem = snd_mixer_find_selem(handle, sid);
    if (!elem) {
        snd_mixer_close(handle);
        return std::make_tuple(-5, outVol);
    }

    long minv, maxv;

    snd_mixer_selem_get_playback_volume_range (elem, &minv, &maxv);
    fprintf(stderr, "Volume range <%i,%i>\n", minv, maxv);

    if(snd_mixer_selem_get_playback_volume(elem, static_cast<snd_mixer_selem_channel_id_t>(0), &outVol) < 0) {
        snd_mixer_close(handle);
        return std::make_tuple(-1, outVol);
    }

    fprintf(stderr, "Get volume %i with status %i\n", outVol, ret);
    /* make the value bound to 100 */
    outVol -= minv;
    maxv -= minv;
    minv = 0;
    outVol = 100 * (outVol) / maxv; // make the value bound from 0 to 100
    snd_mixer_close(handle);
    return std::make_tuple(0, outVol);
}