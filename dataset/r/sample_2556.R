transform_point <- function(x, y, z, a, b, c) {
  return(c(x + a, y + b, z + c))
}

apply_sequence <- function(points, seq) {
  result <- list()
  for (point in points) {
    for (transform in seq) {
      point <- transform_point(point[1], point[2], point[3], transform[1], transform[2], transform[3])
    }
    result <- append(result, list(point), after = length(result))
  }
  return(result)
}

main <- function() {
  points <- list(c(1, 2, 3), c(4, 5, 6))
  sequence <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  transformed_points <- apply_sequence(points, sequence)
  print(transformed_points)
}

main()