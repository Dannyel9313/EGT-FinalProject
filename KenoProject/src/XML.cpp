#include "XML.h"

XML::XML() {
}

XML::XML(const char * file) {
	doc.load_file(file);
}

void XML::write(const char * path) {
	pugi::xml_node declarationNode = doc.append_child(pugi::node_declaration);
    	declarationNode.append_attribute("version")    = "1.0";
    	declarationNode.append_attribute("encoding")   = "ISO-8859-1";
	pugi::xml_node node = doc.append_child("node");
	pugi::xml_node descr = node.append_child("description");
	descr.append_child(pugi::node_pcdata).set_value("simple node");
	pugi::xml_node param = node.insert_child_before("param", descr);
	param.append_attribute("name") = "version";
	doc.save_file(path);
}
