C := g++
HEADERS := $(wildcard src/include/*.hpp)
SOURCES := $(wildcard src/*.cpp)
RELOBJS := $(patsubst src/%.cpp, target/release/%.o, $(SOURCES))
DBGOBJS := $(patsubst src/%.cpp, target/debug/%.o, $(SOURCES))

# These are the llvm flags which instead of being linked normally are instead handled via llvm-config.
# I have no idea what these flags do I just copy pasted this off of:
# https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl03.html
LLVM := `llvm-config --cxxflags --ldflags --system-libs --libs core`

# C++ std, chars are unsigned by default instead of being cpu dependent
GENFLAGS := -std=c++20 -funsigned-char $(LLVM)

# Define DEBUG in the program, turn on tons of extra errors, perform 0 optimizations, detect memory errors
DBGFLAGS := -DDEBUG -Wall -Wextra -O0 -g -pedantic -fsanitize=address

# Max optimizations, 
RELFLAGS := -O3

release: $(RELOBJS)
	@echo "Building release build"
	@$(C) $(GENFLAGS) $(RELFLAGS) -o tobe $^
	@echo "Done! Now run with ./tobe"

debug: $(DBGOBJS)
	$(C) $(GENFLAGS) $(DBGFLAGS) -o tobe $^
	@echo "Debug build finished run with ./tobe"

target/debug/%.o: src/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(C) $(GENFLAGS) $(DBGFLAGS) -c $< -o $@

target/release/%.o: src/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(C) $(GENFLAGS) $(RELFLAGS) -c $< -o $@

clean:
	@echo "Cleaning target folder and executable"
	@rm -rf target tobe
