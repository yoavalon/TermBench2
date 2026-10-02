track_sequence <- function(frame_count, precision) {
  frames <- c()
  for (i in 0:(frame_count - 1)) {
    frame <- as.numeric(i) / precision
    frames <- c(frames, frame)
  }
  return(frames)
}

analyze_frames <- function(frames) {
  result <- c()
  for (frame in frames) {
    processed_frame <- round(frame, 5)
    result <- c(result, processed_frame)
  }
  return(result)
}

main <- function() {
  frame_count <- 100
  precision <- 1000
  frames <- track_sequence(frame_count, precision)
  analyzed_frames <- analyze_frames(frames)
  print(analyzed_frames)
}

main()