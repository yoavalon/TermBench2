library(matrixStats)
library(stats)

generate_paths <- function(s0, mu, sigma, dt, T, N) {
  paths <- matrix(0, nrow = N, ncol = int(T / dt) + 1)
  paths[, 1] <- s0
  for (t in 2:(int(T / dt) + 1)) {
    z <- rnorm(N)
    paths[, t] <- paths[, t - 1] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

calculate_payoff <- function(paths, strike, option_type) {
  if (option_type == 'call') {
    return(pmax(paths[, ncol(paths)] - strike, 0))
  } else if (option_type == 'put') {
    return(pmax(strike - paths[, ncol(paths)], 0))
  }
  return(NULL)
}

monte_carlo_pricing <- function(s0, strike, r, T, sigma, N, dt, option_type) {
  paths <- generate_paths(s0, r, sigma, dt, T, N)
  payoff <- calculate_payoff(paths, strike, option_type)
  discount_factor <- exp(-r * T)
  option_price <- discount_factor * colMeans(payoff)
  return(option_price)
}

main <- function() {
  s0 <- 100.0
  strike <- 100.0
  r <- 0.05
  T <- 1.0
  sigma <- 0.2
  N <- 10000
  dt <- 0.01
  option_type <- 'call'
  price <- monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type)
  print(price)
}

main()