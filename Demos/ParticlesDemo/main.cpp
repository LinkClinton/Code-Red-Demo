#include "ParticlesDemoApp.hpp"

int main() {
	auto app = ParticlesDemoApp("ParticlesDemoApp", 1280, 720);
	
	app.show();
	app.runLoop();
}