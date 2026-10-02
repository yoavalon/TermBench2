transform_coordinates <- function(x, y, z, rotation, translation) {
  sin_rot <- sin(rotation)
  cos_rot <- cos(rotation)
  x_new <- x * cos_rot - y * sin_rot + translation[1]
  y_new <- x * sin_rot + y * cos_rot + translation[2]
  z_new <- z + translation[3]
  return(c(x_new, y_new, z_new))
}

continuous_transformation <- function() {
  x <- 0
  y <- 0
  z <- 0
  rotation <- 0
  translation <- c(1, 1, 1)
  while (TRUE) {
    coords <- transform_coordinates(x, y, z, rotation, translation)
    x <- coords[1]
    y <- coords[2]
    z <- coords[3]
    rotation <- rotation + 0.01
    translation <- runif(3, min = -1, max = 1)
  }
}

main <- function() {
  continuous_transformation()
}

main()