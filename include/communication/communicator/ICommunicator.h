class ICommunicator
{
public:
    virtual void Start() = 0;
    virtual void Send(const char *, int) = 0;
    virtual int Recieve(char * &) = 0;
    virtual void Stop() = 0;
    virtual void Connect() = 0;
    virtual void CloseConnection() = 0;
};