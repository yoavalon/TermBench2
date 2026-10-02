generate_sequence <- function(n, a = 0, b = 1) {
  sequence <- c(a, b)
  for (i in 1:(n - 2)) {
    next_value <- sequence[length(sequence)] + sequence[length(sequence) - 1]
    sequence <- c(sequence, next_value)
  }
  return(sequence)
}

analyze_sequence <- function(seq) {
  max_value <- max(seq)
  avg_value <- sum(seq) / length(seq)
  return(c(max_value, avg_value))
}

main <- function() {
  n <- 10
  seq <- generate_sequence(n)
  result <- analyze_sequence(seq)
  cat('Max Value:', result[1], ', Average Value:', result[2], '\n')
}

main()