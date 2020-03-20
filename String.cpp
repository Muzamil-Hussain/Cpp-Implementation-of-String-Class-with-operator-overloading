/*
 * String.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: muzamil
 */

#include "String.h"

String::String() {
	str = NULL;
	size = 0;
}
String::String(char *str) {
	int siz = strlen(str);
	this->size = siz;
	this->str = new char[size];
	for (int i = 0; str[i] != '\0'; i++) {
		this->str[i] = str[i];
	}
}
String::String(const String &S) {
	this->size = S.size;
	this->str = new char[this->size];
	for (int i = 0; i < this->size; i++) {
		this->str[i] = S.str[i];
	}
}
String::String(int x) {
	this->size = x;
	this->str = new char[x];
}
int String::getSize() const {
	return size;
}

void String::setSize(int size) {
	this->size = size;
}

char* String::getStr() const {
	return str;
}

void String::setStr(char* str) {
	this->str = str;
}
char & String::operator[](int i) {
	if (i >= 0 && i < this->size) {
		return this->str[i];
	}
}
char &String::operator[](int i) const {
	if (i >= 0 && i < this->size) {
		return this->str[i];
	}
}
String String::operator+(const String &Str) {
	int tempsize = 0;
	for (int i = 0; Str.str[i] != '\0'; i++) {
		tempsize++;
	}

	String temp(size + tempsize);
	temp = this->str;
	for (int i = 0; i < tempsize; i++)
		temp[size + i] = Str.str[i];
	this = temp;

	return *this;
}
String String::operator+(const char &str) {
	int tempsize = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		tempsize++;
	}

	String temp(size + tempsize);
	temp = this->str;
	for (int i = 0; i < tempsize; i++)
		temp[size + i] = str[i];
	this = temp;

	return *this;
}
String String::operator+(char *&str) //tbc
		{
	int tempsize = 0;
	for (int i = 0; this->str[i] != '\0'; i++) {
		tempsize++;
	}

	String temp(size + tempsize);
	temp = str;
	for (int i = 0; i < tempsize; i++)
		temp[size + i] = this->str[i];
	this = temp;

	return *this;
}
bool String::operator!() {
	for (int i = 0; i < this->size; i++) {
		if (this->str[i] != '\0') {
			return false;
		}
	}
	return true;
}
String& String::operator=(const String&Str) {

	if (&Str == this) {
		return *this;
	}
	delete[] this->str;

	this->size = Str.size;
	this->str = new char[size];
	for (int i = 0; i < this->size; i++) {
		this->str[i] = Str.str[i];
	}
	return *this;
}
String& String::operator=(char* str) {
	if (this->size <= strlen(str)) {

		for (int i = 0; i < this->size; i++) {
			this->str[i] = str[i];
		}

	}
	return *this;
}
String& String::operator=(const string& strn) {
	this->str = strn;
	return *this;
}
bool String::operator==(const String& Str) const {
	if (this->size != Str.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (this->str[i] != Str.str[i]) {
			return false;
		}
	}
	return true;
}
bool String::operator==(const string& str) const {
	if (this->str != str) {
		return false;
	}
	return true;
}
bool String::operator==(char *str) const {
	if (this->size != strlen(str)) {
		return false;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->str[i] != str[i]) {
			return false;
		}
	}
	return true;
}
int String::operator()(char ch) {
	for (int i = 0; i < this->size; i++) {
		if (this->str[i] == ch) {
			return i;
		}
	}
	return -1;
}
//int String::operator()(const String& Str) {
//	for (int i=0;i<this->size;i++)
//	{
//
//	}
//}
//int String::operator()(const string&) {
//
//}
//int String::operator()(char *) {
//
//}
String String::operator*(int a)
{

}
int String::length() {
	return this->size;
}

String::~String() {
	delete[] str;
}
ostream& operator<<(ostream& input, const String& obj) {
	for (int i=0;i<obj.getSize();i++)
	{
		input<<obj[i]<<" ";
	}
	return input;
}
istream& operator>>(istream& ouput, String& obj) {
	for (int i=0;i<obj.getSize();i++)
	{
		ouput<<obj[i];
	}
	return  ouput;
}
