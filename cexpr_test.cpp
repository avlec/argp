#include <initializer_list>

constexpr int test_cexpr(std::initializer_list<const char*> x)
{
	return (int) (*x.begin())[0];
}

constexpr std::initializer_list<const char*> make_cexpr(std::initializer_list<const char*> il)
{
	return il;
}

int main()
{
	constexpr int r1 = test_cexpr({ "why does this work," });

	constexpr auto broken = { "but this doesn't?" };
	constexpr int r2 = test_cexpr(broken);

	constexpr auto maybe = make_cexpr({"AHHHHHH"});

	return r1 + r2;
}
