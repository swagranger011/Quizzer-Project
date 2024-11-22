#ifndef _NOT_IMPLEMENTED_EXCEPTION
#define _NOT_IMPLEMENTED_EXCEPTION

#include <stdexcept>
#include <string>
using namespace std;

class NotImplementedException : public runtime_error
{
    public:
    NotImplementedException( string functionName )
        : runtime_error( functionName.c_str() ) { ; }
};

#endif
