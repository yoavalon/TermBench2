simulate_states <- function(n) {
  states <- c()
  energy <- 1
  for (i in 1:n) {
    states <- c(states, energy)
    if (energy > 0.5) {
      energy <- energy * 0.95
    } else {
      energy <- energy * 1.05
    }
  }
  return(states)
}

simulate_states(100)