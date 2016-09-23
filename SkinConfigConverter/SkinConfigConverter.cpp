#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <istream>
#include <fstream>

bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

void split(std::string str, std::string splitBy, std::vector<std::string>& tokens)
{

	tokens.push_back(str);

	size_t splitAt;

	size_t splitLen = splitBy.size();

	std::string frag;

	while (true)
	{

		frag = tokens.back();
		splitAt = frag.find(splitBy);
		if (splitAt == std::string::npos)
		{

			break;
		}

		tokens.back() = frag.substr(0, splitAt);

		tokens.push_back(frag.substr(splitAt + splitLen, frag.size() - (splitAt + splitLen)));
	}
}


int main()
{

	std::string skinFloat, skinSeed, buffer, SkinCFGPath, configsPath;
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "-skins.cfg To laserskins.cfg Converter by Lasertrap-" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl << std::endl;
	
	std::cout << "Enter the Path of the skins.cfg(R3Folder\\csgo\\configs\\skins.cfg): ";

	std::getline(std::cin, SkinCFGPath);

	std::cout << "Selected Path: " << SkinCFGPath << std::endl;

	configsPath = SkinCFGPath;
	
	std::transform(configsPath.begin(), configsPath.end(), configsPath.begin(), ::tolower);
	
	std::vector<std::string> results1;
	
	split(SkinCFGPath, "\\", results1);
	
	replace(configsPath, results1.at(results1.size() - 1), "");	
	
	std::cout << "Which Float Value do you wan't to use for the Skins? (Best: 0.000001): ";
	
	std::getline(std::cin, skinFloat);

	std::cout << "Which Seed do you wan't to use for the Skins? (Used for some Skin Patterns like Case Hardened): ";

	std::getline(std::cin, skinSeed);

	std::ifstream isCfg(SkinCFGPath);
	std::ofstream osLaserSkinsCFG(configsPath + "laserskins.cfg");

	if (isCfg.good() && isCfg.is_open()) 
	{
		if (osLaserSkinsCFG.good() && osLaserSkinsCFG.is_open()) 
		{
			std::string line;
			int lineC = 1;
			while (std::getline(isCfg, line))
			{
				std::vector<std::string> results;
				split(line, " ", results);
				if (results.size() > 3) 
				{
					if (results.at(0) == "loadskin")
					{
						std::string commandConverted = "loadskin ";
						commandConverted += results.at(1) + " " + results.at(2) + " " + skinFloat + " 4 " + skinSeed + " " + results.at(3);
						osLaserSkinsCFG << commandConverted + "\n";
					}
				}
				else
				{
					if (line.find("skinchanger_") == std::string::npos) 
					{
						std::cout << "Error while converting Line Number " << lineC << " skipping this line!" << std::endl;
					}
					
				}
				lineC++;
			}
			std::cout << "Wrote LaserSkins Config to: " << configsPath << "laserskins.cfg" << std::endl;
			std::cout << "Press enter to exit Application.";
			std::getline(std::cin, buffer);
		}
		else 
		{
			std::cout << "Error while creating/writing laserskins.cfg! Retry! Press enter to exit Application." << std::endl;
			std::getline(std::cin, buffer);
		}
		
	}
	else 
	{
		std::cout << "Error while parsing skins.cfg! Retry! Press enter to exit Application." << std::endl;
		std::getline(std::cin, buffer);
	}

	osLaserSkinsCFG.close();
	isCfg.close();
	
	return 0;
}

