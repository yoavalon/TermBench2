library(stats)

OptionModel <- setRefClass("OptionModel",
                         fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric", n_simulations = "integer"),
                         methods = list(
                           simulate = function() {
                             option_values <- numeric(self$n_simulations)
                             for (i in 1:self$n_simulations) {
                               S_T <- self$S0 * exp((self$r - 0.5 * self$sigma^2) * self$T + self$sigma * sqrt(self$T) * rnorm(1, 0, 1))
                               option_values[i] <- max(0, S_T - self$K)
                             }
                             return(option_values)
                           }
                         ))

PricingEngine <- setRefClass("PricingEngine",
                         fields = list(model = "OptionModel"),
                         methods = list(
                           calculate_price = function() {
                             option_values <- self$model$simulate()
                             return(mean(option_values))
                           }
                         ))

SimulationController <- setRefClass("SimulationController",
                                  fields = list(pricing_engine = "PricingEngine"),
                                  methods = list(
                                    run = function() {
                                      while (TRUE) {
                                        price <- self$pricing_engine$calculate_price()
                                        print(paste("Option price:", price))
                                      }
                                    }
                                  ))

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  n_simulations <- 1000
  model <- OptionModel$new(S0 = S0, K = K, T = T, r = r, sigma = sigma, n_simulations = n_simulations)
  pricing_engine <- PricingEngine$new(model = model)
  controller <- SimulationController$new(pricing_engine = pricing_engine)
  controller$run()
}

main()