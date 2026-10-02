seq_gen <- function(n) {
  a <- 0
  b <- 1
  sequence <- c()
  for (i in 1:n) {
    sequence <- c(sequence, a)
    temp <- a
    a <- b
    b <- temp + b
  }
  return(sequence)
}

consensus_mechanism <- function(seq) {
  result <- c()
  for (i in 2:length(seq)) {
    diff <- seq[i] - seq[i - 1]
    result <- c(result, diff)
  }
  return(result)
}

main <- function() {
  n <- 10
  sequence <- seq_gen(n)
  consensus <- consensus_mechanism(sequence)
  print(consensus)
}

main()