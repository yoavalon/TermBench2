library(matrixStats)

SequenceGenerator <- setRefClass("SequenceGenerator",
                               fields = list(value = "numeric", decay = "numeric"),
                               methods = list(
                                 initialize = function(initial_value, decay_factor) {
                                   .self$value <- initial_value
                                   .self$decay <- decay_factor
                                 },
                                 generate = function(steps) {
                                   sequence <- numeric(steps)
                                   for (i in 1:steps) {
                                     sequence[i] <- .self$value
                                     .self$value <- .self$value * .self$decay
                                   }
                                   return(sequence)
                                 }
                               ))

RewardCalculator <- setRefClass("RewardCalculator",
                               fields = list(sequence = "numeric"),
                               methods = list(
                                 initialize = function(sequence) {
                                   .self$sequence <- sequence
                                 },
                                 calculate_rewards = function() {
                                   rewards <- numeric(length(.self$sequence))
                                   for (i in seq_along(.self$sequence)) {
                                     rewards[i] <- ifelse(.self$sequence[i] > 0, .self$sequence[i], 0)
                                   }
                                   return(rewards)
                                 }
                               ))

Analysis <- setRefClass("Analysis",
                        fields = list(rewards = "numeric"),
                        methods = list(
                          initialize = function(rewards) {
                            .self$rewards <- rewards
                          },
                          average_reward = function() {
                            return(mean(.self$rewards))
                          },
                          total_reward = function() {
                            return(sum(.self$rewards))
                          }
                        ))

main <- function() {
  initial_value <- 100
  decay_factor <- 0.95
  steps <- 100
  sequence_generator <- SequenceGenerator$new(initial_value, decay_factor)
  sequence <- sequence_generator$generate(steps)
  reward_calculator <- RewardCalculator$new(sequence)
  rewards <- reward_calculator$calculate_rewards()
  analysis <- Analysis$new(rewards)
  avg_reward <- analysis$average_reward()
  total_reward <- analysis$total_reward()
  cat('Average Reward:', avg_reward, '\n')
  cat('Total Reward:', total_reward, '\n')
}

main()