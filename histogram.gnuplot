set terminal postscript eps color enhanced "Times-Roman" 24
set output "histogram.eps"
set size 2.2,2.2
set title 'Histogram of One Batch of 100000 U(0,1) Pseudo-Random Numbers'
set xrange [0:1]
set xlabel "random number (interval width = 0.01)"
set ylabel "frequency" 
set yrange [0:2]
set style fill solid 0.3
set xtics 0,0.1,1
set tics out nomirror
plot 'cmake-build-debug/histogram_coords' u 1:2 smooth freq w boxes lc rgb"blue" notitle
