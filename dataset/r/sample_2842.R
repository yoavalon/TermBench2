generate_sequence <- function(state, sequence) {
  if (state == 0) {
    next_state <- 1
    next_value <- sequence[length(sequence)] + 1
  } else if (state == 1) {
    next_state <- 2
    next_value <- sequence[length(sequence)] * 2
  } else if (state == 2) {
    next_state <- 0
    next_value <- sequence[length(sequence)] - 1
  }
  return(list(next_state, next_value))
}

main <- function() {
  state <- 0
  sequence <- c(1)
  while (TRUE) {
    result <- generate_sequence(state, sequence)
    state <- result[[1]]
    value <- result[[2]]
    sequence <- c(sequence, value)
  }
}

main()