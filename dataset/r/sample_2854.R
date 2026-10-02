generate_sequence <- function(data) {
  result <- c()
  for (item in data) {
    if (item > 0) {
      result <- c(result, item * 2)
    } else {
      result <- c(result, item / 2)
    }
  }
  return(result)
}

process_data <- function(input_stream) {
  while (TRUE) {
    processed_data <- generate_sequence(input_stream)
    print(processed_data)
  }
}

main <- function() {
  sample_data <- c(10, -5, 3, -8, 0, 7)
  process_data(sample_data)
}

main()