#ifndef BLOCKBUILDER_H
#define BLOCKBUILDER_H

#include "Block.h"
#include "BlockWriter.h"

class Terminator;
class DynamicTerminator;
class RegularTerminator;

class BlockBuilder
{
public:
    BlockBuilder();
    BlockBuilder(int blockSize);

    void insertCommand(const Command& command);
    Block getBlock();
    void subscribe(BlockWriter* blockWriter);

    void setTerminator(Terminator *terminator);

private:
    std::vector<Command> m_commands;
    std::vector<BlockWriter*> m_blockWriters;
    Terminator *m_terminator;
};

class Terminator {
public:
    Terminator (BlockBuilder* builder)
        : m_builder(builder) {}
    virtual bool checkFinish(const Command& command) = 0;

protected:
    BlockBuilder* m_builder;
};

class RegularTerminator : public Terminator {
public:
    RegularTerminator(BlockBuilder* builder)
        : Terminator(builder) {}

    bool checkFinish(const Command &command) override;

    static void setCommandSize(int value) {
        commandSize = value;
    }
private:
    static int commandSize;
    int commandCount = 0;
};

class DynamicTerminator : public Terminator {
public:
    DynamicTerminator(BlockBuilder* builder)
        : Terminator(builder) {}

    bool checkFinish(const Command &command) override;

private:
    int m_counter = 0;
};

#endif // BLOCKBUILDER_H

