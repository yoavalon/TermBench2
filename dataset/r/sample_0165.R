library(matrixStats)
library(MASS)

generate_paths <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  S <- matrix(0, nrow = N + 1, ncol = M)
  S[1, ] <- S0
  for (t in 2:(N + 1)) {
    S[t, ] <- S[t - 1, ] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rnorm(M))
  }
  return(S)
}

option_price <- function(paths, K, r, T, payoff) {
  discounted_payoffs <- exp(-r * T) * payoff(paths[nrow(paths), ], K)
  return(mean(discounted_payoffs))
}

main <- function() {
  S0 <- 100
  K <- 100
  r <- 0.05
  T <- 1
  N <- 252
  M <- 10000
  sigma <- 0.2
  mu <- 0.1

  european_call <- function(S, K) {
    return(pmax(S - K, 0))
  }
  paths <- generate_paths(S0, mu, sigma, T, N, M)
  call_price <- option_price(paths, K, r, T, european_call)
  print(call_price)
}

main()