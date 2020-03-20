/*
 * String.h
 *
 *  Created on: Apr 9, 2018
 *      Author: muzamil
 */

#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class String {
private:
	char *str;
	int size;
public:
	String();
    String(char *str);
    String(const String &);
    String(int x);
	int getSize() const;
	void setSize(int size);
	char* getStr() const;
	void setStr(char* str);
    char &operator[](int i);
    char &operator[](int i)const;
    String operator+(const String &str);
    String operator+(const char &str);
    String operator+(char *&str);
    bool operator!();
    String& operator=(const String&);
    String& operator=(char*);
    String& operator=(const string&);
    bool operator==(const String&)const;
    bool operator==(const string&)const;
    bool operator==(char *)const;
    int operator()(char);
    int operator()(const String&);
    int operator()(const string&);
    int operator()(char *);
    String operator*(int a);
    int length();
	~String();
};
ostream& operator<<(ostream& input, const String&);
istream& operator>>(istream& ouput, String&);
#endif /* STRING_H_ */
