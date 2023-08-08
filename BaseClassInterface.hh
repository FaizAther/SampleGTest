#ifndef __BASE_CLASS_INTERFACE_H__
#define __BASE_CLASS_INTERFACE_H__


class BaseClassInterface {
  virtual int foo();
  virtual const int bar(int);
};

int BaseClassInterface::foo() {
  return 5;
}

const int BaseClassInterface::bar(int a) {
  return a;
}

#endif // __BASE_CLASS_INTERFACE_H__