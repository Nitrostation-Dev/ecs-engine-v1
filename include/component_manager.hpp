#pragma once

#include "common.hpp"
#include "component_array.hpp"

#include <array>
#include <memory>
#include <unordered_map>
class ComponentManager {
private:
	std::unordered_map<const char*, ComponentId> m_componentIdsMap{};
	std::unordered_map<ComponentId, std::shared_ptr<IComponentArray>> m_componentArrays{};

	ComponentId m_nextComponentId;

public:
	template <typename T>
	void RegisterComponent() {
		const char* typeName = typeid(T).name();

		m_componentIdsMap.insert({
			typeName,
			m_nextComponentId
		});
		m_componentArrays.insert({
			m_nextComponentId,
			std::make_unique<ComponentArray<T>>()
		});

		++m_nextComponentId;
	}
};
