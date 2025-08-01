#pragma once

#include "nitrogen.hpp"

#include <cassert>
#include <queue>

class EntityManager {
private:
	std::queue<Entity> m_availableEntities;
	Entity m_livingEntitiesCount;

public:

	EntityManager();
	
	Entity CreateEntity();
	void DestroyEntity(Entity entity);
};
