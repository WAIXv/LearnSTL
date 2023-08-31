#pragma once
#include <iostream>

class WaiString
{
    int size;
    char* data;
public:
    WaiString(const char* string)
    {
        std::cout<<"Created!"<<std::endl;
        size = strlen(string);
        data = new char[size];
        memcpy(data,string,size);
    }

    // WaiString(char*&& string)
    // {
    //     std::cout<<"Move created!"<<std::endl;
    //     size = strlen(string);
    //     data = string;
    //     
    //     string = nullptr;
    // }
    
    WaiString(const WaiString& other)
    {
        std::cout<<"Copy!"<<std::endl;
        size = other.size;
        char* tmp = new char[size];
        for(int i = 0; i < size; i++)
        {
            tmp[i] = other.data[i];
        }
    }
    
    WaiString(WaiString&& other)
    {
        std::cout<<"Moved!"<<std::endl;
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
    }

    ~WaiString()
    {
        std::cout<<"Destory!"<<std::endl;
    }
};

class TestEntity
{
    WaiString name;
public:
    TestEntity(const WaiString& name):name(name)
    {}

    TestEntity(WaiString&& name):name(std::move(name))
    {}
};


