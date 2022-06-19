/*
 * logger.h
 * Copyright (C) 2022 tux <K3130>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class SingleLogger
{
	public:
		SingleLogger(const SingleLogger&) = delete; //delete copy
		SingleLogger& operator=(const SingleLogger&) = delete; //delete assignment
	
		static SingleLogger& Instance()
		{
			static SingleLogger instance;
			return instance;
		}
	
		void info(const std::string& aMessage)
		{
			m_os << "    info: " << aMessage << std::endl;
		}
		void warn(const std::string& aMessage)
		{
			m_os << "    warning: " << aMessage << std::endl;
		}

	private:
		SingleLogger() : m_os(std::cerr) {};
		std::ostream& m_os;
		
};

class ProxyLogger
{
	public:
		virtual void info() = 0;
		virtual void error() = 0;
};

class Logger : public ProxyLogger
{
	void info() override
	{
		std::cout << "info" << std::endl;
	}
	void error() override
	{
		std::cout << "error" << std::endl;
	}
};

class LevelLogger : public ProxyLogger
{
	public:
		LevelLogger(int aLevel, ProxyLogger *aLogger) : m_level(aLevel), m_logger(aLogger) {};
		void info() override
		{
			if(m_level > 0)
			{
				m_logger->info();
			}
		}
		void error() override
		{
			m_logger->error();
		}
	private:
		int m_level;
		ProxyLogger *m_logger;
};

#endif /* !LOGGER_H */
