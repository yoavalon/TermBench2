r
library(Matrix)
library(stats)

generate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = N + 1, ncol = M)
  paths[1, ] <- S0
  for (t in 2:(N + 1)) {
    z <- rnorm(M)
    paths[t, ] <- paths[t - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

option_price <- function(paths, K, r, T) {
  payoff <- pmax(paths[nrow(paths), ] - K, 0)
  return(exp(-r * T) * mean(payoff))
}

main <- function() {
  S0 <- 100
  K <- 100
  r <- 0.05
  sigma <- 0.2
  T <- 1
  N <- 252
  M <- 10000
  paths <- generate_paths(S0, T, r, sigma, N, M)
  price <- option_price(paths, K, r, T)
  print(price)
}

main()