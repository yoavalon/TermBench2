library(stats)

OptionPricer <- R6::R6Class("OptionPricer",
  public = list(
    S = NULL,
    K = NULL,
    T = NULL,
    r = NULL,
    sigma = NULL,
    initialize = function(S, K, T, r, sigma) {
      self$S <- S
      self$K <- K
      self$T <- T
      self$r <- r
      self$sigma <- sigma
    },
    d1 = function() {
      (log(self$S / self$K) + (self$r + 0.5 * self$sigma^2) * self$T) / (self$sigma * sqrt(self$T))
    },
    d2 = function() {
      self$d1() - self$sigma * sqrt(self$T)
    },
    call_price = function() {
      self$S * exp(-self$r * self$T) * pnorm(self$d1()) - self$K * exp(-self$r * self$T) * pnorm(self$d2())
    },
    put_price = function() {
      self$K * exp(-self$r * self$T) * pnorm(-self$d2()) - self$S * exp(-self$r * self$T) * pnorm(-self$d1())
    }
  )
)

MonteCarloSimulator <- R6::R6Class("MonteCarloSimulator",
  public = list(
    pricer = NULL,
    simulations = NULL,
    initialize = function(pricer, simulations) {
      self$pricer <- pricer
      self$simulations <- simulations
    },
    simulate = function() {
      call_values <- numeric(self$simulations)
      put_values <- numeric(self$simulations)
      for (i in 1:self$simulations) {
        S_T <- self$pricer$S * exp((self$pricer$r - 0.5 * self$pricer$sigma^2) * self$pricer$T + self$pricer$sigma * sqrt(self$pricer$T) * rnorm(1, 0, 1))
        call_values[i] <- pmax(S_T - self$pricer$K, 0)
        put_values[i] <- pmax(self$pricer$K - S_T, 0)
      }
      return(list(mean(call_values), mean(put_values)))
    }
  )
)

main <- function() {
  S <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  simulations <- 10000
  pricer <- OptionPricer$new(S, K, T, r, sigma)
  simulator <- MonteCarloSimulator$new(pricer, simulations)
  result <- simulator$simulate()
  cat('Call Price:', result[[1]], '\n')
  cat('Put Price:', result[[2]], '\n')
}

main()