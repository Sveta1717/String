// String.cpp : Создать свой собственный супер-удобный класс String,
//который позволит работать со строками именно так, как вы до сих пор об этом только мечтали!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <ctime>
using namespace std;


class String
{
	char* text;
	unsigned int length;
	unsigned int capacity;

public:
	String(const char* text, unsigned int capacity = 80) 
	{
		Initialize(text);
	}

	String()
	{
		Initialize("*");
	}

	explicit String(unsigned int capacity)
	{
		Initialize("", capacity);
	}

	String(const String& original)
	{
		Initialize(original.text, original.capacity);
	}

	~String()
	{
		delete[] text;
	}

	// геттеры-сеттеры	

	void SetString(const char* text)
	{
		length = strlen(text);
		if (length >= capacity)
		{
			delete[] this->text;
			capacity = length + 20;
			this->text = new char[capacity];
		}
		strcpy_s(this->text, length + 1, text);
	}

	const char* GetCharArray() const
	{
		return text;
	}

	int GetLength() const // количество символов
	{
		return length;
	}

	// метода SetLength не должно быть!

	int GetCapacity() const // резерв памяти
	{
		return capacity;
	}

	void Clear()
	{
		text[0] = '\0';
		length = 0;
	}

	void ShrinkToFit()
	{
		if (length + 1 == capacity)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}

	char GetCharAt(unsigned int index)
	{			
		if (index > 0 && index < length + 1)
		{
			return text[index - 1];
		}
		else
		{
			return -1; 
		}
	}	

	void Print()
	{
		cout << GetCharArray() << "\n";
	}

	void PrintLn()
	{
		cout << GetCharArray();
		for (int i = 0; i < 2; i++)
		{
			cout << endl; 
			//getline()
		}				
	}	

	void GetLine()
	{
		cout << "Enter the line\n";			
		/*char line[1000];
		cin.getline(line, sizeof(line), '\n');	*/ // массив char
		string line;
		getline(cin, line); // string
		//cin.get();
	    cout << line << "\n";		
	}

	int CompareTo(const String& text) const  
	{
		cout << "Enter the line\n";
		string line;
		getline(cin, line);
		int res;

		res = line.compare(this->text);
		
		return res;		
	}

	 int CompareTo(const char* line) const
	 {		 
		for (int i = 0;  i < length + 1; i++)
		{
			if (this->text[i] == line[i] && sizeof(this->text) == sizeof(line))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}	
	 }	 

	 void Concat(const String& text) const
	 {	
		 cout << "Enter the line\n";
		 string line;		 
		 getline(cin, line);

		 cout << this->text + line;			 
	 }

	 void Concat(const char* line)
	 {		
		 cout << "Enter the line\n";
		 string text = this->text;
		 cout << text.append(line); // так лучше?
		 /*int length1 = 0;        // или так?
		 int length2 = 0;
		 const char* t = this->text;
		 const char* l = line;
		 while (*t++)
		 {
			 length1++;
		 }
		 while (*t++)
		 {
			 length2++;
		 }
		 char* res = new char[length1 + length2];
		 for (int i = 0; i < length1 + length2; i++)
		 {
			 res[i] = line[i - length1];
		 }
		 for (int i = 0; i < length1; i++)
		 {
			 res[i] = this->text[i];
		 }
		 res[length1 + length2] = '\0';
		cout << res << "\n";*/
	 }

	 void Concat(int x)
	 {
		char s[7];
		char* l = _itoa(x, s, 10);
		
		string text = this->text;
		cout << text.append(l) << "\n";
	 }

	 void Concat(double y) 
	 {		  
		 // cout << text; printf("%g", y); // а так можно? :)		 
		 string text = this->text;
		 cout << text.append(to_string(y)) << "\n";
	 }

	 String* Split(const char* separator, int& pieces) const
	 {		
		 String* text = new String[pieces];		
		 int k = 1;
		 //int* pieces;
		 pieces = k;
		 for (int i = 0; i < length; i++)
		 {
			 for (int j = 0; j < strlen(separator); j++)
			 {
				 if (String::text[i] == ' ')
				 {
					 String::text[i] = separator[j];
					 k++;					 				 
				 }				 
			 }				 
		 }		 
		 return &text[pieces];
	 }

	 String ToLower()
	 {
		 for (int i = 0; i < length; i++)
		 {
			 if (text[i] > 'A' && text[i] < 'Z')
			 {
				 text[i] += 'z' - 'Z';
			 }
			 if (text[i] > 'А' && text[i] < 'Я')
			 {
				 text[i] += 'я' - 'Я';				
			 }			
		 }			
		 return text;
	 }

