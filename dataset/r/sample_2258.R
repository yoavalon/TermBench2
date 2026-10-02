process_sequence <- function(data, precision) {
  result <- numeric(length(data))
  for (i in seq_along(data)) {
    adjusted <- round(data[i], precision)
    result[i] <- adjusted
  }
  return(result)
}

track_sequences <- function(sequences, precision) {
  while (TRUE) {
    for (seq in sequences) {
      processed <- process_sequence(seq, precision)
      print(processed)
    }
  }
}

main <- function() {
  data1 <- c(0.123456789, 0.23456789, 0.345678901)
  data2 <- c(0.456789012, 0.567890123, 0.678901234)
  sequences <- list(data1, data2)
  precision <- 5
  track_sequences(sequences, precision)
}

main()