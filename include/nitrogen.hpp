#pragma once

#include "common.hpp"
#include "entity_manager.hpp"
#include "component_array.hpp"
#include "component_manager.hpp"

#include <memory>
#include <optional>

class Coordinator {
private:
	
	std::unique_ptr<ComponentManager> m_componentManager;
	std::unique_ptr<EntityManager> m_entityManager;

public:

	void Init() {
		m_componentManager = std::make_unique<ComponentManager>();
		m_entityManager = std::make_unique<EntityManager>();
	} 

	Entity CreateEntity() {
		return m_entityManager->CreateEntity();
	}
	void DestroyEntity(Entity entity) {
		m_entityManager->DestroyEntity(entity);
		m_componentManager->EntityDestroyed(entity);
	}

	template<typename T>
	void RegisterComponent() {
		m_componentManager->RegisterComponent<T>();
	}

	template<typename T>
	void AddComponent(Entity entity, T component) {
		if (!m_componentManager->GetComponentId<T>())
			m_componentManager->RegisterComponent<T>();

		m_componentManager->AddComponent(entity, component);
	}

	template<typename... Ts>
	void AddComponent(Entity entity, Ts... components) { (..., AddComponent(entity, components)); }

	template<typename T>
	void RemoveComponent(Entity entity) { m_componentManager->RemoveComponent<T>(entity); }

	template<typename T>
	T& GetComponent(Entity entity) { return m_componentManager->GetComponent<T>(entity); }

	template<typename T>
	ComponentId GetComponentId(Entity entity) { return m_componentManager->GetComponentId<T>(entity); }


	template<typename... Ts>
	Entity SpawnEntity(Ts... args) {
		Entity entity = CreateEntity();

		(..., AddComponent(entity, args));

		return entity;
	}
};
