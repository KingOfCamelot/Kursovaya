#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../Kursovaya/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Test_1)
		{
			char Expression[13] = { '3', '+', '4', '*', '2', '/', '(', '5', '-', '1', ')', '^', '2' };
			int SizeExpression = 13;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			Convert(SizeExpression, &*ArrayForConvert);
			char answer[11] = {'3','4','2' ,'*' ,'5','1','-','2' ,'^', '/' ,'+'};
			for (int i = 0; i < 11; ++i) Assert::AreEqual(answer[i], ArrayForConvert[i]);
		}
		TEST_METHOD(Test_2)
		{
			char Expression[15] = { '(', '8','+','8','*','3',')','/','(','5','-','1',')','^','2'};
			int SizeExpression = 15;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			Convert(SizeExpression, &*ArrayForConvert);
			char answer[11] = { '8','8','3','*','+','5','1','-','2','^','/'};
			for (int i = 0; i < SizeExpression - 4; ++i) Assert::AreEqual(answer[i], ArrayForConvert[i]);
		}
		TEST_METHOD(Test_3)
		{
			char Expression[9] = {'e', '*', '(', '9', '-', '5', ')', '/', '2'};
			int SizeExpression = 9;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			Convert(SizeExpression, &*ArrayForConvert);
			char answer[7] = {'e', '9', '5', '-', '*', '2', '/'};
			for (int i = 0; i < SizeExpression - 2; ++i) Assert::AreEqual(answer[i], ArrayForConvert[i]);
		}
		TEST_METHOD(Test_4)
		{
			char Expression[10] = {'(', '3', '+', '4', '*', '9',')', '+', 'p', 'i'};
			int SizeExpression = 10;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			Convert(SizeExpression, &*ArrayForConvert);
			char answer[8] = {'3', '4', '9', '*', '+', 'p', 'i', '+'};
			for (int i = 0; i < SizeExpression - 2; ++i) Assert::AreEqual(answer[i], ArrayForConvert[i]);
		}
		TEST_METHOD(Incorrectly_entered_expression)
		{
			char Expression[9] = { 'j', '*', '(', '9', '-', '5', ')', '/', '2' };
			int SizeExpression = 9;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			try
			{
				Convert(SizeExpression, &*ArrayForConvert);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Incorrectly entered expression";
			}
		}
		TEST_METHOD(Incorrectly_entered_expression_2)
		{
			char Expression[10] = { '(', '3', '+', '4', '*', '9',')', '+', 'i', 'p' };
			int SizeExpression = 10;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			try
			{
				Convert(SizeExpression, &*ArrayForConvert);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Incorrectly entered expression";
			}
		}
		TEST_METHOD(Brace_mismatch)
		{
			char Expression[14] = { '3', '+', '4', '*', '2', '/', '(', '5', '-', '1', ')', '^', '2',')'};
			int SizeExpression = 14;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			try
			{
				Convert(SizeExpression, &*ArrayForConvert);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Brace mismatch";
			}
		}
		TEST_METHOD(Brace_mismatch_2)
		{
			char Expression[15] = { '(', '8','+','8','*','3',')','/','(','5','-','1','(','^','2' };
			int SizeExpression = 15;
			char* ArrayForConvert = new char[SizeExpression];
			for (int i = 0; i < SizeExpression; ++i) ArrayForConvert[i] = Expression[i];
			try
			{
				Convert(SizeExpression, &*ArrayForConvert);
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				cout << "Brace mismatch";
			}
		}
	};
}