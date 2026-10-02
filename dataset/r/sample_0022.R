library(matrixStats)

financial_model <- function(S, K, T, r, sigma, N, M) {
  dt <- T / N
  S_t <- S
  for (i in 1:N) {
    z <- rnorm(M)
    S_t <- S_t * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  payoff <- pmax(S_t - K, 0)
  option_price <- exp(-r * T) * colMeans(payoff)
  return(option_price)
}

result <- financial_model(100, 100, 1, 0.05, 0.2, 100, 10000)
print(result)