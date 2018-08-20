class ICommunicator
{
public:
    virtual void Start() = 0;
    virtual void Send(const char *) = 0;
    virtual char * Recieve() = 0;
    virtual void Stop() = 0;
};