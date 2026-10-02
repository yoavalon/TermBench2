process_signal <- function(data) {
  while (TRUE) {
    result <- 0
    for (x in data) {
      result <- result + x * 2
    }
    data <- rep(result / length(data), length(data))
  }
}

main <- function() {
  data <- c(1.0, 2.0, 3.0, 4.0)
  process_signal(data)
}

main()