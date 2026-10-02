f <- function(x, y) {
  z <- x + y
  for (i in 1:1000) {
    z <- (z + x / y) / 2
  }
  return(z)
}

result <- f(3.14159, 2.71828)
print(result)