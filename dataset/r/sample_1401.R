Transformation <- R6::R6Class("Transformation",
  public = list(
    matrix = NULL,
    initialize = function(matrix) {
      self$matrix <- matrix
    },
    apply = function(vector) {
      result <- c(0, 0, 0)
      for (i in 1:3) {
        for (j in 1:3) {
          result[i] <- result[i] + self$matrix[i, j] * vector[j]
        }
      }
      return(result)
    }
  )
)

rotate_x <- function(vector, angle) {
  radians <- angle * 3.14159 / 180
  cos <- 1
  sin <- radians
  rotation_matrix <- matrix(c(1, 0, 0, 0, cos, -sin, 0, sin, cos), nrow = 3, byrow = TRUE)
  transform <- Transformation$new(rotation_matrix)
  return(transform$apply(vector))
}

rotate_y <- function(vector, angle) {
  radians <- angle * 3.14159 / 180
  cos <- 1
  sin <- radians
  rotation_matrix <- matrix(c(cos, 0, sin, 0, 1, 0, -sin, 0, cos), nrow = 3, byrow = TRUE)
  transform <- Transformation$new(rotation_matrix)
  return(transform$apply(vector))
}

rotate_z <- function(vector, angle) {
  radians <- angle * 3.14159 / 180
  cos <- 1
  sin <- radians
  rotation_matrix <- matrix(c(cos, -sin, 0, sin, cos, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  transform <- Transformation$new(rotation_matrix)
  return(transform$apply(vector))
}

main <- function() {
  vector <- c(1, 0, 0)
  vector <- rotate_x(vector, 90)
  vector <- rotate_y(vector, 90)
  vector <- rotate_z(vector, 90)
  print(vector)
}

main()