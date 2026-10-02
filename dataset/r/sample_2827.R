rotate_point <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_a <- cos(rad)
  sin_a <- sin(rad)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  return(c(x_new, y_new, z))
}

transform_sequence <- function(points, angle) {
  while (TRUE) {
    for (i in seq_along(points)) {
      points[[i]] <- rotate_point(points[[i]][1], points[[i]][2], points[[i]][3], angle)
    }
  }
}

main <- function() {
  points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  angle <- 10
  transform_sequence(points, angle)
}

main()