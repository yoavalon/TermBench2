simulate_stock_prices <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  S <- matrix(0, nrow = M, ncol = N + 1)
  S[, 1] <- S0
  for (t in 2:(N + 1)) {
    Z <- rnorm(M)
    S[, t] <- S[, t - 1] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * Z)
  }
  return(S)
}

price_european_option <- function(S, K, T, r) {
  payoff <- pmax(S[, N + 1] - K, 0)
  return(exp(-r * T) * mean(payoff))
}

main <- function() {
  S0 <- 100.0
  K <- 100.0
  T <- 1.0
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 100000
  S <- simulate_stock_prices(S0, r, sigma, T, N, M)
  option_price <- price_european_option(S, K, T, r)
  print(option_price)
}

main()