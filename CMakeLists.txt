cmake_minimum_required(VERSION 3.17)
project(adaship2)

set(CMAKE_CXX_STANDARD 14)

add_executable(adaship2 main.cpp Helpers/iohelper.cpp Helpers/iohelper.h Helpers/mathshelper.cpp Helpers/mathshelper.h Helpers/csvhelper.cpp Helpers/csvhelper.h Helpers/stringhelper.cpp Helpers/stringhelper.h Models/Ship.cpp Models/Ship.h mini.h Settings.cpp Settings.h Models/Board.cpp Models/Board.h Players/Player.cpp Players/RealPlayer.cpp Players/RealPlayer.h Models/PlayerBoard.cpp Game.cpp Game.h Models/PlayerBoard.h Grid.h Players/Player.h GridBoard.cpp GridBoard.h Grid.cpp)