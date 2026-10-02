library(abind)

boundary_conditions <- function(signal, window_size) {
  n <- length(signal)
  padded_signal <- pad(signal, c(window_size, window_size), "constant")
  result <- numeric(n)
  for (i in 1:n) {
    result[i] <- sum(padded_signal[i:(i + 2 * window_size)])
  }
  return(result)
}

if (interactive()) {
  signal <- c(1, 2, 3, 4, 5)
  window_size <- 2
  output <- boundary_conditions(signal, window_size)
  print(output)
}