	 String ToUpper()
	 {
		 for (int i = 0; i < length; i++)
		 {
			 if (text[i] > 'a' && text[i] < 'z')
			 {
				 text[i] += 'Z' - 'z';
			 }
			 if (text[i] > 'а' && text[i] < 'я')
			 {
				 text[i] += 'Я' - 'я';
			 }
		 }
		 return text;
	 }

	 void SortAZ()
	 {
		 for (int i = 0; text[i] != '\0'; i++)
		 {
			 for (int j = 0; text[j] != '\0'; j++)
			 {
				 if (text[i] < text[j])
				 {
					 char temp = text[i];
					 text[i] = text[j];
					 text[j] = temp;
				 }
			 }
		 }
		 //cout << text << "\n";
	 }

	 void SortZA()
	 {
		 for (int i = 0; text[i] != '\0'; i++)
		 {
			 for (int j = 0; text[j] != '\0'; j++)
			 {
				 if (text[i] > text[j])
				 {
					 char temp = text[i];
					 text[i] = text[j];
					 text[j] = temp;
				 }
			 }
		 }
		// cout << text << "\n";
	 }

	 void Trim() 
	 {		
		 string text = this->text;
		 for (int i = 0; i < length; i++)
		 {
			 if (text[i] == ' ' && text[length - 1] == ' ')
			 {
				 text.erase(i, 1);				 
			 }
			 else if (text[i] == '\0' && text[i - 1] == ' ')
			 {
				 text.erase(i - 1, 1);
			 }
		 }
		 //cout << text << "|\n";
	 }

	 void TrimEnd()
	 {
		 string text = this->text;
		 for (int i = 0; i < length; i++)
		 {			 
			 if (text[i] == ' ' && text[length - 1] == ' ')
			 {
				 text.erase(length - 1, 1);
			 }
		 }
		 //cout << text << "|\n";
	 }

	 void TrimStart()
	 {
		 string text = this->text;
		 for (int i = 0; i < length; i++)
		 {
			 if (text[i] == ' ' && text[length - 1] == ' ')
			 {
				 text.erase(i, 1);				 
			 }				
		 }		 
	 }

	 void Remove(int x)
	 {
		 string text = this->text;
		 text.erase(x);
		 //cout << text;
	 }

	 void Remove(int start, int count)
	 {
		 string text = this->text;
		 text.erase(start, count);
		 //cout << text;
	 }
	
	 bool Contains(const String& text) // ???
	 {	
		 cout << "Enter the line\n";
		 string line;
		 getline(cin, line);
		 bool res;

		 res = line.compare(this->text);

		 return res;

		/* char* temp = new char[sizeof(line) + 1];	
		 
		 unsigned int length_temp = strlen(temp);
		 if (length_temp > length)
		 {
			 return false;
		 }		 
		 
		 for (int i = 0; i <= length - length_temp; i++)
		 {
			 for (int j = 0; j < length_temp; j++)
			 {
				 text[j] = temp[i + j];
			 }
			 if (strcmp(text, temp) == 0)
			 {
				 return true;
			 }

			 delete[]temp;
		 }	
		 return false;*/
	 }

	 bool EndsWith(const String line) const
	 {
		 char* temp = new char[sizeof(line) + 1];
		 unsigned int length_temp = strlen(temp);
		 if (length_temp > length)
		 {
			 return false;
		 }

		 for (int i = length - length_temp; i <= length; i++)
		 {

			 if (strcmp(text, temp) == 0)
			 {
				 return true;
			 }
		 }
			 delete[]temp;
		 
		 return false;		 
	 }

	 bool StartsWith(const String line) const
	 {
		 char* temp = new char[sizeof(line) + 1];
		 unsigned int length_temp = strlen(temp);
		 if (length_temp > length)
		 {
			 return false;
		 }

		 for (int i = 0; i <= length_temp; i++)
		 {

			 if (strcmp(text, temp) == 0)
			 {
				 return true;
			 }
		 }
		 delete[]temp;

		 return false;
	 }

	 bool Equals(const String text) const
	 {
		 cout << "Enter the line\n";
		 string line;
		 getline(cin, line);
		
		 if(line == this->text)
		 {
			 return true;
		 }		
		 else
		 {
			 return false;
		 }
	 }

	 int IndexOf(char ch)
	 {
		 string text = this->text;		 
		 return text.find_first_of(ch);		 
	 }

	 int LastIndexOf(char ch)
	 {
		 string text = this->text;
		 return text.find_last_of(ch);
	 }

