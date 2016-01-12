SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testdiccionario

$(BIN)/testdiccionario: $(OBJ)/diccionaro.o
	$(CXX) -Wall -I$(INC) $(OBJ)/diccionaro.o $(SRC)/testdiccionario.cpp -o $(BIN)/testdiccionario

$(OBJ)/diccionaro.o: $(INC)/Diccionario.h $(SRC)/Diccionario.cpp $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Diccionario.cpp -o $(OBJ)/diccionaro.o
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/* doc/doxygen_sqlite3.db
