transform_point <- function(x, y, z, a, b, c) {
  x_new <- a * x + b * y + c * z
  y_new <- a * y + b * z + c * x
  z_new <- a * z + b * x + c * y
  return(c(x_new, y_new, z_new))
}

process_points <- function(points, a, b, c) {
  transformed_points <- list()
  for (point in points) {
    transformed <- transform_point(point[1], point[2], point[3], a, b, c)
    transformed_points <- c(transformed_points, list(transformed))
  }
  return(transformed_points)
}

main <- function() {
  points <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  a <- 1
  b <- 0
  c <- 0
  result <- process_points(points, a, b, c)
  print(result)
}

main()