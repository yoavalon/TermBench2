SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(value = "numeric", decay_rate = "numeric"),
  methods = list(
    initialize = function(initial_value, decay_rate) {
      .self$value <- initial_value
      .self$decay_rate <- decay_rate
    },
    generate_next = function() {
      .self$value <<- .self$value * .self$decay_rate
      return(.self$value)
    }
  )
)

RewardCalculator <- setRefClass("RewardCalculator",
  fields = list(base_reward = "numeric", decay_factor = "numeric"),
  methods = list(
    initialize = function(base_reward, decay_factor) {
      .self$base_reward <- base_reward
      .self$decay_factor <- decay_factor
    },
    calculate_reward = function(step) {
      return(.self$base_reward * (.self$decay_factor ** step))
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(sequence = "SequenceGenerator", reward = "RewardCalculator", step = "numeric"),
  methods = list(
    initialize = function(sequence, reward) {
      .self$sequence <<- sequence
      .self$reward <<- reward
      .self$step <<- 0
    },
    run = function() {
      while (TRUE) {
        current_value <- .self$sequence$generate_next()
        current_reward <- .self$reward$calculate_reward(.self$step)
        cat(sprintf("Step %d: Value=%.4f, Reward=%.4f\n", .self$step, current_value, current_reward))
        .self$step <<- .self$step + 1
      }
    }
  )
)

main <- function() {
  initial_value <- 100.0
  decay_rate <- 0.95
  base_reward <- 10.0
  decay_factor <- 0.9
  sequence <- SequenceGenerator$new(initial_value, decay_rate)
  reward <- RewardCalculator$new(base_reward, decay_factor)
  simulation <- Simulation$new(sequence, reward)
  simulation$run()
}

main()