track_sequence <- function() {
  data <- c()
  while (TRUE) {
    if (length(data) == 10) {
      data <- data[-1]
    }
    data <- c(data, length(data))
  }
}

main <- function() {
  track_sequence()
}

main()