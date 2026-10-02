simulate_paths <- function(S0, T, r, sigma, N, M) {
  dt <- T / N
  S <- matrix(0, nrow = N + 1, ncol = M)
  S[1, ] <- S0
  for (t in 2:(N + 1)) {
    Z <- rnorm(M)
    S[t, ] <- S[t - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * Z)
  }
  return(S)
}

option_price <- function(S, K, T, r, type = 'call') {
  if (type == 'call') {
    payoff <- pmax(S[nrow(S), ] - K, 0)
  } else {
    payoff <- pmax(K - S[nrow(S), ], 0)
  }
  price <- exp(-r * T) * mean(payoff)
  return(price)
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 10000
  S <- simulate_paths(S0, T, r, sigma, N, M)
  price <- option_price(S, K, T, r)
  print(price)
}

main()