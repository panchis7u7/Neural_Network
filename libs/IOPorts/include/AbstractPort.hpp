#pragma once
#include <string>
#include <vector>
#include <string.h>
#include <include/BufferQueue.hpp>

class AbstractPort
{
public:
	AbstractPort(const AbstractPort &) = delete;

	//###################################################################################################
	// Polymorphic operations.
	//###################################################################################################

	virtual void flush() = 0;
	virtual int connect() = 0;
	virtual std::string read() = 0;
	virtual std::size_t write(void *data, std::size_t data_len) = 0;
	static std::vector<std::string> getAvailablePorts();

	//###################################################################################################
	// Operator Overloading.
	//###################################################################################################

	friend const char *operator<<(AbstractPort &port, const char *text) {
		port.write((void *)text, strlen(text));
		return text;
	}

	friend void operator>>(AbstractPort &port, std::string &str) {
		str += port.read();
	}

protected:
	AbstractPort(){};
	virtual ~AbstractPort(){};
	BufferQueue* m_bqBuffer;

	std::string m_sError;
};