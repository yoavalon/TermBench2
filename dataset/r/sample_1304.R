r
simulate_paths <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  S <- matrix(0, nrow = M, ncol = N)
  S[, 1] <- S0
  for (t in 2:N) {
    z <- rnorm(M)
    S[, t] <- S[, t - 1] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(S)
}

calculate_option_price <- function(paths, K, r, T) {
  payoff <- pmax(paths[, N] - K, 0)
  option_price <- exp(-r * T) * mean(payoff)
  return(option_price)
}

main <- function() {
  S0 <- 100
  K <- 100
  r <- 0.05
  T <- 1
  N <- 252
  M <- 10000
  paths <- simulate_paths(S0, r, 0.2, T, N, M)
  option_price <- calculate_option_price(paths, K, r, T)
  print(option_price)
}

main()