CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k 
OBJECTS = cell.o chamber.o character.o door.o dragon.o drow.o dwarf.o elf.o enemy.o entity.o floor.o game.o goblin.o halfling.o human.o item.o main.o merchant.o orc.o passage.o player.o potion.o shade.o stair.o tile.o treasure.o troll.o vampire.o wall.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
