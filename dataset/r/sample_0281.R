Environment <- setRefClass("Environment",
                          fields = list(
                            current = "numeric",
                            goal = "numeric",
                            decay_rate = "numeric",
                            time_step = "numeric"
                          ),
                          methods = list(
                            initialize = function(start, goal, decay_rate) {
                              .self$current <- start
                              .self$goal <- goal
                              .self$decay_rate <- decay_rate
                              .self$time_step <- 0
                            },
                            step = function(action) {
                              .self$current <- .self$current + action
                              .self$time_step <- .self$time_step + 1
                              reward <- .self$compute_reward()
                              done <- .self$is_done()
                              return(list(current = .self$current, reward = reward, done = done))
                            },
                            compute_reward = function() {
                              distance <- abs(.self$current - .self$goal)
                              reward <- 1 / (distance + 1)
                              reward <- reward * (1 - .self$decay_rate) ^ .self$time_step
                              return(reward)
                            },
                            is_done = function() {
                              return(.self$current == .self$goal || .self$time_step > 1000)
                            }
                          ))

Agent <- setRefClass("Agent",
                    fields = list(
                      action_space = "ANY"
                    ),
                    methods = list(
                      initialize = function(action_space) {
                        .self$action_space <- action_space
                      },
                      act = function(observation) {
                        return(.self$action_space$sample(1))
                      }
                    ))

run_episode <- function(env, agent) {
  observation <- env$current
  total_reward <- 0
  done <- FALSE
  while (!done) {
    action <- agent$act(observation)
    step_result <- env$step(action)
    observation <- step_result$current
    reward <- step_result$reward
    done <- step_result$done
    total_reward <- total_reward + reward
  }
  return(total_reward)
}

main <- function() {
  set.seed(42)
  env <- Environment$new(start = 0, goal = 10, decay_rate = 0.01)
  agent <- Agent$new(action_space = list(sample = function(n) rnorm(n, 0, 1)))
  episode_reward <- run_episode(env, agent)
  cat(sprintf('Episode reward: %f\n', episode_reward))
}

main()