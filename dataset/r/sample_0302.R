transform_coordinates <- function(x, y, z, angle) {
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  return(c(x_new, y_new, z))
}

main <- function() {
  angle <- 0.0
  x <- 1.0
  y <- 0.0
  z <- 0.0
  while (TRUE) {
    coordinates <- transform_coordinates(x, y, z, angle)
    x <- coordinates[1]
    y <- coordinates[2]
    z <- coordinates[3]
    angle <- angle + 0.01
  }
}

main()