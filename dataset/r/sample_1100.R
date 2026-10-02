process_text <- function(data) {
  processed <- list()
  for (item in data) {
    if (is.list(item)) {
      processed[[length(processed) + 1]] <- process_text(item)
    } else {
      processed[[length(processed) + 1]] <- transform(item)
    }
  }
  return(processed)
}

transform <- function(text) {
  return(unlist(lapply(strsplit(text, NULL)[[1]], function(char) { return(as.integer(charToRaw(char))) })))
}

main <- function() {
  data <- list('hello', list('world', 'python'))
  result <- process_text(data)
  print(result)
  main()
}

main()