#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include "ConsoleColors.h"
#include <chrono>

/* Credits an sarmanu //https://www.dreamincode.net/forums/topic/183191-create-a-simple-configuration-file-parser/ */

class Convert
{
public:
	template <typename T>
	static std::string T_to_string(T const &val)
	{
		std::ostringstream ostr;
		ostr << val;

		return ostr.str();
	}

	template <typename T>
	static T string_to_T(std::string const &val)
	{
		std::istringstream istr(val);
		T returnVal;
		if (!(istr >> returnVal))
			exitWithError( XorStr("  [>] [C]onfig: Kein valider Wert: ") + (std::string)typeid(T).name() + "!\n");
		

		return returnVal;
	}

	template <>
	static std::string string_to_T(std::string const &val)
	{
		return val;
	}
};

void exitWithError(const std::string &error)
{
	g_pColor->printColor(error.c_str(), CC_RED, CC_WHITE);
	g_pColor->printColor(XorStr(" [>] [C]onfig: Da es Fehler bei dem Einlesen der Config gab, \n wird eine neue erstellt."), CC_RED, CC_WHITE);


	std::ofstream outfile("config.cfg");

	outfile << XorStr("# [>] Spyros External Recode [<] #") << std::endl;
	outfile << XorStr("# [>] Standardconfig [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# Zeilen die mit # oder / beginnen, werden nicht eingelesen#") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] Global Vars: [<] #") << std::endl;
	outfile << XorStr("radar = 1") << std::endl;
	outfile << XorStr("bhop = 1") << std::endl;
	outfile << XorStr("noflash = 0") << std::endl;
	outfile << XorStr("glow = 1") << std::endl;
	outfile << XorStr("trigger = 1") << std::endl;
	outfile << XorStr("rcs = 1") << std::endl;
	outfile << XorStr("aimbot = 0") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] Glow Switch Vars: [<] #") << std::endl;
	outfile << XorStr("glowenemy = 1") << std::endl;
	outfile << XorStr("glowfriend = 0") << std::endl;
	outfile << XorStr("glowweapon = 1") << std::endl;
	outfile << XorStr("glownade = 1") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] Glow Farben: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("############# Werte müssen zwischen 0 bzw. 0.0 und 1.0 sein#") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] Gegner: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("enemyred = 0.5") << std::endl;
	outfile << XorStr("enemygreen = 0.5") << std::endl;
	outfile << XorStr("enemyblue = 0") << std::endl;
	outfile << XorStr("enemyalpha = 0.7") << std::endl;
	outfile << XorStr("# [>] Team: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("friendred = 0.5") << std::endl;
	outfile << XorStr("friendgreen = 0.5") << std::endl;
	outfile << XorStr("friendblue = 0.5") << std::endl;
	outfile << XorStr("friendalpha = 0.7") << std::endl;
	outfile << XorStr("# [>] Waffen: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("weaponred = 0") << std::endl;
	outfile << XorStr("weapongreen = 0.5") << std::endl;
	outfile << XorStr("weaponblue = 0.5") << std::endl;
	outfile << XorStr("weaponalpha = 0.7") << std::endl;
	outfile << XorStr("# [>] Granaten: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("nadered = 0.7") << std::endl;
	outfile << XorStr("nadegreen = 0") << std::endl;
	outfile << XorStr("nadeblue = 0.3") << std::endl;
	outfile << XorStr("nadealpha = 0.7") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] Trigger Vars: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("############# Angaben sind in Millisekunden. Bsp 300 = 0,3s#") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("delaypistol = 30") << std::endl;
	outfile << XorStr("delayrifle = 30") << std::endl;
	outfile << XorStr("delaysniper = 50") << std::endl;
	outfile << XorStr("delayshotgun = 1") << std::endl;		
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] RCS Vars: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("############# RCS-Strengh: 1 stärkster Wert, 2 schwächster #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("rcsstartshot = 3") << std::endl;
	outfile << XorStr("rcsstrengh = 1.8") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] Aimbot Vars: [<] #") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("aimbotfov = 3000.5") << std::endl;
	outfile << XorStr("aimnextafterdeath = 0") << std::endl;
	outfile << XorStr("alwaysaimatclosest = 0") << std::endl;
	outfile << XorStr("bone = 6") << std::endl;
	outfile << XorStr("############################################################") << std::endl;
	outfile << XorStr("# [>] Config Ende [<] #") << std::endl;



	outfile.close();
	g_pColor->printColor(XorStr(" [>] [C]onfig: Config wurde erfolgreich erstellt."), CC_RED, CC_WHITE);
	Sleep(5000);
	system("cls");



}

