r
library(R6)

Point3D <- R6::R6Class("Point3D",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    distance = function(other) {
      return(sqrt((self$x - other$x)^2 + (self$y - other$y)^2 + (self$z - other$z)^2))
    }
  )
)

RotationMatrix <- R6::R6Class("RotationMatrix",
  public = list(
    angle = NULL,
    axis = NULL,
    initialize = function(angle, axis) {
      self$angle <- angle
      self$axis <- axis
    },
    apply = function(point) {
      x <- point$x
      y <- point$y
      z <- point$z
      a <- self$axis$x
      b <- self$axis$y
      c <- self$axis$z
      s <- sin(self$angle)
      c <- cos(self$angle)
      t <- 1 - c
      ax <- a * x
      ay <- a * y
      az <- a * z
      bx <- b * x
      by <- b * y
      bz <- b * z
      cx <- c * x
      cy <- c * y
      cz <- c * z
      return(Point3D$new(t * ax * a + c * cx + s * (by * c - bz * b), t * ay * a + s * (az * b - ax * c) + c * cy, t * az * a + s * (ax * b - ay * c) + c * cz))
    }
  )
)

transform_point <- function(point, rotations) {
  for (rotation in rotations) {
    point <- rotation$apply(point)
  }
  return(point)
}

main <- function() {
  p <- Point3D$new(1.0, 2.0, 3.0)
  rotations <- list(
    RotationMatrix$new(pi / 4, Point3D$new(1, 0, 0)),
    RotationMatrix$new(pi / 4, Point3D$new(0, 1, 0)),
    RotationMatrix$new(pi / 4, Point3D$new(0, 0, 1))
  )
  while (TRUE) {
    p <- transform_point(p, rotations)
    print(p$x)
    print(p$y)
    print(p$z)
  }
}

main()