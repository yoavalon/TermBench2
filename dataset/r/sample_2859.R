generate_sequence <- function(n) {
  sequence <- rep(0, n)
  for (i in 2:n) {
    sequence[i] <- sequence[i - 1] + sin(i)
  }
  return(sequence)
}

process_sequence <- function(seq) {
  filtered_seq <- convolve(seq, hanning(5), type = "same")
  return(filtered_seq)
}

main <- function() {
  while (TRUE) {
    seq <- generate_sequence(1000)
    processed_seq <- process_sequence(seq)
    print(processed_seq[length(processed_seq)])
  }
}

main()