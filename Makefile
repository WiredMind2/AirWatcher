# Nom de l'exécutable
EXEC = AppWatcher

# Compilateur et options
CXX = g++
CXXFLAGS = -ansi -pedantic -Wall -std=c++11 -g

# Liste des fichiers sources et objets
SRCS = $(wildcard *.cpp) $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
OBJDIR = obj
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# Règle par défaut : compilation de l'exécutable
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
# Compilation des fichiers .cpp en .o
# Cette règle générique fonctionne pour tous les fichiers .cpp, indépendamment des .h
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
# Nettoyage des fichiers objets et de l'exécutable

clean:
	rm -rf $(OBJDIR) $(EXEC)
	rm -f *.o $(EXEC)

# Nettoyage avancé (en cas de fichiers temporaires additionnels)
mrproper: clean
	rm -f *~ *.bak
# Création du dossier obj si nécessaire
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Indique que certains fichiers ne sont pas des cibles
.PHONY: all clean mrproper
.PHONY: all clean mrproper
