#pragma once

#include "action_impl/action_class_impl.h"
#include "action_impl/action_static_impl.h"
#include "action_impl/action_both_impl.h"

namespace EM {
	// Class-only functions
	template<class... _params>
	using CAction = _action_impl<EActionType::CLASS, _params...>;

	// Static-only functions
	template<class... _params>
	using SAction = _action_impl<EActionType::STATIC, _params...>;

	// Class and static function
	template<class... _params>
	using BAction = _action_impl<EActionType::BOTH, _params...>;

	// Default action type
	template<class... _params>
	using Action = BAction<_params...>;
}