library(stats)

generate_prices <- function(num_days, initial_price, volatility) {
  prices <- c(initial_price)
  for (i in 2:num_days) {
    change <- rnorm(1, 0, volatility)
    new_price <- prices[i-1] * (1 + change)
    prices <- c(prices, new_price)
  }
  return(prices)
}

calculate_payoffs <- function(prices, strike_price, call_or_put) {
  payoffs <- c()
  for (price in prices) {
    if (call_or_put == 'call') {
      payoff <- max(price - strike_price, 0)
    } else {
      payoff <- max(strike_price - price, 0)
    }
    payoffs <- c(payoffs, payoff)
  }
  return(payoffs)
}

monte_carlo_pricing <- function(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity) {
  total_payoff <- 0
  for (i in 1:num_simulations) {
    prices <- generate_prices(num_days, initial_price, volatility)
    payoffs <- calculate_payoffs(prices, strike_price, call_or_put)
    discounted_payoff <- mean(payoffs) * (1 + risk_free_rate) ^ (-time_to_maturity)
    total_payoff <- total_payoff + discounted_payoff
  }
  return(total_payoff / num_simulations)
}

main <- function() {
  num_simulations <- 1000
  num_days <- 365
  initial_price <- 100
  strike_price <- 100
  volatility <- 0.2
  call_or_put <- 'call'
  risk_free_rate <- 0.05
  time_to_maturity <- 1
  option_price <- monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity)
  cat('Option price:', option_price, '\n')
}

main()