SFML_PATH = /opt/homebrew/Cellar/sfml/2.6.1

cppFileNames := $(shell find ./src -type f -name "*.cpp")

all: compile

compile:
	g++ $(cppFileNames) -I$(SFML_PATH)/include -o app -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
