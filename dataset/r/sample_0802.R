library(stats)

MonteCarlo <- setRefClass("MonteCarlo",
  fields = list(
    price = "numeric",
    strike = "numeric",
    rate = "numeric",
    volatility = "numeric",
    time = "numeric",
    simulations = "integer"
  ),
  methods = list(
    _simulate = function(count) {
      if (count >= .self$simulations) {
        return(numeric(0))
      }
      dt <- .self$time / .self$simulations
      drift <- (.self$rate - 0.5 * .self$volatility ^ 2) * dt
      diffusion <- .self$volatility * sqrt(dt)
      price <- .self$price * exp(drift + diffusion * rnorm(1, 0, 1))
      return(c(price, .self$_simulate(count + 1)))
    },
    _payoff = function(prices) {
      return(pmax(prices - .self$strike, 0))
    },
    price_option = function() {
      prices <- .self$_simulate(0)
      payoffs <- .self$_payoff(prices)
      return(exp(-.self$rate * .self$time) * mean(payoffs))
    }
  )
)

main <- function() {
  price <- 100
  strike <- 100
  rate <- 0.05
  volatility <- 0.2
  time <- 1
  simulations <- 10000
  model <- MonteCarlo$new(price, strike, rate, volatility, time, simulations)
  print(model$price_option())
}

main()