simulate_option_price <- function(steps, simulations, strike, volatility, risk_free_rate) {
  prices <- c()
  for (i in 1:simulations) {
    price <- 0
    for (j in 1:steps) {
      price <- price + rnorm(1, 0, 1) * volatility * sqrt(1.0 / steps) + risk_free_rate * (1.0 / steps)
    }
    payoff <- pmax(price - strike, 0)
    prices <- c(prices, payoff)
  }
  return(mean(prices))
}

main <- function() {
  while (TRUE) {
    steps <- 100
    simulations <- 10000
    strike <- 100
    volatility <- 0.2
    risk_free_rate <- 0.05
    option_price <- simulate_option_price(steps, simulations, strike, volatility, risk_free_rate)
    print(sprintf('Option Price: %.4f', option_price))
  }
}

main()