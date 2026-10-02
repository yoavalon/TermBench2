library(abind)

Coordinate <- setRefClass("Coordinate",
  fields = list(
    x = "numeric",
    y = "numeric",
    z = "numeric"
  ),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    rotate = function(angle_x, angle_y, angle_z) {
      rad_x <- angle_x * pi / 180
      rad_y <- angle_y * pi / 180
      rad_z <- angle_z * pi / 180
      cos_x <- cos(rad_x)
      sin_x <- sin(rad_x)
      cos_y <- cos(rad_y)
      sin_y <- sin(rad_y)
      cos_z <- cos(rad_z)
      sin_z <- sin(rad_z)
      x <- .self$x * cos_y * cos_z + .self$y * (sin_x * sin_y * cos_z - cos_x * sin_z) + .self$z * (cos_x * sin_y * cos_z + sin_x * sin_z)
      y <- .self$x * cos_y * sin_z + .self$y * (sin_x * sin_y * sin_z + cos_x * cos_z) + .self$z * (cos_x * sin_y * sin_z - sin_x * cos_z)
      z <- - .self$x * sin_y + .self$y * sin_x * cos_y + .self$z * cos_x * cos_y
      return(new("Coordinate", x = x, y = y, z = z))
    }
  )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(
    origin = "Coordinate",
    angles = "list",
    index = "numeric"
  ),
  methods = list(
    initialize = function(origin, angles) {
      .self$origin <- origin
      .self$angles <- angles
      .self$index <- 0
    },
    next = function() {
      angle_x <- .self$angles[[.self$index %% length(.self$angles)] + 1][1]
      angle_y <- .self$angles[[.self$index %% length(.self$angles)] + 1][2]
      angle_z <- .self$angles[[.self$index %% length(.self$angles)] + 1][3]
      transformed <- .self$origin$rotate(angle_x, angle_y, angle_z)
      .self$index <- .self$index + 1
      return(transformed)
    }
  )
)

Transformer <- setRefClass("Transformer",
  fields = list(
    sequence_generator = "SequenceGenerator"
  ),
  methods = list(
    initialize = function(sequence_generator) {
      .self$sequence_generator <- sequence_generator
    },
    transform = function() {
      while (TRUE) {
        point <- .self$sequence_generator$next()
        cat(sprintf('Transformed Coordinates: (%.2f, %.2f, %.2f)\n', point$x, point$y, point$z))
      }
    }
  )
)

main <- function() {
  origin <- new("Coordinate", x = 1, y = 0, z = 0)
  angles <- list(c(0, 0, 10), c(10, 0, 0), c(0, 10, 0))
  sequence_generator <- new("SequenceGenerator", origin = origin, angles = angles)
  transformer <- new("Transformer", sequence_generator = sequence_generator)
  transformer$transform()
}

main()