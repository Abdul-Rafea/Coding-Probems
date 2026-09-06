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

void print_tag(Tag tag);
void print_query(Query query);

int main() {
    vector<Tag> tags;
    vector<Query> querys;
    std::string string_bin;

    int tag_count = 0;
    int query_count = 0;

    cin >> tag_count;
    cin >> query_count;
    cin.ignore();

    // Parse Tags
    for (int i = 0; i < tag_count; i++) {
        char bin;
        string line;
        Tag tag;

        getline(cin, line);

        // Closing Tag Check
        if (line.at(1) == '/') {
            continue;
        }
            
        stringstream ss(line);

        ss >> bin >> tag.name;

        // Attribute Check
        if (ss.peek() == '>') {
            tags.push_back(tag);
            continue;
        }
            
        // Parse Attriutes
        while (true) {
            Attribute attribute;

			ss >> attribute.name;
			ss >> bin >> bin; // remove '=' and '"'
            ss >> attribute.value;

            if (attribute.value.back() == '>') {
                attribute.value.pop_back(); // remove '>'
				attribute.value.pop_back(); // remove '"'
				tag.attributes.push_back(attribute);
                break;
            }
            else if(attribute.value.back() == '"') {
				attribute.value.pop_back(); // remove '>'
				attribute.value.pop_back(); // remove '"'
				tag.attributes.push_back(attribute);
            }
            else {
                break;
            }
        }

        tags.push_back(tag);
		print_tag(tag);
    }

	// Parse Querys
    for (int i = 0; i < query_count; i++) {
        string line;
		Query query;

		getline(cin, line);

		int pos = line.find('.');
        int pos_2 = 0;
        while (pos > 0) {
            pos_2 += pos;
            pos = line.find('.', pos_2 + 1);
            if (!(pos > 0)) {
				pos_2 += 1;
            }
        }

		int pos_3 = line.find('~', pos_2);
        query.tag = line.substr(pos_2, pos_3 - pos_2);
		query.attribute = line.substr(pos_3 + 1, line.length());

        querys.push_back(query);
        print_query(query);
    }

	// Print Query Results
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

// Function Definitions ---------------------------------------------------------------------------
void print_tag(Tag tag) {
    cout << "Tag Nmae: " << tag.name << endl;
    for (int i = 0; i < tag.attributes.size(); i++) {
		cout << "Attribute Name: " << tag.attributes.at(i).name << endl;
		cout << "Attribute Value: " << tag.attributes.at(i).value << endl;
    }
    cout << endl;
}

void print_query(Query query) {
    cout << "Query Tag: " << query.tag << endl;
    cout << "Query Attribute: " << query.attribute << endl << endl;
}
