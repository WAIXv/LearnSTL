#pragma once
#include <string>

using string = std::string;

class WaiGameObject
{
public:
    string name;
    int guid;

    WaiGameObject(string name,int guid):name(name),guid(guid)
    {}
    
    bool operator== (const WaiGameObject& other) const
    {
        return &other == this;
    }

};

struct ObjectHashHelper
{
    std::size_t operator() (const WaiGameObject& go) const
    {
        return std::hash<WaiGameObject const*>{}(&go);
    }
};

struct ObjectEqualHelper
{
    bool operator() (const WaiGameObject& g1, const WaiGameObject& g2) const
    {
        return &g1 == &g2;
    }
};