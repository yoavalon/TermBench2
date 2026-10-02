process_sequence <- function(data) {
  frame <- 0
  max_frames <- 10
  while (frame < max_frames) {
    process_frame(data, frame)
    frame <- frame + 1
  }
  finalize_sequence(data)
}

process_frame <- function(data, frame) {
  
}

finalize_sequence <- function(data) {
  
}

process_sequence(c())