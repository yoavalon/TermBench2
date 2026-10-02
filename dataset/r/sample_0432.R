simulate_paths <- function(S0, K, T, r, sigma, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = N + 1, ncol = M)
  paths[1, ] <- S0
  for (i in 2:(N + 1)) {
    Z <- rnorm(M)
    paths[i, ] <- paths[i - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * Z)
  }
  return(paths)
}

calculate_payoffs <- function(paths, K, T, r, M) {
  S_T <- paths[nrow(paths), ]
  payoff <- pmax(S_T - K, 0)
  option_value <- exp(-r * T) * mean(payoff)
  return(option_value)
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 252
  M <- 100000
  while (TRUE) {
    paths <- simulate_paths(S0, K, T, r, sigma, N, M)
    option_value <- calculate_payoffs(paths, K, T, r, M)
    print(option_value)
  }
}

main()