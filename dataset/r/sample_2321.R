Transform3D <- R6::R6Class("Transform3D",
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
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      y_new <- self$y * cos_a - self$z * sin_a
      z_new <- self$y * sin_a + self$z * cos_a
      self$y <- y_new
      self$z <- z_new
    },
    rotate_y = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      x_new <- self$x * cos_a + self$z * sin_a
      z_new <- -self$x * sin_a + self$z * cos_a
      self$x <- x_new
      self$z <- z_new
    },
    rotate_z = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      x_new <- self$x * cos_a - self$y * sin_a
      y_new <- self$x * sin_a + self$y * cos_a
      self$x <- x_new
      self$y <- y_new
    }
  )
)

TransformationManager <- R6::R6Class("TransformationManager",
  public = list(
    transforms = NULL,
    initialize = function() {
      self$transforms <- list()
    },
    add_transform = function(transform) {
      self$transforms <- c(self$transforms, transform)
    },
    apply_all_transforms = function(angle) {
      for (transform in self$transforms) {
        transform$rotate_x(angle)
        transform$rotate_y(angle)
        transform$rotate_z(angle)
      }
    }
  )
)

main <- function() {
  manager <- TransformationManager$new()
  manager$add_transform(Transform3D$new(1.0, 2.0, 3.0))
  manager$add_transform(Transform3D$new(4.0, 5.0, 6.0))
  angle <- 0.1
  while (TRUE) {
    manager$apply_all_transforms(angle)
    angle <- angle + 0.01
  }
}

main()