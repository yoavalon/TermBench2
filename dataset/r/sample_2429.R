generate_sequence <- function(n) {
  sequence <- rep(0, n)
  sequence[1] <- 0
  sequence[2] <- 1
  for (i in 3:n) {
    sequence[i] <- sequence[i - 1] + sequence[i - 2]
  }
  return(sequence)
}

main <- function() {
  data <- generate_sequence(10)
  print(data)
}

main()