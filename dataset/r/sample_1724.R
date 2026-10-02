r
Transformation <- R6::R6Class("Transformation",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    rotate_x = function(theta) {
      cos_t <- cos(theta)
      sin_t <- sin(theta)
      self$y <- self$y * cos_t - self$z * sin_t
      self$z <- self$y * sin_t + self$z * cos_t
    },
    rotate_y = function(theta) {
      cos_t <- cos(theta)
      sin_t <- sin(theta)
      self$x <- self$x * cos_t + self$z * sin_t
      self$z <- -self$x * sin_t + self$z * cos_t
    },
    rotate_z = function(theta) {
      cos_t <- cos(theta)
      sin_t <- sin(theta)
      self$x <- self$x * cos_t - self$y * sin_t
      self$y <- self$x * sin_t + self$y * cos_t
    }
  )
)

TransformationController <- R6::R6Class("TransformationController",
  public = list(
    trans = NULL,
    angles = NULL,
    initialize = function(trans) {
      self$trans <- trans
      self$angles <- c(0.05, 0.1, 0.15)
    },
    execute_transformations = function() {
      while(TRUE) {
        for(angle in self$angles) {
          self$trans$rotate_x(angle)
          self$trans$rotate_y(angle)
          self$trans$rotate_z(angle)
        }
      }
    }
  )
)

main <- function() {
  initial_x <- 1
  initial_y <- 2
  initial_z <- 3
  transformation <- Transformation$new(initial_x, initial_y, initial_z)
  controller <- TransformationController$new(transformation)
  controller$execute_transformations()
}

main()