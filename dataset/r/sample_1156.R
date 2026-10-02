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
    rotate_x = function(angle) {
      rad <- angle * pi / 180
      cos_val <- cos(rad)
      sin_val <- sin(rad)
      return(Coordinate$new(self$x, self$y * cos_val - self$z * sin_val, self$y * sin_val + self$z * cos_val))
    },
    rotate_y = function(angle) {
      rad <- angle * pi / 180
      cos_val <- cos(rad)
      sin_val <- sin(rad)
      return(Coordinate$new(self$x * cos_val + self$z * sin_val, self$y, -self$x * sin_val + self$z * cos_val))
    },
    rotate_z = function(angle) {
      rad <- angle * pi / 180
      cos_val <- cos(rad)
      sin_val <- sin(rad)
      return(Coordinate$new(self$x * cos_val - self$y * sin_val, self$x * sin_val + self$y * cos_val, self$z))
    }
  )
)

transform <- function(coord, angle, axis) {
  if (axis == 'x') {
    return(coord$rotate_x(angle))
  } else if (axis == 'y') {
    return(coord$rotate_y(angle))
  } else if (axis == 'z') {
    return(coord$rotate_z(angle))
  }
  return(coord)
}

recursive_transform <- function(coord, angle, axis) {
  new_coord <- transform(coord, angle, axis)
  return(recursive_transform(new_coord, angle, axis))
}

main <- function() {
  initial_coord <- Coordinate$new(1, 0, 0)
  final_coord <- recursive_transform(initial_coord, 90, 'z')
  print(paste(final_coord$x, final_coord$y, final_coord$z))
}

main()