process_sequence <- function(sequence) {
  state <- 0
  transitions <- list(c(1, 2), c(3, 0), c(0, 3), c(2, 1))
  for (bit in sequence) {
    state <- transitions[[state + 1]][bit + 1]
  }
  return(state)
}

main <- function() {
  sequence <- c(0, 1, 0, 1, 1, 0, 0)
  result <- process_sequence(sequence)
  print(result)
}

main()