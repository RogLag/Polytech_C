# Nom de l'exécutable principal
TARGET = main
# Nom de l'exécutable de test
TEST_TARGET = test

# Répertoires
SRC_DIR = .
MODULES_DIR = modules
INCLUDE_DIR = include
TEST_DIR = test

# Fichiers sources principaux
SRC = $(SRC_DIR)/main.c $(MODULES_DIR)/list.c
# Fichiers sources pour les tests
TEST_SRC = $(TEST_DIR)/list-test.c $(MODULES_DIR)/list.c

# Fichiers objets
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

# Compilateur et options de compilation
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra -g -Dmain=WinMain
LDFLAGS = -mconsole -Wl,-subsystem,console

# Règle pour construire l'exécutable principal
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Règle pour l'exécutable de test
$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $(TEST_TARGET) $(LDFLAGS)

# Règle pour compiler les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
.PHONY: clean
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)