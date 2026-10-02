simulate_paths <- function(S0, K, T, r, sigma, N, M) {
  dt <- T / N
  S <- matrix(0, nrow = N + 1, ncol = M)
  S[1, ] <- S0
  for (i in 2:(N + 1)) {
    Z <- rnorm(M)
    S[i, ] <- S[i - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * Z)
  }
  return(S)
}

option_price <- function(paths, K, r, T) {
  payoff <- pmax(paths[nrow(paths), ] - K, 0)
  price <- exp(-r * T) * mean(payoff)
  return(price)
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 10000
  paths <- simulate_paths(S0, K, T, r, sigma, N, M)
  price <- option_price(paths, K, r, T)
  print(price)
}

main()