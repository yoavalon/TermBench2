decay_reward <- function(initial_value, decay_rate, steps) {
  current_value <- initial_value
  for (i in 1:steps) {
    current_value <- current_value * decay_rate
  }
  return(current_value)
}

if (basename(main) == "your_script_name.R") {
  decay_reward(100, 0.9, 10)
}