library(stats)

simulate_paths <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  paths <- replicate(M, c(S0), simplify = FALSE)
  for (i in 2:(N + 1)) {
    for (j in 1:M) {
      dW <- rnorm(1, 0, 1) * sqrt(dt)
      paths[[j]] <- c(paths[[j]], paths[[j]][i - 1] * (1 + mu * dt + sigma * dW))
    }
  }
  return(paths)
}

option_price <- function(paths, K, r, T) {
  payoff <- sapply(paths, function(path) max(path[length(path)] - K, 0))
  discounted_payoff <- payoff * (1 - r * T)
  return(mean(discounted_payoff))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 1000
  paths <- simulate_paths(S0, mu = r, sigma = sigma, T = T, N = N, M = M)
  price <- option_price(paths, K, r, T)
  print(price)
}

main()