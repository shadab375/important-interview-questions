//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class AutoCompleteSystem {
public:
    struct Node {
            unordered_map<string, int> sentences;
            unordered_map<char, Node*> childs;
    };

    Node* root;
    string curString;

    void insert(Node* root, string& sentence, int times) {
        Node* cur = root;
        
        for (char c : sentence) {
            if (!cur->childs.count(c)) {
                cur->childs[c] = new Node();
            }
            cur = cur->childs[c];
            cur->sentences[sentence] += times;
        }
    }

    static bool compare(pair<string, int>& a, pair<string, int>& b) {
        return (a.second > b.second) || (a.second == b.second && a.first < b.first);
    }

    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Node();
        curString = "";

        for (int i = 0; i < sentences.size(); i++) {
            insert(root, sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(root, curString, 1);
            curString = "";
            return {};
        }

        curString += c;
        Node* cur = root;

        for (char ch : curString) {
            if (!cur->childs.count(ch)) {
                return {};
            }
            cur = cur->childs[ch];
        }

        vector<pair<string, int>> suggestions(cur->sentences.begin(), cur->sentences.end());
        sort(suggestions.begin(), suggestions.end(), compare);

        vector<string> result;
        for (int i = 0; i < min(3, static_cast<int>(suggestions.size())); i++) {
            result.push_back(suggestions[i].first);
        }

        return result;
    }
};


/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */


//{ Driver Code Starts.

int main() {

    int t;
	cin >> t;
    cin.ignore();
    while(t--) {
		int n;
		cin>>n;
        cin.ignore();
        vector<string> sentences(n);
		vector<int> times(n);
		for (int i = 0; i < n; ++i){
            
			getline(cin,sentences[i]);
			cin>>times[i];
            cin.ignore();
		}
		AutoCompleteSystem *obj = new AutoCompleteSystem(sentences,times);
		int q;
		cin>>q;
        cin.ignore();

		for (int i = 0; i < q; ++i){
			string query;
			getline(cin,query);
            string qq = "";
            for(auto &x:query){
			    qq+=x;
                vector<string> suggestions = obj->input(x);
                if(x=='#')
                    continue;
                cout<<"Typed : \""<<qq<<"\" , Suggestions: \n";
				for(auto &y:suggestions){
					cout<<y<<"\n";
				}
			}
		}
	}
	return 0;
}




// } Driver Code Ends