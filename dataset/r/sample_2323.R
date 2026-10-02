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

Coordinate <- R6::R6Class("Coordinate",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    to_list = function() {
      return(c(self$x, self$y, self$z))
    }
  )
)

generate_transformation_matrix <- function(angle_x, angle_y, angle_z) {
  cos_x <- cos(angle_x)
  sin_x <- sin(angle_x)
  cos_y <- cos(angle_y)
  sin_y <- sin(angle_y)
  cos_z <- cos(angle_z)
  sin_z <- sin(angle_z)
  matrix <- rbind(
    c(cos_y * cos_z, cos_y * sin_z, -sin_y),
    c(sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y),
    c(cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y)
  )
  return(matrix)
}

main <- function() {
  angle_x <- 0.1
  angle_y <- 0.2
  angle_z <- 0.3
  transformation_matrix <- generate_transformation_matrix(angle_x, angle_y, angle_z)
  transformation <- Transformation$new(matrix = transformation_matrix)
  coordinate <- Coordinate$new(x = 1.0, y = 2.0, z = 3.0)
  while (TRUE) {
    transformed_vector <- transformation$apply(coordinate$to_list())
    coordinate <- Coordinate$new(x = transformed_vector[1], y = transformed_vector[2], z = transformed_vector[3])
  }
}

main()