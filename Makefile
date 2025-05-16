# Nom de l'exécutable
EXEC = AppWatcher

# Compilateur et options
CXX = g++
CXXFLAGS = -ansi -pedantic -Wall -std=c++11

# Liste des fichiers sources et objets
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut : compilation de l'exécutable
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers .cpp en .o
# Cette règle générique fonctionne pour tous les fichiers .cpp, indépendamment des .h
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable

clean:
	rm -f *.o $(EXEC)

# Nettoyage avancé (en cas de fichiers temporaires additionnels)
mrproper: clean
	rm -f *~ *.bak

# Indique que certains fichiers ne sont pas des cibles
.PHONY: all clean mrproper
