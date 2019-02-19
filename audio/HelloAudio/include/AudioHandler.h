

class AudioHandler {
    public:
    void createSineWaveFile(const char* fileName, int format);
    void readWavefile(const char* fileName);
    std::tuple<int32_t, uint32_t> getVolume();
    void setVolume(uint32_t volume);
};