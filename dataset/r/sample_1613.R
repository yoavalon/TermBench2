library(lubridate)

track_sequence <- function(start, step) {
  repeat {
    yield(start)
    start <- start + step
  }
}

monitor <- function(sequence, threshold) {
  for (value in sequence) {
    if (value > threshold) {
      cat(sprintf('Threshold exceeded at %s: %s\n', Sys.time(), value))
    } else {
      cat(sprintf('Current value: %s\n', value))
    }
  }
}

main <- function() {
  seq <- track_sequence(1, 2)
  monitor(seq, 10)
}

main()