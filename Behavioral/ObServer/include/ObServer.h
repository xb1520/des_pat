#pragma once
#include <vector>
#include <string>
#include <format>
#include <iostream>

//观察者接口
class ObServer
{
public:
    virtual void update(const std::string& event) = 0;
};



//被观察事件
class Event
{
public:
    // using ObServerPtr = std::unique_ptr<ObServer>;
    using ObServerPtr = ObServer*;
    virtual void add_observer(ObServerPtr&& ob_server) = 0;
    virtual void remove_observer(ObServerPtr&& ob_server) = 0;
    virtual void update(const std::string& event) = 0;
};


//具体观察者
class TestObServer : public ObServer
{
    std::string name;
public:
    TestObServer(const std::string& name):name(name){}
    void update(const std::string& event){
        std::cout << std::format("[{}]\t观察到事件\t[{}]",name,event) << std::endl;
    }
};



//具体被观察事件
class TestEvent : public Event
{
public:
    using ObServerPtr = Event::ObServerPtr;
    virtual void add_observer(ObServerPtr&& ob_server){
        obs.emplace_back(std::move(ob_server));
    }
    virtual void remove_observer(ObServerPtr&& ob_server){
        auto ob = std::find(obs.begin(),obs.end(),ob_server);
        if(ob == obs.end()) return;
        obs.erase(ob);
    }
    virtual void update(const std::string& event){
        this->event = event;
        notify_obs();
    }
private:
    void notify_obs(){
        for(auto& ob : obs){
            ob->update(event);
        }
    }
private:
    std::vector<ObServerPtr> obs;
    std::string event;
};