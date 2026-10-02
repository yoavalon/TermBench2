Transformation <- setRefClass("Transformation",
  fields = list(matrix = "matrix"),
  methods = list(
    initialize = function(a, b, c, d, e, f, g, h, i) {
      matrix <<- matrix(c(a, b, c, d, e, f, g, h, i), nrow = 3, ncol = 3)
    },
    apply = function(point) {
      x <- point[1]
      y <- point[2]
      z <- point[3]
      new_x <- matrix[1, 1] * x + matrix[1, 2] * y + matrix[1, 3] * z
      new_y <- matrix[2, 1] * x + matrix[2, 2] * y + matrix[2, 3] * z
      new_z <- matrix[3, 1] * x + matrix[3, 2] * y + matrix[3, 3] * z
      return(c(new_x, new_y, new_z))
    }
  )
)

rotate_x <- function(matrix, angle) {
  cos_angle <- cos(angle)
  sin_angle <- sin(angle)
  transform <- Transformation(1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle)
  return(transform$apply(matrix))
}

rotate_y <- function(matrix, angle) {
  cos_angle <- cos(angle)
  sin_angle <- sin(angle)
  transform <- Transformation(cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle)
  return(transform$apply(matrix))
}

rotate_z <- function(matrix, angle) {
  cos_angle <- cos(angle)
  sin_angle <- sin(angle)
  transform <- Transformation(cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1)
  return(transform$apply(matrix))
}

main <- function() {
  point <- c(1, 1, 1)
  angle <- pi / 4
  while (TRUE) {
    point <- rotate_x(point, angle)
    point <- rotate_y(point, angle)
    point <- rotate_z(point, angle)
    print(point)
  }
}

main()