generate_sequence <- function(length) {
  sequence <- numeric(length)
  for (i in 2:length) {
    sequence[i] <- sequence[i - 1] + sample(1:4, 1)
  }
  return(sequence)
}

vectorize_sequence <- function(sequence) {
  vectorizer <- Vectorize(function(x) x * 2)
  return(vectorizer(sequence))
}

main <- function() {
  seq_length <- 10
  seq <- generate_sequence(seq_length)
  vec_seq <- vectorize_sequence(seq)
  print(vec_seq)
}

main()