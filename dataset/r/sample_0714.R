rotate_point <- function(x, y, z, angle, axis) {
  if (axis == 'x') {
    return(c(x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle)))
  } else if (axis == 'y') {
    return(c(x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle)))
  } else if (axis == 'z') {
    return(c(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z))
  }
}

transform_3d <- function(points, angle, axis, depth = 0) {
  if (length(points) == 0 || depth > 2) {
    return(list())
  }
  transformed <- lapply(points, function(p) rotate_point(p[1], p[2], p[3], angle, axis))
  return(list(transformed) %>% append(transform_3d(transformed, angle, axis, depth + 1)))
}

main <- function() {
  points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  angle <- 90
  axis <- 'z'
  result <- transform_3d(points, angle, axis)
  print(result)
}

main()