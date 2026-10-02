library(Rcpp)

# Define the Coordinate class
Coordinate <- R6::R6Class("Coordinate",
  public = list(
    x = 0.0,
    y = 0.0,
    z = 0.0,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    distance_to = function(other) {
      dx <- self$x - other$x
      dy <- self$y - other$y
      dz <- self$z - other$z
      return(sqrt(dx^2 + dy^2 + dz^2))
    }
  )
)

# Define the Transformation class
Transformation <- R6::R6Class("Transformation",
  public = list(
    angle = 0.0,
    axis = NULL,
    initialize = function(angle, axis) {
      self$angle <- angle
      self$axis <- axis
    },
    rotate = function(point) {
      x <- point$x
      y <- point$y
      z <- point$z
      u <- self$axis$x
      v <- self$axis$y
      w <- self$axis$z
      cos_a <- cos(self$angle)
      sin_a <- sin(self$angle)
      norm <- sqrt(u^2 + v^2 + w^2)
      u <- u / norm
      v <- v / norm
      w <- w / norm
      x_new <- (u^2 + (1 - u^2) * cos_a) * x + (u * v * (1 - cos_a) - w * sin_a) * y + (u * w * (1 - cos_a) + v * sin_a) * z
      y_new <- (u * v * (1 - cos_a) + w * sin_a) * x + (v^2 + (1 - v^2) * cos_a) * y + (v * w * (1 - cos_a) - u * sin_a) * z
      z_new <- (u * w * (1 - cos_a) - v * sin_a) * x + (v * w * (1 - cos_a) + u * sin_a) * y + (w^2 + (1 - w^2) * cos_a) * z
      return(Coordinate$new(x_new, y_new, z_new))
    }
  )
)

transform_sequence <- function(points, transformations) {
  transformed_points <- list()
  for (point in points) {
    for (transform in transformations) {
      point <- transform$rotate(point)
    }
    transformed_points <- c(transformed_points, list(point))
  }
  return(transformed_points)
}

main <- function() {
  points <- list(Coordinate$new(1.0, 2.0, 3.0), Coordinate$new(4.0, 5.0, 6.0))
  transformations <- list(Transformation$new(pi / 4, Coordinate$new(1, 0, 0)), Transformation$new(pi / 4, Coordinate$new(0, 1, 0)), Transformation$new(pi / 4, Coordinate$new(0, 0, 1)))
  while (TRUE) {
    transformed_points <- transform_sequence(points, transformations)
    for (point in transformed_points) {
      cat("(", point$x, ", ", point$y, ", ", point$z, ")\n", sep = "")
    }
    points <- transformed_points
  }
}

main()