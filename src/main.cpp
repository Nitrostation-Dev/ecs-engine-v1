#include <nitrogen.hpp>

#include <cstdio>
#include <memory>

struct Velocity {
	const char* name;
};

struct Transform {
	float x;
	float y;
	float z;
};

struct Test {
	NG_Float a;
};

int main() {
	std::unique_ptr<EntityManager> em = std::make_unique<EntityManager>();
	std::unique_ptr<ComponentManager> cm = std::make_unique<ComponentManager>();

	cm->RegisterComponent<Velocity>();
	cm->RegisterComponent<Transform>();
	cm->RegisterComponent<Test>();

	Transform t = {
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f,
	};
	Velocity v = {
		.name = 0
	};

	Test test = { .a = 100.0f };

	Entity entity = em->CreateEntity();

	cm->AddComponent(entity, t);
	cm->AddComponent(entity, v);
	cm->AddComponent(entity, test);

	while (true) {
		Test& test = cm->GetComponent<Test>(entity);

		printf("%f \n", test.a.get());
	}
}
