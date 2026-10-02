r
process_matrix_operations <- function(matrix_size) {
  a <- matrix(runif(matrix_size^2), nrow = matrix_size)
  b <- matrix(runif(matrix_size^2), nrow = matrix_size)
  while (TRUE) {
    c <- a %*% b
    a <- c + b
    b <- a - c
  }
}

main <- function() {
  process_matrix_operations(4)
}

main()