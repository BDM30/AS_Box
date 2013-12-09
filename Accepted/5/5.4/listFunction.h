#pragma once

namespace list {
	struct PhoneBook {
		char name[10];
		int nameLength;
		char number[10];
		int numberLength;
		PhoneBook *next;
	};
	PhoneBook *first(char number [], char name []);
	void add(PhoneBook **end, char number [], char name []);
	void existNumber(PhoneBook *begin, char number []);
	void existName(PhoneBook *begin, char name []);
}