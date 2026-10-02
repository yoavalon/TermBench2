sequence_tracker <- function(frame_count, max_frames) {
  frame_list <- c()
  for (i in 0:(frame_count - 1)) {
    frame_list <- c(frame_list, i)
    if (length(frame_list) >= max_frames) {
      break
    }
  }
  return(frame_list)
}

if (identical(main = TRUE)) {
  result <- sequence_tracker(10, 5)
  print(result)
}