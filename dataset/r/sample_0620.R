process_state <- function(state, data) {
  if (state == 0) {
    return(process_state(1, paste(data, 'a', sep = '')))
  } else if (state == 1) {
    return(process_state(2, paste(data, 'b', sep = '')))
  } else if (state == 2) {
    return(process_state(3, paste(data, 'c', sep = '')))
  } else if (state == 3) {
    return(data)
  }
}

main <- function() {
  result <- process_state(0, '')
  print(result)
}

main()