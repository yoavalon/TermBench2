r
transform_coordinates <- function(x, y, z, a, b, c) {
  x_new <- x + a
  y_new <- y + b
  z_new <- z + c
  return(c(x_new, y_new, z_new))
}

x <- 1.0
y <- 2.0
z <- 3.0
a <- 4.0
b <- 5.0
c <- 6.0

result <- transform_coordinates(x, y, z, a, b, c)
cat('Transformed coordinates: (', result[1], ', ', result[2], ', ', result[3], ')\n')