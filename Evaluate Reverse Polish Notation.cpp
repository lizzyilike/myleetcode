class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> data;
    int n;
    string str1,str2,str3;
    
    for(vector<string>::iterator iter=tokens.begin();iter!=tokens.end();iter++)
    {
        
        if(*iter!="*"&&*iter!="/"&&*iter!="+"&&*iter!="-")
        {
            data.push(*iter);
            
        }
        else
        {
            str1=data.top();
            data.pop();
            str2=data.top();
            data.pop();
            if(*iter=="*")
            {
                n=atoi(str1.c_str())*atoi(str2.c_str());
                stringstream ss;
                ss<<n;
                ss>>str3;
                data.push(str3);
            }
            else if(*iter=="/")
            {
                n=atoi(str2.c_str())/atoi(str1.c_str());
                stringstream ss;
                ss<<n;
                ss>>str3;
                data.push(str3);
            }
             else if(*iter=="+")
            {
                n=atoi(str2.c_str())+atoi(str1.c_str());
                stringstream ss;
                ss<<n;
                ss>>str3;
                data.push(str3);
            }
             else 
            {
                n=atoi(str2.c_str())-atoi(str1.c_str());
                stringstream ss;
                ss<<n;
                ss>>str3;
                data.push(str3);
            }
            
            
        }
        
    }
    string str=data.top();
    n=atoi(str.c_str());
    return n;
        
    }
};
