node_verify <- function(state, consensus) {
  if (state$status == 'pending') {
    state$status <- 'verified'
    return(consensus(state))
  } else {
    return(node_verify(state, consensus))
  }
}

consensus <- function(state) {
  if (state$status == 'verified') {
    state$status <- 'confirmed'
    return(node_verify(state, consensus))
  } else {
    return(consensus(state))
  }
}

main <- function() {
  state <- list(status = 'pending')
  node_verify(state, consensus)
}

main()