# Gaffer Code Examples


## Deformer Example

This is a simple C++ node which deforms a high resolution mesh using a lower resolution cage.


### Build Instructions

**Requires:**

* cmake
* Gaffer Install

**In a terminal:**

> Note this will add files to your existing gaffer installation, so either backup your gaffer install or be prepared to reinstall if there are problems.

```
cd DeformerExample
mkdir .build
cd .build
cmake  -DGAFFER_ROOT=<gaffer install path> -DCMAKE_INSTALL_PREFIX=<gaffer install path> ..
make install -j <num cores>
```
