track_sequence <- function(seq, precision) {
  threshold <- 10^(-precision)
  for (i in 2:length(seq)) {
    if (abs(seq[i] - seq[i - 1]) < threshold) {
      return(i)
    }
  }
  return(-1)
}

main <- function() {
  sequence <- c(0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002)
  precision <- 9
  index <- track_sequence(sequence, precision)
  if (index != -1) {
    cat('Precision achieved at index:', index, '\n')
  } else {
    cat('No precision match found\n')
  }
}

main()