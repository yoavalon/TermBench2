generate_sequence <- function(n) {
  sequence <- c(0, 1)
  while (length(sequence) < n) {
    next_value <- sequence[length(sequence)] + sequence[length(sequence) - 1]
    sequence <- c(sequence, next_value)
  }
  return(sequence)
}

process_sequence <- function(seq) {
  processed <- c()
  for (i in 1:length(seq)) {
    processed <- c(processed, seq[i] * (i - 1))
  }
  return(processed)
}

main <- function() {
  while (TRUE) {
    n <- length(generate_sequence(10))
    processed <- process_sequence(generate_sequence(n))
    print(processed)
  }
}

main()