state_machine <- function(x) {
  while (TRUE) {
    x <- ifelse(x == 0, 1, 0)
    state_machine(x)
  }
}

state_machine(0)