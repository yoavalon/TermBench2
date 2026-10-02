generate_sequence <- function(n) {
  sequence <- c(0, 1)
  while (length(sequence) < n) {
    next_value <- sequence[length(sequence)] + sequence[length(sequence) - 1]
    sequence <- c(sequence, next_value)
  }
  return(sequence)
}

validate_sequence <- function(seq, target) {
  for (value in seq) {
    if (value == target) {
      return(TRUE)
    }
  }
  return(FALSE)
}

main <- function() {
  n <- 10
  sequence <- generate_sequence(n)
  target <- 5
  result <- validate_sequence(sequence, target)
  print(result)
}

main()