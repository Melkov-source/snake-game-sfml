#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

namespace Debug
{
	const std::string DEFALUT_COLOR = "\033[0m";
	const std::string WHITE_COLOR = "\033[1;36;40m";
	const std::string YELLOW_COLOR = "\033[1;33;40m";
	const std::string RED_COLOR = "\033[1;31;40m";

	class Logger
	{
	public:
		enum LOG_PRIORITY
		{
			NONE = 0,
			LOG = 1,
			WARNING = 2,
			ERROR = 3,
			ALL = 4
		};

		template <typename... TParameters>
		static void Log(const std::string& message, TParameters... parameters)
		{
			PrintMessage(WHITE_COLOR, message, parameters...);
		}

		template <typename... TParameters>
		static void Warning(const std::string& message, TParameters... parameters)
		{
			PrintMessage(YELLOW_COLOR, message, parameters...);
		}
		template <typename... TParameters>
		static void Error(const std::string& message, TParameters... parameters)
		{
			PrintMessage(RED_COLOR, message, parameters...);
		}

	private:
		template <typename... TParameters>
		static void PrintMessage(const std::string& color_code, const std::string& message, TParameters... parameters)
		{
			const auto current_time = GetCurrentTime();

			std::string time = "[" + current_time + "] ";

			std::cout << time << color_code << FormatMessage(message, parameters...) << DEFALUT_COLOR << "\n";
		}

		static std::string GetCurrentTime()
		{
			time_t currentTime;
			struct tm timeInfo;
			time(&currentTime);
			localtime_s(&timeInfo, &currentTime);

			int hours = timeInfo.tm_hour;
			int minutes = timeInfo.tm_min;
			int seconds = timeInfo.tm_sec;

			std::ostringstream formattedTime;
			formattedTime << std::setfill('0') << std::setw(2) << hours << ":"
				<< std::setfill('0') << std::setw(2) << minutes << ":"
				<< std::setfill('0') << std::setw(2) << seconds;

			return formattedTime.str();
		}

		template<typename... TParameters>
		static std::string FormatMessage(const std::string& message, TParameters... parameters)
		{
			std::ostringstream string_stream;

			size_t char_index = 0;
			size_t parameter_index = 0;

			while (char_index < message.length())
			{
				size_t placeholder_char_index = message.find("$", char_index);

				if (placeholder_char_index == std::string::npos)
				{
					string_stream << message.substr(char_index);
					break;
				}

				string_stream << message.substr(char_index, placeholder_char_index - char_index);

				if (parameter_index < sizeof...(parameters))
				{
					string_stream << ParametersTupleToString(parameter_index, std::forward<TParameters>(parameters)...);

					parameter_index++;
				}

				char_index = placeholder_char_index + 1;
			}

			return string_stream.str();
		}

		template <typename TParameter, typename... TParameters>
		static std::string ParametersTupleToString(size_t index, TParameter parameter, TParameters... parameters)
		{
			if (index == 0)
			{
				std::ostringstream string_stream;
				string_stream << parameter;
				return string_stream.str();
			}

			return ParametersTupleToString(index - 1, parameters...);
		}

		static std::string ParametersTupleToString(size_t index)
		{
			return "";
		}
	};
}


#endif // !LOGGER_H