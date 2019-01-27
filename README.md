# High-Level-Synthesis
In high-level synthesis, a tool preforms the conversion of a procedural or object-oriented programming language to hardware design at RTL level. In this way it is possible to get high level languages such as C, C++ and MATLAB to transform into VHDL or Verilog. In this project, an efficient cross-talk-preventing algorithm on the FPGA using C++ has been implemented. The figure underneath shows where HLS is located in the design process.

An algorithm in a high-level language is easier to write because the emphasis is on an algorithmic approach. Because of this decline in design complexity, the user does not have to break his head about issues that are at lower level, resulting in fewer mistakes. Because the user works at a high level of abstraction, less code will have to be written and functional verification is very fast. Errors can be detected early. In addition, the conversion to VHDL or Verilog and verification of this generated code occurs in a relatively short time and automatically. In this way, companies are able to bring a product onto the market much faster and to stay ahead of the competition.

# Usage
The C++ code can be found in the SRC and FFT folder. The code has been optimized for a tool like Vivado or Catapult. Be aware that not every concept in C++ can be translated. The concepts in C++ which can (not) be translated with HLS are therefore discussed.

# Report
I made an in depth report (~50 pages) with a presentation. You can find this in the report folder. The final design and optimizations are discussed, as well as the advantages and disadvantages with high level synthesis. This can be relevant for designers.

![hls](https://user-images.githubusercontent.com/9694230/51801755-2b3b4000-2242-11e9-8164-69174ce01e67.PNG)
