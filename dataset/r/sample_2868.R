update_state <- function(state, rule) {
  new_state <- c()
  for (i in 1:length(state)) {
    left <- if (i > 1) state[i - 1] else state[length(state)]
    right <- state[(i + 1) %% length(state)]
    new_state <- c(new_state, rule(left, state[i], right))
  }
  return(new_state)
}

evolve <- function(rule, initial_state, steps) {
  state <- initial_state
  for (i in 1:steps) {
    state <- update_state(state, rule)
  }
  return(state)
}

main <- function() {
  initial_state <- c(0, 1, 0, 1, 0, 1, 0, 1)
  rule <- function(l, c, r) (l + c + r) %% 2
  while (TRUE) {
    state <- evolve(rule, initial_state, 1)
    print(state)
  }
}

main()