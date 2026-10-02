transform_coordinates <- function(x, y, z, a, b, c) {
  r <- sqrt(x^2 + y^2 + z^2)
  theta <- atan2(y, x)
  phi <- acos(z / r)
  x1 <- r * sin(phi + a) * cos(theta + b)
  y1 <- r * sin(phi + a) * sin(theta + b)
  z1 <- r * cos(phi + a) + c
  return(c(x1, y1, z1))
}

x <- 1.0
y <- 2.0
z <- 3.0
a <- 0.1
b <- 0.2
c <- 0.3

result <- transform_coordinates(x, y, z, a, b, c)
print(result)