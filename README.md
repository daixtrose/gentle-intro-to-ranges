# A Gentle Introduction to Ranges v3

> This talk was given on May 17, 2018 at [CUG Aachen](http://www.wilkening-online.de/programmieren/c++-treffen-aachen.html)
## Disclaimer

- This is not "The Complete Guide", but 
  - just a gentle **introduction**
  - a user's view on ranges
  - focus is more on getting the basic ideas (tutorial) 
- You can download this talk **and** code samples in the form of unit tests
  - https://github.com/daixtrose/gentle-intro-to-ranges
- This talk and code are published under MIT licence
 - Code for talk framework based on remark.js was stolen from [Kirk Shoop's Intro to RxCpp](https://github.com/kirkshoop/introductionToRxcpp) 
 - Please contribute fixes or [file an issue](https://github.com/daixtrose/gentle-intro-to-ranges/issues) if you find errors or know about improvements. 
  

## Disclaimer 2

The unit tests in this repository are demos. They do not aim at a full test of the library, but serve only as illustration of the feature behaviors. 
## How to use this code

### Retrieve this repository

```bash
git clone --recursive https://github.com/daixtrose/gentle-intro-to-ranges
cd gentle-intro-to-ranges
``` 

### Read the talk

Open `talk/a-gentle-intro-to-ranges-v3.html` in a decent web browser, press F11, then enjoy.

### Prepare for a build

```bash
mkdir build
cd build
cmake ..
```

### Build 

```bash
make
```

### Test

Execute 
```bash
make test
```
or 
```bash
ctest -VV
```
for detailed information.
