/**/
template <class T, class=void>
struct has_method : std::false_type {};

template <class T>
struct has_method<T, std::void_t<decltype(std::declval<T&>()->bap)>> : std::true_type {};
/**/


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

