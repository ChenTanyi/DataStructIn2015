#include <iostream>
#include <fstream>
#include "../Headers/HuffmanTree.h"

const int N = 1e5+10;

char buffer[N];
HuffSource v, detext;
HuffCode code,decode;
HuffTree<char>* tree = 0;
HuffCodeMap table;
int flag = 0;

void huffmanEncode(HuffSource text, HuffTree<char>* & tree, HuffCodeMap & result);//编码
bool huffmanDecode(const HuffCode & code, HuffTree<char>* tree, HuffSource & result);//解码，返回1时解码成功

int main(){
	std :: ifstream fin;
    while (flag != 3){
        int choice = 0;
        std :: cout << "------------------------------------------------------------\n";
        std :: cout << "|             This is a Huffman Coding Program.            |\n";
        std :: cout << "|        It'll do action according to your choice.         |\n";
		std :: cout << "|            1 to enter the encoding file path.            |\n";
		std :: cout << "|      2 to print the Huffman Coding Tree(as table).       |\n";
		std :: cout << "|                   3 to print the code.                   |\n";
		std :: cout << "|             4 to print the decoding message.             |\n";
		std :: cout << "|            5 to enter the decoding file path.            |\n";
		std :: cout << "|   6 to decode the message according to your code file.   |\n";
		std :: cout << "|                     others to quit.                      |\n";
		std :: cout << "------------------------------------------------------------\n";
		std :: cout << "Please enter your choice: ";
		choice = std :: cin.get() - '0';
		if (choice != '\n' - '0') gets(buffer);
		switch (choice){
		case (1) ://------------------------------------------------1----------------------------------------------------
			std :: cout << "Please enter the file path (within one row): ";
			gets(buffer);
			fin.close();
			fin.open(buffer);
			if (!fin){
				std :: cout << "The file path is wrong. Please do your choice again.\n";
			}
			else {
                std :: cout << "Assign the file successfully!\n";
                v.clear();
                char ch;
                while ((ch = fin.get()) > 0){
                    v.push_back(ch);
                }
                if (tree) delete tree;
                table.clear();
                huffmanEncode(v, tree, table);
                for (HuffSource::const_iterator it = v.begin(); it != v.end(); ++ it){
                    for (int i = 0 ; i < table.size() ; ++ i){
                        if (*it == table[i].first){
                            code.insert(code.end(),table[i].second.begin(),table[i].second.end());
                        }
                    }
                }
                flag = 1;
			}
			break;
		case (2) ://------------------------------------------------2----------------------------------------------------
			if (flag != 1) {
				std :: cout << "There is no file assigned. Please do your choice again.\n";
			}
			else {
                std :: cout << "The code for every character is : \n";
                for (HuffCodeMap::const_iterator it = table.begin(); it != table.end() ; ++ it){
                    std :: cout << it->first << " ";
                    for (int i = 0 ; i < it->second.size() ; ++ i){
                        std :: cout << it->second[i];
                    }
                    std :: cout << "\n";
                }
			}
			break;
        case (3) ://------------------------------------------------3----------------------------------------------------
            if (flag != 1) {
				std :: cout << "There is no file assigned. Please do your choice again.\n";
			}
			else {
                std :: cout << "The code is : \n";
                for (HuffCode::const_iterator it = code.begin(); it != code.end() ; ++ it){
                    std :: cout << *it;
                }
                std :: cout << "\n";
			}
			break;
        case (4) ://------------------------------------------------4----------------------------------------------------
            if (flag != 1) {
				std :: cout << "There is no file assigned. Please do your choice again.\n";
			}
			else {
                HuffSource text;
                if (huffmanDecode(code,tree,text)){
                    std :: cout << "The decoding message is : \n";
                    for (HuffSource::const_iterator it = text.begin(); it != text.end() ; ++ it){
                        std :: cout << *it;
                    }
                    std :: cout << "\n";
                }
                else std :: cout << "Decode error!\n";
            }
            break;
        case(5) ://------------------------------------------------5----------------------------------------------------
            if (flag == 0) {
                std :: cout << "There is no coding tree. Please try again.\n";
                break;
            }
            std :: cout << "Please enter the file path (within one row): ";
			gets(buffer);
			fin.close();
			fin.open(buffer);
			if (!fin){
				std :: cout << "The file path is wrong. Please do your choice again.\n";
			}
			else {
                std :: cout << "Assign the file successfully!\n";
                decode.clear();
                char ch;
                while ((ch = fin.get()) > 0){
                    decode.push_back(ch - '0');
                }
                huffmanDecode(decode, tree, detext);
                flag = 2;
			}
			break;
        case (6) ://------------------------------------------------6----------------------------------------------------
            if (flag != 2){
                std :: cout << "There is no file assigned. Please do your choice again.\n";
            }
            else {
                std :: cout << "The message is : \n";
                for (HuffSource::const_iterator it = detext.begin(); it != detext.end(); ++ it){
                    std :: cout << *it;
                }
                std :: cout << "\n";
            }
            break;
        default : flag = 3;//------------------------------------------others---------------------------------------------
		}
		if (flag != 3){
            std :: cout << "Press any key to continue..";
            gets(buffer);
		}
    }
    if (tree) delete tree;
    return 0;
}
