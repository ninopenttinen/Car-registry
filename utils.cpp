#include "utils.h"

bool isNumeric(const string& s) {
	bool isNumeric = true;
	for_each(s.begin(), s.end(), [&](char c)
		{
			if (!std::isdigit(c)) {
				isNumeric = false;
			}
		}
	);
	return isNumeric;
}