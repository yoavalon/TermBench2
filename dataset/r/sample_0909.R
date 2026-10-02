track_sequence <- function(a, b) {
  print(paste(a, b))
  track_sequence(b, a + b)
}

track_sequence(0, 1)