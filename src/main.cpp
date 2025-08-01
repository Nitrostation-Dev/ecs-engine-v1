#include <nitrogen.hpp>

Coordinator c;

struct Player {};

struct Transform {
	float a;
};

struct Velocity {
	float x;
};

int main() {
	c.Init();

	c.RegisterComponent<Player>();
	c.RegisterComponent<Transform>();
	c.RegisterComponent<Velocity>();

	Entity entity = c.SpawnEntity(Player{}, (Transform){ .a =  10.0f }, (Velocity) { .x =  5.0f });

	std::cout << entity + 0 << std::endl;

	auto transform = c.GetComponent<Transform>(entity);

	std::cout << transform.a << std::endl;

	return 0;
}
