#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include "BlockWriter.h"

class ConsoleWriter : public BlockWriter
{
public:
    ConsoleWriter();
    void write(const Block &block) override;
};

#endif // CONSOLEWRITER_H
