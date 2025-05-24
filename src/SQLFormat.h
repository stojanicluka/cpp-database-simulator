#ifndef MYDBMS_SQLFORMAT_H
#define MYDBMS_SQLFORMAT_H

/* Contains the definition of the SQLFormat class */

#include "Format.h"

// Class is an abstraction of the SQLFormat
// and provides a formatting interface
class SQLFormat : public Format {
public:

    // Formats a database for writing data into a file
    std::string formatDatabase(Database *db) const override;
};


#endif
