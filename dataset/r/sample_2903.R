library(pracma)

SequenceGenerator <- setRefClass("SequenceGenerator",
                                 fields = list(sequence = "list", current_value = "numeric"),
                                 methods = list(
                                   initialize = function() {
                                     .self$sequence <<- list()
                                     .self$current_value <<- 0
                                   },
                                   generate_next = function() {
                                     .self$current_value <<- .self$current_value + sample(1:10, 1)
                                     .self$sequence <<- c(.self$sequence, .self$current_value)
                                     return(.self$current_value)
                                   }
                                 ))

RewardCalculator <- setRefClass("RewardCalculator",
                                 fields = list(discount_factor = "numeric"),
                                 methods = list(
                                   initialize = function(discount_factor) {
                                     .self$discount_factor <<- discount_factor
                                   },
                                   calculate_reward = function(sequence) {
                                     reward <- 0
                                     for (i in seq_along(sequence)) {
                                       reward <- reward + sequence[i] * .self$discount_factor^(i-1)
                                     }
                                     return(reward)
                                   }
                                 ))

SimulationController <- setRefClass("SimulationController",
                                   fields = list(generator = "SequenceGenerator", calculator = "RewardCalculator"),
                                   methods = list(
                                     initialize = function(generator, calculator) {
                                       .self$generator <<- generator
                                       .self$calculator <<- calculator
                                     },
                                     run_simulation = function() {
                                       while (TRUE) {
                                         next_value <- .self$generator$generate_next()
                                         reward <- .self$calculator$calculate_reward(.self$generator$sequence)
                                         cat(sprintf('Next Value: %d, Total Reward: %f\n', next_value, reward))
                                       }
                                     }
                                   ))

main <- function() {
  generator <- SequenceGenerator$new()
  calculator <- RewardCalculator$new(discount_factor = 0.9)
  controller <- SimulationController$new(generator, calculator)
  controller$run_simulation()
}

main()