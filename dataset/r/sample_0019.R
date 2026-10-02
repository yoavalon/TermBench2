calculate_option_price <- function(S, K, r, T, sigma, N) {
  dt <- T / N
  dS <- S * sigma * sqrt(dt)
  paths <- S * exp((r - 0.5 * sigma^2) * dt + dS * rnorm(N))
  payoff <- pmax(paths[N] - K, 0)
  return(exp(-r * T) * mean(payoff))
}

result <- calculate_option_price(100, 100, 0.05, 1, 0.2, 1000)
print(result)