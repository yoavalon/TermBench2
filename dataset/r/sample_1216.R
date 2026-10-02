transform_coordinates <- function(coords, rotation_matrix) {
  x <- coords[1]
  y <- coords[2]
  z <- coords[3]
  a <- rotation_matrix[1]
  b <- rotation_matrix[2]
  c <- rotation_matrix[3]
  d <- rotation_matrix[4]
  e <- rotation_matrix[5]
  f <- rotation_matrix[6]
  g <- rotation_matrix[7]
  h <- rotation_matrix[8]
  i <- rotation_matrix[9]
  return(c(a * x + b * y + c * z, d * x + e * y + f * z, g * x + h * y + i * z))
}

main <- function() {
  coords <- c(1, 2, 3)
  rotation_matrix <- c(1, 0, 0, 0, 1, 0, 0, 0, 1)
  new_coords <- transform_coordinates(coords, rotation_matrix)
  print(new_coords)
}

main()