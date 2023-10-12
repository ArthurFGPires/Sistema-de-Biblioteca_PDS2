# Nome do projeto
PROJ_NAME=Main

# Nome do arquivo executável
EXEC=$(PROJ_NAME)

# Diretório dos arquivos .h
INCLUDE_DIR=include

# Diretório dos arquivos .cpp
SRC_DIR=src

# Diretório dos arquivos .o
BUILD_DIR=build

# Compilador
CC=g++

# Flags do compilador
CC_FLAGS=-Wall -std=c++11 -I $(INCLUDE_DIR)

# Bibliotecas
LIBS=-lm

# Arquivos .cpp
CPP_FILES=$(wildcard $(SRC_DIR)/*.cpp)

# Arquivos .o
OBJ_FILES=$(addprefix $(BUILD_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

# Comando para criar o diretório build, se não existir
MKDIR_P=mkdir -p

# Regra principal
all: $(BUILD_DIR) $(EXEC)

# Cria o diretório build
$(BUILD_DIR):
	$(MKDIR_P) $(BUILD_DIR)

# Cria o executável
$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

# Cria os arquivos .o a partir dos arquivos .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CC_FLAGS) -o $@ $<

run: $(EXEC)
	./$(EXEC)
# Remove os arquivos .o e o executável
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)
