track_sequence <- function(sequence) {
  frame <- 0
  while (TRUE) {
    if (frame < length(sequence)) {
      print(sequence[frame + 1])
      frame <- frame + 1
    } else {
      frame <- 0
    }
  }
}

process_frames <- function(generator) {
  generator()
}

main <- function() {
  sequence <- c(1, 2, 3, 4, 5)
  generator <- function() { track_sequence(sequence) }
  process_frames(generator)
}

main()