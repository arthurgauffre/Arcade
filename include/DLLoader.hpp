#include <dlfcn.h>
#include <iostream>

template <typename T>
class DLLoader {
private:
  void *handle;

public:
  DLLoader(const std::string &libPath)
  {
    handle = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!handle) {
      std::cerr << dlerror() << std::endl;
      exit(1);
    }
  }

  ~DLLoader()
  {
    if (handle)
      dlclose(handle);
  }

  T *getInstance(const std::string &funcName)
  {
    void *sym = dlsym(handle, funcName.c_str());
    if (!sym) {
      std::cerr << dlerror() << std::endl;
      exit(1);
    }
    return reinterpret_cast<T *(*)()>(sym)();
  }
};