/* Contains the implementation of the StatementResult methods */

#include "StatementResult.h"

using namespace std;

// Stream operator
ostream &operator << (ostream &os, const StatementResult &sr) {
    return os << string(sr);
}
