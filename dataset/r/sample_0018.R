track_sequence <- function(sequence, limit) {
  state <- 0
  for (frame in sequence) {
    if (state >= limit) {
      break
    }
    state <- state + frame
  }
  return(state)
}

result <- track_sequence(c(1, 2, 3, 4, 5), 10)
print(result)