transform_coordinates <- function(data) {
  matrix <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  for (i in 1:nrow(data)) {
    data[i, ] <- matrix %*% data[i, ]
  }
  return(data)
}

if (isTRUE(interactive())) {
  points <- matrix(c(1, 2, 3, 4, 5, 6, 7, 8, 9), nrow = 3, byrow = TRUE)
  result <- transform_coordinates(points)
  print(result)
}