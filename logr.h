#ifndef __CPP_LOGR_H_
#define __CPP_LOGR_H_

#include <memory>
#include <string>

namespace logr {

class Error;
using std::string;

class InfoLogger {
  public:
    template <typename... Args>
    void Info(const string &msg, const Args &... args);

    bool Enabled();
};

class Logger : public InfoLogger {
  public:
    template <typename... Args>
    Logger WithValues(const Args &... keysAndValues);

    Logger WithName(const string &name);

    template <typename... Args>
    void Error(Error err, const string &msg, const Args &... keysAndValues);

    InfoLogger V(int level);
};

} // namespace logr

#endif // __CPP_LOGR_H_