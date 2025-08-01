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

	// c.RegisterComponent<Player>();
	// c.RegisterComponent<Transform>();
	// c.RegisterComponent<Velocity>();

	Entity entity = c.SpawnEntity(Player{}, (Velocity) { .x =  5.0f });

	std::cout << entity + 0 << std::endl;

	auto velocity = c.GetComponent<Velocity>(entity);

	std::cout << velocity.x << std::endl;

	Entity e = c.CreateEntity();
	
	c.AddComponent(e, Player{}, Transform { .a = 10000.3245f });
	auto transform1 = c.GetComponent<Transform>(e);
	std::cout << transform1.a << std::endl;

	return 0;
}
