library(matrixStats)

simulate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = N + 1, ncol = M)
  paths[1, ] <- S0
  for (t in 2:(N + 1)) {
    Z <- rnorm(M)
    paths[t, ] <- paths[t - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * Z)
  }
  return(paths)
}

option_price <- function(paths, K, r, T, N) {
  discounted_payoffs <- exp(-r * T) * pmax(paths[N + 1, ] - K, 0)
  return(mean(discounted_payoffs))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 10000
  paths <- simulate_paths(S0, T, r, sigma, N, M)
  price <- option_price(paths, K, r, T, N)
  print(price)
}

main()