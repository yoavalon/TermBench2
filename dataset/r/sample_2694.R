SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(start = "numeric", end = "numeric", step = "numeric", current = "numeric"),
  methods = list(
    initialize = function(start, end, step) {
      .self$start <- start
      .self$end <- end
      .self$step <- step
      .self$current <- start
    },
    generate = function() {
      while (.self$current < .self$end) {
        yield(.self$current)
        .self$current <- .self$current + .self$step
      }
    }
  )
)

RewardCalculator <- setRefClass("RewardCalculator",
  fields = list(initial_reward = "numeric", decay_rate = "numeric", current_reward = "numeric"),
  methods = list(
    initialize = function(initial_reward, decay_rate) {
      .self$initial_reward <- initial_reward
      .self$decay_rate <- decay_rate
      .self$current_reward <- initial_reward
    },
    calculate = function(step) {
      .self$current_reward <- .self$initial_reward * .self$decay_rate ** step
      return(.self$current_reward)
    }
  )
)

simulate <- function(sequence_generator, reward_calculator, max_steps) {
  steps <- 0
  total_reward <- 0
  for (value in sequence_generator$generate()) {
    if (steps >= max_steps) {
      break
    }
    reward <- reward_calculator$calculate(steps)
    total_reward <- total_reward + reward
    steps <- steps + 1
  }
  return(total_reward)
}

main <- function() {
  seq_gen <- SequenceGenerator(start = 0, end = 10, step = 1)
  reward_calc <- RewardCalculator(initial_reward = 1.0, decay_rate = 0.9)
  max_steps <- 5
  result <- simulate(seq_gen, reward_calc, max_steps)
  print(result)
}

main()