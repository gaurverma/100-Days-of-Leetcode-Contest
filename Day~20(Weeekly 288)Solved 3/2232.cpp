class Solution {
public:
    int eval(string e){
        int muls = 0,mule = 0,a=0,b=0;
        if(e[0]=='(') muls = 1;
        if(e[e.length()-1]==')') mule = 1;
        int i=0;
        while(e[i]!='('){
            muls *= 10;
            muls += e[i]-'0';
            i++;
        }
        i++;
        //if(muls==-1) muls = 1;
        //cout<<muls<<endl;
        while(e[i]!='+'){
            a *= 10;
            a += e[i]-'0';
            i++;
        }
        i++;
        //cout<<a<<endl;
        while(e[i]!=')'){
            b *= 10;
            b += e[i]-'0';
            i++;
        }
        i++;
        //cout<<b<<endl;
        while(i<e.length()){
            mule *= 10;
            mule += e[i]-'0';
            i++;
        }
        //if(mule==-1) mule = 1;
        //cout<<mule<<endl;
        //cout<<a<<" "<<b<<" "<<muls<<" "<<mule<<endl;
        return ((a+b)*muls*mule);
    }
    string minimizeResult(string e) {
        string ans;
        int mxval = INT_MAX;
        for(int i=0;e[i]!='+';i++){
            for(int j=e.length()-1;e[j]!='+';j--){
                string t;
                for(int k=0;k<e.length();k++){
                    if(k==i) t+='(';
                    t += e[k];
                    if(k==j) t+=')';
                }
                int val = eval(t);
                //cout<<t<<" "<<val<<endl;
                if(val<mxval){
                    ans = t;
                    mxval = val;
                }
            }
        }
        return  ans;
    }
};