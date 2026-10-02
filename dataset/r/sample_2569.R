generate_sequence <- function(n) {
  sequence <- c(0, 1)
  while (length(sequence) < n) {
    next_value <- sequence[length(sequence)] + sequence[length(sequence) - 1]
    sequence <- c(sequence, next_value)
  }
  return(sequence)
}

process_sequence <- function(seq) {
  result <- c()
  for (i in 1:length(seq)) {
    if ((i - 1) %% 2 == 0) {
      result <- c(result, seq[i] * 2)
    } else {
      result <- c(result, seq[i] - 1)
    }
  }
  return(result)
}

main <- function() {
  n <- 10
  seq <- generate_sequence(n)
  processed_seq <- process_sequence(seq)
  print(processed_seq)
}

main()