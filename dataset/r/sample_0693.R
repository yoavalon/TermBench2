tokenize <- function(text, tokens = NULL) {
  if (is.null(tokens)) {
    tokens <- character(0)
  }
  if (text == '') {
    return(tokens)
  } else {
    return(tokenize(substr(text, 2, nchar(text)), c(tokens, substr(text, 1, 1))))
  }
}

if (identical(commandArgs(trailingOnly = TRUE), '')) {
  result <- tokenize('hello world')
  print(result)
}