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
    translate = function(dx, dy, dz) {
      Point3D$new(self$x + dx, self$y + dy, self$z + dz)
    },
    scale = function(sx, sy, sz) {
      Point3D$new(self$x * sx, self$y * sy, self$z * sz)
    },
    rotate_x = function(angle) {
      c <- cos(angle)
      s <- sin(angle)
      Point3D$new(self$x, self$y * c - self$z * s, self$y * s + self$z * c)
    },
    rotate_y = function(angle) {
      c <- cos(angle)
      s <- sin(angle)
      Point3D$new(self$x * c + self$z * s, self$y, -self$x * s + self$z * c)
    },
    rotate_z = function(angle) {
      c <- cos(angle)
      s <- sin(angle)
      Point3D$new(self$x * c - self$y * s, self$x * s + self$y * c, self$z)
    }
  )
)

Transformation <- R6::R6Class("Transformation",
  public = list(
    point = NULL,
    initialize = function(point) {
      self$point <- point
    },
    apply_transformations = function(translations, scalings, rotations) {
      for (dx in translations[[1]]) {
        self$point <- self$point$translate(dx, translations[[2]], translations[[3]])
      }
      for (sx in scalings[[1]]) {
        self$point <- self$point$scale(sx, scalings[[2]], scalings[[3]])
      }
      for (angle in rotations) {
        self$point <- self$point$rotate_x(angle)
        self$point <- self$point$rotate_y(angle)
        self$point <- self$point$rotate_z(angle)
      }
    },
    get_final_position = function() {
      c(self$point$x, self$point$y, self$point$z)
    }
  )
)

main <- function() {
  initial_point <- Point3D$new(1.0, 2.0, 3.0)
  transformations <- Transformation$new(initial_point)
  translations <- list(c(1.0, 0.0, 0.0), c(0.0, 1.0, 0.0))
  scalings <- list(c(2.0, 2.0, 2.0))
  rotations <- c(0.785398163)
  transformations$apply_transformations(translations, scalings, rotations)
  final_position <- transformations$get_final_position()
  print(final_position)
}

main()