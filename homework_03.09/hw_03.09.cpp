#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
	char* model;
	char* country;
	char* colour;
	int year;
	double price;

public:
	Car()
	{
		model = nullptr;
		country = nullptr;
		colour = nullptr;
		year = 0;
		price = 0.0;
	}
	Car(const char* mod, const char* countr, const char* col, int y, double pr)
	{
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
		country = new char[strlen(countr) + 1];
		strcpy_s(country, strlen(countr) + 1, countr);
		colour = new char[strlen(col) + 1];
		strcpy_s(colour, strlen(col) + 1, col);
		year = y;
		price = pr;
	}

	~Car()
	{
		delete[] model;
		delete[] country;
		delete[] colour;
	}

	void init()
	{
		char buffer[100];

		cout << "Enter model: ";
		cin.getline(buffer, 100);
		model = new char[strlen(buffer) + 1];
		strcpy_s(model, strlen(buffer) + 1, buffer);

		cout << "Enter country: ";
		cin.getline(buffer, 100);
		country = new char[strlen(buffer) + 1];
		strcpy_s(country, strlen(buffer) + 1, buffer);

		cout << "Enter colour: ";
		cin.getline(buffer, 100);
		colour = new char[strlen(buffer) + 1];
		strcpy_s(colour, strlen(buffer) + 1, buffer);

		cout << "Enter year: ";
		cin >> year;
		cout << "Enter price: ";
		cin >> price;
	}

	void print()
	{
		cout << "Car info: " << endl;
		cout << "Model: " << model << endl;
		cout << "Country: " << country << endl;
		cout << "Colour: " << colour << endl;
		cout << "Year: " << year << endl;
		cout << "Price: " << price << endl;
	}

	char* get_model()
	{
		return model;
	}

	void set_model(const char* mod)
	{
		if (model != nullptr)
		{
			delete[] model;
		}
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
	}

	char* get_country()
	{
		return country;
	}

	void set_country(const char* countr)
	{
		if(country != nullptr)
		{
			delete[] country;
		}
		country = new char[strlen(countr) + 1];
		strcpy_s(country, strlen(countr) + 1, countr);
	}

	char* get_colour()
	{
		return colour;
	}

	void set_colour(const char* col)
	{
		if(colour != nullptr)
		{
			delete[] colour;
		}
		colour = new char[strlen(col) + 1];
		strcpy_s(colour, strlen(col) + 1, col);
	}

	int get_year()
	{
		return year;
	}

	void set_year(int y)
	{
		year = y;
	}

	double get_price()
	{
		return price;
	}

	void set_price(double pr)
	{
		price = pr;
	}
};

int main()
{

	Car car1;
	car1.init();
	car1.print();

	Car car2("Toyota", "Japan", "Red", 2020, 30000.0);
	car2.print();

	car2.set_colour("Blue");
	car2.set_price(28000);
	cout << endl<< "After updates:" << endl;
	car2.print();
	return 0;
}