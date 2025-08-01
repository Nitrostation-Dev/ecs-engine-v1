#include <nitrogen.hpp>

#include <cstdio>
#include <memory>

struct Velocity {
	float x;
};

int main() {
	std::unique_ptr<EntityManager> em = std::make_unique<EntityManager>();
	std::unique_ptr<ComponentManager> cm = std::make_unique<ComponentManager>();

	cm->RegisterComponent<Velocity>();
}
