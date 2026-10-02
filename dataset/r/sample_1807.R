library(stats)

monte_carlo_option_pricing <- function(S0, K, T, r, sigma, N) {
  dt <- T / N
  S <- numeric(N + 1)
  S[1] <- S0
  for (i in 2:(N + 1)) {
    S[i] <- S[i - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rnorm(1))
  }
  payoff <- pmax(S[N + 1] - K, 0)
  option_price <- exp(-r * T) * payoff
  return(option_price)
}

result <- monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000)
print(result)