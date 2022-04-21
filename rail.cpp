#include<iostream>
#include<fstream>
#include<cstring>

void help(std::string &n);
bool digits_only(char* s);
void decryptMsg(char *enMsg, int key);
void encryptMsg(char *msg, int key);

int main(int argc, char **argv)
{
	std::string name;
	std::string c_string;
	bool c_digit = true;
	int d;

	for (int i = 0;i < argc; i++)
	{
		if(argc <= i+1)
		{
			std::cout<<"Try -h or --help"<<std::endl;
			exit(0);
			break;
		}
		else if(argc <= i+5)
		{
			if((c_string=argv[i+1]) == "-h" || (c_string=argv[i+1]) == "--help")
			{
				name = argv[0];
				help(name);
				break;
			}
			else if((c_string=argv[i+1]) == "-dl" || (c_string=argv[i+1]) == "-l" || (c_string=argv[i+1]) == "-d")
			{
				if(c_digit = digits_only(argv[i+2]) || ((c_string=argv[i+2]) == "-l") || (c_string=argv[i+3]) == "-d" || (c_string=argv[i+2]) == "-l")
				{
					if(argc == i+4)
					{
						if ((c_string=argv[i+1]) == "-d")
						{
							d = atoi(argv[i+3]);
							std::getline(std::cin,name);
							char *c = const_cast<char*>(name.c_str());
							decryptMsg(c,d);
							break;
						}
						else if((c_string=argv[i+3]) == "-d")
						{
							d = atoi(argv[i+2]);
							std::getline(std::cin,name);
							char *c = const_cast<char*>(name.c_str());
							decryptMsg(c,d);
							break;
						}
						else if((c_string=argv[i+1]) == "-l")
						{
							d = atoi(argv[i+2]);
							name = argv[i+3];
							std::ifstream file(name);
							if(file.is_open())
							{
								std::string n;
								while(std::getline(file,n))
								{
									char *c = const_cast<char*>(n.c_str());
									encryptMsg(c,d);
								}
								file.close();
								break;
							}
							else
							{
								char *c = const_cast<char*>(name.c_str());
								encryptMsg(c,d);
								break;
							}
						}
						else
						{
							d = atoi(argv[i+2]);
							name = argv[i+3];
							std::ifstream file(name);
							if(file.is_open())
							{
								std::string n;
								while (std::getline(file,n))
								{
									char* c = const_cast<char*>(n.c_str());
									decryptMsg(c,d);
								}
								file.close();
								break;
							}
							else
							{
								char *c = const_cast<char*>(name.c_str());
								decryptMsg(c,d);
								break;
							}
						}
					}
					else if(argc == i+5)
					{
						if((c_string=argv[i+2]) == "-l")
						{
							d = atoi(argv[i+3]);
							name = argv[i+4];
							std::ifstream file(name);
							if(file.is_open())
							{
								std::string n;
								while(std::getline(file,n))
								{
									char *c = const_cast<char*>(n.c_str());
									decryptMsg(c,d);
								}
								file.close();
								break;
							}
							else
							{
								char *c = const_cast<char*>(name.c_str());
								decryptMsg(c,d);
								break;
							}
						}
						else
						{
							d = atoi(argv[i+2]);
							name = argv[i+4];
							std::ifstream file(name);
							if(file.is_open())
							{
								std::string n;
								while(std::getline(file,n))
								{
									char* c = const_cast<char*>(n.c_str());
									decryptMsg(c,d);
								}
								file.close();
								break;
							}
							else
							{
								char *c = const_cast<char*>(name.c_str());
								decryptMsg(c,d);
								break;
							}
						}
					}
					else if(argc == 3)
					{
						d = atoi(argv[i+2]);
						if((c_string=argv[i+1]) == "-dl")
						{
							std::getline(std::cin,name);
							char *c = const_cast<char*>(name.c_str());
							decryptMsg(c,d);
							break;
						}
						else
						{
							std::getline(std::cin,name);
							char *c = const_cast<char*>(name.c_str());
							encryptMsg(c,d);
							break;
						}
					}
				}
				else
				{
					std::cout<<"-l need an integet value\nTry -h or --help"<<std::endl;
					break;
				}
			}
			else
			{
				std::string name = argv[0];
				help(name);
				break;
			}
		}
		else
		{
			std::cout<<"Invalid Arguments\nTry -h or --help"<<std::endl;
			break;
		}
	}
	return 0;
}

void help(std::string &n)
{
  std::cout<<"Usage: \n\t"<<n<<"\t[options] [file] or [string]"<<std::endl;
	std::cout<<"\t"<<n<<"\t[options] [string]"<<std::endl;
	std::cout<<"Options: \n\t --help Help options\n\t -h"<<std::endl;
	std::cout<<"\t -d \tDecrypt text\n\t -l \tIs layer for Rail Fence Cipher\n\t\t-l takes parameter i.e -l 4"<<std::endl;
	std::cout<<"\t\tTo Encrypt text just omit '-d' i.e "<<std::endl;
	std::cout<<"\t\t"<<n<<" -l 4 [file] or [string]"<<std::endl;
}

bool digits_only(char *s)
{
  while(*s)
  {
    if(isdigit(*s++) == 0) return false;
  }
  return 1;
}

void decryptMsg(char *enMsg, int key)
{
    int msgLen = strlen(enMsg);
    int i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];

    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for(i = 0; i < msgLen; ++i)
		{
      railMatrix[row][col++] = '*';

      if(row == 0 || row == key-1)
        k= k * (-1);

      row = row + k;
    }

    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];

    row = col = 0;
    k = -1;

    for(i = 0; i < msgLen; ++i)
		{
      std::cout<<railMatrix[row][col++];

      if(row == 0 || row == key-1)
          k= k * (-1);

      row = row + k;
    }
}

void encryptMsg(char *msg, int key)
{
  int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;
  char railMatrix[key][msgLen];
 
  for(i = 0; i < key; ++i)
      for(j = 0; j < msgLen; ++j)
          railMatrix[i][j] = '\n';
 
  for(i = 0; i < msgLen; ++i)
	{
    railMatrix[row][col++] = msg[i];
 
    if(row == 0 || row == key-1)
        k= k * (-1);
 
    row = row + k;
  }

  for(i = 0; i < key; ++i)
	{
    for(j = 0; j < msgLen; ++j)
		{
      if(railMatrix[i][j] != '\n')
        std::cout<<railMatrix[i][j];
		}
	}
}