#ifndef MYDBMS_FORMAT_H
#define MYDBMS_FORMAT_H

/* Contains the definition of the Format class */

#include <iostream>
#include <string>
#include "Database.h"

// Class is an abstraction of the export format
// and provides a formatting interface
class Format {
public:

    // Formats a database for writing data into a file
    virtual std::string formatDatabase(Database *db) const = 0;
};

#endif
