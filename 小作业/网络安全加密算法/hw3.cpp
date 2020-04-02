/*
Author: Catnip
Data: 20200315
*/
#include <iostream>
#include <algorithm>
using namespace std;
// ASCII中A = 65, Z = 90, a = 97, z = 122

string secretKey = "BLACKHAT";

// 两个字母相加
char x_add_y(char x, char y) {
	return (((x - 65) + (y - 65)) % 26) + 65;
	// 令 a = x - 65, b = y - 65
	// 由于a和b都小于26，故(a + b) % 26为
	// 若a + b < 26则结果为a + b，若大于等于26则结果为a + b - 26
}

char z_sub_y(char z, char y) {
	int zSub65 = z - 65;
	int ySub65 = y - 65;
	int xSub65 = zSub65 - ySub65 < 0 ? zSub65 - ySub65 + 26 : zSub65 - ySub65;
	return xSub65 + 65;
}

// 两串长度相同的字母相加
string XaddY(string X, string Y) {
	string result;
	for (int i = 0; i < X.size(); i++) {
		result.push_back(x_add_y(X[i], Y[i]));
	}
	return result;
}

string ZsubY(string Z, string Y) {
	string result;
	for (int i = 0; i < Z.size(); i++) {
		result.push_back(z_sub_y(Z[i], Y[i]));
	}
	return result;
}

// 数据清洗，删除明文中非字母的元素
string deleteBlack(string str) {
	string result = "";
	int length = str.length();
	for (int i = 0; i < length; i++) {
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
			result += str[i];
		}
	}
	return result;
}

// 加密函数
string encryption(string plainText) {
	transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);// 将明文全部转为大写字母
	plainText = deleteBlack(plainText); // 删去明文中的空格

	int lenText = plainText.size();
	int lenKey = secretKey.size();

	int time = 0; // 整块运算的次数
	int leftLetter = 0; // 剩余运算的字母数量
	if (lenText >= lenKey) {
		time = lenText / lenKey;
		if (lenText % lenKey != 0) { // 不能整除，有多余字母
			leftLetter = lenText % lenKey;
		}
	}
	else {
		leftLetter = lenText;
	}

	string encryptionResult = "";
	for (int i = 0; i < time; i++) { // 整块加密运算
		string copySubString = plainText.substr(i * lenKey, lenKey);
		encryptionResult += XaddY(copySubString, secretKey);
	}
	if (leftLetter != 0) { // 剩余运算
		string copySubSecretKey = secretKey.substr(0, leftLetter);
		string copySubString = plainText.substr(time * lenKey, leftLetter);
		encryptionResult += XaddY(copySubString, copySubSecretKey);
	}

	return encryptionResult;
}

// 解密函数
string decryption(string cipherText) {
	int lenText = cipherText.size();
	int lenKey = secretKey.size();

	int time = 0; // 整块运算的次数
	int leftLetter = 0; // 剩余运算的字母数量
	if (lenText >= lenKey) {
		time = lenText / lenKey;
		if (lenText % lenKey != 0) { // 不能整除，有多余字母
			leftLetter = lenText % lenKey;
		}
	}
	else {
		leftLetter = lenText;
	}

	string decryptionResult = "";
	for (int i = 0; i < time; i++) { // 整块加密运算
		string copySubString = cipherText.substr(i * lenKey, lenKey);
		decryptionResult += ZsubY(copySubString, secretKey);
	}
	if (leftLetter != 0) { // 剩余运算
		string copySubSecretKey = secretKey.substr(0, leftLetter);
		string copySubString = cipherText.substr(time * lenKey, leftLetter);
		decryptionResult += ZsubY(copySubString, copySubSecretKey);
	}

	// 将得到的明文转为小写字母
	transform(decryptionResult.begin(), decryptionResult.end(), decryptionResult.begin(), ::tolower);

	return decryptionResult;
}

int main() {
	string plainText = "Methods of making messages unintelligible to adversaries have been necessary. Substitution is the simplest method that replaces a character in the plaintext with a fixed different character in the ciphertext. This method preserves the letter frequency in the plaintext and so one can search for the plaintext from a given ciphertext by comparing the frequency of each letter against the known common frequency in the underlying language.";
	string cipherText = "NPTJYKSHGXAMSUGFFDSCQLSNOTNVOSLBHTBNOAOTEGETCHRBFDHCFLBXFYNGMLSLBCYUEISMJEUVSVNBTEHGCPMIMPSVWLTAPOTJKARXQWAEOZAVILRCMAEKJYTJOWLTJYTGHAWBUSAHSEEWETFHOYEGUNHCBHCMFCIPDOEVJAHGBAEQUEHKCTEMIZDRBLSXSGEUDOEEFETGBMRXRFEPMFIGUSERVHIGUPXVKUDLPZNGMHNLFLRERMOKUSERVHIGUPXVPYOFBRIXOUCBQSETDLXMCJCQWWAKJYGVRLFKFBUGXJYHGPAERSEMUPRCQHIGTETJORNHXYCQWTOGGCESELNVZTNVRLUGEPRNIPNZMLNIEHGX";

	cout << encryption(plainText) << endl << endl;
	cout << decryption(cipherText) << endl;
}