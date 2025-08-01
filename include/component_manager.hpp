#pragma once

#include "common.hpp"
#include "component_array.hpp"

#include <array>
#include <iostream>
#include <memory>
#include <unordered_map>

class ComponentManager {
private:
	std::unordered_map<const char*, ComponentId> m_componentIdsMap{};
	std::unordered_map<ComponentId, std::shared_ptr<IComponentArray>> m_componentArrays{};

	ComponentId m_nextComponentId = 0;

public:
	template <typename T>
	void RegisterComponent() {
		const char* typeName = typeid(T).name();
		
		ComponentId id = m_nextComponentId;
		m_componentIdsMap.insert({
			typeName,
			id	
		});
		m_componentArrays.insert({
			id,
			std::make_unique<ComponentArray<T>>()
		});

		std::cout << "Registered Component to ECS: " << typeName << " with id: " << id + 0 << std::endl;

		++m_nextComponentId;
	}

	template<typename T>
	ComponentId GetComponentId() {
		const char* typeName = typeid(T).name();

		assert(m_componentIdsMap.find(typeName) != m_componentIdsMap.end() && "Component Not Registered.");

		return m_componentIdsMap[typeName];
	}

	template<typename T>
	void AddComponent(Entity entity, T component) {
		GetComponentArray<T>()->InsertData(entity, component);
	}
	
	template<typename T>
	void RemoveComponent(Entity entity) {
		GetComponentArray<T>()->RemoveData(entity);
	}

	template<typename T>
	T& GetComponent(Entity entity) {
		return GetComponentArray<T>()->GetData(entity);
	}

	void EntityDestroyed(Entity entity) {
		for (auto const& pair : m_componentArrays) {
			auto const& component = pair.second;
			component->EntityDestroyed(entity);
		}
	}

private:
	
	template <typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray() {
		const char* typeName = typeid(T).name();
		assert(m_componentIdsMap.find(typeName) != m_componentIdsMap.end() && "Component Not Registered.");

		return std::static_pointer_cast<ComponentArray<T>>(m_componentArrays[m_componentIdsMap[typeName]]);
	}
};
