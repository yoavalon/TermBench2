simulate_thermodynamic_state <- function() {
  library(MASS)
  state <- runif(3)
  precision <- 1e-10
  while (TRUE) {
    state <- state + mvrnorm(1, mu = rep(0, 3), Sigma = diag(precision^2, 3))
    print(mean(state))
  }
}

simulate_thermodynamic_state()