#pragma once

#include <typeinfo>
#include <typeindex>

#include <unordered_map>
#include <vector>

#include <function/ActionPack.h>

namespace EM {
	class EventSystem {
	private:
		typedef std::unordered_map<std::type_index, ActionPack<>> EventMap;

		static EventMap m_EventMap;
	public:
		template<class T>
		static void Subscribe(Action<const T&> action) {
			m_EventMap[typeid(T)].addAction({ action.getActionPtr(), action.getObj() });
		}

		template<class T>
		static void Unsubscribe(Action<const T&> action) {
			m_EventMap[typeid(T)].removeObject(action.getObj());
		}

		template<class T>
		static void Trigger(const T& ev) {
			EventMap::iterator it = m_EventMap.find(typeid(T));

			if (it != m_EventMap.end()) {
				((ActionPack<const T&>*)(void*)&it->second)->execute(ev);
			}
		};
	};
}