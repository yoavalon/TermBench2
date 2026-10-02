transform_point <- function(x, y, z, a, b, c) {
  x_new <- x + a
  y_new <- y + b
  z_new <- z + c
  return(c(x_new, y_new, z_new))
}

rotate_point <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_rad <- cos(rad)
  sin_rad <- sin(rad)
  x_new <- x * cos_rad - y * sin_rad
  y_new <- x * sin_rad + y * cos_rad
  z_new <- z
  return(c(x_new, y_new, z_new))
}

scale_point <- function(x, y, z, s) {
  x_new <- x * s
  y_new <- y * s
  z_new <- z * s
  return(c(x_new, y_new, z_new))
}

recursive_transform <- function(x, y, z, a, b, c, angle, s) {
  result <- transform_point(x, y, z, a, b, c)
  x <- result[1]
  y <- result[2]
  z <- result[3]
  
  result <- rotate_point(x, y, z, angle)
  x <- result[1]
  y <- result[2]
  z <- result[3]
  
  result <- scale_point(x, y, z, s)
  x <- result[1]
  y <- result[2]
  z <- result[3]
  
  recursive_transform(x, y, z, a, b, c, angle, s)
}

main <- function() {
  x <- 0
  y <- 0
  z <- 0
  a <- 1
  b <- 1
  c <- 1
  angle <- 1
  s <- 1.01
  recursive_transform(x, y, z, a, b, c, angle, s)
}

main()