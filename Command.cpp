#include "Command.h"

#include <iostream>

Command::Command(const std::string &line)
    : m_line(line)
{
    m_timeStamp = std::time(nullptr);
    std::cout << "Command line: " << line << " CommandType: " << static_cast<int>( commandType() ) << std::endl;
}

std::string Command::line() const
{
    return m_line;
}

std::time_t Command::timeStamp() const
{
    return m_timeStamp;
}

Command::CommandType Command::commandType() const
{
    if (m_line.size() == 2) {
        switch ( m_line[0] ) {
        case '{':
            return CommandType::OpenBrace;
        case '}':
            return CommandType::CloseBrce;
        case EOF:
            return CommandType::Eof;
        default:
            break;
        }
    }
    return CommandType::Line;
}

std::ostream& operator<<(std::ostream &os, const Command &command)
{
    return os << command.line();
}
