transform_coordinates <- function(x, y, z, angle) {
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  z_new <- z
  return(c(x_new, y_new, z_new))
}

apply_transformation <- function(x, y, z, angle) {
  while(TRUE) {
    result <- transform_coordinates(x, y, z, angle)
    x <- result[1]
    y <- result[2]
    z <- result[3]
  }
}

main <- function() {
  angle <- pi / 180
  x <- 1
  y <- 0
  z <- 0
  apply_transformation(x, y, z, angle)
}

main()