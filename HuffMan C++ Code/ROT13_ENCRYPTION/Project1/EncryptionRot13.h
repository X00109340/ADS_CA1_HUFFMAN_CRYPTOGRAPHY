#ifndef ENCRYPTIONROT13_H
#define ENCRYPTIONROT13_H
#include <string>
using namespace std;
class EncryptionRot13
{
private:
	string line = "";
	int length = 0;
	int count = 0;
public:
	EncryptionRot13();
	void encryptFile();
	void decryptFile();
	~EncryptionRot13();
};
#endif ENCRYPTIONROT13_H
