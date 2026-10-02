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
    add = function(other) {
      Vector$new(self$x + other$x, self$y + other$y, self$z + other$z)
    },
    scale = function(factor) {
      Vector$new(self$x * factor, self$y * factor, self$z * factor)
    },
    repr = function() {
      paste("Vector(", self$x, ", ", self$y, ", ", self$z, ")", sep = "")
    }
  )
)

Matrix <- R6::R6Class("Matrix",
  public = list(
    a11 = NULL,
    a12 = NULL,
    a13 = NULL,
    a21 = NULL,
    a22 = NULL,
    a23 = NULL,
    a31 = NULL,
    a32 = NULL,
    a33 = NULL,
    initialize = function(a11, a12, a13, a21, a22, a23, a31, a32, a33) {
      self$a11 <- a11
      self$a12 <- a12
      self$a13 <- a13
      self$a21 <- a21
      self$a22 <- a22
      self$a23 <- a23
      self$a31 <- a31
      self$a32 <- a32
      self$a33 <- a33
    },
    multiply = function(vector) {
      x <- self$a11 * vector$x + self$a12 * vector$y + self$a13 * vector$z
      y <- self$a21 * vector$x + self$a22 * vector$y + self$a23 * vector$z
      z <- self$a31 * vector$x + self$a32 * vector$y + self$a33 * vector$z
      Vector$new(x, y, z)
    },
    repr = function() {
      paste("Matrix(", self$a11, ", ", self$a12, ", ", self$a13, ", ", self$a21, ", ", self$a22, ", ", self$a23, ", ", self$a31, ", ", self$a32, ", ", self$a33, ")", sep = "")
    }
  )
)

transform_vector <- function(matrix, vector, depth) {
  if (depth == 0) {
    return(vector)
  }
  transformed <- matrix$ multiply(vector)
  transform_vector(matrix, transformed, depth - 1)
}

main <- function() {
  vector <- Vector$new(1, 2, 3)
  matrix <- Matrix$new(1, 0, 0, 0, 1, 0, 0, 0, 1)
  depth <- 5
  result <- transform_vector(matrix, vector, depth)
  cat(result$repr(), "\n")
}

main()