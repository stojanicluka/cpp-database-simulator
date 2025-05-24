#ifndef MYDBMS_CUSTOMFORMAT_H
#define MYDBMS_CUSTOMFORMAT_H

/* Contains the CustomFormat class definition */

#include "Format.h"

// Class is an abstraction of the CustomFormat
// and provides a formatting interface
class CustomFormat : public Format {
public:

    // Formats a database for writing data into a file
    std::string formatDatabase(Database *db) const override;
};


#endif
