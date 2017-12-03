#pragma once

#include "Sender.h"

namespace AlgorytmGen
{
	using namespace std;

	public class Receiver
	{
	public:
		map<string, int> var;
		int tryConnect()
		{
			sf::TcpListener listener;
			unsigned int port = 34020;

			if (listener.listen(port) != sf::Socket::Done)
			{
				throw "Nie mogê rozpocz¹æ nas³uchiwania na porcie " + port;
			}

			char* data = new char[dataSize];
			std::size_t received;

			sf::Socket::Status status = sf::Socket::Status::NotReady;
				sf::TcpSocket client;
				listener.setBlocking(false);
				status = listener.accept(client);
				if (status != sf::Socket::Status::Done)
				{
					delete[] data;
					return 0;
				}

				if (client.receive(data, dataSize, received) != sf::Socket::Done)
				{
					throw "";
				}
				else
				{
					string varName = "";
					int iDane = 0;
					while (data[iDane] != ' ' || data[iDane] != '=')
					{
						varName += data[iDane];
						iDane++;
					}
					if (data[iDane] == '=')
					{
						iDane++;
						string value = "";
						while (data[iDane] != ' ')
						{
							value += data[iDane];
							iDane++;
						}
						var["{" + client.getRemoteAddress().toString() + "}." + varName] = atoi(value.c_str());
					}
					else
					{
						Sender s;
						bool ex = false;
						for each (pair<string, int> v in var)
						{
							if (v.first == varName)
							{
								ex = true;
								break;
							}
						}

						if (!ex)
						{
							varName += "=" + to_string(var[varName]);
							try
							{
								s.TryConnect(varName, client.getRemoteAddress());
							}
							catch (string ex)
							{
								throw ex;
							}
						}
					}
			}
			delete[] data;
			return 1;
		}
	private:
		const int dataSize = 29;
	};
}