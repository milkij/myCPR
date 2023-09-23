#include <iostream>
#include <string>
#include <cpr/cpr.h>

class USER_REQUEST
{
    std::string url = "http://httpbin.org/";
    cpr::Response _response;
public:

    USER_REQUEST() {};

    void get() {
        _response = cpr::Get(cpr::Url(url+"get"));
        printResponseText();
    };
    void post() {
        _response = cpr::Post(cpr::Url(url+"post"));
        printResponseText();
    };
    void _delete() {
        _response = cpr::Delete(cpr::Url(url+"delete"));
       printResponseText();
    };
    void patch() {
        _response = cpr::Patch(cpr::Url(url+"patch"));
       printResponseText();
    };
    void put() {
        _response = cpr::Put(cpr::Url(url+"put"));
       printResponseText();
    };

    void printResponseText(){
        std::cout << _response.text << std::endl;
    }
};

int main() {
    /*cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/headers")
                                    ,cpr::Header({{"User-Agent","Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36"},{"Accept", "text/html"}
                                        ,{"bla","blabla"}
                                        }));

    //std::cout << r.text << std::endl;

    cpr::Response r2 = cpr::Post(cpr::Url("http://httpbin.org/post")
            , cpr::Payload({{"name", "Alex"}}));

    std::cout << r2.text << std::endl;*/

    USER_REQUEST userRequest;
    std::string cmd;
    while (cmd!="exit") {
        std::cout << "Input cmd: get, post, delete, patch, put: ";
        std::cin >> cmd;
        if (cmd=="get")  userRequest.get();
        else if (cmd=="post")  userRequest.post();
        else if (cmd=="delete")  userRequest._delete();
        else if (cmd=="patch")  userRequest.patch();
        else if (cmd=="put")  userRequest.put();
        else std::cout << "incorrect cmd" << std::endl;
    }



    return 0;
}
