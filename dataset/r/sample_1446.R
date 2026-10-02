library(MASS)

generate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = N + 1, ncol = M)
  paths[1, ] <- S0
  for (t in 2:(N + 1)) {
    z <- mvrnorm(M, rep(0, 1), diag(1))
    paths[t, ] <- paths[t - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

calculate_payoffs <- function(paths, K, option_type) {
  if (option_type == 'call') {
    return(pmax(paths[nrow(paths), ] - K, 0))
  } else if (option_type == 'put') {
    return(pmax(K - paths[nrow(paths), ], 0))
  }
  return(NULL)
}

price_option <- function(S0, K, T, r, sigma, N, M, option_type) {
  paths <- generate_paths(S0, T, r, sigma, N, M)
  payoffs <- calculate_payoffs(paths, K, option_type)
  return(exp(-r * T) * mean(payoffs))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 10000
  option_type <- 'call'
  option_price <- price_option(S0, K, T, r, sigma, N, M, option_type)
  cat(sprintf('Option price: %.2f\n', option_price))
}

main()