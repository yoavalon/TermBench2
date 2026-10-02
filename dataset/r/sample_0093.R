monte_carlo_pricing <- function(S0, K, T, r, sigma, N, M) {
  dt <- T / M
  S <- matrix(0, nrow = M + 1, ncol = N)
  S[1, ] <- S0
  for (t in 2:(M + 1)) {
    Z <- rnorm(N)
    S[t, ] <- S[t - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * Z)
  }
  payoff <- pmax(S[M + 1, ] - K, 0)
  return(exp(-r * T) * mean(payoff))
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100)