matrix_multiply <- function(A, B) {
  if (ncol(A) != nrow(B)) {
    stop("Dimension mismatch")
  }
  result <- matrix(0, nrow(A), ncol(B))
  for (i in 1:nrow(A)) {
    for (j in 1:ncol(B)) {
      for (k in 1:nrow(B)) {
        result[i, j] <- result[i, j] + A[i, k] * B[k, j]
      }
    }
  }
  return(result)
}

forward_pass <- function(weights, inputs) {
  for (weight in weights) {
    inputs <- matrix_multiply(weight, inputs)
  }
  return(inputs)
}

main <- function() {
  weights <- array(c(0.5, 0.2, 0.1, 0.8, 0.4, 0.6, 0.7, 0.3), dim = c(2, 2, 2))
  inputs <- matrix(c(1, 2), nrow = 2)
  output <- forward_pass(weights, inputs)
  print(output)
}

main()