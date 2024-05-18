#pragma once
#include "action_interface.h"

namespace EM {
	template<class... _params>
	class _action_impl<EActionType::STATIC, _params...> {
	private:
		void(*action)(_params...);
	public:
		_action_impl() :
			action(nullptr)
		{}

		_action_impl(void (*_action)(_params...)) :
			action(_action)
		{}

		void execute(_params... params) {
			(*action)(params...);
		}

		void operator()(_params... params) {
			execute(params...);
		}

		void* getObj() { return NULL; }
		void* getActionPtr() { return action; }
	};
}