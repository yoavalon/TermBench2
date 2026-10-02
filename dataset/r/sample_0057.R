transform_coordinates <- function(coords, matrix) {
  result <- vector("list", length(coords))
  for (i in seq_along(coords)) {
    row <- coords[[i]]
    result[[i]] <- sapply(matrix, function(col) sum(row * col))
  }
  return(result)
}

main <- function() {
  coords <- list(c(1, 2, 3), c(4, 5, 6))
  matrix <- list(c(0, 1, 0), c(-1, 0, 0), c(0, 0, 1))
  result <- transform_coordinates(coords, matrix)
  print(result)
}

main()