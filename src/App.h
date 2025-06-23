#include <raylib.h>

class App {
private:
	const int SC_WIDTH = 1900;
	const int SC_HEIGHT = 1000;

	Camera2D camera = { {0, 0}, {0, 0}, 0, 1 };

	void init();
	void simulate();
	void compute();
	void draw();
	void close();

public:
	void Run();
};

