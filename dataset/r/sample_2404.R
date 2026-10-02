financial_model <- function(S, K, T, r, sigma, N) {
  dt <- T / N
  dS <- S * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rnorm(1))
  payoff <- pmax(dS - K, 0)
  option_price <- exp(-r * T) * mean(payoff)
  return(option_price)
}

if (commandArgs(trailingOnly = TRUE)[[1]] == "main") {
  financial_model(100, 100, 1, 0.05, 0.2, 1000)
}