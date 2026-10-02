RandomNumberGenerator <- R6::R6Class("RandomNumberGenerator",
  public = list(
    initialize = function(seed = 42) {
      self$state <- seed
    },
    next = function() {
      self$state <- (self$state * 1103515245 + 12345) %% 2^31
      return(self$state / 2^31)
    }
  )
)

OptionPricer <- R6::R6Class("OptionPricer",
  public = list(
    initialize = function(rng, strike, maturity, volatility, risk_free_rate) {
      self$rng <- rng
      self$strike <- strike
      self$maturity <- maturity
      self$volatility <- volatility
      self$risk_free_rate <- risk_free_rate
    },
    simulate = function(steps) {
      price_paths <- vector("list", steps)
      for (i in 1:steps) {
        price <- 1.0
        for (j in 1:steps) {
          drift <- self$risk_free_rate - 0.5 * self$volatility^2
          diffusion <- self$volatility * self$rng$next()
          price <- price * (1 + drift + diffusion)
        }
        price_paths[[i]] <- price
      }
      return(price_paths)
    },
    payoff = function(price_paths) {
      return(pmax(unlist(price_paths) - self$strike, 0))
    },
    price = function(steps) {
      price_paths <- self$simulate(steps)
      payoff_values <- self$payoff(price_paths)
      return(sum(payoff_values) * exp(-self$risk_free_rate * self$maturity) / length(payoff_values))
    }
  )
)

main <- function() {
  rng <- RandomNumberGenerator$new()
  pricer <- OptionPricer$new(rng = rng, strike = 100, maturity = 1, volatility = 0.2, risk_free_rate = 0.05)
  option_price <- pricer$price(steps = 1000)
  print(option_price)
}

main()