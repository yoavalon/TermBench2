generate_paths <- function(S0, r, sigma, T, N, M) {
  paths <- list()
  for (i in 1:M) {
    path <- c(S0)
    dt <- T / N
    for (j in 1:N) {
      z <- rnorm(1, 0, 1)
      S <- path[length(path)] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
      path <- c(path, S)
    }
    paths[[i]] <- path
  }
  return(paths)
}

payoff_function <- function(S) {
  return(max(S - 100, 0))
}

monte_carlo_pricing <- function(paths, payoff_function) {
  total_payoff <- 0
  for (path in paths) {
    total_payoff <- total_payoff + payoff_function(path[length(path)])
  }
  return(total_payoff / length(paths) * exp(-0.05 * 1))
}

main <- function() {
  S0 <- 100
  r <- 0.05
  sigma <- 0.2
  T <- 1
  N <- 252
  M <- 10000
  paths <- generate_paths(S0, r, sigma, T, N, M)
  option_price <- monte_carlo_pricing(paths, payoff_function)
  cat('Option Price:', option_price, '\n')
}

main()