SRC = .
CXXFLAGS += -I${SRC}
ifeq (${DEBUG}, 1)
  CXXFLAGS += -1
endif


OBJECTS = main.o card.o cardshoe.o baseplayer.o player.o
blackjack : ${OBJECTS}
	${CXX} -o $@ $^

%.o : %.c %.h


.PHONY : clean
clean :
	rm -f blackjack *.o
