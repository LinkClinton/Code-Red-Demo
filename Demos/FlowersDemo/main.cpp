#include "FlowersDemoApp.hpp"

int main() {
	auto app = FlowersDemoApp("FlowersDemoApp", 1280, 720);

	app.show();
	app.runLoop();
}