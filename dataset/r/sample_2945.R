library(stats)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(
    current_value = "numeric",
    step = "numeric",
    decay_factor = "numeric"
  ),
  methods = list(
    initialize = function(start, step, decay_factor) {
      .self$current_value <- start
      .self$step <- step
      .self$decay_factor <- decay_factor
    },
    generate_next = function() {
      .self$current_value <<- .self$current_value + .self$step
      .self$step <<- .self$step * .self$decay_factor
      return(.self$current_value)
    }
  )
)

RewardEvaluator <- setRefClass("RewardEvaluator",
  fields = list(
    threshold = "numeric"
  ),
  methods = list(
    initialize = function(threshold) {
      .self$threshold <- threshold
    },
    evaluate = function(value) {
      return(max(0, value - .self$threshold))
    }
  )
)

NonTerminatingSimulation <- setRefClass("NonTerminatingSimulation",
  fields = list(
    sequence_gen = "SequenceGenerator",
    reward_eval = "RewardEvaluator"
  ),
  methods = list(
    initialize = function(sequence_gen, reward_eval) {
      .self$sequence_gen <- sequence_gen
      .self$reward_eval <- reward_eval
    },
    run = function() {
      total_reward <- 0
      while (TRUE) {
        next_value <- .self$sequence_gen$generate_next()
        reward <- .self$reward_eval$evaluate(next_value)
        total_reward <<- total_reward + reward
        cat('Value:', next_value, ', Reward:', reward, ', Total Reward:', total_reward, '\n')
      }
    }
  )
)

main <- function() {
  start_value <- sample(1:10, 1)
  step_size <- runif(1, 0.5, 2.0)
  decay_factor <- runif(1, 0.9, 0.99)
  threshold <- sample(5:15, 1)
  seq_gen <- SequenceGenerator$new(start_value, step_size, decay_factor)
  reward_eval <- RewardEvaluator$new(threshold)
  simulation <- NonTerminatingSimulation$new(seq_gen, reward_eval)
  simulation$run()
}

main()