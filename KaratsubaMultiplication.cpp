#include <bits/stdc++.h>
using namespace std;

int mkelength(string &x,string &y){
    int lengthX = x.size();
    int lengthY = y.size();
    if(lengthX > lengthY){
        for(int i=0; i < (lengthX - lengthY); ++i){
            y = "0" + y;
            cout << y << endl;
        }
        return lengthX;
    }
    else{
        for(int i=0; i < (lengthY - lengthX); ++i){
            x = "0" + x;
        }
        return lengthY;
    }

}
string add(string x,string y){
    string res = "";
    for(int i=0; i < x.size(); ++i){
        res += ((x[i] - '0') + (y[i] - '0') + '0');
        //cout << "res = " << res << endl;
    }

    return res;
}

long long multi1num(string x,string y){
    return ((x[0]-'0')*(y[0]-'0'));
}

long long multiply(string x,string y){

    int length = mkelength(x,y);

    if(length == 0) return 0;
    if(length == 1) return multi1num(x,y);

    int fh = length/2;
    int sh = (length - fh);
    string Xl = x.substr(0, fh);
    string Xr = x.substr(fh, sh);

    string Yl = y.substr(0, fh);
    string Yr = y.substr(fh, sh);

    long long P1 = multiply(Xl, Yl); /// ac
    long long P2 = multiply(Xr, Yr); /// bd
    long long P3 = multiply(add(Xl,Xr) , add(Yl,Yr)); /// (a + c)*(c + d)

    return (pow(10,length)*P1 + pow(10,length/2)*(P3-P1-P2) + P2); /// 10^n * ac + 10 ^n/2 *(ad+bc) + bd
}

int main(){

    string x,y;
    cin >> x >> y;
    cout << x << endl << y << endl;

    ///int l = mkelength(x,y);
    ///cout << "Length = " << l << endl;
    ///cout << x << endl << y << endl;
    ///int mlti = multi1num(x,y);
    ///cout << endl <<mlti << endl;
    ///string res = add(x,y);
    ///cout << res << endl;
    long long res = multiply(x,y);
    cout << res << endl;

    ///cout << 1234*5678 << endl;
    return 0;
}

