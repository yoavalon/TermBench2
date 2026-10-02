rotate_point <- function(x, y, z, angle) {
  rad <- radians(angle)
  cos_a <- cos(rad)
  sin_a <- sin(rad)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  return(c(x_new, y_new, z))
}

translate_point <- function(x, y, z, dx, dy, dz) {
  return(c(x + dx, y + dy, z + dz))
}

main <- function() {
  x <- 1.0
  y <- 1.0
  z <- 1.0
  angle <- 10
  dx <- 1.0
  dy <- 1.0
  dz <- 1.0
  while (TRUE) {
    c(x, y, z) <- rotate_point(x, y, z, angle)
    c(x, y, z) <- translate_point(x, y, z, dx, dy, dz)
    angle <- angle + 5
  }
}

main()