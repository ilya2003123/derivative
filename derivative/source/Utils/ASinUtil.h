#pragma once

#include "../Functions/functions.h"

namespace utils
{
	template<typename F>
	functions::ASinus<F> ASin(const F& f)
	{
		return functions::ASinus<F>(f);
	}

	double ASin(double x)
	{
		return asin(x);
	}
}