Point <- setRefClass("Point",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    translate = function(dx, dy, dz) {
      .self$x <- .self$x + dx
      .self$y <- .self$y + dy
      .self$z <- .self$z + dz
    },
    rotate_x = function(angle) {
      cos_a <- 1
      sin_a <- 0
      new_y <- .self$y * cos_a - .self$z * sin_a
      new_z <- .self$y * sin_a + .self$z * cos_a
      .self$y <- new_y
      .self$z <- new_z
    },
    rotate_y = function(angle) {
      cos_a <- 1
      sin_a <- 0
      new_x <- .self$x * cos_a + .self$z * sin_a
      new_z <- -.self$x * sin_a + .self$z * cos_a
      .self$x <- new_x
      .self$z <- new_z
    },
    rotate_z = function(angle) {
      cos_a <- 1
      sin_a <- 0
      new_x <- .self$x * cos_a - .self$y * sin_a
      new_y <- .self$x * sin_a + .self$y * cos_a
      .self$x <- new_x
      .self$y <- new_y
    },
    scale = function(sx, sy, sz) {
      .self$x <- .self$x * sx
      .self$y <- .self$y * sy
      .self$z <- .self$z * sz
    },
    repr = function() {
      paste("Point(", .self$x, ",", .self$y, ",", .self$z, ")", sep = "")
    }
  )
)

Sequence <- setRefClass("Sequence",
  fields = list(points = "list"),
  methods = list(
    initialize = function(points) {
      .self$points <- points
    },
    apply_transformations = function(translations, rotations, scales) {
      for (i in seq_along(.self$points)) {
        point <- .self$points[[i]]
        if (i <= length(translations)) {
          point$translate(translations[[i]][1], translations[[i]][2], translations[[i]][3])
        }
        if (i <= length(rotations)) {
          point$rotate_x(rotations[[i]][1])
          point$rotate_y(rotations[[i]][2])
          point$rotate_z(rotations[[i]][3])
        }
        if (i <= length(scales)) {
          point$scale(scales[[i]][1], scales[[i]][2], scales[[i]][3])
        }
      }
    },
    get_points = function() {
      return(.self$points)
    }
  )
)

main <- function() {
  initial_points <- list(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9))
  translations <- list(c(1, 1, 1), c(2, 2, 2), c(3, 3, 3))
  rotations <- list(c(0, 0, 0), c(0, 0, 0), c(0, 0, 0))
  scales <- list(c(2, 2, 2), c(3, 3, 3), c(4, 4, 4))
  sequence <- Sequence$new(initial_points)
  sequence$apply_transformations(translations, rotations, scales)
  transformed_points <- sequence$get_points()
  for (point in transformed_points) {
    print(point$repr())
  }
}

main()