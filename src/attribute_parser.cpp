#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Attribute {
    string name;
    string value;
};

struct Tag {
    string name;
    vector<Attribute> attributes;
};

struct Query {
    string tag;
    string attribute;
};

void parse_tag(vector<Tag>& tags);
void print_tag(Tag tag);
void parse_query(vector<Query>& querys);
void print_query(Query query);

int main() {
    vector<Tag> tags;
    vector<Query> querys;
    std::string string_bin;

    int tag_count = 0;
    int query_count = 0;

    cin >> tag_count;
    cin >> query_count;
    
    // Parse Tags
    for (int i = 0; i < tag_count; i++) {
        char bin;
        Tag tag;
        string line;

        cin >> line;

        while (true) {
            int skip_position = 1;
            
            // Closing Tag Check
            if (line.at(skip_position) == '/') {
                break;
            }
            
            // Attribute Check
            if (tag.name.back() == '>') {
				tag.name = tag.name.substr(0, tag.name.length() - 1);
                tags.push_back(tag);
                break;
            }

            //Parse Attriutes
            while (true) {
                Attribute attribute;
				ss >> attribute.name;
                ss >> bin >> bin;
                ss >> attribute.value;

                if (attribute.value.back() == '>') {
                    attribute.value.pop_back();
					tag.attributes.push_back(attribute);
                    break;
                }
                else if(attribute.value.back() == '"') {
					attribute.value.pop_back();
					tag.attributes.push_back(attribute);
                }
                else {
                    break;
                }
            }

			
        }

        tags.push_back(tag);
    }

    for (int i = 0; i < (tag_count / 2); i++) {
        parse_tag(tags);
    }

    // Skip closing Tags
    for (int i = 0; i < (tag_count / 2); i++) {
        cin >> string_bin;
    }

    for (int i = 0; i < query_count; i++) {
        parse_query(querys);
    }

    for (int i = 0; i < querys.size(); i++) {
		bool found = false;
        for (int j = 0; j < tags.size(); j++) {
            if (querys.at(i).tag == tags.at(j).name) {
                for (int k = 0; k < tags.at(j).attributes.size(); k++) {
                    if (querys.at(i).attribute == tags.at(j).attributes.at(k).name) {
						cout << tags.at(j).attributes.at(k).value << endl;
						found = true;
                        break;
                    }
                }
            }
        }
        if (!found) {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}

void parse_tag(vector<Tag>& tags) {
    Tag tag;
    char bin;
    string token;

    cin >> bin;
    cin >> tag.name;

    while(tag.name.back() != '>') {
        Attribute attribute;
        cin >> attribute.name;

        // Skip = And "
        for (int i = 0; i < 2; i++) {
			cin >> bin;
        }

		cin >> attribute.value;

		bin = attribute.value.back();
        if (bin == '>') {
            for (int i = 0; i < 2; i++) {
                attribute.value.pop_back();
            }

			tag.attributes.push_back(attribute);
            break;
        }
        else if(bin == '"') {
			attribute.value.pop_back();

            tag.attributes.push_back(attribute);
        }
    }
    
	tags.push_back(tag);
}

void print_tag(Tag tag) {
    cout << "Tag Nmae: " << tag.name << endl;
    for (int i = 0; i < tag.attributes.size(); i++) {
		cout << "Attribute Name: " << tag.attributes.at(i).name << endl;
		cout << "Attribute Value: " << tag.attributes.at(i).value << endl;
    }
}

void parse_query(vector<Query>& querys) {
	Query query;
    string line;

    cin >> line;

    int pos = line.find('.');
    int search_pos = 0;

    while (true) {
        if (pos < 0) {
			pos = line.find('~');
            query.tag = line.substr(search_pos, pos - search_pos);
			query.attribute = line.substr(pos + 1, line.length());

            break;
        }
        else if (pos > 0) {
			search_pos = pos + 1;
			pos = line.find('.', search_pos);
        }
    }
    
    querys.push_back(query);
}

void print_query(Query query) {
    cout << "Query Tag: " << query.tag << endl;
    cout << "Query Attribute: " << query.attribute << endl;
}
