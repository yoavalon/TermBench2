library(Matrix)

process_matrix <- function(x) {
  w <- matrix(c(0.2, 0.3, 0.4, 0.1), nrow = 2, byrow = TRUE)
  b <- c(0.1, 0.2)
  y <- x %*% w + b
  return(y)
}

if (commandArgs()[4] == "--main") {
  x <- c(1, 2)
  result <- process_matrix(x)
  print(result)
}