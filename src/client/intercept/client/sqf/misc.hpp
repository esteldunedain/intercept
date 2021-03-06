/*!
@file
@author Verox (verox.averre@gmail.com)
@author Nou (korewananda@gmail.com)
@author Glowbal (thomasskooi@live.nl)

@brief Misc function wrappers.

This is basically stuff that has not been categorized yet. Compared to uncategorized.hpp,
which is functions that lack a clear category.

https://github.com/NouberNou/intercept
*/
#pragma once
#include "shared.hpp"
#include "client\client.hpp"
#include "shared\client_types.hpp"
#include<vector>

using namespace intercept::types;

namespace intercept {
	namespace sqf {
		struct game_resolution
		{
			vector2 resolution;
			vector2 viewport;
			float aspect_ratio;
			float ui_scale;
		};
    }
}
