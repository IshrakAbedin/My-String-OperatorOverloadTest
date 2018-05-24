#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

class myStr{
    int size;
    char *str;

    public:

    myStr(){
        this->size = 1;
        str = new char[size];
        str[0] = '\0';
    }

    myStr(int size, const char* str){
        this->size = size;
        this->str = new char[this->size+1];
        for(int i=0; i<size; i++){
            this->str[i] = str[i];
        }
        this->str[size] = '\0';
    }

    myStr(const myStr & copyobject){
        this->size = copyobject.size;
        this->str = new char[this->size+1];
        for(int i=0; i<=copyobject.size; i++){
            this->str[i] = copyobject.str[i];
        }
    }

    ~myStr(){
        delete[] this->str;
    }
    myStr operator+(myStr rop){
        myStr temp;
        temp.size = this->size + rop.size;
        temp.str = new char[temp.size+1];
        int i;
        for(i=0; i<this->size; i++){
            temp.str[i] = this->str[i];
        }
        for(int j=0; j< rop.size; j++){
            temp.str[i] = rop.str[j];
            i++;
        }
        temp.str[temp.size] = '\0';
        return temp;
    }

    myStr operator=(myStr rop){
        this->size = rop.size;
        this->str = new char[this->size+1];
        for(int i=0; i<=rop.size; i++){
            this->str[i] = rop.str[i];
        }
        return *this;
    }

    char & operator[](int index){
        if(index < 0 || index > this->size){
            exit(1);
        }
        else{
            return this->str[index];
        }
    }

    void print_str(){
        for(int i=0; i<this->size; i++){
            cout<< this->str[i];
        }
        cout<<endl;
    }
};

void foo(myStr ob){
    ob.print_str();
}

myStr boo(){
    myStr ob(5,"HELLO");
    return ob;
}

int main(){
    myStr s1(6,"HELLO ");
    myStr s2(5,"World");
    myStr s3 = s1+s2;
    s3.print_str();
    s3 = s1;
    s3.print_str();
    cout<< s3[1] << s3[2] << endl;
    cin >> s3[0];
    s3.print_str();
    cin.ignore();
    return 0;
}
