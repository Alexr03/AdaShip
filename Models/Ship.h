//
// Created by alexr on 01/03/2021.
//

#ifndef ADASHIP2_SHIP_H
#define ADASHIP2_SHIP_H


#include <string>
#include <list>
#include <vector>

class Ship {

public:
    explicit Ship(int id);

private:
    std::string id;
public:
    const std::string &getId() const;

private:
    std::string name;
    int length{};
    bool destroyed{};
    std::vector<std::string> coordinates;
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    int getLength() const;

    void setLength(int length);

    bool isDestroyed() const;

    const std::vector<std::string> &getCoordinates() const;

    void setCoordinates(const std::vector<std::string> &coords);
};


#endif //ADASHIP2_SHIP_H
