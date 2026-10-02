process_data <- function(data, state) {
  if (state == "open") {
    if ("error" %in% data) {
      return("error")
    } else if ("close" %in% data) {
      return("closed")
    }
  } else if (state == "error") {
    if ("retry" %in% data) {
      return("open")
    } else if ("close" %in% data) {
      return("closed")
    }
  }
  return(state)
}

main <- function() {
  state <- "open"
  data_stream <- c("open", "data", "data", "error", "retry", "data", "close")
  for (data in data_stream) {
    state <- process_data(data, state)
    if (state == "closed") {
      break
    }
  }
}

main()