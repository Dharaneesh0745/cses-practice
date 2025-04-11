cmake_minimum_required(VERSION 3.30)
project(CSES)

set(CMAKE_CXX_STANDARD 23)

# Main executable (if you want to keep this)
add_executable(CSES test.cpp
        "CSES - test.cpp")

# Counting_Rooms executable
add_executable(Labyrinth
        "CSES - Graphs/Labyrinth.cpp")

add_executable(Message_Route
        "CSES - Graphs/Message_Route .cpp")

add_executable(Building_Teams
        "CSES - Graphs/Building_Teams .cpp")

add_executable(Round_Trip
        "CSES - Graphs/Round_Trip .cpp")

add_executable(Building_Roads
        "CSES - Graphs/Building_Roads .cpp")

add_executable(Monsters
        "CSES - Graphs/Monsters.cpp")

