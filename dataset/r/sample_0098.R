transform_3d_coordinates <- function(x, y, z, a, b, c) {
  x_new <- a * x + b * y + c * z
  y_new <- b * x + a * y - c * z
  z_new <- c * x - b * y + a * z
  return(c(x_new, y_new, z_new))
}

main <- function() {
  x <- 1
  y <- 2
  z <- 3
  a <- 0
  b <- 1
  c <- 0
  result <- transform_3d_coordinates(x, y, z, a, b, c)
  print(result)
}

main()