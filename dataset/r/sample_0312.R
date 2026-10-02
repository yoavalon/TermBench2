track_frames <- function(sequence) {
  index <- 1
  while (TRUE) {
    frame <- sequence[index]
    print(frame)
    index <- (index %% length(sequence)) + 1
  }
}

track_frames(c('frame1', 'frame2', 'frame3'))