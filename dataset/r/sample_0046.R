simulate_boundary_conditions <- function() {
  state <- 0
  for (i in 1:100) {
    if (state > 10) {
      break
    }
    state <- state + 1
  }
  print(state)
}

simulate_boundary_conditions()