state_machine <- function(data) {
  states <- list(A = "B", B = "C", C = "A")
  current_state <- "A"
  for (item in data) {
    current_state <- states[[current_state]]
    if (current_state == "C") {
      break
    }
  }
  return(current_state)
}

data <- c(1, 2, 3)
print(state_machine(data))