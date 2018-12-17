#pragma once
#include <iostream>
#include <exception>
#include <string>

class unknown_color : public std::exception {
public:
	unknown_color(const std::string & name) :
		s{ std::string{"Unknown color ["}+name + "]" }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class end_of_file : public std::exception {
public:
	end_of_file() :
		s{ std::string{"File has ended" } }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class invalid_position : public std::exception {
public:
	invalid_position(const std::string & s) :
		s{ std::string{"Position ["}+s + "] is false" }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_shape : public std::exception {
public:
	unknown_shape(const std::string &name) :
		s{ std::string{"Shape [" + name + "] is incorrect" } }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_file : public std::exception {
public:
	unknown_file() :
		s{ std::string{"File could not open"} }
	{}
	const char * what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};