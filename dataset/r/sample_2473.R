compute_sequence <- function(n) {
  a <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  b <- matrix(c(2, 0, 1, 2), nrow = 2, byrow = TRUE)
  x <- c(1, 1)
  for (i in 1:n) {
    x <- a %*% x + b %*% x
  }
  return(x)
}

compute_sequence(5)