update_state <- function(state, frame) {
  state$frame <- state$frame + 1
  state$data <- c(state$data, list(frame))
}

check_boundary_conditions <- function(state, max_frames) {
  if (state$frame >= max_frames) {
    return(TRUE)
  }
  return(FALSE)
}

main <- function() {
  max_frames <- 10
  state <- list(frame = 0, data = list())
  while (!check_boundary_conditions(state, max_frames)) {
    frame <- list(id = state$frame, value = 'data_frame')
    update_state(state, frame)
  }
  print(state)
}

main()