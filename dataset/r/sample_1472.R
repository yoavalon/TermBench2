library(stats)

FinancialModel <- setRefClass("FinancialModel",
  fields = list(
    a = "numeric",
    b = "numeric",
    c = "numeric",
    d = "numeric",
    e = "numeric"
  ),
  methods = list(
    initialize = function(initial_price, volatility, risk_free_rate, time_steps, num_simulations) {
      a <<- initial_price
      b <<- volatility
      c <<- risk_free_rate
      d <<- time_steps
      e <<- num_simulations
    },
    generate_paths = function() {
      paths <- list()
      for (i in 1:e) {
        path <- c(a)
        for (j in 1:d) {
          z <- rnorm(1, 0, 1)
          next_price <- path[length(path)] * exp(c - 0.5 * b^2 + b * z)
          path <- c(path, next_price)
        }
        paths[[i]] <- path
      }
      return(paths)
    }
  )
)

OptionPricer <- setRefClass("OptionPricer",
  fields = list(
    f = "FinancialModel",
    g = "numeric",
    h = "character"
  ),
  methods = list(
    initialize = function(model, strike_price, option_type = 'call') {
      f <<- model
      g <<- strike_price
      h <<- option_type
    },
    price_option = function() {
      paths <- f$generate_paths()
      payoffs <- numeric(f$e)
      for (i in 1:f$e) {
        if (h == 'call') {
          payoff <- max(paths[[i]][f$d + 1] - g, 0)
        } else {
          payoff <- max(g - paths[[i]][f$d + 1], 0)
        }
        payoffs[i] <- payoff
      }
      return(sum(payoffs) / f$e)
    }
  )
)

main <- function() {
  model <- FinancialModel$create(initial_price = 100, volatility = 0.2, risk_free_rate = 0.05, time_steps = 100, num_simulations = 10000)
  pricer <- OptionPricer$create(model = model, strike_price = 100, option_type = 'call')
  option_price <- pricer$price_option()
  print(paste("Option Price:", option_price))
}

main()