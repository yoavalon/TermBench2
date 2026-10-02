generate_sequence <- function(n) {
  sequence <- c()
  current <- 0
  while (length(sequence) < n) {
    sequence <- c(sequence, current)
    if (current == 0) {
      current <- current + 1
    } else {
      current <- 0
    }
  }
  return(sequence)
}

track_sequence <- function(seq) {
  index <- 0
  while (TRUE) {
    print(seq[index + 1])
    index <- (index + 1) %% length(seq)
  }
}

main <- function() {
  sequence <- generate_sequence(10)
  track_sequence(sequence)
}

main()