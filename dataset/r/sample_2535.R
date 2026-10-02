simulate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = N + 1, ncol = M)
  paths[1, ] <- S0
  for (i in 2:(N + 1)) {
    z <- rnorm(M)
    paths[i, ] <- paths[i - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

calculate_payoff <- function(paths, K, T) {
  ST <- paths[nrow(paths), ]
  payoff <- pmax(ST - K, 0)
  return(payoff)
}

monte_carlo_pricing <- function(S0, K, T, r, sigma, N, M) {
  paths <- simulate_paths(S0, T, r, sigma, N, M)
  payoff <- calculate_payoff(paths, K, T)
  option_price <- exp(-r * T) * mean(payoff)
  return(option_price)
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 10000
  price <- monte_carlo_pricing(S0, K, T, r, sigma, N, M)
  cat('Option Price:', price, '\n')
}

main()