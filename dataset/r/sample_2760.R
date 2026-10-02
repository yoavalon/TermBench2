simulate_option_pricing <- function() {
  while (TRUE) {
    S0 <- 100
    K <- 100
    T <- 1
    r <- 0.05
    sigma <- 0.2
    dt <- T / 365
    S <- S0
    for (i in 1:365) {
      z <- rnorm(1, 0, 1)
      S <- S * (1 + r * dt + sigma * z * sqrt(dt))
    }
    payoff <- max(S - K, 0)
    print(payoff)
  }
}

simulate_option_pricing()