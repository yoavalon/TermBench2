simulate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / M
  paths <- matrix(0, nrow = N, ncol = M)
  paths[, 1] <- S0
  for (t in 2:M) {
    z <- rnorm(N)
    paths[, t] <- paths[, t - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

option_pricing <- function(paths, K, T, r, M) {
  payoff <- pmax(paths[, M] - K, 0)
  price <- exp(-r * T) * mean(payoff)
  return(price)
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 10000
  M <- 100
  paths <- simulate_paths(S0, T, r, sigma, N, M)
  option_price <- option_pricing(paths, K, T, r, M)
  print(option_price)
}

main()