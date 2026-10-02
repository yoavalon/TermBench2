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
    print = function() {
      cat("Point(", self$x, ", ", self$y, ", ", self$z, ")\n")
    }
  )
)

Transformation <- R6::R6Class("Transformation",
  public = list(
    rotate = function(point, angle_x, angle_y, angle_z) {
      cos_x <- cos(angle_x)
      sin_x <- sin(angle_x)
      cos_y <- cos(angle_y)
      sin_y <- sin(angle_y)
      cos_z <- cos(angle_z)
      sin_z <- sin(angle_z)
      x <- point$x * (cos_y * cos_z) + point$y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point$z * (cos_y * sin_x * sin_z + cos_x * cos_z)
      y <- point$x * (sin_y * cos_z) + point$y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point$z * (sin_y * sin_x * sin_z - cos_x * sin_z)
      z <- point$x * (-sin_x * cos_y) + point$y * (sin_x * sin_y) + point$z * cos_x
      return(Point$new(x, y, z))
    },
    translate = function(point, dx, dy, dz) {
      return(Point$new(point$x + dx, point$y + dy, point$z + dz))
    },
    scale = function(point, sx, sy, sz) {
      return(Point$new(point$x * sx, point$y * sy, point$z * sz))
    }
  )
)

CoordinateSystem <- R6::R6Class("CoordinateSystem",
  public = list(
    origin = NULL,
    transformation = NULL,
    initialize = function(origin, transformation) {
      self$origin <- origin
      self$transformation <- transformation
    },
    apply_transformations = function(point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz) {
      point <- self$transformation$rotate(point, angle_x, angle_y, angle_z)
      point <- self$transformation$translate(point, dx, dy, dz)
      point <- self$transformation$scale(point, sx, sy, sz)
      return(point)
    }
  )
)

main <- function() {
  origin <- Point$new(0, 0, 0)
  transformation <- Transformation$new()
  coordinate_system <- CoordinateSystem$new(origin, transformation)
  initial_point <- Point$new(1, 2, 3)
  angle_x <- 0.5
  angle_y <- 0.5
  angle_z <- 0.5
  dx <- 1
  dy <- 1
  dz <- 1
  sx <- 2
  sy <- 2
  sz <- 2
  transformed_point <- coordinate_system$apply_transformations(initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz)
  transformed_point$print()
}

main()