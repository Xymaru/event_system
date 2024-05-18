#pragma once
#include "action_interface.h"

namespace EM {
	template<class... _params>
	class _action_impl<EActionType::CLASS, _params...> {
	private:
		void (Callable::* action)(_params...);
		Callable* obj;
	public:
		_action_impl() :
			action(nullptr),
			obj(nullptr)
		{}

		template<class T>
		_action_impl(void (T::* _action)(_params...), T* _obj) :
			action((void (Callable::*)(_params...))_action),
			obj((Callable*)_obj)
		{}

		_action_impl(void* _action, void* _obj) :
			action(_action),
			obj((Callable*)_obj)
		{}

		void execute(_params... params) {
			(obj->*action)(params...);
		}

		void operator()(_params... params) {
			execute(params...);
		}

		void* getObj() { return obj; }
		void* getActionPtr() { return (void*&)action; }
	};
}