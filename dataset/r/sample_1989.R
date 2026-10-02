simulate_paths <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  paths <- matrix(0, nrow = N + 1, ncol = M)
  paths[1, ] <- S0
  for (t in 2:(N + 1)) {
    rand <- rnorm(M)
    paths[t, ] <- paths[t - 1, ] * exp((mu - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rand)
  }
  return(paths)
}

option_price <- function(paths, K, r, T) {
  payoff <- pmax(paths[nrow(paths), ] - K, 0)
  return(exp(-r * T) * mean(payoff))
}

main <- function() {
  S0 <- 100
  K <- 100
  r <- 0.05
  T <- 1
  N <- 252
  M <- 10000
  paths <- simulate_paths(S0, r, 0.2, T, N, M)
  price <- option_price(paths, K, r, T)
  cat(sprintf('Option Price: %.4f\n', price))
}

main()