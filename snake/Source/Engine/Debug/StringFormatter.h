#ifndef STRING_FORMATTER_H
#define STRING_FORMATTER_H

#include <iostream>
#include <string>
#include <sstream>

class StringFormatter
{
public:
	template<typename... TParameters>
	static std::string Combine(const std::string& message, TParameters... parameters)
	{
		std::ostringstream string_stream;

		size_t char_index = 0;
		size_t parameter_index = 0;

		while (char_index < message.length())
		{
			const size_t placeholder_char_index = message.find('$', char_index);

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

private:
	template <typename TParameter, typename... TParameters>
	static std::string ParametersTupleToString(const size_t index, TParameter parameter, TParameters... parameters)
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

#endif // !STRING_FORMATTER_H