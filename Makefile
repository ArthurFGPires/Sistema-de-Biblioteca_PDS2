# Nome do projeto
PROJ_NAME=Sistema_Biblioteca

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
CC_FLAGS=-Wall -std=c++20 -I $(INCLUDE_DIR)

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

# Compila todos os arquivos .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CC_FLAGS) -o $@ $<

# Cria o executável
$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

# Regra para compilar um arquivo .o específico
%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CC_FLAGS) -o $(BUILD_DIR)/$@ $<

run: $(EXEC)
	./$(EXEC)

# Remove os arquivos .o e o executável
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)
