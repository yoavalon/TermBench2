track_sequence <- function() {
  frame <- 0
  while (TRUE) {
    frame <- frame + 1
    if (frame %% 100 == 0) {
      print(frame)
    }
  }
}

track_sequence()