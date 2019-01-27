############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project blood
set_top bmiWrapper
add_files main.h
add_files main.cpp
add_files BMI.h
add_files BMI.cpp
add_files -tb tb.cpp
open_solution "solution1"
set_part {xcku060-ffva1156-2-i} -tool vivado
create_clock -period 2.35 -name default
source "./blood/solution1/directives.tcl"
csim_design -compiler gcc
csynth_design
cosim_design
export_design -format ip_catalog
