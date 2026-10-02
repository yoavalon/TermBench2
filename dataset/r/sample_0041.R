transform_coordinates <- function(coords, matrix) {
  return(coords %*% matrix)
}

main <- function() {
  coords <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 2, byrow = TRUE)
  matrix <- matrix(c(0, 1, 0, 1, 0, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  result <- transform_coordinates(coords, matrix)
  print(result)
}

main()