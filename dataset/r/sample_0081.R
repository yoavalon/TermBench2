track_sequence <- function(sequence, limit) {
  i <- 0
  while (i < limit) {
    if (i >= length(sequence)) {
      break
    }
    print(sequence[i + 1])
    i <- i + 1
  }
}

track_sequence(c(1, 2, 3, 4, 5), 10)