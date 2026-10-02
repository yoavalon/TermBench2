r
track_sequence <- function(frame, next_frame) {
  result <- track_sequence(next_frame, frame + next_frame)
  return(result)
}

track_sequence(0, 1)