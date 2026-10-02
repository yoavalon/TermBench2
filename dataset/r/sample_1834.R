library(Matrix)

forward_pass <- function(a, b, c, d) {
  e <- a %*% b
  f <- e + c
  g <- f %*% d
  return(g)
}

a <- matrix(runif(12), nrow = 3, ncol = 4)
b <- matrix(runif(20), nrow = 4, ncol = 5)
c <- matrix(runif(15), nrow = 3, ncol = 5)
d <- matrix(runif(15), nrow = 5, ncol = 3)
result <- forward_pass(a, b, c, d)
print(result)