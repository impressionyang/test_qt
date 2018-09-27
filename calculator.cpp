#include "calculator.h"

double string_double(string num_str){
    double result=0;
    istringstream convert(num_str);
    convert >> result;

    return result;
}


Calculator::Calculator(){
    OPND=new stack<double>();
    OPTR=new stack<char>();
    result=0;
}


double Calculator::get_result(string get){
    string *c=format(get);
    OPTR->push('#');
    string input;
    double result=0;
    char theta;
    double a;
    double b;

    int i=0;
    while(c[i][0]!='#'||OPTR->top()!='#'){
        //不是运算符则进栈
        if(!isSymble(c[i][0])){
            //cout<<"不是运算符则进栈"<<c[i]<<endl;
            OPND->push(string_double(c[i]));
            i++;
        }else{
            //是运算符的话就必定会只有一个元素
            //cout<<"是运算符的话就必定会只有一个元素"<<c[i]<<endl;
            switch(Precede(OPTR->top(),c[i][0])){
            case '<':
                OPTR->push(c[i][0]);
                i++;
                break;
            case '=':
                //result=OPTR.top();
                OPTR->pop();
                i++;
                break;
            case '>':
                theta=OPTR->top();
                OPTR->pop();

                b=OPND->top();
                OPND->pop();

                a=OPND->top();
                OPND->pop();

                OPND->push(Operate(a,b,theta));
                //cout<<"目前结果:"<<OPND->top()<<endl;
                break;
            }//switch
        }//if
    }//while

    result=OPND->top();

    return result;

}



bool Calculator::isSymble(char get){
    if(get=='+'||get=='-'||get=='*'||get=='/'||get=='('||get==')'||get=='='||get=='#'){
        return true;
    }

    return false;
}

string * Calculator::format(string get){
    string *afterformat=new string[get.length()];
    string temp;
    int j=0;
    for(int i=0;i<(int)get.length();i++){
        if(get[i]=='+'||get[i]=='-'||get[i]=='*'||get[i]=='/'||get[i]=='('||get[i]==')'||get[i]=='#'||get[i]=='='){
            if(!temp.empty()){
                afterformat[j]=temp;
                //cout<<"temp:"<<temp<<endl;
                temp.erase();
                j++;

            }

            afterformat[j]=get[i];
            j++;
        }else{
            temp.append(1,get[i]);
        }

    }
    return afterformat;
}


char Calculator::Precede(char first,char second){
    switch(first){
    case '+':
        switch(second){
        case '+':
            return '>';
            break;
        case '-':
            return '>';
            break;
        case '*':
            return '<';
            break;
        case '/':
            return '<';
            break;
        case '(':
            return '<';
            break;
        case ')':
            return '>';
            break;
        case '#':
            return '>';
            break;
        }
        break;


    case '-':
        switch(second){
        case '+':
            return '>';
            break;
        case '-':
            return '>';
            break;
        case '*':
            return '<';
            break;
        case '/':
            return '<';
            break;
        case '(':
            return '<';
            break;
        case ')':
            return '>';
            break;
        case '#':
            return '>';
            break;
        }

        break;
    case '*':
        switch(second){
        case '+':
            return '>';
            break;
        case '-':
            return '>';
            break;
        case '*':
            return '>';
            break;
        case '/':
            return '>';
            break;
        case '(':
            return '<';
            break;
        case ')':
            return '>';
            break;
        case '#':
            return '>';
            break;
        }

        break;
    case '/':
        switch(second){
        case '+':
            return '>';
            break;
        case '-':
            return '>';
            break;
        case '*':
            return '>';
            break;
        case '/':
            return '>';
            break;
        case '(':
            return '<';
            break;
        case ')':
            return '>';
            break;
        case '#':
            return '>';
            break;
        }

        break;
    case '(':
        switch(second){
        case '+':
            return '<';
            break;
        case '-':
            return '<';
            break;
        case '*':
            return '<';
            break;
        case '/':
            return '<';
            break;
        case '(':
            return '<';
            break;
        case ')':
            return '=';
            break;
        case '#':
            //return '>';
            break;
        }

        break;
    case ')':
        switch(second){
        case '+':
            return '>';
            break;
        case '-':
            return '>';
            break;
        case '*':
            return '>';
            break;
        case '/':
            return '>';
            break;
        case '(':
            //return '>';
            break;
        case ')':
            return '>';
            break;
        case '#':
            return '>';
            break;
        }

        break;
    case '#':
        switch(second){
        case '+':
            return '<';
            break;
        case '-':
            return '<';
            break;
        case '*':
            return '<';
            break;
        case '/':
            return '<';
            break;
        case '(':
            return '<';
            break;
        case ')':
            //return '=';
            break;
        case '#':
            return '=';
            break;
        }

        break;
    }
    return '0';
}


double Calculator::Operate(double a,double b,char operation){
    switch(operation){
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    }
    return 0;
}

void Calculator::test(){

    for(int i=0;i<100;i++){
        OPND->push(i);
    }

    for(int i=0;i<100;i++){
        cout<<OPND->top()<<endl;
        OPND->pop();
    }

    cout<<test2<<endl;
}
