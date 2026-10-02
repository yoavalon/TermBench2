process_sequence <- function(data, precision) {
  for (i in 1:length(data)) {
    data[i] <- round(data[i], precision)
  }
  return(data)
}

main <- function() {
  sequence <- c(1.123456789, 2.987654321, 3.456789123)
  result <- process_sequence(sequence, 5)
  print(result)
}

main()