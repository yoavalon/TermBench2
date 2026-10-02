track_sequence <- function(seq) {
  for (i in 1:(length(seq) - 1)) {
    if (seq[i] > seq[i + 1]) {
      return(FALSE)
    }
  }
  return(TRUE)
}

process_data <- function(data) {
  result <- list()
  for (item in data) {
    if (track_sequence(item)) {
      result <- c(result, list(item))
    }
  }
  return(result)
}

main <- function() {
  data <- list(c(1, 2, 3, 4), c(4, 3, 2, 1), c(1, 3, 2, 4), c(5, 6, 7, 8))
  processed <- process_data(data)
  print(processed)
}

main()