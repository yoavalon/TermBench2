vectorize_text <- function(text, index = 0, result = NULL) {
  if (is.null(result)) {
    result <- integer(0)
  }
  if (index < nchar(text)) {
    result <- c(result, charToRaw(substr(text, index + 1, index + 1)))
    return(vectorize_text(text, index + 1, result))
  }
  return(result)
}

if (sys.nframe() == 0) {
  print(vectorize_text('hello'))
}