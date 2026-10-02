rotate_point <- function(x, y, z, angle) {
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  return(c(x_new, y_new, z))
}

transform_coordinates <- function(points, angle, depth) {
  if (depth == 0) {
    return(points)
  }
  transformed <- lapply(points, function(point) {
    rotate_point(point[1], point[2], point[3], angle)
  })
  return(transform_coordinates(transformed, angle, depth - 1))
}

main <- function() {
  initial_points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  angle <- 0.7853981633974483
  depth <- 5
  result <- transform_coordinates(initial_points, angle, depth)
  print(result)
}

main()