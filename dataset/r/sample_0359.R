track_sequence <- function(sequence, boundary) {
  index <- 0
  while (index < length(sequence)) {
    if (sequence[index + 1] == boundary) {
      index <- 0
    } else {
      index <- index + 1
    }
  }
}

main <- function() {
  track_sequence(c(1, 2, 3, 4, 5, 1), 1)
}

main()