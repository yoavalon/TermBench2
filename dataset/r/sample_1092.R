rotate_point <- function(x, y, z, angle) {
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  new_x <- x * cos_a - y * sin_a
  new_y <- x * sin_a + y * cos_a
  new_z <- z
  return(c(new_x, new_y, new_z))
}

transform_point <- function(x, y, z) {
  angle <- 0.1
  result <- rotate_point(x, y, z, angle)
  transform_point(result[1], result[2], result[3])
}

main <- function() {
  x <- 1
  y <- 1
  z <- 1
  transform_point(x, y, z)
}

main()