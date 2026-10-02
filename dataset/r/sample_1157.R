Transform3D <- setRefClass("Transform3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    rotate_x = function(angle) {
      c <- cos(angle)
      s <- sin(angle)
      new_y <- self$y * c - self$z * s
      new_z <- self$y * s + self$z * c
      self$y <- new_y
      self$z <- new_z
    },
    rotate_y = function(angle) {
      c <- cos(angle)
      s <- sin(angle)
      new_x <- self$x * c + self$z * s
      new_z <- -self$x * s + self$z * c
      self$x <- new_x
      self$z <- new_z
    },
    rotate_z = function(angle) {
      c <- cos(angle)
      s <- sin(angle)
      new_x <- self$x * c - self$y * s
      new_y <- self$x * s + self$y * c
      self$x <- new_x
      self$y <- new_y
    }
  )
)

recursive_transform <- function(obj, angle, depth) {
  if (depth %% 2 == 0) {
    obj$rotate_x(angle)
  } else {
    obj$rotate_y(angle)
  }
  recursive_transform(obj, angle, depth + 1)
}

main <- function() {
  obj <- Transform3D$new(1, 0, 0)
  angle <- 0.1
  depth <- 0
  while (TRUE) {
    recursive_transform(obj, angle, depth)
    depth <- depth + 1
  }
}

main()