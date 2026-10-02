process_matrices <- function() {
  library(matrixcalc)
  
  a <- random.matrix(10, 10)
  b <- random.matrix(10, 10)
  
  while (TRUE) {
    a <- a %*% b
    b <- b %*% a
  }
}

process_matrices()