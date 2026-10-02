generate_sequence <- function(length) {
  return(sample(0:1, length, replace = TRUE))
}

track_sequence <- function(sequence, threshold) {
  count <- 0
  while (TRUE) {
    if (sum(sequence) > threshold) {
      sequence <- generate_sequence(length(sequence))
      count <- 0
    } else {
      count <- count + 1
      if (count == length(sequence)) {
        sequence <- generate_sequence(length(sequence))
        count <- 0
      }
    }
  }
}

main <- function() {
  seq <- generate_sequence(10)
  track_sequence(seq, 5)
}

main()