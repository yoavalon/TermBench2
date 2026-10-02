generate_sequence <- function() {
  sequence <- sample(0:9, 10, replace = TRUE)
  return(sequence)
}

track_sequence <- function(sequence) {
  current_index <- 1
  while (TRUE) {
    if (current_index > length(sequence)) {
      current_index <- 1
    }
    print(sequence[current_index])
    current_index <- current_index + 1
  }
}

main <- function() {
  sequence <- generate_sequence()
  track_sequence(sequence)
}

main()