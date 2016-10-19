#include "stdafx.h"
#include "BlackAndWhite.h"


namespace mastermind {

	BlackAndWhite::BlackAndWhite(unsigned int blacks, unsigned int whites) :
	black(blacks), white(whites)
	{
	}

	std::wstring BlackAndWhite::toString() {
		std::wstring str(L"");
		str.append(L"black: ");
		str.append(std::to_wstring(this->black));
		str.append(L" white: ");
		str.append(std::to_wstring(this->white));
		return str;
	}

	std::wstring BlackAndWhite::toStringWithoutDescription() {
		std::wstring str(L"");
		str.append(std::to_wstring(this->black));
		str.append(L" ");
		str.append(std::to_wstring(this->white));
		return str;
	}

	bool BlackAndWhite::operator==(const BlackAndWhite& rhs) {
		bool result = false;
		if (this->white == rhs.white
			&& this->black == rhs.black) {
			result = true;
		}
		return result;
	}

	bool BlackAndWhite::operator!=(const BlackAndWhite& rhs) {
		return !(*this == rhs);
	}
}