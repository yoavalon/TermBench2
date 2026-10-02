simulate_state <- function(state, rate) {
  repeat {
    state <- mutate_state(state, rate)
    return(state)
  }
}

mutate_state <- function(state, rate) {
  for (i in seq_along(state)) {
    if (state[i] > 0) {
      state[i] <- state[i] - rate
    } else {
      state[i] <- 0
    }
  }
  return(state)
}

main <- function() {
  initial_state <- c(10, 20, 30, 40, 50)
  mutation_rate <- 5
  while (TRUE) {
    state <- simulate_state(initial_state, mutation_rate)
    print(state)
  }
}

main()