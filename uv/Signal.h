/*
   Copyright 2017, object_he@yeah.net  All rights reserved.

   Author: object_he@yeah.net 
    
   Last modified: 2017-10-9
    
   Description: 
*/

#ifndef UV_SIGNAL_H
#define UV_SIGNAL_H


#include <map>
#include <functional>

#include "EventLoop.h"

namespace uv
{

using SignalHandle = std::function<void(int)>;

class Signal
{
public:
    Signal(EventLoop* loop,int sig, SignalHandle handle = nullptr);
    void close(std::function<void()>& callback);
    virtual ~Signal();

    void setHandle(SignalHandle handle);
    bool handle(int signum);

    void closeComplete();
    static void Ignore(int sig);
private:
    uv_signal_t* signal_;
    SignalHandle hanlde_;
    std::function<void()> closeCallback_;
    static void onSignal(uv_signal_t* handle, int signum);
};

}
#endif
