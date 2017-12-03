#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <regex>

namespace AlgorytmGen
{
	using namespace std;
	using namespace System;

	public class MyExpression
	{
	public:
		string expr;
		map<string, int> varLoc;
		map<string, int> varGlo;
		int i = 0;

		string processe()
		{
			while (expr.find_first_of(' ') != string::npos)
			{
				expr.erase(expr.find_first_of(' '), 1);
			}
			int result = 0;
			// Pierwszy etap edycji wyra¿enia. Przeszukanie wyra¿enia, w celu wyszukania nawiasów, a nastêpnie dokonane edycji wyra¿enia wewn¹trz niego.
			while (expr.find_first_of('(') != string::npos)
			{
				string part = "";
				string::iterator it = expr.begin();
				while (it != expr.end())
				{
					switch (*it)
					{
					case '(':
						part = "(";
						it++;
						break;
					case ')':
					{
						part += *it;
						string newVar = "!x" + to_string(i);
						try
						{
							varGlo[newVar] = third(sec(part));
						}
						catch (string ex)
						{
							throw ex;
						}
						expr.replace(expr.find(part), part.length(), newVar);
						it = expr.end();
						i++;
						break;
					}
					default:
						part += *it;
						it++;
						break;
					}
				}
			}
			if (expr.find_first_of('/') != string::npos || expr.find_first_of('*') != string::npos)
			{
				try
				{
					expr = sec(expr);
				}
				catch (string ex)
				{
					throw ex;
				}
			}

			if (expr.find_first_of('+') != string::npos || expr.find_first_of('-') != string::npos)
			{
				try
				{
					int res = third(expr);
					varGlo.clear();
					varGlo = varLoc;
					return to_string(res);
				}
				catch (string ex)
				{
					throw ex;
				}
			}
			int finalResult = varGlo[expr];
			varGlo.clear();
			varGlo = varLoc;
			return  to_string(finalResult);
		}

	private:
		///Drugi etap edycji wyra¿enia. Likwidacja znaków '*' i '/'
		string sec(string part)
		{
			if (part.find_first_of('*') != string::npos || part.find_first_of('/') != string::npos)
			{
				if (part.find_first_of('(') != string::npos)
				{
					part.pop_back();
					part.erase(0, 1);
				}
				string varName1 = "";
				string varName2 = "";
				string::iterator it = part.begin();
				while (it != part.end())
				{
					switch (*it)
					{
					case '+':
					case '-':
						varName1 = "";
						it++;
						break;
					case '/':
					{
						if (varName1.find_first_of('{') != string::npos)
						{
							try
							{
								getGlobal(varName1);
							}
							catch (string ex)
							{
								throw ex;
							}
						}
						varName2 = "";
						it++;
						while (*it != '+' && *it != '-' && *it != '/' && *it != '*')
						{
							varName2 += *it;
							it++;
							if (it != part.end()) continue;
							else break;
						}
						if (varName2.find_first_of('{') != string::npos)
						{
							try
							{
								getGlobal(varName2);
							}
							catch (string ex)
							{
								throw ex;
							}
						}
						string fragment = varName1 + "/" + varName2;
						string newVar = "!x" + to_string(i);
						i++;
						part.replace(part.find(fragment), fragment.length(), newVar);
						varGlo[newVar] = varGlo[varName1] / varGlo[varName2];
						it = part.begin();
						varName1 = "";
						break;
					}
					case '*':
					{
						if (varName1.find_first_of('{') != string::npos)
						{
							try
							{
								getGlobal(varName1);
							}
							catch (string ex)
							{
								throw ex;
							}
						}
						varName2 = "";
						it++;
						while (*it != '+' && *it != '-' && *it != '/' && *it != '*')
						{
							varName2 += *it;
							it++;
							if (it != part.end()) continue;
							else break;
						}
						if (varName2.find_first_of('{') != string::npos)
						{
							try
							{
								getGlobal(varName2);
							}
							catch (string ex)
							{
								throw ex;
							}
						}
						string fragment = varName1 + "*" + varName2;
						string newVar = "!x" + to_string(i);
						i++;
						part.replace(part.find(fragment), fragment.length(), newVar);
						varGlo[newVar] = varGlo[varName1] * varGlo[varName2];
						varName1 = "";
						it = part.begin();
						break;
					}
					default:
					{
						varName1 += *it;
						it++;
						break;
					}
					}
				}
			}
			return part;
		}
		/// Edycja ci¹gu znaków. Ci¹g mo¿e posiadaæ jedynie liczby, '+' i '-'
		int third(string part)
		{
			if (part.find_first_of('(') != string::npos)
			{
				part.pop_back();
				part.erase(0, 1);
			}

			int result = 0;
			string varName = "";
			string::iterator it = part.begin();
			char c = *it == '-' ? *it++ : '+';

			for (it; it != part.end(); ++it)
			{
				switch (*it)
				{
				case '+':
				case '-':
					if (varName.find_first_of('{') != string::npos)
					{
						try
						{
							getGlobal(varName);
						}
						catch (string ex)
						{
							throw ex;
						}
					}
					result = c == '+' ? result + varGlo[varName] : result - varGlo[varName];
					varName = "";
					c = *it;
					break;
				default:
					varName += *it;
					break;
				}
			}
			if (varName.find_first_of('{') != string::npos)
			{
				try
				{
					getGlobal(varName);
				}
				catch (string ex)
				{
					throw ex;
				}
			}
			return c == '+' ? result + varGlo[varName] : result - varGlo[varName];
		}

		bool chkExp(string exp)
		{
			int braL = 0;
			int braR = 0;
			for (string::iterator it = exp.begin(); it != exp.end(); it++)
			{
				switch (*it)
				{
				case '(':
					braL++;
					break;
				case ')':
					braR++;
					break;
				}
			}
			return braL == braR;
		}

		bool chkIP(string exp)
		{
			regex re(".\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}[^\\d]*");
			bool rr = regex_match(exp, re);
			return rr;
		}

		bool getGlobal(string varName)
		{
			bool exist = false;
			map<string, int>::iterator it = varGlo.begin();
			while (it != varGlo.end())
			{
				if ((*it).first == varName)
				{
					return true;
					break;
				}
				it++;
			}

			if (!chkIP(varName)) throw "Wyst¹pi³ b³¹d podczas wywo³ania zmiennej globalnej " + varName;
			Sender stemp;
			
			string ips = "";
			string::iterator it2 = varName.begin() + 1;
			for (it2; *it2 != '}'; it2++)
			{
				ips += *it2;
			}
			it2 += 2;
			sf::IpAddress ip = ips;
			ips = "";
			for (it2; it2 != varName.end(); it2++)
			{
				ips += *it2;
			}
			try
			{
				string qwertyu = ip.toString();
				stemp.TryConnect(ips, ip);
				Sleep(8000);
				string temp123456 = stemp.TryReceive();
				string value;
				if (temp123456.find_first_of('}') != string::npos) value = temp123456.substr(temp123456.find_first_of('}') + 2);
				else value = temp123456;
				if (temp123456 != "") varGlo[varName] = stoi(value);
			}
			catch (string ex)
			{
				throw ex;
			}
			return false;
		}
	};
}