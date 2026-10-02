rotate_point <- function(x, y, z, angle) {
  cos_theta <- cos(angle)
  sin_theta <- sin(angle)
  x_new <- x * cos_theta - y * sin_theta
  y_new <- x * sin_theta + y * cos_theta
  return(c(x_new, y_new, z))
}

translate_point <- function(x, y, z, dx, dy, dz) {
  return(c(x + dx, y + dy, z + dz))
}

main <- function() {
  x <- 0
  y <- 0
  z <- 0
  dx <- 1
  dy <- 2
  dz <- 3
  angle <- pi / 4
  while (TRUE) {
    c(x, y, z) <- rotate_point(x, y, z, angle)
    c(x, y, z) <- translate_point(x, y, z, dx, dy, dz)
    print(sprintf('(%0.2f, %0.2f, %0.2f)', x, y, z))
  }
}

main()