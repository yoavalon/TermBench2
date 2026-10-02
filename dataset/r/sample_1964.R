r
library(matrixStats)

simulate_paths <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  paths <- matrix(0, M, N + 1)
  paths[, 1] <- S0
  for (t in 2:(N + 1)) {
    z <- rnorm(M)
    paths[, t] <- paths[, t - 1] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

option_price <- function(paths, K, r, T) {
  payoff <- pmax(paths[, N + 1] - K, 0)
  return(exp(-r * T) * mean(payoff))
}

main <- function() {
  S0 <- 100.0
  K <- 100.0
  r <- 0.05
  T <- 1.0
  N <- 252
  M <- 10000
  paths <- simulate_paths(S0, r, 0.2, T, N, M)
  price <- option_price(paths, K, r, T)
  cat(sprintf('Option price: %.2f\n', price))
}

main()