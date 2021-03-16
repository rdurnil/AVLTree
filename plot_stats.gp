
#----------------------------------------------------------------------

# This is a gnuplot script to generate a basic statistics information
# for data structures used in CPSC 223.  This script requires an
# "out.dat" file, which was generated by running:
#
#     ./hw6perf 6 > out.dat
#
# To run this script type the following at the command line
#
#     gnuplot -c plot_script.gp infile testname outfile
#
# For example, to create the output for HW-6, run
# the following from the command line
#
#     gnuplot -c plot_script.gp "out.dat" "Average Chain Length" "avg-chain-len.png"
#
#----------------------------------------------------------------------

infile = ARG1
testname = ARG2
outfile = ARG3

# Set the terminal for PNG output and aspect ratio
set terminal pngcairo enhanced font 'Verdana, 10'
set size ratio 0.75

# Save the graph in the given file name (e.g., "add_end.png")
set output outfile

# Set the title and each axis label
set title testname
set xlabel "Input Size (n)"
set ylabel "Length"

set key noautotitle
set grid
set auto x

set xtics border in scale 0,0 nomirror autojustify
set xtics norangelimit rotate 90
set xrange [0:*] noreverse writeback
set yrange [0:30] noreverse writeback

# Move the key to the left of the graph
set key left

# plot infile u 2:xticlabels(1) t "BST Height" pointtype 7, \
#      infile u 3:xticlabels(1) t "AVL Height" pointtype 7

plot infile u 3:xticlabels(1) t "AVL Height" pointtype 7





