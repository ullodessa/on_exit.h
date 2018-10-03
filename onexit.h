#pragma once

enum class SomeClass {};

template <typename F>
class ScopeGuard
{
	F f;
public:
	ScopeGuard(F && _f) : f(std::move(_f)) {}
	~ScopeGuard() { f(); }
};

template <typename Fun>
ScopeGuard<Fun>
operator+(SomeClass s, Fun && f)
{
	return ScopeGuard <Fun>(std::forward<Fun>(f));
};
#define CONIMPL(a,b) a##b
#define CON(a,b) CONIMPL(a,b)
#define AVAR(a) CON(a,__LINE__)
#define ON_EXIT auto AVAR(anonymous) = SomeClass() + [&]()

