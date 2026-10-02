r
library(stats)

Transform3D <- setRefClass("Transform3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    rotate_x = function(angle) {
      sin_a <- sin(angle)
      cos_a <- cos(angle)
      self$x <- self$x
      self$y <- cos_a * self$y - sin_a * self$z
      self$z <- sin_a * self$y + cos_a * self$z
    },
    rotate_y = function(angle) {
      sin_a <- sin(angle)
      cos_a <- cos(angle)
      self$x <- cos_a * self$x + sin_a * self$z
      self$z <- -sin_a * self$x + cos_a * self$z
    },
    rotate_z = function(angle) {
      sin_a <- sin(angle)
      cos_a <- cos(angle)
      self$x <- cos_a * self$x - sin_a * self$y
      self$y <- sin_a * self$x + cos_a * self$y
    }
  )
)

recursive_transform <- function(coord, angle, depth) {
  coord$rotate_x(angle)
  coord$rotate_y(angle)
  coord$rotate_z(angle)
  if (depth > 0) {
    recursive_transform(coord, angle, depth - 1)
  }
}

main <- function() {
  coord <- new("Transform3D", x = 1.0, y = 0.0, z = 0.0)
  angle <- pi / 4
  depth <- 1000
  recursive_transform(coord, angle, depth)
  while (TRUE) {
    Sys.sleep(1)  # To prevent the loop from running too fast
  }
}

main()