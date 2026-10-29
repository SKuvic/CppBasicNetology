#ifndef Leaver_h
#define Leaver_h
#include <string>

class __declspec(dllexport) Leaver {
public:
	Leaver() = default;

	std::string leave(const std::string& name);
};

#endif
