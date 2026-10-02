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
    initialize = function(initial_price, volatility, risk_free_rate, strike_price, maturity) {
      a <<- initial_price
      b <<- volatility
      c <<- risk_free_rate
      d <<- strike_price
      e <<- maturity
    },
    simulate_paths = function(n) {
      paths <- list()
      for (i in 1:n) {
        path <- c(a)
        for (j in 1:(e * 252)) {
          z <- rnorm(1, mean = 0, sd = 1)
          s <- tail(path, 1) * (1 + c / 252 + b * z / 100)
          path <- c(path, s)
        }
        paths[[i]] <- path
      }
      return(paths)
    },
    payoff = function(path) {
      return(max(tail(path, 1) - d, 0))
    }
  )
)

PricingEngine <- setRefClass("PricingEngine",
  fields = list(
    f = "FinancialModel"
  ),
  methods = list(
    initialize = function(model) {
      f <<- model
    },
    price_option = function(simulations) {
      total <- 0
      for (i in 1:simulations) {
        paths <- f$simulate_paths(100)
        payoff_sum <- sum(sapply(paths, f$payoff))
        total <- total + payoff_sum / length(paths)
      }
      return(total / simulations * exp(-f$c * f$e))
    }
  )
)

main <- function() {
  model <- FinancialModel$new(100, 20, 0.05, 100, 1)
  engine <- PricingEngine$new(model)
  price <- engine$price_option(1000)
  print(price)
}

main()