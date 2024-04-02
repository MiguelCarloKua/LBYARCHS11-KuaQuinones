# LBYARCH x86-to-C Programming Documentation

**Authors:**
- Miguel Carlo Kua
- Angelo Yanto Quinones


### Note

The rest of the pictures 


## Introduction

This documentation provides an overview of the performance comparison between x86 assembly and C implementations for a computational task, specifically calculating the powers of a given input and the performance observed in both debug and release modes.

## Performance Overview

The comparison is based on program runs with the input value "20". The C and assembly implementations have shown a significant gap in performance, especially notable in debug mode. This assessment is supported by the figures derived from the initial runs of the program.

### Observations:

![Figure 1: Input 15 in Debug Mode]([image]https://github.com/MiguelCarloKua/LBYARCHS11-KuaQuinones/blob/main/screenshots/debug/15debug.png)

![Figure 2: Input 15 in Release Mode]((https://github.com/MiguelCarloKua/LBYARCHS11-KuaQuinones/blob/main/screenshots/release/Screenshot%202024-04-02%20203923.png))

![Figure 3: Input 20 in Debug Mode]([image](https://github.com/MiguelCarloKua/LBYARCHS11-KuaQuinones/blob/main/screenshots/debug/20debug.png))

![Figure 4: Input 20 in Release Mode]([image](https://github.com/MiguelCarloKua/LBYARCHS11-KuaQuinones/blob/main/screenshots/release/Screenshot%202024-04-02%20203812.png))

- For 3 iterations, the function iterates to calculate \( n \), \( n+4 \), and \( n+10 \) powers, simulating the powers of 20, 24, and 30, respectively.
- Both debug and release modes showed a consistent gap in performance between the C and assembly versions.
- The C implementation exhibited a more significant difference in runtimes between the debug (approximately 4 seconds) and release modes (approximately 1.6 seconds) when computing the 30th power.
- Assembly performance was consistent across both modes, without significant deviation.

## Conclusion

These observations highlight the efficiency of assembly language for executing tasks with fewer instructions and less resource overhead, particularly for complex computations such as the scalar dot product. The consistency in assembly's runtime, regardless of the mode, suggests its suitability for scenarios where performance is a critical requirement.
