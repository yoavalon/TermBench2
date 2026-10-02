forward_pass <- function(matrix, vector) {
  result <- matrix %*% vector
  return(result)
}

main <- function() {
  A <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  b <- c(5, 6)
  output <- forward_pass(A, b)
  print(output)
}

main()