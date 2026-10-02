library(abind)

Coordinate <- setRefClass("Coordinate",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    rotate_x = function(angle) {
      angle_rad <- angle * pi / 180
      cos_val <- cos(angle_rad)
      sin_val <- sin(angle_rad)
      self$y <- self$y * cos_val - self$z * sin_val
      self$z <- self$y * sin_val + self$z * cos_val
    },
    rotate_y = function(angle) {
      angle_rad <- angle * pi / 180
      cos_val <- cos(angle_rad)
      sin_val <- sin(angle_rad)
      self$x <- self$x * cos_val + self$z * sin_val
      self$z <- -self$x * sin_val + self$z * cos_val
    },
    rotate_z = function(angle) {
      angle_rad <- angle * pi / 180
      cos_val <- cos(angle_rad)
      sin_val <- sin(angle_rad)
      self$x <- self$x * cos_val - self$y * sin_val
      self$y <- self$x * sin_val + self$y * cos_val
    }
  )
)

generate_sequence <- function(start, increment, length) {
  sequence <- vector("list", length)
  for (i in 1:length) {
    sequence[[i]] <- start
    start <- start + increment
  }
  return(sequence)
}

apply_transformation <- function(sequence, angle_x, angle_y, angle_z) {
  for (i in 1:length(sequence)) {
    coord_obj <- Coordinate$new(x = sequence[[i]][1], y = sequence[[i]][2], z = sequence[[i]][3])
    coord_obj$rotate_x(angle_x)
    coord_obj$rotate_y(angle_y)
    coord_obj$rotate_z(angle_z)
    sequence[[i]] <- c(coord_obj$x, coord_obj$y, coord_obj$z)
  }
}

main <- function() {
  start_point <- c(0, 0, 0)
  increment <- c(1, 1, 1)
  sequence_length <- 100
  sequence <- generate_sequence(start_point, increment, sequence_length)
  angle_x <- 5
  angle_y <- 5
  angle_z <- 5
  while (TRUE) {
    apply_transformation(sequence, angle_x, angle_y, angle_z)
    angle_x <- angle_x + 1
    angle_y <- angle_y + 1
    angle_z <- angle_z + 1
  }
}

main()