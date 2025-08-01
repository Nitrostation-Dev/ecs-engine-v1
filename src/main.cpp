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

int main() {
	std::unique_ptr<EntityManager> em = std::make_unique<EntityManager>();
	std::unique_ptr<ComponentManager> cm = std::make_unique<ComponentManager>();

	cm->RegisterComponent<Velocity>();
	cm->RegisterComponent<Transform>();

	Transform t = {
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f,
	};
	Velocity v = {
		.name = 0
	};

	Entity entity = em->CreateEntity();

	cm->AddComponent(entity, t);
	cm->AddComponent(entity, v);

	while (true) {
		Transform& transform = cm->GetComponent<Transform>(entity);

		transform.x += 1.0f;

		printf("%f %f %f\n", transform.x, transform.y, transform.z);
	}
}
