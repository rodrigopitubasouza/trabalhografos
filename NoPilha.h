#ifndef NOPILHA_H_INCLUDED
#define NOPILHA_H_INCLUDED

class NoPilha
{
private:
    int info;
    NoPilha* prox;
public:
    NoPilha()                    {};
    ~NoPilha()                   {};
    void setInfo(int val)   { info = val; };
    void setProx(NoPilha* p)     { prox = p; };
    int getInfo()           { return info; };
    NoPilha * getProx()          { return prox; };
};

#endif // NOPILHA_H_INCLUDED