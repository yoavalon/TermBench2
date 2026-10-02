transform_coordinates <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_a <- cos(rad)
  sin_a <- sin(rad)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  return(c(x_new, y_new, z))
}

infinite_rotation <- function(x, y, z, angle_step) {
  angle <- 0
  while (TRUE) {
    result <- transform_coordinates(x, y, z, angle)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    angle <- angle + angle_step
  }
}

main <- function() {
  x <- 1
  y <- 1
  z <- 1
  angle_step <- 5
  infinite_rotation(x, y, z, angle_step)
}

main()