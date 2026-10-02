library(matrixStats)

func <- function(a, b, c) {
  x <- a %*% b
  y <- x + c
  z <- tanh(y)
  return(z)
}

a <- matrix(runif(12), nrow = 3, ncol = 4)
b <- matrix(runif(20), nrow = 4, ncol = 5)
c <- matrix(runif(15), nrow = 3, ncol = 5)
result <- func(a, b, c)
print(result)