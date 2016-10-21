#include "stdafx.h"
#include "BlackAndWhite.h"

#include <cassert>
namespace mastermind {
	namespace logic {
		const BlackAndWhite BlackAndWhite::WIN_STICKS = BlackAndWhite(SLOT_COUNT, 0);

		BlackAndWhite::BlackAndWhite(std::size_t blacks, std::size_t whites) :
			black(blacks), white(whites)
		{
		}

		BlackAndWhite::BlackAndWhite(std::list<int> &list) {
			if (list.size() != 2) {
				throw std::invalid_argument("only two tuple allowed!");
			}
			const size_t size = list.size();
			std::list<int>::iterator iter = list.begin();
			black = *iter;
			++iter;
			white = *iter;
			assert(iter == list.end());
		}

		std::wstring BlackAndWhite::toString() {
			std::wstring str(L"");
			str.append(L"black: ");
			str.append(std::to_wstring(this->black));
			str.append(L" white: ");
			str.append(std::to_wstring(this->white));
			return str;
		}
		std::wstring BlackAndWhite::toString() const {
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

		const bool BlackAndWhite::operator==(const BlackAndWhite& rhs) const {
			bool result = false;
			if (this->white == rhs.white && this->black == rhs.black) {
				result = true;
			}
			return result;
		}

		bool BlackAndWhite::operator!=(const BlackAndWhite& rhs) {
			return !(*this == rhs);
		}

		std::size_t BlackAndWhite::getWhite() {
			return this->white;
		}

		std::size_t BlackAndWhite::getBlack() {
			return this->black;
		}
	}
}