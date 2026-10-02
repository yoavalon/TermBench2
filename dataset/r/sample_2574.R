update_state <- function(state, rule) {
  new_state <- c()
  for (i in 1:length(state)) {
    left <- if (i > 1) state[i - 1] else state[length(state)]
    right <- state[(i + 1) %% length(state)]
    new_state <- c(new_state, rule(left, state[i], right))
  }
  return(new_state)
}

cellular_automaton <- function(steps, initial, rule) {
  state <- initial
  for (i in 1:steps) {
    state <- update_state(state, rule)
  }
  return(state)
}

rule_conway <- function(left, center, right) {
  count <- left + center + right
  if (count == 3) {
    return(1)
  } else if (count == 2) {
    return(0)
  } else {
    return(center)
  }
}

main <- function() {
  initial_state <- c(0, 1, 0, 1, 0, 1, 0, 1, 0, 1)
  steps <- 5
  final_state <- cellular_automaton(steps, initial_state, rule_conway)
  print(final_state)
}

main()