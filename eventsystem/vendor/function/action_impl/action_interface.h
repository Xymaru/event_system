#pragma once

namespace EM {
	class Callable {};

	enum class EActionType {
		CLASS,
		STATIC,
		BOTH,
		NONE
	};

	template<EActionType AT, class... _params>
	class _action_impl {
	public:
		_action_impl();

		void execute(_params... params);

		void operator()(_params... params);

		void* getObj();
		void* getActionPtr();
	};
}