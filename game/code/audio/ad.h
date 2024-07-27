
class AudioEngine
{
    public:
    static void Init();
    static void Update();
    static void Shutdown();

    void LoadSound( const string& strSoundName, bool b3d=true, bool bLooping=false, bool bStrea=false );
    void UnLoadSound( const string& strSoundName );
    void Set3dListenerAndOrientation( const Vec3& vPosition, const Vec3& vLook, const Vec3& vUp );
    int PlaySound( const string& strSoundName, const Vec3& vPos=Vec3{0,0,0}, float fVolumedB=0.0f );
    void StopChannel( in nChannelId );
    void StopAllChannels();
    void SetChannel3dPosition( int nChannelId, const Vec3& vPosition );
    void SetChannelVolume( int nChannelId, float fVolumedB );
    bool IsPlaying( int nChannelId ) const;
};

struct Implementation
{
    Implementation();
    ~Implementation();

    void Update();

    FMOD::System* mpSystem;

    int mnNextChannelId;

    typedef map<string, FMOD::Sound*> SoundMap;
    typedef map<int, FMOD::Channel*> ChannelMap;
    SoundMap mSounds;
    ChannelMap mChannels;
};

Implementation* sgpImplementation = nullptr;

void AudioEngine::Init()
{
    sgpImplementation = new Implementation;
}

void AudioEngine::Update()
{
    sgpImplementation->Update();
}

void AudioEngine::Shutdown()
{
    delete sgpImplementation;
}