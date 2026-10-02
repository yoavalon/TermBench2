data_mutations <- function() {
  x <- 1.0
  decay <- 0.9
  epsilon <- 0.001
  while (x > epsilon) {
    x <- x * decay
  }
  return(x)
}

data_mutations()