#pragma once

#include "../Operations/operations.h"
#include "../Functions/functions.h"
#include "General.h"
#include "../Utils/Utils.h"

template <typename F>
class Derivative<functions::ACotangent<F>> 
{
public:
	Derivative(const functions::ACotangent<F>& f)
		: m_f(f.m_f), m_df(f.m_f)
	{
	}

	double operator()(double x) const
	{
		double fx = m_f(x);
		return (-m_df(x) / (1 + fx * fx));
	}

	F m_f;
	Derivative<F> m_df;

	typedef operations::Divide<operations::Multiply<functions::Const,
		typename Derivative<F>::Type>, operations::Add<functions::Const, operations::Multiply<F, F>>> Type;
	Type expression() const
	{
		return ((functions::Const(-1) * m_df.expression()) / (functions::Const(1) + utils::Sqr(m_f)));
	}

};