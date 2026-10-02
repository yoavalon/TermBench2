# Define the Point3D class
Point3D <- setRefClass("Point3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    translate = function(dx, dy, dz) {
      x <<- x + dx
      y <<- y + dy
      z <<- z + dz
    },
    rotate_x = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      y <<- y * cos_a - z * sin_a
      z <<- y * sin_a + z * cos_a
    },
    rotate_y = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      x <<- x * cos_a + z * sin_a
      z <<- -x * sin_a + z * cos_a
    },
    rotate_z = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      x <<- x * cos_a - y * sin_a
      y <<- x * sin_a + y * cos_a
    }
  )
)

# Define the transform_point function
transform_point <- function(point, angles, translations) {
  point$rotate_x(angles[1])
  point$rotate_y(angles[2])
  point$rotate_z(angles[3])
  point$translate(translations[1], translations[2], translations[3])
}

# Define the recursive_transform function
recursive_transform <- function(point, angles, translations) {
  transform_point(point, angles, translations)
  recursive_transform(point, angles, translations)
}

# Define the main function
main <- function() {
  p <- new("Point3D", x = 1, y = 0, z = 0)
  a <- c(0.1, 0.2, 0.3)
  t <- c(0.1, 0.1, 0.1)
  recursive_transform(p, a, t)
}

# Call the main function
main()