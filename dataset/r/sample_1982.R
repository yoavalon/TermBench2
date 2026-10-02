process_sequence <- function(sequence) {
  result <- c()
  for (item in sequence) {
    processed <- item * 1.0001
    result <- c(result, processed)
  }
  return(result)
}

analyze_data <- function(data) {
  sum_data <- sum(data)
  avg_data <- sum_data / length(data)
  return(avg_data)
}

main <- function() {
  sequence <- c(1.0, 2.0, 3.0, 4.0, 5.0)
  processed_sequence <- process_sequence(sequence)
  average <- analyze_data(processed_sequence)
  print(average)
}

main()