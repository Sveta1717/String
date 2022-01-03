#include "Library.h"

class String
{
	char* text;
	unsigned int length;
	unsigned int capacity;

public:
	String(const char* text, unsigned int capacity);
	String();
	explicit String(unsigned int capacity);	
	String(const String& original);

	~String();
	
	void SetString(const char* text);	
	const char* GetCharArray() const;	
	int GetLength() const;		
	int GetCapacity() const; 
	void Clear();
	void ShrinkToFit();	
	char GetCharAt(unsigned int index);	
	void Print();	
	void PrintLn();
	void GetLine();
	int CompareTo(const String& text) const;	
	int CompareTo(const char* line) const;	
	void Concat(const String& text) const;	
	void Concat(const char* line);
	void Concat(int x);	
	void Concat(double y);	
	String* Split(const char* separator, int& pieces) const;
	String ToLower();	
	String ToUpper();	
	void SortAZ();	
	void SortZA();
	void Trim();	
	void TrimEnd();	
	void TrimStart();	
	void Remove(int x);	
	void Remove(int start, int count);	
	bool Contains(const String& text);
	bool EndsWith(const String line) const;
	bool StartsWith(const String line) const;
	bool Equals(const String text) const;	
	int IndexOf(char ch);	
	int LastIndexOf(char ch);	
	int IndexOf(const String text) const;	
	int LastIndexOf(const String text) const;	
	void Replace(char R, char Z);	
	void Reverse();	
	void Shuffle();	
	void RandomFill();
	
private:
	void Initialize(const char* str, int capacity); 
};