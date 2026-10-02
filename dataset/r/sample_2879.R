library(matrixStats)

simulate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = M, ncol = N + 1)
  paths[, 1] <- S0
  for (t in 2:(N + 1)) {
    z <- rnorm(M)
    paths[, t] <- paths[, t - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
  }
  return(paths)
}

price_option <- function(paths, strike, option_type) {
  if (option_type == 'call') {
    payoff <- pmax(paths[, N + 1] - strike, 0)
  } else if (option_type == 'put') {
    payoff <- pmax(strike - paths[, N + 1], 0)
  }
  return(exp(-r * T) * mean(payoff))
}

S0 <- 100
T <- 1
r <- 0.05
sigma <- 0.2
N <- 252
M <- 10000
strike <- 100
option_type <- 'call'

main <- function() {
  while (TRUE) {
    paths <- simulate_paths(S0, T, r, sigma, N, M)
    price <- price_option(paths, strike, option_type)
    print(price)
  }
}

main()