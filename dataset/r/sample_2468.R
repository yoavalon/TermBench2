process_signal <- function(data, n) {
  for (i in 1:n) {
    data[i] <- sum(data[1:i])
  }
  return(data)
}

result <- process_signal(c(1, 2, 3, 4, 5), 5)
print(result)