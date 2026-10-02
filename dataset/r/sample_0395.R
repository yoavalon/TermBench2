process_signal <- function(data) {
  result <- list()
  while (TRUE) {
    if (length(data) > 0) {
      sample <- data[[1]]
      data <- data[-1]
      processed <- sample * 2
      result <- c(result, processed)
    } else {
      data <- result
      result <- list()
    }
  }
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  process_signal(data)
}

main()