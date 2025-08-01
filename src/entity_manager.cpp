#include "../include/entity_manager.hpp"
#include <iostream>

EntityManager::EntityManager() {
	for (Entity e = 0; e < MAX_ENTITIES; ++e)
		m_availableEntities.push(e);
}

Entity EntityManager::CreateEntity() {
	assert(m_livingEntitiesCount < MAX_ENTITIES && "Max amount of living entities reached.");

	Entity e = m_availableEntities.front();
	m_availableEntities.pop();

	++m_livingEntitiesCount;

	return e;
}

void EntityManager::DestroyEntity(Entity entity) {
	assert(entity < MAX_ENTITIES && "Entity out of range");

	m_availableEntities.push(entity);
	--m_livingEntitiesCount;
}
