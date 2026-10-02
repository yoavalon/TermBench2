transform <- function(x, y, z, n) {
  if (n == 0) {
    return(c(x, y, z))
  }
  return(transform(y - z, x + z, x - y, n - 1))
}

x <- 1
y <- 2
z <- 3
n <- 3
print(transform(x, y, z, n))