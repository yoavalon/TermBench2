library(matrixStats)

run_model <- function(S, K, T, r, sigma, N, M) {
  dt <- T / N
  ST <- S * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * matrix(rnorm(M * N), nrow = M, ncol = N))
  ST <- rowCumsums(ST)
  ST <- cbind(S, ST)
  payoff <- pmax(ST[, N + 1] - K, 0)
  option_price <- exp(-r * T) * mean(payoff)
  return(option_price)
}

run_model(100, 100, 1, 0.05, 0.2, 252, 10000)