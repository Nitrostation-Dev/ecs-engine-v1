#pragma once

#include "common.hpp"

#include <array>
#include <cassert>
#include <unordered_map>

class IComponentArray {
public:
	virtual ~IComponentArray() = default;
	virtual void EntityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
private:
	std::array<T, MAX_ENTITIES> m_components;
	std::unordered_map<Entity, size_t> m_entityToIndexMap;
	std::unordered_map<size_t, Entity> m_indexToEntityMap;

	size_t m_size;

public:

	void InsertData(Entity entity, T component) {
		assert(entity < MAX_ENTITIES && "Entity out of range");
		
		size_t newSize = m_size;
		m_components[newSize] = component;

		m_entityToIndexMap[entity] = newSize;
		m_indexToEntityMap[newSize] = entity;

		++m_size;
	}

	void RemoveData(Entity entity) {
		assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Removing Non-existant component");

		size_t indexOfRemovedEntity = m_entityToIndexMap[entity];
		size_t indexOfLastElement = m_size - 1;
		m_components[indexOfRemovedEntity] = m_components[indexOfLastElement];

		Entity entityOfLastElement = m_indexToEntityMap[indexOfLastElement];
		m_entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
		m_indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

		m_entityToIndexMap.erase(entity);
		m_indexToEntityMap.erase(indexOfLastElement);

		--m_size;
	}

	T& GetData(Entity entity) {
		assert(entity < MAX_ENTITIES && "Entity out of range.");

		return m_components[m_entityToIndexMap[entity]];
	}

	void EntityDestroyed(Entity entity) override {
		if (m_entityToIndexMap.find(entity) != m_entityToIndexMap.end())
			RemoveData(entity);
	}
};
