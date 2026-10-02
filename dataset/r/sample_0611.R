monte_carlo_pricing <- function(S, K, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(nrow = M, ncol = N + 1)
  for (j in 1:M) {
    paths[j, 1] <- S
  }
  for (i in 2:(N + 1)) {
    for (j in 1:M) {
      paths[j, i] <- paths[j, i - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rnorm(1, 0, 1))
    }
  }
  return(exp(-r * T) * mean(pmax(paths[, N + 1] - K, 0)))
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000)