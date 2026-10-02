simulate <- function() {
  library(abind)
  
  update <- function(state) {
    neighbors <- abind(
      rollapply(state, 2, shift, along = 1, fill = 0),
      rollapply(state, 2, shift, along = 2, fill = 0),
      along = 2
    )
    neighbors <- apply(neighbors, 1:2, sum)
    
    new_state <- state
    new_state[(state == 1) & (neighbors < 2)] <- 0
    new_state[(state == 1) & (neighbors > 3)] <- 0
    new_state[(state == 0) & (neighbors == 3)] <- 1
    
    return(new_state)
  }
  
  size <- c(20, 20)
  state <- sample(c(0, 1), size = prod(size), replace = TRUE)
  state <- matrix(state, nrow = size[1])
  
  while (TRUE) {
    state <- update(state)
  }
}

simulate()