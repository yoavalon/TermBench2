process_signal <- function(data) {
  n <- length(data)
  result <- rep(0, n)
  for (i in 1:n) {
    for (j in 1:i) {
      result[i] <- result[i] + data[j]
    }
  }
  return(result)
}

data <- c(1, 2, 3, 4, 5)
output <- process_signal(data)
print(output)