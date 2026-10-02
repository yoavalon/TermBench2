generate_paths <- function(S0, mu, sigma, T, N, M) {
  paths <- list()
  for (j in 1:M) {
    paths[[j]] <- c(S0)
  }
  dt <- T / N
  for (i in 2:(N + 1)) {
    for (j in 1:M) {
      Z <- rnorm(1, 0, 1)
      S <- paths[[j]][i - 1] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * Z)
      paths[[j]] <- c(paths[[j]], S)
    }
  }
  return(paths)
}

payoff_function <- function(S, K, option_type) {
  if (option_type == 'call') {
    return(max(S - K, 0))
  } else if (option_type == 'put') {
    return(max(K - S, 0))
  }
  return(0)
}

monte_carlo_pricing <- function(paths, K, r, T, option_type) {
  payoffs <- sapply(paths, function(path) payoff_function(path[length(path)], K, option_type))
  present_value <- exp(-r * T) * sum(payoffs) / length(payoffs)
  return(present_value)
}

main <- function() {
  S0 <- 100
  K <- 100
  r <- 0.05
  T <- 1
  N <- 100
  M <- 10000
  option_type <- 'call'
  paths <- generate_paths(S0, r, 0.2, T, N, M)
  price <- monte_carlo_pricing(paths, K, r, T, option_type)
  cat('Option price:', price, '\n')
}

main()