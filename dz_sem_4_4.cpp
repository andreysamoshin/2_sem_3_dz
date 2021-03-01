#include <iostream>

int main()
{

	std::cout << "Please, enter the number of the month" << std::endl;

	enum class Month
	{
		january,
		february,
		march,
		april,
		may,
		june,
		july,
		august,
		september,
		october,
		november,
		december
	};

	void num(const Month& month);
	{
		switch (month)
		{
		case Month::january:
		case Month::march:
		case Month::may:
		case Month::july:
		case Month::august:
		case Month::october:
		case Month::december:
			std::cout << "31 days"<< std::endl;
		break;
		case Month::february:
			std::cout << "28 days" << std::endl;
			break;

		case Month::april:
		case Month::june:
		case Month::september:
		case Month::november:
			std::cout << "30 days" << std::endl;
			break;
		}
	}



	system("pause");
	return 0;
}