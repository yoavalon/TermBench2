cellular_automata <- function(state, rule) {
  size <- length(state)
  next_state <- rep(0, size)
  for (i in 1:size) {
    left <- state[(i - 1) %% size + 1]
    center <- state[i]
    right <- state[(i + 1) %% size + 1]
    index <- (left << 2) | (center << 1) | right
    next_state[i] <- (rule >> index) & 1
  }
  return(cellular_automata(next_state, rule))
}

rule <- 30
initial_state <- c(rep(0, 10), 1, rep(0, 10))
cellular_automata(initial_state, rule)