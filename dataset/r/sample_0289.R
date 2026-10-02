Environment <- setRefClass("Environment",
                         fields = list(
                           max_steps = "numeric",
                           current_step = "numeric"
                         ),
                         methods = list(
                           initialize = function(max_steps) {
                             .self$max_steps <- max_steps
                             .self$current_step <- 0
                           },
                           step = function(action) {
                             .self$current_step <<- .self$current_step + 1
                             reward <- .self$calculate_reward()
                             done <- .self$current_step >= .self$max_steps
                             return(list(reward = reward, done = done))
                           },
                           calculate_reward = function() {
                             return(1 - .self$current_step / .self$max_steps)
                           }
                         ))

Agent <- setRefClass("Agent",
                     fields = list(
                       environment = "Environment"
                     ),
                     methods = list(
                       initialize = function(environment) {
                         .self$environment <<- environment
                       },
                       act = function() {
                         action <- 0
                         result <- .self$environment$step(action)
                         return(list(reward = result$reward, done = result$done))
                       }
                     ))

main <- function() {
  max_steps <- 50
  env <- Environment$new(max_steps)
  agent <- Agent$new(env)
  total_reward <- 0
  repeat {
    result <- agent$act()
    total_reward <- total_reward + result$reward
    if (result$done) {
      break
    }
  }
  print(total_reward)
}

main()