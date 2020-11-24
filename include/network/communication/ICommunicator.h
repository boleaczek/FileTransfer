#pragma once

class ICommunicator
{
public:
    virtual void Start() = 0;
    virtual void Send(const char *, int) = 0;
    virtual int Recieve(char * &, int) = 0;
    virtual void Stop() = 0;
};