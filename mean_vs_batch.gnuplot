set terminal postscript eps color enhanced "Times-Roman" 24
set output "mean.eps"
set size 2.2,2.2
set title 'Level of Noise for the Mean over 1000 Batches Each Containing 1000000 U(0,1) Pseudo-Random Numbers'
set xrange [1:1000]
set xlabel "batch number"
set ylabel "mean" 
set yrange [0.48:0.52]
set style line 1 lt 1 lw 2 lc rgb"blue"
plot 'cmake-build-debug/sample_mean' u 2:4 w l ls 1 notitle, 0.5 w l lt 1 lw 3 lc rgb"red" title 'Population Mean = 0.5'
