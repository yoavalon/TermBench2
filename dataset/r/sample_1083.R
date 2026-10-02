simulate_price <- function(path, strike, rate, vol, time, steps) {
  dt <- time / steps
  for (i in 1:steps) {
    rand <- rnorm(1, 0, 1)
    drift <- (rate - 0.5 * vol^2) * dt
    diffusion <- vol * rand * sqrt(dt)
    path <- c(path, path[length(path)] * (1 + drift + diffusion))
  }
  return(path)
}

option_price <- function(paths, strike, r, t) {
  payoff <- 0
  for (path in paths) {
    payoff <- payoff + max(tail(path, 1) - strike, 0)
  }
  return(payoff * (1 / r)^t)
}

main <- function() {
  strike <- 100
  rate <- 0.05
  vol <- 0.2
  time <- 1
  steps <- 252
  paths <- list(c(100))
  paths[[1]] <- simulate_price(paths[[1]], strike, rate, vol, time, steps)
  while (TRUE) {
    paths[[length(paths) + 1]] <- c(100)
    paths[[length(paths)]] <- simulate_price(paths[[length(paths)]], strike, rate, vol, time, steps)
    print(option_price(paths, strike, rate, time))
  }
}

main()