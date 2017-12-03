#pragma once

#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <windows.h>
#include <SFML/Network.hpp>

namespace AlgorytmGen
{
	using namespace std;
	using namespace System;

	public class Sender
	{
	public:
		map<string, int> varLoc;
		int TryConnect(string var, sf::IpAddress ipV)
		{
			char* data = new char[dataSize];
			for (int i = 0; i < dataSize; i++) data[i] = ' ';

			int i = 0;
			for (i; i < var.size(); i++)
			{
				data[i] = var[i];
			}
			sf::TcpSocket socket;
			unsigned int port = 34020;
			
			if (socket.connect(ipV, port) != sf::Socket::Done)
			{
				throw "Wyst¹pi³ b³¹d przy po³¹czeniu z " + ipV.toString();
			}

			if (socket.send(data, dataSize) != sf::Socket::Done)
			{
				throw "Wyst¹pi³ b³¹d przy po³¹czeniu z " + ipV.toString();
			}
			delete[] data;
			return 0;
		}

		string TryReceive()
		{
			char* data = new char[dataSize];
			data[0] = '?';
			data[1] = '?';
			for (std::size_t i = 2; i < dataSize; i++) data[i] = ' ';
			int i = 0;			
			sf::TcpSocket socket;
			unsigned int port = 34020;

			if (socket.connect(sf::IpAddress::LocalHost, port) != sf::Socket::Done)
			{
				throw "Wyst¹pi³ b³¹d przy po³¹czeniu z " + sf::IpAddress::LocalHost.toString();
			}

			std::size_t received;
			if (socket.receive(data, dataSize, received) != sf::Socket::Done)
			{
				throw "Wyst¹pi³ b³¹d przy po³¹czeniu z " + sf::IpAddress::LocalHost.toString();
			}
			else
			{ 				
				if (data[0] != ' ' && data[0] != '?')
				{
					string rez = "";
					for (int i = 0; i < dataSize; i++)
					{
						if (data[i] != ' ') rez += data[i];
					}
					return rez;
				}
			}

			delete[] data;
			return "";
		}
	private:
		const int dataSize = 33;
	};
}