simulate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = N + 1, ncol = M)
  paths[1, ] <- S0
  for (t in 2:(N + 1)) {
    z <- rnorm(M)
    paths[t, ] <- paths[t - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

payoff_function <- function(paths, K, option_type) {
  if (option_type == 'call') {
    return(pmax(paths[nrow(paths), ] - K, 0))
  } else if (option_type == 'put') {
    return(pmax(K - paths[nrow(paths), ], 0))
  }
}

price_option <- function(S0, K, T, r, sigma, N, M, option_type) {
  paths <- simulate_paths(S0, T, r, sigma, N, M)
  payoff <- payoff_function(paths, K, option_type)
  return(exp(-r * T) * mean(payoff))
}

main <- function() {
  S0 <- 100.0
  K <- 100.0
  T <- 1.0
  r <- 0.05
  sigma <- 0.2
  N <- 252
  M <- 10000
  option_type <- 'call'
  option_price <- price_option(S0, K, T, r, sigma, N, M, option_type)
  cat('Option Price:', option_price, '\n')
}

main()