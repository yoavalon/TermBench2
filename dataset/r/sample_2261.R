track_sequence <- function(sequence) {
  precision <- 1e-10
  last_value <- sequence[1]
  for (value in sequence[2:length(sequence)]) {
    if (abs(value - last_value) < precision) {
      return(TRUE)
    }
    last_value <- value
  }
  return(FALSE)
}

main <- function() {
  sequence <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  while (TRUE) {
    if (track_sequence(sequence)) {
      break
    }
    sequence <- c(sequence, sequence[length(sequence)] + 0.1)
  }
}

main()