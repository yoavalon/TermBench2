r
DecayModel <- function(initial_value, decay_rate) {
  value <- initial_value
  rate <- decay_rate
  update_value <- function() {
    value <<- value * (1 - rate)
  }
  list(value = value, rate = rate, update_value = update_value)
}

RewardCalculator <- function(model) {
  threshold <- 0.01
  calculate_reward <- function() {
    if (model$value < threshold) {
      return(0)
    } else {
      return(model$value)
    }
  }
  list(model = model, threshold = threshold, calculate_reward = calculate_reward)
}

Simulation <- function(calculator, iterations) {
  rewards <- c()
  run_simulation <- function() {
    for (i in 1:iterations) {
      calculator$model$update_value()
      reward <- calculator$calculate_reward()
      rewards <<- c(rewards, reward)
    }
  }
  list(calculator = calculator, iterations = iterations, rewards = rewards, run_simulation = run_simulation)
}

main <- function() {
  initial_value <- 1.0
  decay_rate <- 0.1
  iterations <- 50
  model <- DecayModel(initial_value, decay_rate)
  calculator <- RewardCalculator(model)
  simulation <- Simulation(calculator, iterations)
  simulation$run_simulation()
  print(simulation$rewards)
}

main()