// to model a DFA and use it to accept strings of associated language
//#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<fstream>
#include<string>
#include<limits>
#include<map>
#include<istream>
#include<sstream>
#include<algorithm>
//#include<state.h>
using namespace std;


// return true if its not alpha numeric to use with remove_if, isalum returns o if neither alph or char
bool isNotAlnum(char c) {
    return isalnum(c) == 0;
}

std::ifstream& GotoLine(std::ifstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

int main(int argc, char* argv[])
{

  set<char> alphabet;
  set<char> states;
  set<char> acceptstates;
  string startstate;
  string acceptstate;

  string filename;

  if (argc > 1)
  {
    filename = argv[1];
  } else
    {
      cout<<"please enter the DFA file name"<<endl;
      cin>>filename;
    }
    fstream myfile(filename);
      if(!myfile)
        {
          cerr<<"File could not be opened"<<endl;
          exit(1);
        }
      string line, line2;



          getline(myfile, line);
            // erase(remove (iterator of removed items-> end of line )
          line.erase(std::remove_if(line.begin(), line.end(), isNotAlnum), line.end());
            //first line the alphabet up to closing bracket
          alphabet.insert(begin(line), end(line));//iterate throught alphabets
          //line1.erase();
          getline(myfile, line);//second line states
          line.erase(std::remove_if(line.begin(), line.end(), isNotAlnum), line.end());
          states.insert(begin(line), end(line));
          getline(myfile, startstate, '\n');//thrid line start state
          getline(myfile, line); //forth line accept states
          line.erase(std::remove_if(line.begin(), line.end(), isNotAlnum), line.end());
          acceptstates.insert(begin(line),end(line));
          myfile.close();

          //now for the transitions

          typedef pair<char, char> trigger;
          map<trigger, char> transitions;


          ifstream statefile (filename);
            if(!statefile)
            {
            cerr<<"file could not  be opened"<<endl;
            exit(1);
            }
          GotoLine( statefile, 5 );

          while(getline(statefile, line2))
          {
            char first,second, third;
            line2.erase(remove_if(line2.begin(), line2.end(), isNotAlnum), line2.end());
            stringstream ss(line2);

            ss>>first>>second>>third;

            transitions.insert(make_pair(make_pair(first, second), third));
          }



      cout<< "alphabet:"<<endl;
      for (auto it = alphabet.begin(); it !=
                            alphabet.end(); ++it)
       cout << ' ' << *it;

       cout<<"\nThe states are:"<<endl;

       for (auto it = states.begin(); it !=
                            states.end(); ++it)
       cout << ' ' << *it;

      cout<<"\nStartstate is:\n"<<startstate<<endl;
      cout<<"Acceptstates are:\n";
      for (auto it = acceptstates.begin(); it != acceptstates.end(); ++it)
        cout<<' '<< *it;
        cout<<"\n"<<endl;

        cout<<"The transitions are:\n"<<endl;

        for (const auto &entry : transitions)
        {
        auto key_pair=entry.first;
        std:: cout <<"{"<< key_pair.first <<","<< key_pair.second << "}-> " << entry.second << "\n";
        }

        cout<< "Please enter string to test\n"<<endl;

        //assert(startstate.size() == 1);
        char currentstate = startstate[0];
        char inputChar;
        string test;
        cin>>test;
        char char_array [test.length()];
        for(int i=0; i< sizeof(char_array); i++)
        {
        std::cout << currentstate <<"->"<< transitions.find(make_pair(currentstate, test[i]))->second << '\n';
        currentstate=(transitions.find(make_pair(currentstate, test[i]))->second);
      //  std::cout<<currentstate<<endl;
        }
        const bool is_in = acceptstates.find(currentstate) != acceptstates.end();
        if(is_in)
        {
        cout<<"String accepted"<<endl;
        }
        else cout<< "string not accepted"<<endl;
        return 0;
}
