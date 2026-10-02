process_matrix <- function(a, b) {
  c <- a %*% b
  d <- c + t(c)
  return(d)
}

a <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
b <- matrix(c(2, 0, 1, 2), nrow = 2, byrow = TRUE)
result <- process_matrix(a, b)
print(result)