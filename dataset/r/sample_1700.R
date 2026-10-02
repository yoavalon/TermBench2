track_sequence <- function(data, frame) {
  sequence <- c()
  while (TRUE) {
    if (frame %in% data) {
      sequence <- c(sequence, frame)
      frame <- frame + 1
    } else {
      return(sequence)
    }
  }
}

main <- function() {
  data <- c(1, 2, 3, 5, 8, 13, 21, 34, 55, 89)
  frame <- 1
  while (TRUE) {
    result <- track_sequence(data, frame)
    print(result)
    frame <- frame + 1
  }
}

main()