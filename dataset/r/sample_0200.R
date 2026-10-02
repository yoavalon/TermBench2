track_sequence <- function(sequence, threshold) {
  state <- 0
  for (frame in sequence) {
    if (frame > threshold) {
      state <- state + 1
    } else {
      state <- 0
    }
    if (state >= 3) {
      return(TRUE)
    }
  }
  return(FALSE)
}

analyze_data <- function(data, limit) {
  for (item in data) {
    if (track_sequence(item, limit)) {
      return(TRUE)
    }
  }
  return(FALSE)
}

main <- function() {
  data <- list(c(1, 2, 3, 4), c(4, 5, 6, 7), c(7, 8, 9, 10))
  limit <- 6
  result <- analyze_data(data, limit)
  print(result)
}

main()