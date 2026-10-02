analyze_sequences <- function() {
  state <- 0
  transitions <- c(1, 2, 0)
  sequence <- c(state)
  for (i in 1:10) {
    state <- transitions[state + 1]
    sequence <- c(sequence, state)
  }
  return(sequence)
}

result <- analyze_sequences()
print(result)