#ifndef ORE_H
#define ORE_H

#include <string>

class Model;

class Ore
{

private:
    std::string m_name;
    int m_levelReq, m_xpYield, m_goldYield;

public:
    Ore(std::string name, int levelReq, int xpYield, int goldYield);

    void mine(Model &model);

};

#endif // ORE_H
