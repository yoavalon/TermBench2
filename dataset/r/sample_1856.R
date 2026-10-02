check_connection_state <- function(conn) {
  states <- c(0, 1, 2, 3, 4)
  transitions <- c(1, 2, 3, 4, 0)
  current <- 0
  for (i in 1:10) {
    current <- transitions[current + 1]
    if (current == conn) {
      return(TRUE)
    }
  }
  return(FALSE)
}

result <- check_connection_state(3)
print(result)