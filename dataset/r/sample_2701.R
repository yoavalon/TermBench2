process_sequence <- function() {
  vocab <- c('a', 'b', 'c')
  vector_size <- 3
  while (TRUE) {
    sequence_length <- sample(1:9, 1)
    sequence <- sample(vocab, size = sequence_length, replace = TRUE)
    vectorized_sequence <- replicate(sequence_length, runif(vector_size))
    print(vectorized_sequence)
  }
}

process_sequence()