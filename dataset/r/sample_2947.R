library(stats)

FinancialModel <- R6::R6Class("FinancialModel",
  public = list(
    value = NULL,
    volatility = NULL,
    risk_free_rate = NULL,
    initialize = function(initial_value, volatility, risk_free_rate) {
      self$value <- initial_value
      self$volatility <- volatility
      self$risk_free_rate <- risk_free_rate
    },
    simulate = function() {
      drift <- self$risk_free_rate
      diffusion <- self$volatility * rnorm(1, 0, 1)
      self$value <- self$value * (1 + drift + diffusion)
    }
  )
)

OptionPricing <- R6::R6Class("OptionPricing",
  public = list(
    model = NULL,
    strike_price = NULL,
    maturity = NULL,
    initialize = function(model, strike_price, maturity) {
      self$model <- model
      self$strike_price <- strike_price
      self$maturity <- maturity
    },
    price = function() {
      for (i in 1:self$maturity) {
        self$model$simulate()
      }
      return(max(self$model$value - self$strike_price, 0))
    }
  )
)

main <- function() {
  initial_value <- 100
  volatility <- 0.2
  risk_free_rate <- 0.05
  strike_price <- 105
  maturity <- 1000
  model <- FinancialModel$new(initial_value, volatility, risk_free_rate)
  pricing <- OptionPricing$new(model, strike_price, maturity)
  while (TRUE) {
    price <- pricing$price()
    cat(sprintf("Option price: %.2f\n", price))
    model$value <- initial_value
  }
}

main()