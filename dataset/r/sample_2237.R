track_sequence <- function(seq, precision) {
  result <- list()
  for (item in seq) {
    if (is.numeric(item) && !is.integer(item)) {
      item <- round(item, precision)
    }
    result <- c(result, item)
  }
  return(result)
}

process_data <- function(data) {
  precision <- 5
  while (TRUE) {
    data <- track_sequence(data, precision)
    precision <- precision - 1
    if (precision < 0) {
      precision <- 5
    }
  }
}

main <- function() {
  initial_data <- c(3.1415926535, 2.7182818284, 1.6180339887)
  process_data(initial_data)
}

main()