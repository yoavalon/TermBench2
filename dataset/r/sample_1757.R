CoordinateTransform <- R6::R6Class("CoordinateTransform",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    translate = function(dx, dy, dz) {
      self$x <- self$x + dx
      self$y <- self$y + dy
      self$z <- self$z + dz
    },
    rotate_x = function(angle) {
      rad <- angle * pi / 180
      self$y <- self$y * cos(rad) - self$z * sin(rad)
      self$z <- self$y * sin(rad) + self$z * cos(rad)
    },
    rotate_y = function(angle) {
      rad <- angle * pi / 180
      self$x <- self$x * cos(rad) + self$z * sin(rad)
      self$z <- -self$x * sin(rad) + self$z * cos(rad)
    },
    rotate_z = function(angle) {
      rad <- angle * pi / 180
      self$x <- self$x * cos(rad) - self$y * sin(rad)
      self$y <- self$x * sin(rad) + self$y * cos(rad)
    }
  )
)

transform_sequence <- function(coord, sequence) {
  for (action in sequence) {
    if (action[1] == "translate") {
      coord$translate(action[2], action[3], action[4])
    } else if (action[1] == "rotate_x") {
      coord$rotate_x(action[2])
    } else if (action[1] == "rotate_y") {
      coord$rotate_y(action[2])
    } else if (action[1] == "rotate_z") {
      coord$rotate_z(action[2])
    }
  }
}

main <- function() {
  coord <- CoordinateTransform$new(1, 2, 3)
  sequence <- list(c("translate", 1, 1, 1), c("rotate_x", 45), c("rotate_y", 45), c("rotate_z", 45), c("translate", -1, -1, -1))
  while (TRUE) {
    transform_sequence(coord, sequence)
    print(paste0("(", coord$x, ", ", coord$y, ", ", coord$z, ")"))
  }
}

main()