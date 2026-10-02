r
Point <- R6::R6Class("Point",
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
    
    rotate = function(angle_x, angle_y, angle_z) {
      cos_x <- cos(angle_x)
      sin_x <- sin(angle_x)
      cos_y <- cos(angle_y)
      sin_y <- sin(angle_y)
      cos_z <- cos(angle_z)
      sin_z <- sin(angle_z)
      x <- self$x
      y <- self$y
      z <- self$z
      self$x <- x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z)
      self$y <- x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z)
      self$z <- -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    }
  )
)

transform_point <- function(point, translation, rotation) {
  point$translate(translation[1], translation[2], translation[3])
  point$rotate(rotation[1], rotation[2], rotation[3])
}

main <- function() {
  p <- Point$new(1.0, 2.0, 3.0)
  translation <- c(4.0, 5.0, 6.0)
  rotation <- c(0.5, 1.0, 1.5)
  transform_point(p, translation, rotation)
  print(c(p$x, p$y, p$z))
}

main()