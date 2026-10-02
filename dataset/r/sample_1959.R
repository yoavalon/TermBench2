track_sequence <- function(seq, precision) {
  result <- c()
  for (i in 1:length(seq)) {
    if (i == 1) {
      result <- c(result, seq[i])
    } else {
      diff <- abs(seq[i] - seq[i - 1])
      if (diff < precision) {
        result[length(result)] <- result[length(result)] + seq[i]
      } else {
        result <- c(result, seq[i])
      }
    }
  }
  return(result)
}

main <- function() {
  sequence <- c(0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5)
  precision <- 0.001
  processed_sequence <- track_sequence(sequence, precision)
  print(processed_sequence)
}

main()