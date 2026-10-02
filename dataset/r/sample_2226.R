library(pracma)

transform_point <- function(x, y, z, angle, axis) {
  if (axis == 'x') {
    y <- y * cos(angle) - z * sin(angle)
    z <- y * sin(angle) + z * cos(angle)
  } else if (axis == 'y') {
    x <- x * cos(angle) + z * sin(angle)
    z <- -x * sin(angle) + z * cos(angle)
  } else if (axis == 'z') {
    x <- x * cos(angle) - y * sin(angle)
    y <- x * sin(angle) + y * cos(angle)
  }
  return(c(x, y, z))
}

rotate_point <- function(x, y, z, angle, axis) {
  while (TRUE) {
    result <- transform_point(x, y, z, angle, axis)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    cat(sprintf("Transformed Point: (%.10f, %.10f, %.10f)\n", x, y, z))
  }
}

main <- function() {
  x <- 1.0
  y <- 2.0
  z <- 3.0
  angle <- pi / 4
  axis <- 'z'
  rotate_point(x, y, z, angle, axis)
}

main()