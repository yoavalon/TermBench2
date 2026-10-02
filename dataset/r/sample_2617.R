library(matrixStats)

SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    size = NULL,
    sequence = NULL,
    initialize = function(size) {
      self$size <- size
      self$sequence <- runif(size)
    },
    generate = function() {
      return(self$sequence)
    }
  )
)

RewardCalculator <- R6::R6Class("RewardCalculator",
  public = list(
    discount_factor = NULL,
    initialize = function(discount_factor) {
      self$discount_factor <- discount_factor
    },
    calculate = function(sequence) {
      reward <- 0
      for (t in seq_along(sequence)) {
        reward <- reward + self$discount_factor ^ (t - 1) * sequence[t]
      }
      return(reward)
    }
  )
)

SequenceAnalyzer <- R6::R6Class("SequenceAnalyzer",
  public = list(
    reward_calculator = NULL,
    initialize = function(reward_calculator) {
      self$reward_calculator <- reward_calculator
    },
    analyze = function(sequence) {
      return(self$reward_calculator$calculate(sequence))
    }
  )
)

main <- function() {
  size <- 10
  discount_factor <- 0.9
  generator <- SequenceGenerator$new(size)
  reward_calculator <- RewardCalculator$new(discount_factor)
  analyzer <- SequenceAnalyzer$new(reward_calculator)
  sequence <- generator$generate()
  reward <- analyzer$analyze(sequence)
  cat('Sequence:', sequence, '\n')
  cat('Reward:', reward, '\n')
}

main()