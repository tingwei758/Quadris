CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -MMD
EXEC = quadris
OBJECTS = Up.o Subject.o main.o Block.o Board.o Cell.o Clockwise.o Counterclockwise.o Down.o Drop.o Game.o GraphicsDisplay.o I_Block.o I_Command.o Invoker.o J_Block.o J_Command.o L_Block.o L_Command.o Left.o Level.o Level0.o Level1.o Level2.o Level3.o Level4.o Leveldown.o Levelup.o NoRandom.o O_Block.o O_Command.o Random.o Restart.o Right.o S_Block.o Score.o S_Command.o Sequence.o T_Block.o T_Command.o TextDisplay.o Z_Block.o Z_Command.o Hint.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
