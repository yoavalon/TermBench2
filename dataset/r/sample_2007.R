library(stats)

FinancialModel <- setRefClass("FinancialModel",
  fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric"),
  methods = list(
    simulate_paths = function(num_simulations, num_steps) {
      paths <- vector("list", num_simulations)
      dt <- self$T / num_steps
      for (i in 1:num_simulations) {
        S <- self$S0
        path <- c(S)
        for (j in 1:num_steps) {
          dS <- S * (self$r * dt + self$sigma * sqrt(dt) * rnorm(1, 0, 1))
          S <- S + dS
          path <- c(path, S)
        }
        paths[[i]] <- path
      }
      return(paths)
    }
  )
)

OptionPricer <- setRefClass("OptionPricer",
  fields = list(model = "FinancialModel"),
  methods = list(
    european_call_price = function(paths) {
      payoff <- 0.0
      for (path in paths) {
        payoff <- payoff + max(tail(path, 1) - self$model$K, 0)
      }
      payoff <- payoff / length(paths)
      discount_factor <- exp(-self$model$r * self$model$T)
      return(payoff * discount_factor)
    }
  )
)

AnalysisEngine <- setRefClass("AnalysisEngine",
  fields = list(pricer = "OptionPricer"),
  methods = list(
    execute = function(num_simulations, num_steps) {
      paths <- self$pricer$model$simulate_paths(num_simulations, num_steps)
      price <- self$pricer$european_call_price(paths)
      return(price)
    }
  )
)

main <- function() {
  S0 <- 100.0
  K <- 100.0
  T <- 1.0
  r <- 0.05
  sigma <- 0.2
  num_simulations <- 1000
  num_steps <- 100
  model <- new("FinancialModel", S0 = S0, K = K, T = T, r = r, sigma = sigma)
  pricer <- new("OptionPricer", model = model)
  engine <- new("AnalysisEngine", pricer = pricer)
  price <- engine$execute(num_simulations, num_steps)
  print(paste("European Call Option Price:", price))
}

main()