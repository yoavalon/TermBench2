monte_carlo_pricing <- function(S, K, T, r, sigma, N) {
  dt <- T / N
  S_t <- numeric(N + 1)
  S_t[1] <- S
  z <- rnorm(N)
  for (i in 2:(N + 1)) {
    S_t[i] <- S_t[i - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z[i - 1])
  }
  payoff <- pmax(S_t[N + 1] - K, 0)
  option_price <- exp(-r * T) * mean(payoff)
  return(option_price)
}

result <- monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000)
print(result)