data_mutations <- function(x) {
  w <- matrix(runif(ncol(x) * 10), ncol = 10)
  b <- runif(10)
  z <- x %*% w + b
  a <- pmax(0, z)
  w2 <- matrix(runif(10 * 1), ncol = 1)
  b2 <- runif(1)
  z2 <- a %*% w2 + b2
  return(z2)
}

if (interactive()) {
  x <- matrix(runif(5 * 10), nrow = 5)
  result <- data_mutations(x)
  print(result)
}