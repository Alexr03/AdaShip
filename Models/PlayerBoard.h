//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_PLAYERBOARD_H
#define ADASHIP2_PLAYERBOARD_H

#include "Board.h"
#include "Coord.h"
#include "Mine.h"

class Player;
class PlayerBoard : public Board {
private:
    Player *player{};
    std::vector<Ship> ships{};
    std::vector<Mine> mines{};
    std::vector<Coord> hitSpots{};

public:
    /// Initialize the player board with a player object
    /// \param player1
    explicit PlayerBoard(Player *player1);

    /// Get ships in this board
    /// \return
    const std::vector<Ship> &getShips() const;

    /// Get hit spots in this board
    /// \return
    const std::vector<Coord> &getHitSpots() const;

    /// Get mines in this board
    /// \return
    const std::vector<Mine> &getMines() const;

    /// Set a spot in the board as "hit"
    /// \param row Row where to hit
    /// \param col Col where to hit
    void hitSpot(int row, std::string col);

    /// Checks if a coordinate was hit
    /// \param row Row to check
    /// \param col Col to check
    /// \return True if hit
    bool isHitSpot(int row, std::string col);

    /// Checks if entities are overlapping with another
    /// \param entity Entity to check
    /// \return True if overlapping another entity.
    bool isEntityOverlapping(const MapEntity* entity);
};

#endif //ADASHIP2_PLAYERBOARD_H
