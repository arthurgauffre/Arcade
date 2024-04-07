/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <Arcade.hpp>

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
      throw arcade::LibraryLoadException();
      exit(1);
    }
  }

  ~DLLoader()
  {
    if (handle)
      dlclose(handle);
  }

  T getInstance(const std::string &funcName)
  {
    void *sym = dlsym(handle, funcName.c_str());
    if (!sym) {
      std::cerr << dlerror() << std::endl;
      throw arcade::NoEntryPointException();
      exit(1);
    }
    return reinterpret_cast<T (*)()>(sym)();
  }
};

#endif /* !DLLOADER_HPP_ */