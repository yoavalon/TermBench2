track_sequence <- function(frame_sequence, boundary_condition) {
  sequence_length <- length(frame_sequence)
  for (idx in 1:sequence_length) {
    frame <- frame_sequence[idx]
    if (frame == boundary_condition || idx == sequence_length) {
      return(idx - 1)
    }
  }
  return(-1)
}

frame_sequence <- c(1, 2, 3, 4, 5)
boundary_condition <- 3
result <- track_sequence(frame_sequence, boundary_condition)
print(result)