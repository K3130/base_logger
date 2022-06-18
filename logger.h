/*
 * logger.h
 * Copyright (C) 2022 tux <tux@tux-pc>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class Logger
{
	public:
		Logger(const Logger&) = delete; //delete copy
		Logger& operator=(const Logger&) = delete; //delete assignment
	
		static Logger& Instance()
		{
			static Logger instance;
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
		Logger() : m_os(std::cerr) {};
		std::ostream& m_os;
		
};
#endif /* !LOGGER_H */
