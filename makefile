CXX = g++
CXXFLAGS = -std=c++0x

OBJS = main.o room.o normal_room.o monster_room.o switch_room.o item_room.o teleport_room.o humanoids.o monster.o player.o
 
HEADERS = room.h normal_room.h monster_room.h switch_room.h item_room.h teleport_room.h humanoids.h monster.h player.h 

SRCS = main.cpp room.cpp normal_room.cpp monster_room.cpp switch_room.cpp item_room.cpp teleport_room.cpp humanoids.cpp monster.cpp player.cpp

PROGS = final_project

all: clear finalproject

clear:
	rm -rf *o ${PROGS}

finalproject: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o finalproject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
