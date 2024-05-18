#pragma once
#include "action_interface.h"

namespace EM {
	template<class... _params>
	class _action_impl<EActionType::BOTH, _params...> {
	private:
		void* action;
		Callable* obj;
	public:
		typedef void(Callable::* MemFunc)(_params...);
		typedef void(*StaticFunc)(_params...);

		_action_impl() :
			action(nullptr),
			obj(nullptr)
		{}

		template<class T>
		_action_impl(void (T::* _action)(_params...), T* _obj) :
			action((void*&)_action),
			obj((Callable*)_obj)
		{}

		_action_impl(void* _action, void* _obj) :
			action(_action),
			obj((Callable*)_obj)
		{}

		_action_impl(void(*action)(_params...)) :
			action(action),
			obj(nullptr)
		{}

		void execute(_params... params) {
			if (obj) {
				(obj->*((MemFunc&)action))(params...);
			}
			else {
				(*((StaticFunc)action))(params...);
			}
		}

		void operator()(_params... params) {
			execute(params...);
		}

		void* getObj() { return obj; }
		void* getActionPtr() { return action; }
	};
}