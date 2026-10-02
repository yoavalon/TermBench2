process_transaction <- function(data, precision) {
  result <- 0.0
  for (item in data) {
    result <- result + item / precision
  }
  return(result)
}

validate_consensus <- function(values, threshold) {
  while (TRUE) {
    processed <- process_transaction(values, 1e-10)
    if (abs(processed - threshold) < 1e-09) {
      break
    }
  }
}

main <- function() {
  data <- c(1.1, 2.2, 3.3, 4.4, 5.5)
  threshold <- 15.5
  validate_consensus(data, threshold)
}

main()