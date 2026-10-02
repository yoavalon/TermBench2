generate_paths <- function(S0, r, sigma, T, M, N) {
  dt <- T / M
  paths <- matrix(0, nrow = M + 1, ncol = N)
  paths[1, ] <- S0
  for (t in 2:(M + 1)) {
    z <- rnorm(N)
    paths[t, ] <- paths[t - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

price_option <- function(paths, strike, T, r) {
  payoff <- pmax(paths[nrow(paths), ] - strike, 0)
  return(exp(-r * T) * mean(payoff))
}

main <- function() {
  S0 <- 100
  r <- 0.05
  sigma <- 0.2
  T <- 1
  M <- 100
  N <- 1000
  K <- 100
  paths <- generate_paths(S0, r, sigma, T, M, N)
  option_price <- price_option(paths, K, T, r)
  print(paste('Option Price:', option_price))
}

main()