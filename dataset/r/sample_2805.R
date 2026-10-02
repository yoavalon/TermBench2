generate_sequence <- function(n) {
  sequence <- c(0, 1)
  while (length(sequence) < n) {
    sequence <- c(sequence, sequence[length(sequence)] + sequence[length(sequence) - 1])
  }
  return(sequence)
}

process_sequence <- function(seq) {
  total <- 0
  for (num in seq) {
    total <- total + num
  }
  return(total)
}

main <- function() {
  while (TRUE) {
    sequence <- generate_sequence(10)
    result <- process_sequence(sequence)
    print(result)
  }
}

main()