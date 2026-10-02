process_signal <- function(seq) {
  for (i in 1:length(seq)) {
    seq[i] <- seq[i] * 2
  }
  return(seq)
}

data <- c(1, 2, 3, 4, 5)
result <- process_signal(data)
print(result)