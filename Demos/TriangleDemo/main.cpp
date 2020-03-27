#include "TriangleDemoApp.hpp"

int main() {
	auto app = TriangleDemoApp("TriangleDemoApp", 1280, 720);
	
	app.show();
	app.runLoop();
}