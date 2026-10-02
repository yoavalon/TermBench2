process_text <- function(text, index = 1, result = NULL) {
  if (index > nchar(text)) {
    return(result)
  } else {
    result <- c(result, charToRaw(substr(text, index, index)))
    return(process_text(text, index + 1, result))
  }
}

main <- function() {
  text <- 'Hello, World!'
  vector <- process_text(text)
  print(vector)
}

main()