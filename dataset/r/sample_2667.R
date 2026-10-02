library(Matrix)

Point <- function(x, y, z) {
  list(x = x, y = y, z = z)
}

distance <- function(p1, p2) {
  sqrt((p1$x - p2$x)^2 + (p1$y - p2$y)^2 + (p1$z - p2$z)^2)
}

Transformation <- function(matrix) {
  list(matrix = matrix)
}

apply_transformation <- function(transformation, point) {
  matrix <- transformation$matrix
  x <- matrix[1, 1] * point$x + matrix[1, 2] * point$y + matrix[1, 3] * point$z + matrix[1, 4]
  y <- matrix[2, 1] * point$x + matrix[2, 2] * point$y + matrix[2, 3] * point$z + matrix[2, 4]
  z <- matrix[3, 1] * point$x + matrix[3, 2] * point$y + matrix[3, 3] * point$z + matrix[3, 4]
  Point(x, y, z)
}

Sequence <- function(start_point, transformation, steps) {
  list(start_point = start_point, transformation = transformation, steps = steps)
}

generate_sequence <- function(sequence) {
  points <- list(sequence$start_point)
  current <- sequence$start_point
  for (i in 1:sequence$steps) {
    current <- apply_transformation(sequence$transformation, current)
    points <- c(points, list(current))
  }
  points
}

main <- function() {
  start <- Point(0, 0, 0)
  matrix <- Matrix(c(1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1), nrow = 4, byrow = TRUE)
  transform <- Transformation(matrix)
  seq <- Sequence(start, transform, 10)
  points <- generate_sequence(seq)
  distances <- sapply(1:(length(points) - 1), function(i) distance(points[[i]], points[[i + 1]]))
  print(distances)
}

main()