class ConfigFile
{
private:
	std::map<std::string, std::string> contents;
	std::string fName;

	void removeComment(std::string &line) const
	{
		if (line.find(';') != line.npos)
			line.erase(line.find(';'));
		if (line.rfind('#') != line.npos)
			line.erase(line.find('#'));
	}

	bool onlyWhitespace(const std::string &line) const
	{
		return (line.find_first_not_of(' ') == line.npos);
	}
	bool validLine(const std::string &line) const
	{
		std::string temp = line;
		temp.erase(0, temp.find_first_not_of("\t "));
		if (temp[0] == '=')
			return false;

		for (size_t i = temp.find('=') + 1; i < temp.length(); i++)
			if (temp[i] != ' ')
				return true;

		return false;
	}

	void extractKey(std::string &key, size_t const &sepPos, const std::string &line) const
	{
		key = line.substr(0, sepPos);
		if (key.find('\t') != line.npos || key.find(' ') != line.npos)
			key.erase(key.find_first_of("\t "));
	}
	void extractValue(std::string &value, size_t const &sepPos, const std::string &line) const
	{
		value = line.substr(sepPos + 1);
		value.erase(0, value.find_first_not_of("\t "));
		value.erase(value.find_last_not_of("\t ") + 1);
	}

	void extractContents(const std::string &line)
	{
		std::string temp = line;
		temp.erase(0, temp.find_first_not_of("\t "));
		size_t sepPos = temp.find('=');

		std::string key, value;
		extractKey(key, sepPos, temp);
		extractValue(value, sepPos, temp);

		if (!keyExists(key))
			contents.insert(std::pair<std::string, std::string>(key, value));
		else
			exitWithError XorStr((" [>] [C}onfig: Jeder Variablenname muss einzigartig sein!\n"));
	}

	void parseLine(const std::string &line, size_t const lineNo)
	{
		if (line.find('=') == line.npos)
			exitWithError(XorStr(" [>] [C]onfig: Ein Seperator fehlt in folgender Zeile: ") + Convert::T_to_string(lineNo) + "\n");

		if (!validLine(line))
			exitWithError(XorStr(" [>] [C]onfig: Falsches Format in folgender Zeile: ") + Convert::T_to_string(lineNo) + "\n");

		extractContents(line);
	}

	void ExtractKeys()
	{
		std::ifstream file;
		file.open(fName.c_str());
		if (!file)
			exitWithError(XorStr(" [>] [C]onfig: Die Configdatei: ") + fName + XorStr(" konnte nicht gefunden werden\n"));

		std::string line;
		size_t lineNo = 0;
		while (std::getline(file, line))
		{
			lineNo++;
			std::string temp = line;

			if (temp.empty())
				continue;

			removeComment(temp);
			if (onlyWhitespace(temp))
				continue;

			parseLine(temp, lineNo);
		}

		file.close();
	}
public:
	ConfigFile(const std::string &fName)
	{
		this->fName = fName;
		ExtractKeys();
	}

	bool keyExists(const std::string &key) const
	{
		return contents.find(key) != contents.end();
	}

	template <typename ValueType>
	ValueType getValueOfKey(const std::string &key, ValueType const &defaultValue = ValueType()) const
	{
		if (!keyExists(key))
			return defaultValue;

		return Convert::string_to_T<ValueType>(contents.find(key)->second);
	}
};

