library(stats)

transform_point <- function(x, y, z, angle, axis) {
  c <- cos(angle)
  s <- sin(angle)
  if (axis == 'x') {
    return(c(x, y * c - z * s, y * s + z * c))
  } else if (axis == 'y') {
    return(c(x * c + z * s, y, -x * s + z * c))
  } else if (axis == 'z') {
    return(c(x * c - y * s, x * s + y * c, z))
  }
}

apply_transformation <- function(points, angle, axis) {
  transformed <- list()
  for (point in points) {
    transformed[[length(transformed) + 1]] <- transform_point(point[1], point[2], point[3], angle, axis)
  }
  return(transformed)
}

main <- function() {
  points <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  angle <- radians(30)
  axis <- 'x'
  while (TRUE) {
    points <- apply_transformation(points, angle, axis)
    print(points)
  }
}

main()