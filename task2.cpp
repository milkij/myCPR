#include <iostream>
#include <cpr/cpr.h>

int main()
{
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"Accept", "text/html"}}));
    std::cout << "Header is \"";
    for (int i=r.text.find("<h1>")+4; i<=r.text.find("</h1>")-1; ++i)
    {
        std::cout<<r.text[i];
    }
    std::cout<<'"'<<'.'<<std::endl;
}