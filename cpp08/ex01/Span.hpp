#include <vector>
#include <string>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;

	public:
		Span();
		Span(int n);
		Span(const Span& s);
		Span& operator=(const Span& s);
		~Span();

		void addNumber(int n);
		void randomFill();
		int shortestSpan();
		int longestSpan();
		void printVector();
		class ContainerFullException : public std::exception
		{
			private:
				std::string _msg;
			public:
				explicit ContainerFullException(const std::string& msg);
				virtual ~ContainerFullException() throw();
				const char* what() const throw();
		};
};
