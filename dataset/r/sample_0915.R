track_frames <- function(x) {
  print(x)
  track_frames(x + 1)
}

track_frames(0)