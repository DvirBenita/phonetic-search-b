
#include "PhoneticFinder.hpp"


    string phonetic::find(string text,string word){
        if(text.size()==0 || word.size()==0 ){
            throw exception();
        }
        vector<string> *elements = new vector<string>;
        string l_case_word = lowCase(word); 
        split(*elements,text);
        for(string element:*elements){

            
           if( match(lowCase(element),l_case_word)){
               return element;
           }
        }
        
        throw exception();

    }
  bool phonetic:: checkProprietry(string s){
     size_t pos = s.find(' ');
      if(pos==0 || pos == s.size()-1 || pos == string::npos){
          return false;
      }
      return true;
    }

    bool phonetic:: match(string element, string word){
        if(element.size()!= word.size()){
            return false;
         }
        
        for(size_t i=0;i<element.size();i++){
            if(element[i] == word[i]){
                continue;
             }
            switch (word[i])
            {
                //v,w
             case 'w':
                if (element[i] != 'v')
                    return false;
                break;
            
            case 'v':
                if (element[i] != 'w')
                    return false;
                break;

            //b,f,p
             case 'p':
                if (  element[i] != 'b'&&element[i] != 'f')
                    return false;
                break;
            case 'b':
                if (element[i] != 'p'&& element[i] != 'f' )
                    return false;
                break;
            case 'f':
                if (element[i] != 'p'&&element[i] != 'b'  )
                    return false;
                break;
           

            // g,j
            case 'g':
                if (element[i] != 'j')
                    return false;
                break;
            case 'j':
                if (element[i] != 'g')
                    return false;
                break;

            // c,k,q
            case 'c':
                if ( element[i] != 'q'&& element[i] != 'k')
                    return false;
                break;
            case 'k':
                if (  element[i] != 'q'&&element[i] != 'c')
                    return false;
                break;
            case 'q':
                if (  element[i] != 'k'&&element[i] != 'c')
                    return false;
                break;

            // s,z
            case 's':
                if (element[i] != 'z')
                    return false;
                break;
            case 'z':
                if (element[i] != 's')
                    return false;
                break;

            // d,t
            case 'd':
                if (element[i] != 't')
                    return false;
                break;
            case 't':
                if (element[i] != 'd')
                    return false;
                break;

            // o,u
            case 'o':
                if (element[i] != 'u')
                    return false;
                break;
            case 'u':
                if (element[i] != 'o')
                    return false;
                break;

            // i,y
            case 'i':
                if (element[i] != 'y')
                    return false;
                break;
            case 'y':
                if (element[i] != 'i')
                    return false;
                break;
            default:
                return false;
            }
        }
        return true;
   

    }




    string phonetic::lowCase(string toLowCase){
        string word = toLowCase;
        for(size_t i=0;i<word.size();i++){
            word[i] = tolower(toLowCase[i]);
        }
        return word;
    }
    
    void phonetic::split(vector<string> &elements,const string &text){
    char space = ' ';
    size_t pos = text.find(space);
    size_t initialPos = 0;
    elements.clear();

   
    while (pos != string::npos)
    {
        elements.push_back(text.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = text.find(space, initialPos);
    }

  
    elements.push_back(text.substr(initialPos, min(pos, text.size()) - initialPos + 1));

    }




