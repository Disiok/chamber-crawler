CXX = g++
CXXFLAGS = -Wall -MMD -DSEED=100 -DDLC
EXEC = cc3k
OBJECTS = armor.o boostAtk.o boostDef.o cell.o chamber.o character.o door.o dragon.o dragonTreasure.o drow.o dwarf.o elf.o enemy.o entity.o equipment.o floor.o game.o goblin.o halfling.o human.o inventory.o main.o merchant.o merchantTreasure.o normalTreasure.o orc.o passage.o player.o poisonHealth.o potion.o restoreHealth.o shade.o smallTreasure.o stair.o sword.o tile.o treasure.o troll.o vampire.o wall.o woundAtk.o woundDef.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
