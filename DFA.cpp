// to model a DFA and use it to accept strings of associated language

class Automata
{
public:
    Automata(int start) : s0(start)
    {}

    void add_transition(int i, int j, char c) {
        //...(a,0)->b ect. use map and hashtable
    }

    void add_final_state(int i) {
        //...
    }

    bool validate_string(const std::string &str) {
        //...
    }
private:
    std::map<std::pair<int, char>, int> tr; // transitions map
    std::vector<int> fs; // final states vectors
    int s0; // initial state
};
