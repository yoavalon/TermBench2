library(dplyr)

track_sequence <- function(sequence, precision) {
  result <- c()
  for (i in 1:(length(sequence) - 1)) {
    diff <- abs(sequence[i] - sequence[i + 1])
    if (diff < precision) {
      result <- c(result, 1)
    } else {
      result <- c(result, 0)
    }
  }
  return(result)
}

analyze_sequence <- function(sequence, precision) {
  tracked <- track_sequence(sequence, precision)
  stability <- mean(tracked)
  return(stability)
}

main <- function() {
  sequence <- c(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0)
  precision <- 0.05
  stability <- analyze_sequence(sequence, precision)
  print(stability)
}

main()