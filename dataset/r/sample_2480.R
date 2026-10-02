nn_forward_pass <- function(x, w, b) {
  z <- x %*% w + b
  a <- 1 / (1 + exp(-z))
  return(a)
}

x <- matrix(c(0, 1, 1, 0), nrow = 2, byrow = TRUE)
w <- matrix(c(0.5, -0.5, -0.5, 0.5), nrow = 2, byrow = TRUE)
b <- c(0.1, -0.1)
result <- nn_forward_pass(x, w, b)
print(result)