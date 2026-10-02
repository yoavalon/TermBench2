library(Matrix)

matrix_op <- function(a, b, depth) {
  if (depth == 0) {
    return(a)
  }
  return(a %*% matrix_op(b, a, depth - 1))
}

main <- function() {
  a <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  b <- matrix(c(2, 0, 1, 2), nrow = 2, byrow = TRUE)
  result <- matrix_op(a, b, 3)
  print(result)
}

main()