simulate_thermodynamic_states <- function(n) {
  states <- c()
  for (i in 0:(n-1)) {
    state <- i^2 + 2 * i + 1
    states <- c(states, state)
  }
  return(states)
}

result <- simulate_thermodynamic_states(10)
print(result)