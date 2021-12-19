#include <iostream>
#include <fstream>

std::string to16(int a);
std::string numbofrow(int k);

int main() {

	const char* ifname = "input.txt";
	const char* ofname = "output.txt";

	std::ifstream inFile(ifname, std::ios_base::binary);
	if (!inFile)
	{
		std::cout << "Can not open file to read: " << ifname << std::endl;
		return 1;
	}

	std::ofstream outFile(ofname);
	if (!outFile)
	{
		std::cout << "Can not open file to write: " << ofname << std::endl;
		inFile.close();
		return 2;
	}

	int numb = 0;
	int str[16];
	int sizes = 0;

	while (inFile.peek() != EOF) {

		outFile << numbofrow(numb);
		outFile << ": ";
		numb++;

		for (int j = 0; j < 16; ++j) {

			if (inFile.peek() != EOF) {
				str[j] = inFile.get();
				sizes = 16;
			}
			else {
				sizes = j + 1;
				break;
			}
		}

		for (int j = 0; j < sizes; ++j) {
			if (j == 8) {
				outFile << "| ";
			}
			outFile << to16(str[j]);
			outFile << " ";

		}

		if (sizes != 16) { // for last string
			for (int j = 0; j < 16 - sizes; ++j) {

				if (j + sizes == 8) {
					outFile << "| ";
				}
				outFile << "  ";
				outFile << " ";
			}
		}
			
		if (sizes == 16) {

			for (int j = 0; j < 16; ++j) {
				if (str[j] >= 32) {
					outFile.put(char(str[j]));
				}
				else {
					outFile.put('.');
				}
			}

		} else {

			for (int j = 0; j < sizes - 1; ++j) {
				if (str[j] >= 32) {
					outFile.put(char(str[j]));
				}
				else {
					outFile.put('.');
				}
			}
		}

		outFile << std::endl;
	}

	std::cout << "Done!";
	inFile.close();
	outFile.close();

	return 0;
}

std::string to16(int a) {

	std::string result;
	int b = a % 16;
	a /= 16;

	if (a <= 9) {
		result += a + '0';
	}
	else {
		result += a + 'F' - 15;
	}

	if (b <= 9) {
		result += b + '0';
	}
	else {
		result += b + 'F' - 15;
	}

	return result;
}

std::string numbofrow(int k) {
    
    std::string result = "0";
    
    for (int i = 0; i < 4; ++i) {
        
        result = to16(k % 256) + result;
        k /= 256;
    }
    
    return ("0" + result);
}