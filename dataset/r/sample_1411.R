library(stats)

simulate_paths <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  paths <- replicate(M, S0, simplify = FALSE)
  for (t in 2:(N + 1)) {
    for (i in 1:M) {
      z <- rnorm(1, mean = 0, sd = 1)
      paths[[i]][t] <- paths[[i]][t - 1] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
    }
  }
  return(paths)
}

calculate_payoffs <- function(paths, K, T, r, type = 'call') {
  payoffs <- numeric(length(paths))
  for (i in 1:length(paths)) {
    ST <- paths[[i]][length(paths[[i]])]
    if (type == 'call') {
      payoff <- pmax(0, ST - K)
    } else {
      payoff <- pmax(0, K - ST)
    }
    payoffs[i] <- payoff * exp(-r * T)
  }
  return(payoffs)
}

monte_carlo_pricing <- function(S0, K, T, r, sigma, M) {
  paths <- simulate_paths(S0, r, sigma, T, 100, M)
  payoffs <- calculate_payoffs(paths, K, T, r)
  return(mean(payoffs))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  M <- 10000
  price <- monte_carlo_pricing(S0, K, T, r, sigma, M)
  cat('Option Price:', sprintf('%.2f', price), '\n')
}

main()