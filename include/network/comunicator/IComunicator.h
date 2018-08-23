#ifndef I_COMMUNICATOR_H
#define I_COMMUNICATOR_H

class IComunicator
{
public:
    virtual void Start() = 0;
    virtual void Send(const char *, int) = 0;
    virtual int Recieve(char * &, int) = 0;
    virtual void Stop() = 0;
};

#endif