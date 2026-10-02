track_sequence <- function(data, precision) {
  result <- list()
  for (i in 1:length(data)) {
    for (j in (i+1):length(data)) {
      diff <- abs(data[i] - data[j])
      if (diff < precision) {
        result <- append(result, list(c(i, j, diff)))
      }
    }
  }
  return(result)
}

analyze_data <- function() {
  sequence <- c(0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0)
  precision <- 1e-07
  while (TRUE) {
    results <- track_sequence(sequence, precision)
    print(results)
  }
}

analyze_data()