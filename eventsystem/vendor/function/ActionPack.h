#pragma once
#include <vector>
#include "Action.h"

namespace EM {
	template<EActionType AT, class... _params >
	class _actionPack {
	private:
		std::vector<_action_impl<AT, _params...>> actions;
	public:
		_actionPack() {

		}

		void addAction(_action_impl<AT, _params...> action) {
			actions.emplace_back(action);
		}

		void removeObject(void* obj) {
			size_t size = actions.size();

			for (size_t i = 0; i < size; i++) {
				if (actions[i].getObj() == obj) {
					actions.erase(actions.begin() + i);
					break;
				}
			}
		}

		void execute(_params... params) {
			size_t size = actions.size();

			for (size_t i = 0; i < size; i++) {
				actions[i](params...);
			}
		}

		void operator+=(_action_impl<AT, _params...> action) {
			addAction(action);
		}

		void operator-=(void* obj) {
			removeObject(obj);
		}

		void operator()(_params... params) {
			execute(params...);
		}
	};

	template<class... _params>
	using CActionPack = _actionPack<EActionType::CLASS, _params...>;

	template<class... _params>
	using SActionPack = _actionPack<EActionType::STATIC, _params...>;

	template<class... _params>
	using BActionPack = _actionPack<EActionType::BOTH, _params...>;

	// Default action packing
	template<class... _params>
	using ActionPack = BActionPack<_params...>;
}