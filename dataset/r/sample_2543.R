generate_sequence <- function(n) {
  sequence <- c()
  for (i in 0:(n-1)) {
    sequence[i+1] <- i * (i + 1) %/% 2
  }
  return(sequence)
}

analyze_sequence <- function(seq) {
  result <- list()
  for (index in seq_along(seq)) {
    value <- seq[index]
    result[[as.character(value)]] <- index
  }
  return(result)
}

main <- function() {
  seq <- generate_sequence(10)
  analysis <- analyze_sequence(seq)
  print(analysis)
}

main()