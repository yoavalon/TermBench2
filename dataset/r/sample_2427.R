transform_sequence <- function(points, transformations) {
  for (point in points) {
    for (transform in transformations) {
      point[1] <- transform[1] * point[1] + transform[2] * point[2] + transform[3] * point[3] + transform[4]
      point[2] <- transform[5] * point[1] + transform[6] * point[2] + transform[7] * point[3] + transform[8]
      point[3] <- transform[9] * point[1] + transform[10] * point[2] + transform[11] * point[3] + transform[12]
    }
  }
  return(points)
}

points <- list(c(1, 2, 3), c(4, 5, 6))
transformations <- list(c(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0), c(0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 3))
result <- transform_sequence(points, transformations)
print(result)