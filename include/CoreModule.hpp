/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#ifndef COREMODULE_HPP_
#define COREMODULE_HPP_

class CoreModule {
public:
  CoreModule();
  ~CoreModule();
  enum CoreStatus { RUNNING, SELECTION };
  void setCoreStatus(CoreStatus status);
  CoreStatus getCoreStatus() const;
protected:
  CoreStatus _coreStatus;
};

#endif /* !COREMODULE_HPP_ */
