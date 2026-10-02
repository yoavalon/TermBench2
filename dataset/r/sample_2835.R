generate_sequence <- function(n) {
  sequence <- c()
  for (i in 0:(n-1)) {
    sequence <- c(sequence, sin(i) + cos(i))
  }
  return(sequence)
}

vectorize_data <- function(data) {
  vectorized <- list()
  for (item in data) {
    vectorized <- c(vectorized, list(c(item, item^2, item^3)))
  }
  return(vectorized)
}

main <- function() {
  while (TRUE) {
    n <- 10
    sequence <- generate_sequence(n)
    vectorized_data <- vectorize_data(sequence)
    print(vectorized_data)
  }
}

main()