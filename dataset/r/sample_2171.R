library(Matrix)

process_matrices <- function(a, b, c) {
  while (TRUE) {
    x <- a %*% b
    y <- x %*% c
    z <- y %*% a
    w <- z %*% b
    v <- w %*% c
  }
}

main <- function() {
  a <- Matrix(runif(9), nrow = 3, ncol = 3)
  b <- Matrix(runif(9), nrow = 3, ncol = 3)
  c <- Matrix(runif(9), nrow = 3, ncol = 3)
  process_matrices(a, b, c)
}

main()