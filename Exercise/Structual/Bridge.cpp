#include <iostream>
#include <memory>
#include <map>

using namespace std;

class IDevice{
public:
    virtual void operate(const string& name, const int& value) = 0;
    virtual void stop() = 0;
    virtual void showInfo() = 0;
};

class Tv: public IDevice{
public:
    map<string, int> setting;
    virtual void operate(const string& name, const int& value) override{
        map<string, int>::iterator itr;
        itr = setting.find(name);

        if(itr == setting.end()){
            setting.insert(pair<string, int>(name, value));
        }
        else{
            setting[name] = value;
        }        
    }
    virtual void stop() override{
        cout << "Tv video stop" << endl;
    }
    virtual void showInfo() override{
        for(auto i: setting){
            cout << i.first << " " << i.second << endl;
        }
    }
};

class Radio: public IDevice{
public:
    map<string, int> setting;
    virtual void operate(const string& name, const int& value) override{
        setting[name] = value;
    }
    virtual void stop() override{
        cout << "Radio sound stop" << endl;
    }
};

class ARemote{
public:
    unique_ptr<IDevice> device;
    ARemote(IDevice* d): device(d){}
    virtual void volumeDown() = 0;
    virtual void channelDown() = 0;
};

class TvRemote: public ARemote{
public:
    TvRemote(IDevice* d): ARemote(d){}
    virtual void volumeDown() override{
        device->operate("volume", 10);
    }
    virtual void channelDown() override{
        device->operate("channel", 22);
    }
};



int main()
{
    unique_ptr<ARemote> remote = make_unique<TvRemote>(new Tv());
    remote->volumeDown();
    remote->channelDown();

    remote->device->showInfo();

    return 0;
}