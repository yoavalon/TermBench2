Matrix <- R6::R6Class("Matrix",
  public = list(
    data = NULL,
    rows = NULL,
    cols = NULL,
    initialize = function(data) {
      self$data <- data
      self$rows <- nrow(data)
      self$cols <- if (self$rows > 0) ncol(data) else 0
    },
    multiply = function(other) {
      if (self$cols != other$rows) {
        stop('Matrix dimensions do not match for multiplication')
      }
      result <- matrix(0, nrow = self$rows, ncol = other$cols)
      for (i in 1:self$rows) {
        for (j in 1:other$cols) {
          for (k in 1:self$cols) {
            result[i, j] <- result[i, j] + self$data[i, k] * other$data[k, j]
          }
        }
      }
      return(new(Matrix, data = result))
    },
    print = function() {
      cat(paste0(self$data, collapse = "\n"))
    }
  )
)

matrix_multiply_recursive <- function(A, B, result = NULL, i = 1, j = 1, k = 1) {
  if (is.null(result)) {
    result <- matrix(0, nrow = A$rows, ncol = B$cols)
  }
  if (i > A$rows) {
    return(new(Matrix, data = result))
  }
  if (j > B$cols) {
    return(matrix_multiply_recursive(A, B, result, i + 1, 1, 1))
  }
  if (k > A$cols) {
    return(matrix_multiply_recursive(A, B, result, i, j + 1, 1))
  }
  result[i, j] <- result[i, j] + A$data[i, k] * B$data[k, j]
  return(matrix_multiply_recursive(A, B, result, i, j, k + 1))
}

forward_pass <- function(weights, inputs) {
  if (length(weights) == 0) {
    return(inputs)
  }
  next_layer <- weights[[1]]$multiply(inputs)
  return(forward_pass(weights[-1], next_layer))
}

main <- function() {
  A <- new(Matrix, data = matrix(c(1, 2, 3, 4), nrow = 2))
  B <- new(Matrix, data = matrix(c(2, 0, 1, 2), nrow = 2))
  cat("Recursive Matrix Multiplication:\n")
  matrix_multiply_recursive(A, B)$print()
  
  weights <- list(
    new(Matrix, data = matrix(c(1, 0, 0, 1), nrow = 2)),
    new(Matrix, data = matrix(c(2, 3, 4, 5), nrow = 2))
  )
  inputs <- new(Matrix, data = matrix(c(1, 2), nrow = 2))
  cat("\nNeural Network Forward Pass:\n")
  forward_pass(weights, inputs)$print()
}

main()