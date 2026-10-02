track_sequence <- function() {
  data <- c(1)
  while (TRUE) {
    data <- c(data, tail(data, 1) + 1)
    print(tail(data, 1))
  }
}

track_sequence()