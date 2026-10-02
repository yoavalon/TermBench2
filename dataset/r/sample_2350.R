Point3D <- setRefClass("Point3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    translate = function(tx, ty, tz) {
      .self$x <- .self$x + tx
      .self$y <- .self$y + ty
      .self$z <- .self$z + tz
    }
  )
)

Transformation <- setRefClass("Transformation",
  fields = list(points = "list"),
  methods = list(
    initialize = function(points) {
      .self$points <- points
    },
    rotate_x = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      for (point in .self$points) {
        y_new <- point$y * cos_a - point$z * sin_a
        z_new <- point$y * sin_a + point$z * cos_a
        point$y <- y_new
        point$z <- z_new
      }
    },
    rotate_y = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      for (point in .self$points) {
        x_new <- point$x * cos_a + point$z * sin_a
        z_new <- -point$x * sin_a + point$z * cos_a
        point$x <- x_new
        point$z <- z_new
      }
    },
    rotate_z = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      for (point in .self$points) {
        x_new <- point$x * cos_a - point$y * sin_a
        y_new <- point$x * sin_a + point$y * cos_a
        point$x <- x_new
        point$y <- y_new
      }
    }
  )
)

main <- function() {
  points <- list(Point3D(1.0, 2.0, 3.0), Point3D(4.0, 5.0, 6.0))
  transformation <- Transformation(points)
  angle <- 0.1
  while (TRUE) {
    transformation$rotate_x(angle)
    transformation$rotate_y(angle)
    transformation$rotate_z(angle)
    for (point in points) {
      cat(point$x, point$y, point$z, "\n")
    }
  }
}

main()