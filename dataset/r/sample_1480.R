# Define the Point3D class
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
      x_new <- self$x * cos_y * cos_z + self$y * (sin_x * sin_y * cos_z - cos_x * sin_z) + self$z * (cos_x * sin_y * cos_z + sin_x * sin_z)
      y_new <- self$x * cos_y * sin_z + self$y * (sin_x * sin_y * sin_z + cos_x * cos_z) + self$z * (cos_x * sin_y * sin_z - sin_x * cos_z)
      z_new <- self$x * -sin_y + self$y * sin_x * cos_y + self$z * cos_x * cos_y
      self$x <- x_new
      self$y <- y_new
      self$z <- z_new
    },
    
    scale = function(sx, sy, sz) {
      self$x <- self$x * sx
      self$y <- self$y * sy
      self$z <- self$z * sz
    }
  )
)

transform_point <- function(point, translations, rotations, scales) {
  dx <- translations[1]
  dy <- translations[2]
  dz <- translations[3]
  angle_x <- rotations[1]
  angle_y <- rotations[2]
  angle_z <- rotations[3]
  sx <- scales[1]
  sy <- scales[2]
  sz <- scales[3]
  point$translate(dx, dy, dz)
  point$rotate(angle_x, angle_y, angle_z)
  point$scale(sx, sy, sz)
}

process_points <- function(points, transformations) {
  for (i in seq_along(points)) {
    transform_point(points[[i]], transformations[[i]])
  }
}

main <- function() {
  points <- list(Point3D$new(1, 2, 3), Point3D$new(4, 5, 6))
  transformations <- list(
    list(c(1, 1, 1), c(0.1, 0.2, 0.3), c(1.5, 1.5, 1.5)),
    list(c(-1, -1, -1), c(0.3, 0.2, 0.1), c(0.5, 0.5, 0.5))
  )
  process_points(points, transformations)
  for (point in points) {
    cat(sprintf("Point(%s, %s, %s)\n", point$x, point$y, point$z))
  }
}

main()