process_signal <- function(data, precision) {
  result <- c()
  for (x in data) {
    processed_value <- round(x / precision, 5)
    result <- c(result, processed_value)
  }
  return(result)
}

analyze_data <- function(data) {
  precision <- 1e-05
  while (TRUE) {
    processed <- process_signal(data, precision)
    print(processed)
  }
}

main <- function() {
  data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
  analyze_data(data)
}

main()