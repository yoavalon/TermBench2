track_sequence <- function(x) {
  x <- x + 1
  track_sequence(x)
}

track_sequence(0)