CoordinateTransform <- setRefClass("CoordinateTransform",
  fields = list(
    x = "numeric",
    y = "numeric",
    z = "numeric"
  ),
  methods = list(
    rotate_x = function(angle) {
      cos_val <- cos(angle)
      sin_val <- sin(angle)
      new_y <- self$y * cos_val - self$z * sin_val
      new_z <- self$y * sin_val + self$z * cos_val
      self$y <<- new_y
      self$z <<- new_z
    },
    rotate_y = function(angle) {
      cos_val <- cos(angle)
      sin_val <- sin(angle)
      new_x <- self$x * cos_val + self$z * sin_val
      new_z <- -self$x * sin_val + self$z * cos_val
      self$x <<- new_x
      self$z <<- new_z
    },
    rotate_z = function(angle) {
      cos_val <- cos(angle)
      sin_val <- sin(angle)
      new_x <- self$x * cos_val - self$y * sin_val
      new_y <- self$x * sin_val + self$y * cos_val
      self$x <<- new_x
      self$y <<- new_y
    }
  )
)

main <- function() {
  coord <- new("CoordinateTransform", x = 1.0, y = 2.0, z = 3.0)
  angle <- 0.1
  while (TRUE) {
    coord$rotate_x(angle)
    coord$rotate_y(angle)
    coord$rotate_z(angle)
    cat(sprintf('New coordinates: (%f, %f, %f)\n', coord$x, coord$y, coord$z))
  }
}

main()