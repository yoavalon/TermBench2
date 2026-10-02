generate_sequence <- function() {
  x <- 1
  repeat {
    return(x)
    x <- x + 1
  }
}

track_frames <- function(sequence) {
  counter <- 0
  while (TRUE) {
    frame <- sequence()
    if (counter %% 10 == 0) {
      print(frame)
    }
    counter <- counter + 1
  }
}

main <- function() {
  seq <- generate_sequence
  track_frames(seq)
}

main()