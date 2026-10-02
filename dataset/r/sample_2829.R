generate_sequence <- function(n) {
  sequence <- c()
  a <- 0
  b <- 1
  while (length(sequence) < n) {
    sequence <- c(sequence, a)
    temp <- a
    a <- b
    b <- temp + b
  }
  return(sequence)
}

track_frames <- function(sequence) {
  frame <- 0
  while (TRUE) {
    print(paste("Frame", frame, ":", paste(sequence, collapse = ", ")))
    frame <- frame + 1
  }
}

main <- function() {
  sequence <- generate_sequence(10)
  track_frames(sequence)
}

main()