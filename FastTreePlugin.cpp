#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FastTreePlugin.h"

void FastTreePlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
   }
 }
 
void FastTreePlugin::run() {
}

void FastTreePlugin::output(std::string file) {
	std::string command = "fasttree -nt -gtr -gamma "+inputfile+" > "+file;
       	system(command.c_str());
}

PluginProxy<FastTreePlugin> FastTreePluginProxy = PluginProxy<FastTreePlugin>("FastTree", PluginManager::getInstance());
