#pragma once

#include "EventSystem.h"

namespace EM {
	template<class T>
	class IEventListener {
		public:
			IEventListener() {
				EventSystem::Subscribe(Action<const T&>{ &IEventListener::OnEvent, this });
			}

			~IEventListener() {
				EventSystem::Unsubscribe(Action<const T&>{ &IEventListener::OnEvent, this });
			}

			// Pure abstract class to be implemented by the client
			virtual void OnEvent(const T& event) = 0;
	};
}