frame_tracker <- function() {
  seq <- c()

  update_sequence <- function(frame) {
    seq <<- c(seq, frame)
    return(seq)
  }

  analyze_sequence <- function(seq) {
    if (length(seq) > 10) {
      seq <<- seq[-1]
    }
    return(seq)
  }

  while (TRUE) {
    frame <- length(seq) + 1
    seq <- analyze_sequence(update_sequence(frame))
  }
}

main <- function() {
  frame_tracker()
}

main()