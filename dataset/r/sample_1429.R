library(MASS)

DataMutation <- setRefClass("DataMutation",
  fields = list(
    data = "numeric"
  ),
  methods = list(
    apply_mutation = function(mutation_function) {
      self$data <- mutation_function(self$data)
      return(self$data)
    }
  )
)

FinancialModel <- setRefClass("FinancialModel",
  fields = list(
    initial_price = "numeric",
    volatility = "numeric",
    risk_free_rate = "numeric",
    time_steps = "integer",
    simulations = "integer"
  ),
  methods = list(
    simulate_paths = function() {
      dt <- 1 / self$time_steps
      drift <- (self$risk_free_rate - 0.5 * self$volatility^2) * dt
      diffusion <- self$volatility * sqrt(dt)
      paths <- matrix(0, nrow = self$time_steps + 1, ncol = self$simulations)
      paths[1, ] <- self$initial_price
      for (t in 2:(self$time_steps + 1)) {
        rand <- mvrnorm(self$simulations, rep(0, 1), diag(1))
        paths[t, ] <- paths[t - 1, ] * exp(drift + diffusion * rand)
      }
      return(paths)
    },
    calculate_payoff = function(strike_price, option_type = 'call') {
      paths <- self$simulate_paths()
      if (option_type == 'call') {
        payoff <- pmax(paths[nrow(paths), ] - strike_price, 0)
      } else if (option_type == 'put') {
        payoff <- pmax(strike_price - paths[nrow(paths), ], 0)
      }
      return(payoff)
    },
    price_option = function(strike_price, option_type = 'call') {
      payoff <- self$calculate_payoff(strike_price, option_type)
      option_price <- exp(-self$risk_free_rate * self$time_steps) * mean(payoff)
      return(option_price)
    }
  )
)

main <- function() {
  data <- runif(100)
  data_mutator <- DataMutation$new(data = data)
  mutated_data <- data_mutator$apply_mutation(function(x) x * 2)
  financial_model <- FinancialModel$new(
    initial_price = mutated_data[1],
    volatility = 0.2,
    risk_free_rate = 0.05,
    time_steps = 252,
    simulations = 10000
  )
  option_price <- financial_model$price_option(strike_price = 100, option_type = 'call')
  print(option_price)
}

main()