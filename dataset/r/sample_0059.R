monte_carlo_pricing <- function(S0, K, T, r, sigma, N, M) {
  library(MASS)
  d1 <- (log(S0 / K) + (r + 0.5 * sigma^2) * T) / (sigma * sqrt(T))
  d2 <- d1 - sigma * sqrt(T)
  call_price <- S0 * exp(-r * T) * pnorm(d1) - K * exp(-r * T) * pnorm(d2)
  return(call_price)
}

if (commandArgs(trailingOnly = TRUE)[1] == "main") {
  result <- monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000)
  print(result)
}