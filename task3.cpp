#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <map>

class USER_REQUEST
{
    const std::string url_get = "http://httpbin.org/get&";
    const std::string url_post = "http://httpbin.org/post";
    std::map<std::string, std::string> args;

public:
    USER_REQUEST() {};

    void get_and_pars_args(std::string &value)
    {
        int pos = value.find(' ');
        std::string _key = value.substr(0,pos) , _value = value.substr(pos+1, value.length());

        args.insert(make_pair(_key,_value));
    }

    std::string create_user_get_request()
    {
        std::string request_url = this->url_get;
        int args_size = args.size()-1;
        for (std::map<std::string,std::string>::iterator it = args.begin(); it!=args.end();++it) {

            request_url+=it->first+'='+it->second+(args_size!=0 ? '?' : ' ');
            --args_size;
        }
        return request_url;
    };


};

int main()
{
#ifdef true
    while (true)
    {
        cpr::Response r;
        std::string $value;
        USER_REQUEST* ur = new USER_REQUEST();
        std::cout << "If you want to determ the way of request: input get or post" << std::endl;
        while (true) {
            std::cout << "Input key,value: ";
            std::getline(std::cin, $value);
            if($value=="get") {
                r = cpr::Get(cpr::Url(ur->create_user_get_request()));
                std::cout << r.text << std::endl;
                delete ur;
                break;
            }

            if ($value=="exit") {
                std::cout << "Good luck!" << std::endl;
                return 0;
            }

            ur->get_and_pars_args($value);
        }
    }
#endif


}