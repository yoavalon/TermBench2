library(pracma)

Point3D <- setRefClass("Point3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    distance = function(other) {
      sqrt((self$x - other$x)^2 + (self$y - other$y)^2 + (self$z - other$z)^2)
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
      self$x <<- x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
      self$y <<- x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
      self$z <<- -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    }
  )
)

Transformation <- setRefClass("Transformation",
  fields = list(angle_x = "numeric", angle_y = "numeric", angle_z = "numeric"),
  methods = list(
    apply = function(point) {
      point$rotate(self$angle_x, self$angle_y, self$angle_z)
    }
  )
)

simulate_transformation <- function() {
  point <- Point3D$new(x = 1.0, y = 1.0, z = 1.0)
  transformation <- Transformation$new(angle_x = pi / 4, angle_y = pi / 4, angle_z = pi / 4)
  while (TRUE) {
    transformation$apply(point)
    cat(sprintf("(%10.10f, %10.10f, %10.10f)\n", point$x, point$y, point$z))
  }
}

simulate_transformation()