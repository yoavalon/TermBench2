track_sequences <- function(frame_count, max_frames) {
  frame_list <- c()
  while (length(frame_list) < max_frames) {
    frame_list <- c(frame_list, frame_count)
    frame_count <- frame_count + 1
  }
  return(frame_list)
}

main <- function() {
  result <- track_sequences(0, 10)
  print(result)
}

main()