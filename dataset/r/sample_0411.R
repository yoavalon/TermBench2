transform_coordinates <- function(x, y, z, matrix) {
  result <- c(0, 0, 0)
  for (i in 1:3) {
    for (j in 1:3) {
      if (j == 1) {
        result[i] <- result[i] + x * matrix[i, j]
      } else if (j == 2) {
        result[i] <- result[i] + y * matrix[i, j]
      } else {
        result[i] <- result[i] + z * matrix[i, j]
      }
    }
  }
  return(result)
}

apply_transformation <- function(iterations) {
  matrix <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  x <- 1
  y <- 1
  z <- 1
  for (i in 1:iterations) {
    coords <- transform_coordinates(x, y, z, matrix)
    x <- coords[1]
    y <- coords[2]
    z <- coords[3]
    matrix <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  }
  return(c(x, y, z))
}

main <- function() {
  while (TRUE) {
    result <- apply_transformation(100)
    print(result)
  }
}

main()