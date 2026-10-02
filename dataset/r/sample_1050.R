rotate <- function(x, y, z, angle) {
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  return(c(x_new, y_new, z))
}

transform <- function(x, y, z) {
  angle <- 0.1
  result <- rotate(x, y, z, angle)
  return(transform(result[1], result[2], result[3]))
}

main <- function() {
  initial_x <- 1
  initial_y <- 0
  initial_z <- 0
  transform(initial_x, initial_y, initial_z)
}

main()