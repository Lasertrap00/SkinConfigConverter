#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <istream>
#include <fstream>
#include "jsoncons\json.hpp"

using jsoncons::json;

bool replace(std::string& str, const std::string& from, const std::string& to)
{
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

enum WEAPONS : int
{
	WEAPON_DEAGLE = 1,
	WEAPON_ELITE = 2,
	WEAPON_FIVESEVEN = 3,
	WEAPON_GLOCK = 4,
	WEAPON_AK47 = 7,
	WEAPON_AUG = 8,
	WEAPON_AWP = 9,
	WEAPON_FAMAS = 10,
	WEAPON_G3SG1 = 11,
	WEAPON_GALILAR = 13,
	WEAPON_M249 = 14,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10 = 17,
	WEAPON_P90 = 19,
	WEAPON_UMP45 = 24,
	WEAPON_XM1014 = 25,
	WEAPON_BIZON = 26,
	WEAPON_MAG7 = 27,
	WEAPON_NEGEV = 28,
	WEAPON_SAWEDOFF = 29,
	WEAPON_TEC9 = 30,
	WEAPON_TASER = 31,
	WEAPON_HKP2000 = 32,
	WEAPON_MP7 = 33,
	WEAPON_MP9 = 34,
	WEAPON_NOVA = 35,
	WEAPON_P250 = 36,
	WEAPON_SCAR20 = 38,
	WEAPON_SG556 = 39,
	WEAPON_SSG08 = 40,
	WEAPON_KNIFE = 42,
	WEAPON_FLASHBANG = 43,
	WEAPON_HEGRENADE = 44,
	WEAPON_SMOKEGRENADE = 45,
	WEAPON_MOLOTOV = 46,
	WEAPON_DECOY = 47,
	WEAPON_INCGRENADE = 48,
	WEAPON_C4 = 49,
	WEAPON_KNIFE_T = 59,
	WEAPON_M4A1_SILENCER = 60,
	WEAPON_USP_SILENCER = 61,
	WEAPON_CZ75A = 63,
	WEAPON_REVOLVER = 64,
	WEAPON_KNIFE_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT = 506,
	WEAPON_KNIFE_KARAMBIT = 507,
	WEAPON_KNIFE_M9_BAYONET = 508,
	WEAPON_KNIFE_TACTICAL = 509,
	WEAPON_KNIFE_FALCHION = 512,
	WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
	WEAPON_KNIFE_BUTTERFLY = 515,
	WEAPON_KNIFE_PUSH = 516
};

std::string WeaponIndexToName(int index)
{
	std::string name = ("Not Found");
	switch (index)
	{
	case WEAPON_AK47:
		name = ("AK-47");
		break;
	case WEAPON_AUG:
		name = ("AUG");
		break;
	case WEAPON_AWP:
		name = ("AWP");
		break;
	case WEAPON_BIZON:
		name = ("PP-Bizon");
		break;
	case WEAPON_C4:
		name = ("C4");
		break;
	case WEAPON_CZ75A:
		name = ("CZ75");
		break;
	case WEAPON_DEAGLE:
		name = ("Desert Eagle");
		break;
	case WEAPON_DECOY:
		name = ("Decoy Grenade");
		break;
	case WEAPON_ELITE:
		name = ("Dual Berettas");
		break;
	case WEAPON_FAMAS:
		name = ("FAMAS");
		break;
	case WEAPON_FIVESEVEN:
		name = ("Five-Seven");
		break;
	case WEAPON_FLASHBANG:
		name = ("Flashbang");
		break;
	case WEAPON_G3SG1:
		name = ("G3SG1");
		break;
	case WEAPON_GALILAR:
		name = ("Galil AR");
		break;
	case WEAPON_GLOCK:
		name = ("Glock-18");
		break;
	case WEAPON_HEGRENADE:
		name = ("HE Grenade");
		break;
	case WEAPON_HKP2000:
		name = ("P2000");
		break;
	case WEAPON_INCGRENADE:
		name = ("Incendiary Grenade");
		break;
	case WEAPON_KNIFE:
		name = ("Knife");
		break;
	case WEAPON_KNIFE_BAYONET:
		name = ("Bayonet");
		break;
	case WEAPON_KNIFE_BUTTERFLY:
		name = ("Butterfly Knife");
		break;
	case WEAPON_KNIFE_FALCHION:
		name = ("Falchion Knife");
		break;
	case WEAPON_KNIFE_FLIP:
		name = ("Flip Knife");
		break;
	case WEAPON_KNIFE_GUT:
		name = ("Gut Knife");
		break;
	case WEAPON_KNIFE_KARAMBIT:
		name = ("Karambit");
		break;
	case WEAPON_KNIFE_M9_BAYONET:
		name = ("M9 Bayonet");
		break;
	case WEAPON_KNIFE_PUSH:
		name = ("Shadow Daggers");
		break;
	case WEAPON_KNIFE_SURVIVAL_BOWIE:
		name = ("Bowie Knife");
		break;
	case WEAPON_KNIFE_TACTICAL:
		name = ("Huntsman Knife");
		break;
	case WEAPON_M249:
		name = ("M249");
		break;
	case WEAPON_M4A1:
		name = ("M4A4");
		break;
	case WEAPON_M4A1_SILENCER:
		name = ("M4A1-S");
		break;
	case WEAPON_MAC10:
		name = ("MAC-10");
		break;
	case WEAPON_MAG7:
		name = ("MAG-7");
		break;
	case WEAPON_MOLOTOV:
		name = ("Molotov");
		break;
	case WEAPON_MP7:
		name = ("MP7");
		break;
	case WEAPON_MP9:
		name = ("MP9");
		break;
	case WEAPON_NEGEV:
		name = ("Negev");
		break;
	case WEAPON_NOVA:
		name = ("Nova");
		break;
	case WEAPON_P250:
		name = ("P250");
		break;
	case WEAPON_P90:
		name = ("P90");
		break;
	case WEAPON_REVOLVER:
		name = ("R8 Revolver");
		break;
	case WEAPON_SAWEDOFF:
		name = ("Sawed Off");
		break;
	case WEAPON_SCAR20:
		name = ("SCAR-20");
		break;
	case WEAPON_SG556:
		name = ("SG 553");
		break;
	case WEAPON_SSG08:
		name = ("SSG 08");
		break;
	case WEAPON_TEC9:
		name = "Tec-9";
		break;
	case WEAPON_UMP45:
		name = "UMP-45";
		break;
	case WEAPON_USP_SILENCER:
		name = ("USP-S");
		break;
	case WEAPON_XM1014:
		name = ("XM1014");
		break;
	default:
		name = ("Not Found");
	};
	return name;
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

	json j;


	if (isCfg.good() && isCfg.is_open())
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
					commandConverted += results.at(1) + " " + + " " + skinFloat + " 4 " + skinSeed + " " + results.at(3);

					std::string key = WeaponIndexToName(atoi(results.at(1).c_str()));

					j["Skins"][key]["Paintkit"] = atoi(results.at(2).c_str());
					j["Skins"][key]["Seed"] = atoi(skinSeed.c_str());
					j["Skins"][key]["Float"] = atof(skinFloat.c_str());
					j["Skins"][key]["StatTrak"] = atoi(results.at(3).c_str());
					j["Skins"][key]["EntityQuality"] = 4;
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

		std::ofstream os(configsPath + "laserskins.json", std::ios::out);

		if (os.good())
		{
			jsoncons::output_format format;

			format.precision(7);

			os << std::fixed << pretty_print(j, format);
		}

		os.close();

		isCfg.close();

		std::cout << "Wrote LaserSkins Config to: " << configsPath << "laserskins.json" << std::endl;
		std::cout << "Press enter to exit Application.";
		std::getline(std::cin, buffer);
	}
	else
	{
		std::cout << "Error while parsing skins.cfg! Retry! Press enter to exit Application." << std::endl;
		std::getline(std::cin, buffer);
	}

	return 0;
}
