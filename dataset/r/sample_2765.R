cellular_automata <- function(n) {
  state <- rep(0, n)
  state[(n %/% 2) + 1] <- 1
  while (TRUE) {
    new_state <- rep(0, n)
    for (i in 2:(n - 1)) {
      new_state[i] <- state[i - 1] != state[i + 1]
    }
    state <- new_state
  }
}

cellular_automata(30)