	 int IndexOf(const String text) const
	 {
		 cout << "Enter the line\n";
		 string line;
		 getline(cin, line);		 
		 //string text = this->text;
		 return line.find_first_of(this->text);		 
	 }

	 int LastIndexOf(const String text) const
	 {
		 cout << "Enter the line\n";
		 string line;
		 getline(cin, line);		
		 return line.find_last_of(this->text);
	 }
	 
	  void Replace(char R, char Z) 
	  {		
		  for (int i = 0; i < length; i++)
		  {
			  if (text[i] == R)
			  {				 
				  text[i] = Z;				 
			  }				  
		  }
	  }

	 void Reverse()
	 {	
		 for (int i = length - 1; i >= 0; i--)
		 {
			 //cout << text[i];
		 }
	 }

	 void Shuffle()
	 {
		 for (int i = 0; i < length; i++)
		 {
			 int j = i + rand() % (length - i);
			 char temp = text[j];
			 text[j] = text[i];
			 text[i] = temp;
		 }
		 cout << text << "\n";
	 }

	 void RandomFill()
	 {
		 for (int i = 0; i < capacity; i++)
		 {
			 text[i] = rand() % 256;
			 puts(text);			 
			 //cout << text << "\n";
		 }
	 }

private:
	void Initialize(const char* str, int capacity = 80) {
		length = strlen(str);
		this->capacity = (capacity > length) ? capacity : length + 20;
		this->text = new char[this->capacity];
		strcpy_s(this->text, length + 1, str);
	}
};

int main()
{
	setlocale(0, "UKR");
	srand(time(0));
	int x = 2022;
	double y = 20.22;
	int z = 0;
	const char* w = ";";
	const char* line = " hello world ";
	String a;
	String b(" hello world ");
	String c = b;	
	String s = " hello happy New Year ";
	String d = "С НОВЫМ ГОДОМ";
	String e = "с новым годом";
		
	a.Print();
	cout << "========================\n";
	b.Print();
	cout << "========================\n";
	c.PrintLn();
	cout << "========================\n";
	cout << b.GetCharAt(7) << "\n";
	cout << "========================\n";
	b.GetLine();
	b.Print();
	cout << "========================\n";
	cout << b.CompareTo(d) << "\n";
	cout << "========================\n";
	cout << d.CompareTo(line) << "\n";	
	cout << "========================\n";
	b.Concat(s);
	b.Print();
	cout << "========================\n";
    s.Concat(" Happy!\n");
	s.Print();
	cout << "========================\n";
	s.Concat(x);
	s.Print();
	cout << "========================\n";
	s.Concat(y);
	s.Print();
	cout << "========================\n";
	cout << b.Contains(s) << "\n";
	cout << "========================\n";
	cout << b.EndsWith(line);
	cout << "========================\n";
	cout << b.StartsWith(line);
	cout << "========================\n";
	cout << b.Equals(s) << "\n";
	cout << "========================\n";	
    s.Trim();
	s.Print();
	cout << "========================\n";
	s.TrimEnd();
	s.Print();
	cout << "========================\n";
	s.TrimStart();
	s.Print();
	cout << "========================\n";
	d.Split(w, z);
	d.Print();
	cout << "========================\n";
	d.ToLower();
	d.Print();
	cout << "========================\n";
	e.ToUpper();
	e.Print();
	cout << "========================\n";
	b.SortAZ();
	b.Print();
	cout << "========================\n";
	b.SortZA();
	b.Print();
	cout << "========================\n";
	b.Remove(3);
	b.Print();
	cout << "========================\n";
	b.Remove(3, 2);
	b.Print();
	cout << "========================\n";
    a.RandomFill();
	a.Print();
	cout << b.IndexOf('l') << "\n";
	cout << "========================\n";
	cout << b.LastIndexOf('l') << "\n";
	cout << "========================\n";
	cout << s.IndexOf(b) << "\n";
	cout << "========================\n";
	s.Reverse();
	s.Print();
	cout << "========================\n";
	b.Replace('l', 't');
	b.Print();
	cout << "========================\n";
	b.Shuffle();
	b.Print();
	cout << "========================\n";	
	cout << b.GetLength() << endl;
	cout << b.GetCapacity() << endl;
	cout << "========================\n";
	a.SetString("nice weather");	
	cout << a.GetLength() << endl;
	cout << a.GetCapacity() << endl;
	cout << "========================\n";
	a.Clear();	
	cout << a.GetLength() << endl;
	cout << a.GetCapacity() << endl;
	cout << "========================\n";
	a.ShrinkToFit();
	cout << a.GetLength() << endl;
	cout << a.GetCapacity() << endl;
	cout << "\n";
}


