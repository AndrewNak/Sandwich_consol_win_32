/*"Сэндвич" — это строка, образованная двумя одинаковыми концами и отличной от концов серединой. 
Например: AABBBAA 
Обратите внимание, что левый и правый концы сэндвича идентичны как по длине, так и по повторяющимся символам.
Следующее не является сэндвичем с мороженным : 
BBBBB - вы не можете иметь только мороженное (без сэндвича) 
AAACCCAA - вы не можете иметь неравные по длине окончания в сэндвиче 
AACDCAA - вы не можете иметь начинку из разных символов 
A - ваш сэндвич не может быть менее трех символов" 

Далее идет проверка по условиям*/


#include <iostream>
#include <string>
using namespace std;

//проверка на состав "сендвича", количество компонентов, и наличия хлеба по обеям сторонам
bool checkcomposition(string sandwich) 
{
	//проверка на колличество компонентов(должно быть не меньше трех)
	if (sandwich.size()<3)
	{
		cout << "FALSE		в составе сендвича не может быть меньше трех компонентов! " << endl;
		return false;
	}
	cout << "OK		в составе сендвича больше трех компонентов! " << endl;
	//проверка наличие хлеба с двух сторон
	if (sandwich[0]!=sandwich[sandwich.size()-1])
	{
		cout << "FALSE		в составе сендвича хлеб с обеих сторон должен быть одинаков! " << endl;
		return false;
	}
	cout << "OK		в составе сендвича хлеб присутствует с обеих сторон! " << endl;

	//если проверка найдет разные компоненты, функция вернет ТРУ
	for (int i = 0; i < sandwich.size(); i++)
	{
		if (sandwich[0] != sandwich[i])
		{
			cout << "OK		сендвич состоит из разных компонентов! " << endl;
			return true;
		}
	}
	cout << "FALSE		cендвич не должен состоять из одного хлеба! " << endl;
	return false;
}
//проверка начинки сендвича, начинка должна состоять из одного компанента.
bool checkstuffing(string sandwich, int &a, int &b)
{
	for (int i = a; i < sandwich.size()-b; i++)
	{
		if (sandwich[i]!=sandwich[(sandwich.size()-1)-(b)])
		{
			cout << "FALSE		начинка должна быть с одного компанента! " << endl;
			return false;
		}
		
	}
	cout << "OK		начинка состоит из одного компанента! " << endl;
	return true;
}
//подсчет колличества хлеба в сендвиче,хлеба с обех сторон должно быть поровну
bool checkSizeBread(bool V, string sandwich, int &a, int &b)
{
	if (V)
	{
		int c = sandwich.size();
		while (sandwich[0] == sandwich[a])
		{
			a++;
		}
		while (sandwich[(sandwich.size())-1] == sandwich[c-2])
		{
			c--;
			b++;
		}

		if (a == b)
		{
			cout << "OK		cендвич состоит из равных кусков хлеба!" << endl;
			return true;
		}
		else
		{
			cout << "FALSE		сендвич состоит из неравных кусков хлеба" << endl;
			return false;
		}
	}
	else
	{
		return false;
	}
	
}

int main()
{
	setlocale(LC_ALL, "ru");
	
	cout << "\"Сэндвич\" — это строка, образованная двумя одинаковыми концами и отличной от концов серединой. " << endl;
	cout << "\tНапример: AABBBAA \nОбратите внимание, что левый и правый концы сэндвича идентичны как по длине, так и по повторяющимся символам." << endl;
	cout << "Следующее не является сэндвичем с мороженным : " << endl;
	cout << "\tBBBBB - вы не можете иметь только мороженное (без сэндвича) \n\tAAACCCAA - вы не можете иметь неравные по длине окончания в сэндвиче \n\tAACDCAA - вы не можете иметь начинку из разных символов \n\tA - ваш сэндвич не может быть менее трех символов" << endl;
	
	
	string sandwich; //переменая для хранения самого "сендвича"	
	bool allCheck; //переменная для хранения результата всех проверок "сендвича"
		

	do
	{
		int startSymbols = 1;//переменая подсчета символов сначала "сендвича"
		int endSymbols = 1;//переменныя подсчета символов с конца "сендвича"


		cout << "Введите сендвич: " << endl;
		cin >> sandwich;

		
		allCheck = checkSizeBread(checkcomposition(sandwich), sandwich, startSymbols, endSymbols) && checkstuffing(sandwich, startSymbols, endSymbols);
	} while (!allCheck);
	cout << "\t\tСендвич удался!" << endl;
	system("pause");
	return 0;
}

