TransformationMatrix <- R6::R6Class("TransformationMatrix",
  public = list(
    matrix = NULL,
    initialize = function(matrix) {
      self$matrix <- matrix
    },
    multiply = function(other) {
      result <- list()
      for (i in 1:nrow(self$matrix)) {
        row <- list()
        for (j in 1:ncol(other$matrix)) {
          sum_val <- 0
          for (k in 1:nrow(other$matrix)) {
            sum_val <- sum_val + self$matrix[i, k] * other$matrix[k, j]
          }
          row[[j]] <- sum_val
        }
        result[[i]] <- row
      }
      return(TransformationMatrix$new(result))
    }
  )
)

Vector <- R6::R6Class("Vector",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    apply_transformation = function(matrix) {
      transformed <- list()
      for (i in 1:nrow(matrix$matrix)) {
        sum_val <- 0
        for (j in 1:ncol(matrix$matrix)) {
          sum_val <- sum_val + matrix$matrix[i, j] * c(self$x, self$y, self$z)[j]
        }
        transformed[[i]] <- sum_val
      }
      return(Vector$new(transformed[[1]], transformed[[2]], transformed[[3]]))
    }
  )
)

generate_transformation_matrix <- function(rotation_angle) {
  cos_val <- cos(rotation_angle)
  sin_val <- sin(rotation_angle)
  return(TransformationMatrix$new(matrix(c(cos_val, -sin_val, 0, sin_val, cos_val, 0, 0, 0, 1), nrow = 3, byrow = TRUE)))
}

main <- function() {
  vector <- Vector$new(runif(1), runif(1), runif(1))
  while (TRUE) {
    rotation_angle <- runif(1) * pi
    transformation_matrix <- generate_transformation_matrix(rotation_angle)
    vector <- vector$apply_transformation(transformation_matrix)
    print(c(vector$x, vector$y, vector$z))
  }
}

main()