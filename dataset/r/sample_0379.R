simulate_boundary_conditions <- function() {
  state <- 0
  while (TRUE) {
    state <- (state + 1) %% 100
    print(paste("State:", state))
  }
}

simulate_boundary_conditions()