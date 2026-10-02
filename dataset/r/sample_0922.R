library(matrixcalc)

non_term_func <- function(a, b) {
  c <- a %*% b
  non_term_func(c, b)
}

main <- function() {
  a <- matrix(runif(9), nrow = 3, ncol = 3)
  b <- matrix(runif(9), nrow = 3, ncol = 3)
  non_term_func(a, b)
}

main()