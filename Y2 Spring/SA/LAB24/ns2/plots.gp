# This file includes commands for gnuplot.
# It provides also the command hints to produce your plots.
# The current uncommented commands are complete and ready to produce the first required plot for X.

# To obtain the plot using the gnuplot command, type:
# gnuplot plots.gp

# To generate a new figure, modify the title, 
# xlabel and ylabel and comment/uncomment the adequate instructions.

set title 'Output rate as a function of {/Symbol l}'
set xlabel '{/Symbol l}'
set ylabel 'X'

set term postscript eps enhanced color "Times-Roman" 22
set output 'X.eps'

# set output 'R.eps'
# set output 'Q.eps'

# plot the 7th field of the file res1 as a function of the 1st field
plot "res1" using 1:7 t "X" w lp 

# plot "res1" using 1:8 t "R" w lp 
# plot "res1" using 1:10 t "Q" w lp 

# Plotting with confidence intervals
# plot "res2" using 1:8:11 notitle w yerrorbars pt 0, "res2" using 1:8 t "X" w lines lt 2 lw 4

# Plotting several curves on the same figure
# plot "res1" using 1:7 t "X simul" w lp, "model" using 1:2 t "X theo" w lp
# plot "res1" using 1:7 t "R simul" w lp, "model" using 1:3 t "R theo" w lp
# plot "res1" using 1:9 t "Q simul" w lp, "model" using 1:4 t "Q theo" w lp


