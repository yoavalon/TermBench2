generate_sequence <- function(length) {
  return(sample(letters, length, replace = TRUE))
}

vectorize_sequence <- function(sequence) {
  vector <- table(sequence)
  return(vector)
}

process_data <- function() {
  while (TRUE) {
    seq <- generate_sequence(100)
    vec <- vectorize_sequence(seq)
    print(vec)
  }
}

main <- function() {
  process_data()
}

main()