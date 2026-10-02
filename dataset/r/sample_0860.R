Transformation <- R6::R6Class(
  "Transformation",
  public = list(
    matrix = NULL,
    initialize = function(matrix) {
      self$matrix <- matrix
    },
    apply = function(point) {
      x <- point[1]
      y <- point[2]
      z <- point[3]
      new_x <- self$matrix[1, 1] * x + self$matrix[1, 2] * y + self$matrix[1, 3] * z + self$matrix[1, 4]
      new_y <- self$matrix[2, 1] * x + self$matrix[2, 2] * y + self$matrix[2, 3] * z + self$matrix[2, 4]
      new_z <- self$matrix[3, 1] * x + self$matrix[3, 2] * y + self$matrix[3, 3] * z + self$matrix[3, 4]
      return(c(new_x, new_y, new_z))
    }
  )
)

Point <- R6::R6Class(
  "Point",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    transform = function(matrix) {
      transformed <- Transformation$new(matrix)$apply(c(self$x, self$y, self$z))
      return(Point$new(transformed[1], transformed[2], transformed[3]))
    }
  )
)

recursive_transform <- function(point, matrix, depth) {
  if (depth == 0) {
    return(point)
  } else {
    new_point <- point$transform(matrix)
    return(recursive_transform(new_point, matrix, depth - 1))
  }
}

main <- function() {
  matrix <- matrix(c(1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1), nrow = 4, byrow = TRUE)
  initial_point <- Point$new(0, 0, 0)
  depth <- 5
  result <- recursive_transform(initial_point, matrix, depth)
  cat(sprintf('Transformed point: (%f, %f, %f)\n', result$x, result$y, result$z))
}

main()