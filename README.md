# organic - A simulated and evolving universe.

### What is it?
In short - it's an evolution simulator through random bit changes of small, self-copying, self-modifying programs. Think bacteria, and the DNA is their machine code. The petri-dish, our simulated universe, is a very tiny and custom RTOS kernel, written for the Arm architecture.

Introducing this random (and very low) copy error-factor on a program's copying of its machine code to a new location will likely result in invalid CPU instructions, or combinations of instructions, 99.999% of the time. My hope is, however, given a couple billion generations of these 'organisms', a few of those copy errors will result in a viable sequence of bits that, while different from its parents, is still able to reproduce itself.

There is _much_ to do still, and it may not be entirely possible, due to some technological oversight on my part. But it's making for a fun summer project so far, and I welcome any and all contributions.

### Getting Started  
For information on how to set up the development environment and build organic, [please refer to the wiki here](https://github.com/tegan-lamoureux/organic/wiki).
