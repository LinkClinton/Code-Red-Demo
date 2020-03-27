#include "EffectPassDemoApp.hpp"

int main() {
	auto app = EffectPassDemoApp("EffectPassDemoApp", 1280, 720);

	app.show();
	app.runLoop();
}